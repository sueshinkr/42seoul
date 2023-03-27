from socket import *

import time

GREEN = '\033[32m'
RED = '\033[91m'
YELLOW = '\033[93m'
RESET = '\033[0m'

ip = "localhost"
port = 9090

def send_server(s, value):
   s.send(bytes(value + "\r\n", encoding='utf-8'))

def recv_server(s):
	result = ""
	while True:
		try :
			tmp = s.recv(2048).decode()
			result += tmp
		except :
			return result

def info_msg(msg):
	l = 56 - len(msg) - 2
	print("=" * (l//2), end='')
	print(" " + msg + " ", end='')
	if l % 2 == 0:
		print("=" * ((l//2) - 1))
	else:
		print("=" * (l//2))

s = socket(AF_INET,SOCK_STREAM)
s2 = socket(AF_INET, SOCK_STREAM)
s2.connect((ip, port))
s.connect((ip,port))
s.settimeout(1.0)
s2.settimeout(1.0)

# ====================== LOGIN ======================
info_msg("LOGIN")
send_server(s,"PASS a")
send_server(s,"NICK taehyeok")
send_server(s,"USER username hostname servername realname")

send_server(s2,"PASS a")
send_server(s2,"NICK temp")
send_server(s2,"USER username hostname servername realname")
answer = recv_server(s)
assert "001" in answer and "002" in answer, f"{RED}[TEST 1] Login |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 1] Login |OK|" + RESET)
time.sleep(0.5)
print("=======================================================\n")
# =======================================================

# ====================== JOIN TEST ======================
info_msg("JOIN")
# TEST 1 Simple Join
send_server(s, "JOIN #1")
answer = recv_server(s)
assert "JOIN #1" in answer and "353" in answer and "366" in answer, f"{RED}[TEST 1] Simple Join |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 1] Simple Join |OK|" + RESET)
time.sleep(0.5)

# TEST 2 Double Join
#send_server(s, "JOIN #1\r\n")
answer = recv_server(s)
assert "JOIN #1" not in answer and "353" not in answer and "366" not in answer, f"{RED}[TEST 2] Double Join |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 2] Double Join |OK|" + RESET)
time.sleep(0.5)

# TEST 3 Not Enough Parameter
send_server(s, "JOIN")
answer = recv_server(s)
assert "461" in answer, f"{RED}[TEST 3] Not Enough Parameter |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 3] Not Enough Parameter |OK|" + RESET)
time.sleep(0.5)

# TEST 4 Too many Paramter
send_server(s, "JOIN #1 #11 #111 #1111 #11111")
answer = recv_server(s)
assert "" == answer, f"{RED}[TEST 4] Too Many Parameter |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 4] Too Many Parameter |OK|" + RESET)
time.sleep(0.5)

# TEST 5 Not Channel Name
send_server(s, "JOIN 123")
answer = recv_server(s)
assert "" == answer, f"{RED} [TEST 5] Not Channel Name |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 5] Not Channel Name |OK|" + RESET)
time.sleep(0.5)

# TEST 6 Max limit Join
send_server(s2, "JOIN #11")
send_server(s2, "MODE #11 +l 1")
answer = recv_server(s2)
send_server(s, "JOIN #11")
answer = recv_server(s)
assert "471" in answer, f"{RED} [TEST 6] Max limit Join |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 6] Max limit Join |OK|" + RESET)
time.sleep(0.5)

# TEST 7 Bad Channel Key
send_server(s2, "JOIN #111 key")
answer = recv_server(s2)
send_server(s, "JOIN #111")
answer = recv_server(s)
assert "475" in answer, f"{RED} [TEST 7] Bad Channel Key |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 7] Bad Channel Key |OK|" + RESET)
time.sleep(0.5)

# TEST 8 Join Channel with Key
send_server(s, "JOIN #111 key")
answer = recv_server(s)
assert "JOIN #111" in answer, f"{RED} [TEST 8] Join Channel with Key |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 8] Join Channel with Key |OK|" + RESET)
time.sleep(0.5)

