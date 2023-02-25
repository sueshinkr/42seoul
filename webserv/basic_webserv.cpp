#include <iostream>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <cerrno>

using namespace std;

#define BUF_SIZE	2048
#define BUF_SMALL	100
#define EPOLL_SIZE	50

void	request_handler(int clnt_sock);
const char*	content_type(char *file);
void	send_data(int fd, char *ct, char *filename);
void	send_error(int fd);
void	setnonblock(int fd);

int	main(int argc, char *argv[])
{
	int					serv_sock, clnt_sock;
	struct sockaddr_in	serv_adr, clnt_adr;
	socklen_t			clnt_adr_size;

	struct epoll_event	*ep_events;
	struct epoll_event	event;
	int					epfd, event_cnt;

	if(argc != 2)
	{
		cout << "Usage : " << argv[0] << " <port>\n";
		exit(1);
	}

	serv_sock = socket(PF_INET, SOCK_STREAM, 0);
	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family = AF_INET;
	serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_adr.sin_port = htons(atoi(argv[1]));

	if (::bind(serv_sock, (sockaddr*)&serv_adr, sizeof(serv_adr)) == -1)
		return 1;

	if (::listen(serv_sock, 5) == -1)
		return 1;

	epfd = epoll_create(EPOLL_SIZE);	// epoll 인스턴스 생성성
	ep_events = new epoll_event[EPOLL_SIZE];

	setnonblock(serv_sock);
	event.events = EPOLLIN;
	event.data.fd = serv_sock;
	epoll_ctl(epfd, EPOLL_CTL_ADD, serv_sock, &event);	// epoll 인스턴스에 관찰대상이 되는 fd 등록

	//	요청 및 응답
	while (1)
	{
		cout << "wait for new connection...\n";

		event_cnt = epoll_wait(epfd, ep_events, EPOLL_SIZE, -1);
		if (event_cnt == -1)
			break;

		for (int i = 0; i < event_cnt; i++)
		{
			
			if (ep_events[i].data.fd == serv_sock)
			{
				clnt_adr_size = sizeof(clnt_adr);
				clnt_sock = accept(serv_sock, (sockaddr*)&clnt_adr, &clnt_adr_size);
				//setnonblock(clnt_sock);
				event.events = EPOLLIN;
				event.data.fd = clnt_sock;
				epoll_ctl(epfd, EPOLL_CTL_ADD, clnt_sock, &event);
				cout << "Connection Request : " << "socket " << clnt_sock << " - " << inet_ntoa(clnt_adr.sin_addr) << " : " << ntohs(clnt_adr.sin_port) << endl;
			}
			else
			{
				cout << "Client request\n";
				request_handler(ep_events[i].data.fd);
			}
		}
	}
	close(serv_sock);
	return 0;
}

void	request_handler(int clnt_sock)
{
	char	req_line[BUF_SMALL + 1];
	char	method[BUF_SMALL];
	char	ct[BUF_SMALL];
	char	file_name[BUF_SMALL];

/*
	while (1)
	{
		if (recv(clnt_sock, req_line, 20, 0) < 0 && errno == EAGAIN)
			break;
		cout << ":" << req_line << endl;
	}
*/

	recv(clnt_sock, req_line, 50, 0);
	cout << ":" << req_line << endl;
	if (strstr(req_line, "HTTP/") == NULL)
		send_error(clnt_sock);

	strcpy(method, strtok(req_line, " /"));
	strcpy(file_name, strtok(NULL, " /"));	// 요청 파일이름 확인
	strcpy(ct, content_type(file_name));	// Content-type 확인
	if (strcmp(method, "GET"))				// Get 방식 요청인지 확인
		send_error(clnt_sock);

	send_data(clnt_sock, ct, file_name);	// 응답
}

void	send_data(int fd, char *ct, char *file_name)
{
	std::string	protocol = "HTTP/1.0 200 OK\r\n";
	std::string	server = "Server : simple web server\r\n";
	std::string	cnt_len = "Content-length : 2048\r\n";
	std::string	cnt_type = "Content-type : ";
	std::string	data;
	char buf[BUF_SIZE];
	FILE	*send_file;

	cnt_type += ct;
	cnt_type += "\r\n\r\n";
	if ((send_file = fopen(file_name, "r")) == NULL)
	{
		printf("no file\n");
		send_error(fd);
		return ;
	}
	data = protocol + server + cnt_len + cnt_type;
	while (fgets(buf, BUF_SIZE, send_file) != NULL)
		data += buf;
	send(fd, data.c_str(), data.size(), 0);
	cout << "send data : " << data << endl;
}

void	send_error(int fd)	// 오류 발생시 메시지 전달
{
	std::string	protocol = "HTTP/1.0 400 Bad Request\r\n";
	std::string	server = "Server:siple web server\r\n";
	std::string	cnt_len = "Content-length:2048\r\n";
	std::string	cnt_type = "Content-type:text/html\r\n\r\n";
	std::string	content = "<html><head><title>NETWORK</title></head>"
		"<body><font size=+5><br>오류 발생! 요청 파일명 및 요청 방식 확인!"
		"</font></body></html>";
	std::string error_msg = protocol + server + cnt_len + cnt_type + content;

	send(fd, error_msg.c_str(), error_msg.size(), 0);
}

const char*	content_type(char *file)	// Content-Type 구분
{
	char	extension[BUF_SMALL];
	char	file_name[BUF_SMALL];

	cout << "file : " << file << endl;
	strcpy(file_name, file);
	strtok(file_name, ".");
	strcpy(extension, strtok(NULL, "."));
	if (!strcmp(extension, "html") || !strcmp(extension, "htm"))
		return "text/html";
	else
		return "text/plain";
}

void	setnonblock(int fd)
{
	int flag = fcntl(fd, F_GETFL, 0);
	fcntl(fd, F_SETFL, flag | O_NONBLOCK);
}
