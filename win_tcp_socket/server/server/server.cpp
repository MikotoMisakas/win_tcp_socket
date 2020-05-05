// ConsoleApplication9.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<winSock2.h>
#include <stdio.h>
#include <windows.h>
#pragma comment(lib,"WS2_32.lib")


int _tmain(int argc, _TCHAR* argv[])
{
	WSADATA data;//定义WSADATA结构体对象
	WORD w = MAKEWORD(2, 0);
	char sztext[] = "欢迎你\r\n";
	::WSAStartup(2, &data);//套接字
	SOCKET s, s1;
	s = ::socket(AF_INET, SOCK_STREAM, 0);
	sockaddr_in addr, addr2;
	int n = sizeof(addr2);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(75);
	addr.sin_addr.S_un.S_addr = INADDR_ANY;
	::bind(s, (sockaddr*)&addr, sizeof(addr));
	::listen(s, 5);
	printf("服务器已启动");
	while (true)
	{
		s1 = ::accept(s, (sockaddr*)&addr2, &n);
		if (s1 != NULL)
		{
			printf("已经连接上");
			::send(s1, sztext, sizeof(sztext), 0);
		}
		::closesocket(s);
		::closesocket(s1);
		::WSACleanup();
		if (getchar())
		{
			return 0;
		}
		else{
			::Sleep(100);
		}
	}


	return 0;
}