# TEST 9 Part All Channel (JOIN 0)
send_server(s, "JOIN #1111")
send_server(s, "JOIN #1112")
send_server(s, "JOIN #1113")
send_server(s, "JOIN 0")
answer = recv_server(s)
assert "PART #1111" in answer and "PART #1112" in answer and "PART #1113" in answer, f"{RED} [TEST 9] Part All Channel (JOIN 0) |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 9] Part All Channel (JOIN 0) |OK|" + RESET)
time.sleep(0.5)
print("=======================================================\n")
# =======================================================

# ====================== KICK TEST ======================
info_msg("KICK")
# Test 1 Not Enough Parameter
send_server(s, "KICK")
answer = recv_server(s)
assert "461" in answer, f"{RED}[TEST 1] Not Enough Parameter |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 1] Not Enough Parameter |OK|" + RESET)
time.sleep(0.5)

# Test 2 Too many Paramter
send_server(s, "KICK #123 abcd abcd abcd abcd")
answer = recv_server(s)
assert "" == answer, f"{RED}[TEST 2] Too Many Parameter |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 2] Too Many Parameter |OK|" + RESET)
time.sleep(0.5)

# Test 3 No Channel
send_server(s, "KICK #abcd taehyeok")
answer = recv_server(s)
assert "403" in answer, f"{RED}[TEST 3] No Channel |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 3] No Channel |OK|" + RESET)
time.sleep(0.5)

# Test 4 No Such User
send_server(s, "JOIN #1")
send_server(s, "KICK #1 nonick")
answer = recv_server(s)
assert "401" in answer, f"{RED}[TEST 4] No Such User |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 4] No Such User |OK|" + RESET)
time.sleep(0.5)

# Test 5 No Such Channel
send_server(s, "KICK #123 taehyeok")
answer = recv_server(s)
assert "403" in answer, f"{RED}[TEST 5] No Such Channel |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 5] No Such Channel |OK|" + RESET)
time.sleep(0.5)

# Test 6 No Channel Oper
send_server(s, "MODE #1 -o taehyeok")
send_server(s, "KICK #1 taehyeok")
answer = recv_server(s)
assert "482" in answer, f"{RED}[TEST 6] No Channel Oper |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 6] No Channel Oper |OK|" + RESET)
time.sleep(0.5)

# Test 7 Simple Kick
send_server(s, "JOIN #22")
send_server(s, "KICK #22 taehyeok")
answer = recv_server(s)
assert "KICK #22 taehyeok" in answer, f"{RED}[TEST 7] Simple Kick |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 7] Simple Kick |OK|" + RESET)
time.sleep(0.5)

# Test 8 Not in Channel
send_server(s2, "JOIN #222")
answer = recv_server(s2)
send_server(s, "KICK #222 temp")
answer = recv_server(s)
assert "442" in answer, f"{RED}[TEST 8] Not in Channel |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 8] Not in Channel |OK|" + RESET)
time.sleep(0.5)
print("=======================================================\n")
# =======================================================

# ====================== KILL TEST ======================
info_msg("KILL")
# Test 1 Not Enough Parameter
send_server(s, "kill")
answer = recv_server(s)
assert "461" in answer, f"{RED}[TEST 1] Not Enough Parameter |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 1] Not Enough Parameter |OK|" + RESET)
time.sleep(0.5)

# Test 2 Too many Paramter
send_server(s, "kill abcd abcd abcd abcd abcd")
answer = recv_server(s)
assert "" == answer, f"{RED}[TEST 2] Too Many Parameter |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 2] Too Many Parameter |OK|" + RESET)
time.sleep(0.5)

# Test 3 Not Operator
send_server(s, "kill taehyeok")
answer = recv_server(s)
assert "481" in answer, f"{RED}[TEST 3] Not Operator |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 3] Not Operator |OK|" + RESET)

# Test 4 No Such Nick
send_server(s, "OPER taehyeok password")
send_server(s, "kill abcd")
answer = recv_server(s)
assert "401" in answer, f"{RED}[TEST 4] No Such Nick |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 4] No Such Nick |OK|" + RESET)

# Test 5 Simple Kill
send_server(s, "kill temp")
answer = recv_server(s)
assert "361" in answer, f"{RED}[TEST 5] Simple Kill |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 5] Simple Kill |OK|" + RESET)
s2.close()
s2 = socket(AF_INET, SOCK_STREAM)

# Reconnect Temp
s2.connect((ip, port))
s2.settimeout(1.0)
send_server(s2,"PASS a")
send_server(s2,"NICK temp")
send_server(s2,"USER username hostname servername realname")
print("=======================================================\n")
# =======================================================

