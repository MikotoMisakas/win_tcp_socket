#include <WinSock2.h>//�����׽��ֿ�
#include <stdio.h>
#include <windows.h>
#pragma comment(lib,"WS2_32.lib")//��ʾ�����׽��ֿ�
int main(){
	WSADATA data;//����WSADATA�ṹ�����
	WORD w = MAKEWORD(2, 0);//����汾��
	::WSAStartup(w, &data);//��ʼ���׽��ֿ�
	SOCKET s;//���������׽��־��
	char sztex[10] = { 0 };
	s = ::socket(AF_INET, SOCK_STREAM, 0);//����tcp�׽���
	sockaddr_in addr;//�����׽��ֵ�ַ�ṹ
	addr.sin_family = AF_INET;//��ʼ����ַ�ṹ
	addr.sin_port = htons(75);
	addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	printf("�ͻ���������");//�����ʾ��Ϣ
	::connect(s, (sockaddr*)&addr, sizeof(addr));
	::recv(s, sztex, sizeof(sztex), 0);
	printf("%s\r\n", sztex);
	::closesocket(s);//�ر��׽��־��
	::WSACleanup();//�ͷ��׽��ֿ�
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