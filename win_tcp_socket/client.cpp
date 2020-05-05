#include <WinSock2.h>//包含套接字库
#include <stdio.h>
#include <windows.h>
#pragma comment(lib,"WS2_32.lib")//显示连接套接字库
int main(){
	WSADATA data;//定义WSADATA结构体对象
	WORD w = MAKEWORD(2, 0);//定义版本号
	::WSAStartup(w, &data);//初始化套接字库
	SOCKET s;//定义连接套接字句柄
	char sztex[10] = { 0 };
	s = ::socket(AF_INET, SOCK_STREAM, 0);//创建tcp套接字
	sockaddr_in addr;//定义套接字地址结构
	addr.sin_family = AF_INET;//初始化地址结构
	addr.sin_port = htons(75);
	addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	printf("客户端已启动");//输出提示信息
	::connect(s, (sockaddr*)&addr, sizeof(addr));
	::recv(s, sztex, sizeof(sztex), 0);
	printf("%s\r\n", sztex);
	::closesocket(s);//关闭套接字句柄
	::WSACleanup();//释放套接字库
	if (getchar())
	{
		return 0;
	}
	else
	{
		::Sleep(100);
	}





	return 0;
}