# ====================== Channel MODE TEST ======================
info_msg("Channel MODE")
# Test 1 Not Enough Parameter
send_server(s, "MODE")
answer = recv_server(s)
assert "461" in answer, f"{RED}[TEST 1] Not Enough Parameter |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 1] Not Enough Parameter |OK|" + RESET)
time.sleep(0.5)

# Test 2 Too many Paramter
send_server(s, "MODE #1 abcd abcd abcd abcd")
answer = recv_server(s)
assert "" == answer, f"{RED}[TEST 2] Too Many Parameter |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 2] Too Many Parameter |OK|" + RESET)
time.sleep(0.5)

# Test 3 No Such Channel
send_server(s, "MODE #noChannel +v taehyeok")
answer = recv_server(s)
assert "403" in answer, f"{RED}[TEST 3] No Such Channel |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 3] No Such Channel |OK|" + RESET)
time.sleep(0.5)

# Test 4 Not On Channel
send_server(s2, "JOIN #MODEtest4")
answer = recv_server(s2)
send_server(s, "MODE #MODEtest4 -v temp")
answer = recv_server(s)
assert "441" in answer, f"{RED}[TEST 4] Not On Channel |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 4] Not On Channel |OK|" + RESET)
time.sleep(0.5)

# Test 5 Voice Channel Option
send_server(s, "JOIN #MODEtest5")
send_server(s, "MODE #MODEtest5 +v taehyeok")
send_server(s, "MODE #MODEtest5 -v taehyeok")
answer = recv_server(s)
assert "MODE #MODEtest5 -v taehyeok" in answer and "MODE #MODEtest5 +v taehyeok" in answer, f"{RED}[TEST 5] Voice Channel Option |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 5] Voice Channel Option |OK|" + RESET)
time.sleep(0.5)

# Test 6 Notice Channel Option
send_server(s, "MODE #MODEtest5 +n")
send_server(s, "MODE #MODEtest5 -n")
answer = recv_server(s)
assert "MODE #MODEtest5 -n" in answer and "MODE #MODEtest5 +n" in answer, f"{RED}[TEST 6] Notice Channel Option |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 6] Notice Channel Option |OK|" + RESET)
time.sleep(0.5)

# Test 7 Limit Channel Option
send_server(s, "MODE #MODEtest5 +l 10")
send_server(s, "MODE #MODEtest5 -l")
answer = recv_server(s)
assert "MODE #MODEtest5 -l" in answer and "MODE #MODEtest5 +l 10" in answer, f"{RED}[TEST 7] Limit Channel Option |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 7] Limit Channel Option |OK|" + RESET)
time.sleep(0.5)

# Test 8 Key Channel Option
send_server(s, "MODE #MODEtest5 +k key")
send_server(s, "MODE #MODEtest5 -k key")
answer = recv_server(s)
assert "MODE #MODEtest5 -k key" in answer and "MODE #MODEtest5 +k key" in answer, f"{RED}[TEST 8] Key Channel Option |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 8] Key Channel Option |OK|" + RESET)
time.sleep(0.5)

# Test 9 No Option
send_server(s, "MODE #MODEtest5 +b key")
answer = recv_server(s)
assert "472" in answer, f"{RED}[TEST 9] No Option |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 9] No Option |OK|" + RESET)
time.sleep(0.5)

# Test 10 Operator Channel Option
send_server(s, "MODE #MODEtest5 +o taehyeok")
send_server(s, "MODE #MODEtest5 -o taehyeok")
answer = recv_server(s)
assert "MODE #MODEtest5 +o taehyeok" in answer and "MODE #MODEtest5 -o taehyeok" in answer, f"{RED}[TEST 10] Operator Channel Option |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 10] Operator Channel Option |OK|" + RESET)
time.sleep(0.5)

# Test 11 Not Channel Operator
send_server(s, "MODE #MODEtest5 +o taehyeok")
answer = recv_server(s)
assert "482" in answer, f"{RED}[TEST 11] Not Channel Operator |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 11] Not Channel Operator |OK|" + RESET)
time.sleep(0.5)
print("=======================================================\n")
# =======================================================

