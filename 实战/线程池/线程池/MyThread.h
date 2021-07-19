#pragma once
#include <windows.h>

//�߳�Ҫ��������
typedef unsigned int(*jobFunction)(WPARAM wParam, LPARAM lParam);
//�߳���ɺ��֪ͨ�ص�����
typedef void(*jobCallBack)(unsigned int pResult);

class CMyThread
{
public:
	CMyThread();
	~CMyThread();

	bool isWorking();//�Ƿ����ڸɻ�
	void doJob(jobFunction jobProc, WPARAM wParam, LPARAM lParam, jobCallBack cb);//�߳̿�ʼ����

private:
	BOOL bIsWorking;
	jobFunction m_jobFunc;
	jobCallBack m_jobCallBack;
	WPARAM wParam;
	LPARAM lParam;
	HANDLE m_hThread;
	void jobDone();//�̹߳���һ��
	static DWORD WINAPI threadProc(LPARAM lParam);
};

