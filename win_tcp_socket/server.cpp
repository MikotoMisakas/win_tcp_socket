// ConsoleApplication9.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<winSock2.h>//����ͷ�ļ�
#include <stdio.h>
#include <windows.h>
#pragma comment(lib,"WS2_32.lib")//��ʾ�����׽��ֿ�


int _tmain(int argc, _TCHAR* argv[])
{
	WSADATA data;//����WSADATA�ṹ�����
	WORD w = MAKEWORD(2, 0);//����汾��
	char sztext[] = "��ӭ��\r\n";//���岢��ʼ�����͵��ͻ��˵��ַ�����
	::WSAStartup(2, &data);//��ʼ���׽��ֿ�
	SOCKET s, s1;//���������׽��ֺ������շ��׽��־��
	s = ::socket(AF_INET, SOCK_STREAM, 0);//����tcp�׽���
	sockaddr_in addr, addr2;//�����׽��ֵ�ַ�ṹ
	int n = sizeof(addr2);//��ȡ�׽��ֵ�ַ�ṹ��С
	addr.sin_family = AF_INET;//��ʼ����ַ�ṹ
	addr.sin_port = htons(75);
	addr.sin_addr.S_un.S_addr = INADDR_ANY;
	::bind(s, (sockaddr*)&addr, sizeof(addr));//���׽���
	::listen(s, 5);//�����׽���
	printf("������������");//�����ʾ��Ϣ
	while (true)
	{
		s1 = ::accept(s, (sockaddr*)&addr2, &n);//������������
		if (s1 != NULL)
		{
			printf("�Ѿ�������");
			::send(s1, sztext, sizeof(sztext), 0);//��ͻ��˷����ַ�����
		}
		::closesocket(s);//�ر��׽��־��
		::closesocket(s1);
		::WSACleanup();//�ͷ��׽��ֿ�
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