# ====================== User MODE TEST ======================
info_msg("User MODE")
# Test 1 Not Enough Parameter
send_server(s, "MODE")
answer = recv_server(s)
assert "461" in answer, f"{RED}[TEST 1] Not Enough Parameter |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 1] Not Enough Parameter |OK|" + RESET)
time.sleep(0.5)

# Test 2 Too many Paramter
send_server(s, "MODE abcd abcd abcd abcd abcd")
answer = recv_server(s)
assert "" == answer, f"{RED}[TEST 2] Too Many Parameter |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 2] Too Many Parameter |OK|" + RESET)
time.sleep(0.5)

# Test 3 +Operator User option
send_server(s, "MODE taehyeok +o")
answer = recv_server(s)
assert "481" in answer, f"{RED}[TEST 3] +Operator User option |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 3] +Operator User option |OK|" + RESET)
time.sleep(0.5)

# Test 4 -Operator User option
send_server(s, "OPER taehyeok password")
send_server(s, "MODE taehyeok -o")
answer = recv_server(s)
assert "MODE taehyeok" in answer, f"{RED}[TEST 4] -Operator User option |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 4] -Operator User option |OK|" + RESET)
time.sleep(0.5)

# Test 5 Another User option
send_server(s, "MODE taehyeok -k")
answer = recv_server(s)
assert "501" in answer, f"{RED}[TEST 5] Another User option |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 5] Another User option |OK|" + RESET)
time.sleep(0.5)

# Test 6 User Don't Match
send_server(s, "MODE temp -i")
answer = recv_server(s)
assert "502" in answer, f"{RED}[TEST 6] User Don't Match |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 6] User Don't Match |OK|" + RESET)
time.sleep(0.5)

# Test 7 No Such User
send_server(s, "MODE abc -k")
answer = recv_server(s)
assert "401" in answer, f"{RED}[TEST 7] No Such User |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 7] No Such User |OK|" + RESET)
time.sleep(0.5)
print("=======================================================\n")
# =======================================================

# ====================== NICK TEST ======================
info_msg("NICK")
# Test 1 Not Enough Parameter
send_server(s, "NICK")
answer = recv_server(s)
assert "431" in answer, f"{RED}[TEST 1] Not Enough Parameter |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 1] Not Enough Parameter |OK|" + RESET)
time.sleep(0.5)

# Test 2 Too many Paramter
send_server(s, "NICK abcd abcd abcd abcd abcd")
answer = recv_server(s)
assert "" == answer, f"{RED}[TEST 2] Too Many Parameter |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 2] Too Many Parameter |OK|" + RESET)
time.sleep(0.5)

# Test 3 Simple Nick
send_server(s, "NICK sueshin")
answer = recv_server(s)
assert "NICK sueshin" in answer, f"{RED}[TEST 3] Simple Nick |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 3] Simple Nick |OK|" + RESET)
time.sleep(0.5)

# Test 4 Dupulicate Nick
send_server(s, "NICK temp")
answer = recv_server(s)
assert "433" in answer, f"{RED}[TEST 4] Dupulicate Nick |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 4] Dupulicate Nick |OK|" + RESET)
time.sleep(0.5)

# Test 5 Invalid Nick
send_server(s, "NICK #123")
answer = recv_server(s)
assert "432" in answer, f"{RED}[TEST 5] Invalid Nick |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 5] Invalid Nick |OK|" + RESET)
time.sleep(0.5)
print("=======================================================\n")
# =======================================================

# ====================== NOTICE TEST ======================
info_msg("NOTICE")
# Test 1 Not Enough Parameter
send_server(s, "NOTICE")
answer = recv_server(s)
assert "" in answer, f"{RED}[TEST 1] Not Enough Parameter |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 1] Not Enough Parameter |OK|" + RESET)
time.sleep(0.5)
print("=======================================================\n")
# =======================================================

# ====================== PRIVMSG TEST ======================
info_msg("PRIVMSG")
# Test 1 Not Enough Parameter
send_server(s, "PRIVMSG")
answer = recv_server(s)
assert "" in answer, f"{RED}[TEST 1] Not Enough Parameter |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 1] Not Enough Parameter |OK|" + RESET)
time.sleep(0.5)

