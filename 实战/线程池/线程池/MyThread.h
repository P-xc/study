#pragma once
#include <windows.h>

//线程要做的事情
typedef unsigned int(*jobFunction)(WPARAM wParam, LPARAM lParam);
//线程完成后的通知回调函数
typedef void(*jobCallBack)(unsigned int pResult);

class CMyThread
{
public:
	CMyThread();
	~CMyThread();

	bool isWorking();//是否正在干活
	void doJob(jobFunction jobProc, WPARAM wParam, LPARAM lParam, jobCallBack cb);//线程开始工作

private:
	BOOL bIsWorking;
	jobFunction m_jobFunc;
	jobCallBack m_jobCallBack;
	WPARAM wParam;
	LPARAM lParam;
	HANDLE m_hThread;
	void jobDone();//线程工作一次
	static DWORD WINAPI threadProc(LPARAM lParam);
};

