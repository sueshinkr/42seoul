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

using namespace std;

#define BUF_SIZE	2048
#define BUF_SMALL	100
#define EPOLL_SIZE	50

void*	request_handler(void *arg);
const char*	content_type(char *file);
void	send_data(FILE *fp, char *ct, char *filename);
void	send_error(FILE *fp);
void	setnonblock(int fd);
void	error_handling(const char *message);

int	main(int argc, char *argv[])
{
	int					serv_sock, clnt_sock;
	struct sockaddr_in	serv_adr, clnt_adr;
	socklen_t			clnt_adr_size;
	pthread_t			t_id;

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
		error_handling("bind() error");

	if (::listen(serv_sock, 5) == -1)
		error_handling("listen() error");

	epfd = epoll_create(EPOLL_SIZE);	// epoll 인스턴스 생성성
	ep_events = new epoll_event[EPOLL_SIZE];

	setnonblock(serv_sock);
	event.events = EPOLLIN;
	event.data.fd = serv_sock;
	epoll_ctl(epfd, EPOLL_CTL_ADD, serv_sock, &event);	// epoll 인스턴스에 관찰대상이 되는 fd 등록

	//	요청 및 응답
	while (1)
	{
		event_cnt = epoll_wait(epfd, ep_events, EPOLL_SIZE, -1);
		if (event_cnt == -1)
			break;

		for (int i = 0; i < event_cnt; i++)
		{
			
			if (ep_events[i].data.fd == serv_sock)
			{
				clnt_adr_size = sizeof(clnt_adr);
				clnt_sock = accept(serv_sock, (sockaddr*)&clnt_adr, &clnt_adr_size);
				setnonblock(clnt_sock);
				event.events = EPOLLIN | EPOLLET;
				event.data.fd = clnt_sock;
				epoll_ctl(epfd, EPOLL_CTL_ADD, clnt_sock, &event);
				cout << "Connection Request : " << inet_ntoa(clnt_adr.sin_addr) << " : " << ntohs(clnt_adr.sin_port) << endl;
			}
			else
			{
				pthread_create(&t_id, NULL, request_handler, &ep_events[i]);
				pthread_detach(t_id);
			}
		}
	}
	close(serv_sock);
	return 0;
}

void*	request_handler(void *arg)
{
	epoll_event	ep_event = *(epoll_event *)arg;
	int			clnt_sock = ep_event.data.fd;
	char		req_line[BUF_SMALL];
	FILE		*clnt_read;
	FILE		*clnt_write;

	char	method[BUF_SMALL];
	char	ct[BUF_SMALL];
	char	file_name[BUF_SMALL];

	clnt_read = fdopen(clnt_sock, "r");
	clnt_write = fdopen(dup(clnt_sock), "w");
	fgets(req_line, BUF_SMALL, clnt_read);
	if (strstr(req_line, "HTTP/") == NULL)
	{
		send_error(clnt_write);
		fclose(clnt_read);
		fclose(clnt_write);
		return NULL;
	}

	strcpy(method, strtok(req_line, " /"));
	strcpy(file_name, strtok(NULL, " /"));	// 요청 파일이름 확인
	strcpy(ct, content_type(file_name));	// Content-type 확인
	if (strcmp(method, "GET"))				// Get 방식 요청인지 확인
	{
		send_error(clnt_write);
		fclose(clnt_read);
		fclose(clnt_write);
		return NULL;
	}
	
	fclose(clnt_read);
	send_data(clnt_write, ct, file_name);	// 응답
	return NULL;
}

void	send_data(FILE *fp, char *ct, char *file_name)
{
	char	protocol[] = "HTTP/1.0 200 OK\r\n";
	char	server[] = "Server : simple web server\r\n";
	char	cnt_len[] = "Content-length : 2048\r\n";
	char	cnt_type[BUF_SMALL];
	char	buf[BUF_SIZE];
	FILE	*send_file;

	sprintf(cnt_type, "Content-type : %s\r\n\r\n", ct);
	if ((send_file = fopen(file_name, "r")) == NULL)
	{
		printf("no file\n");
		send_error(fp);
		return ;
	}

	// 헤더 정보 전송
	fputs(protocol, fp);
	fputs(server, fp);
	fputs(cnt_len, fp);
	fputs(cnt_type, fp);

	// 요청 데이터 전송
	while (fgets(buf, BUF_SIZE, send_file) != NULL)
	{
		fputs(buf, fp);
		fflush(fp);
	}
	fflush(fp);
	fclose(fp);
}

void	send_error(FILE *fp)	// 오류 발생시 메시지 전달
{
	char	protocol[] = "HTTP/1.0 400 Bad Request\r\n";
	char	server[] = "Server:siple web server\r\n";
	char	cnt_len[] = "Content-length:2048\r\n";
	char	cnt_type[] = "Content-type:text/html\r\n\r\n";
	char	content[] = "<html><head><title>NETWORK</title></head>"
		"<body><font size=+5><br>오류 발생! 요청 파일명 및 요청 방식 확인!"
		"</font></body></html>";

	printf("send_error\n");
	fputs(protocol, fp);
	fputs(server, fp);
	fputs(cnt_len, fp);
	fputs(cnt_type, fp);
	fputs(content, fp);
	fflush(fp);
}

const char*	content_type(char *file)	// Content-Type 구분
{
	char	extension[BUF_SMALL];
	char	file_name[BUF_SMALL];
	
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

void	error_handling(const char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