# Test 2 Channel Privmsg
send_server(s, "JOIN #testPriv")
send_server(s2, "JOIN #testPriv")
answer = recv_server(s2)
send_server(s, "PRIVMSG #testPriv Hi")
answer = recv_server(s2)
assert "PRIVMSG #testPriv Hi" in answer, f"{RED}[TEST 2] Channel Privmsg |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 2] Channel Privmsg |OK|" + RESET)
time.sleep(0.5)

# Test 3 User Privmsg
send_server(s, "PRIVMSG temp Hi")
answer = recv_server(s2)
assert "PRIVMSG temp Hi" in answer, f"{RED}[TEST 3] User Privmsg |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 3] User Privmsg |OK|" + RESET)
time.sleep(0.5)

# Test 4 Not In Channel
send_server(s2, "JOIN #testPriv2")
send_server(s, "PRIVMSG #testPriv2 Hi")
answer = recv_server(s2)
assert "PRIVMSG #testPriv2 Hi" in answer, f"{RED}[TEST 4] Not In Channel |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 4] Not In Channel |OK|" + RESET)
time.sleep(0.5)

# Test 5 No Such Channel
send_server(s, "PRIVMSG #abcdefg Hi")
answer = recv_server(s)
assert "403" in answer, f"{RED}[TEST 5] No Such Channel |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 5] No Such Channel |OK|" + RESET)
time.sleep(0.5)

# Test 6 No Such Nick
send_server(s, "PRIVMSG abcdefg Hi")
answer = recv_server(s)
assert "401" in answer, f"{RED}[TEST 6] No Such Nick |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 6] No Such Nick |OK|" + RESET)
time.sleep(0.5)

# Test 7 Send to -v Channel
send_server(s, "JOIN #testPriv2")
send_server(s2, "MODE #testPriv2 -v sueshin")
answer = recv_server(s2)
send_server(s, "PRIVMSG #testPriv2 Hi")
answer = recv_server(s)
assert "404" in answer, f"{RED}[TEST 7] Send to -v Channel |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 7] Send to -v Channel |OK|" + RESET)
time.sleep(0.5)

# Test 8 Not In Channel(+n)
send_server(s2, "JOIN #testPriv3")
send_server(s2, "MODE #testPriv3 +n")
answer = recv_server(s2)
send_server(s, "PRIVMSG #testPriv3 Hi")
answer = recv_server(s)
assert "404" in answer, f"{RED}[TEST 8] Not In Channel(+n) |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 8] Not In Channel(+n) |OK|" + RESET)
time.sleep(0.5)
print("=======================================================\n")
# =======================================================

# ====================== OPER TEST ======================
info_msg("OPER")
# Test 1 Not Enough Parameter
send_server(s, "OPER")
answer = recv_server(s)
assert "461" in answer, f"{RED}[TEST 1] Not Enough Parameter |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 1] Not Enough Parameter |OK|" + RESET)
time.sleep(0.5)

# Test 2 Too many Paramter
send_server(s, "OPER abcd abcd abcd abcd abcd")
answer = recv_server(s)
assert "" == answer, f"{RED}[TEST 2] Too Many Parameter |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 2] Too Many Parameter |OK|" + RESET)
time.sleep(0.5)

# Test 3 No Such Nick
send_server(s, "OPER abcd password")
answer = recv_server(s)
assert "401" in answer, f"{RED}[TEST 3] No Such Nick |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 3] No Such Nick |OK|" + RESET)
time.sleep(0.5)

# Test 4 Simple Oper
send_server(s, "OPER sueshin password")
answer = recv_server(s)
assert "381" in answer, f"{RED}[TEST 4] Simple Oper |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 4] Simple Oper |OK|" + RESET)
time.sleep(0.5)
print("=======================================================\n")
# =======================================================

# ====================== PART TEST ======================
info_msg("PART")
# Test 1 Not Enough Parameter
send_server(s, "PART")
answer = recv_server(s)
assert "461" in answer, f"{RED}[TEST 1] Not Enough Parameter |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 1] Not Enough Parameter |OK|" + RESET)
time.sleep(0.5)

# Test 2 Too many Paramter
send_server(s, "PART abcd abcd abcd abcd abcd")
answer = recv_server(s)
assert "" == answer, f"{RED}[TEST 2] Too Many Parameter |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 2] Too Many Parameter |OK|" + RESET)
time.sleep(0.5)

# Test 3 Wrong Channel Name
send_server(s, "PART 1234")
answer = recv_server(s)
assert "" == answer, f"{RED}[TEST 3] Wrong Channel Name |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 3] Wrong Channel Name |OK|" + RESET)
time.sleep(0.5)

# Test 4 Simple Part
send_server(s, "JOIN #part1")
send_server(s, "PART #part1")
answer = recv_server(s)
assert "PART #part1" in answer, f"{RED}[TEST 4] Simple Part |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 4] Simple Part |OK|" + RESET)
time.sleep(0.5)

# Test 5 No Such Channel
send_server(s, "PART #part1")
answer = recv_server(s)
assert "403" in answer, f"{RED}[TEST 5] No Such Channel |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 5] No Such Channel |OK|" + RESET)
time.sleep(0.5)

# Test 6 Multiple Part Channel
send_server(s, "JOIN #part1")
send_server(s, "JOIN #part2")
send_server(s, "PART #part1,#part2")
answer = recv_server(s)
assert "PART #part1" in answer and "PART #part2" in answer, f"{RED}[TEST 6] Multiple Part Channel |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 6] Multiple Part Channel |OK|" + RESET)
time.sleep(0.5)

# Test 7 Not In Channel
send_server(s2, "JOIN #part1")
answer = recv_server(s2)
send_server(s, "PART #part1")
answer = recv_server(s)
assert "442" in answer, f"{RED}[TEST 7] Not In Channel |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 7] Not In Channel |OK|" + RESET)
time.sleep(0.5)
print("=======================================================\n")
# =======================================================

# ====================== PONG TEST ======================
info_msg("PONG")
# Test 1 Not Enough Parameter
send_server(s, "PING")
answer = recv_server(s)
assert "461" in answer, f"{RED}[TEST 1] Not Enough Parameter |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 1] Not Enough Parameter |OK|" + RESET)
time.sleep(0.5)

# Test 2 Too many Paramter
send_server(s, "PING abcd abcd abcd abcd abcd")
answer = recv_server(s)
assert "" == answer, f"{RED}[TEST 2] Too Many Parameter |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 2] Too Many Parameter |OK|" + RESET)
time.sleep(0.5)
print("=======================================================\n")
# =======================================================

# ====================== WHOIS TEST ======================
info_msg("WHOIS")
# Test 1 Not Enough Parameter
send_server(s, "WHOIS")
answer = recv_server(s)
assert "461" in answer, f"{RED}[TEST 1] Not Enough Parameter |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 1] Not Enough Parameter |OK|" + RESET)
time.sleep(0.5)

# Test 2 Too many Paramter
send_server(s, "WHOIS abcd abcd abcd abcd abcd")
answer = recv_server(s)
assert "" == answer, f"{RED}[TEST 2] Too Many Parameter |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 2] Too Many Parameter |OK|" + RESET)
time.sleep(0.5)

# Test 3 No Such Nick
send_server(s, "WHOIS abcd")
answer = recv_server(s)
assert "401" in answer, f"{RED}[TEST 3] No Such Nick |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 3] No Such Nick |OK|" + RESET)
time.sleep(0.5)

# Test 4 Simple Whois
send_server(s, "WHOIS sueshin")
answer = recv_server(s)
assert "312" in answer and "318" in answer, f"{RED}[TEST 4] Simple Whois |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 4] Simple Whois |OK|" + RESET)
time.sleep(0.5)
print("=======================================================\n")
# =======================================================

# ====================== USER TEST ======================
info_msg("USER")
# Test 1 Not Enough Parameter
send_server(s, "USER")
answer = recv_server(s)
assert "461" in answer, f"{RED}[TEST 1] Not Enough Parameter |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 1] Not Enough Parameter |OK|" + RESET)
time.sleep(0.5)

# Test 2 Too many Paramter
send_server(s, "USER abcd abcd abcd abcd abcd")
answer = recv_server(s)
assert "" == answer, f"{RED}[TEST 2] Too Many Parameter |KO| {YELLOW}\n=== RECV_DATA ===\n{answer}{RESET}"
print(GREEN + "[TEST 2] Too Many Parameter |OK|" + RESET)
time.sleep(0.5)
print("=======================================================\n")
# =======================================================


print("=======================================================")
print(GREEN + "[🌈Congratulations!!🌈] All Tests |OK|" + RESET)
print("=======================================================")
