#include "pch.h"
#include "MyThread.h"
#include <cstdio>

CMyThread::CMyThread()
{
	bIsWorking = false;
	m_jobFunc = 0;
	m_jobCallBack = 0;
	wParam = 0;
	lParam = 0;
	m_hThread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)threadProc, this, 0, 0);
	printf("new thread %08X\n", m_hThread);
}

CMyThread::~CMyThread()
{
	//if (m_hThread != INVALID_HANDLE_VALUE) {
	//	TerminateThread(m_hThread, 0);
	//}
	if (m_hThread != INVALID_HANDLE_VALUE) {
		m_jobCallBack = (jobCallBack)INVALID_HANDLE_VALUE;
		m_jobFunc = (jobFunction)INVALID_HANDLE_VALUE;
		ResumeThread(m_hThread);
		WaitForSingleObject(m_hThread, INFINITE);
		CloseHandle(m_hThread);
	}
}

bool CMyThread::isWorking()
{
	return this->bIsWorking;
}

void CMyThread::doJob(jobFunction jobProc, WPARAM wParam, LPARAM lParam, jobCallBack cb)
{
	this->m_jobCallBack = cb;
	this->m_jobFunc = jobProc;
	this->wParam = wParam;
	this->lParam = lParam;
	ResumeThread(m_hThread);//恢复线程
	printf("thread start working..wParam %d lParam %d %08X\n", m_hThread, wParam, lParam);
}

void CMyThread::jobDone()
{
	bIsWorking = false;
	SuspendThread(m_hThread);//暂停线程
	printf("thread %08X job done\n", m_hThread);
}

DWORD WINAPI CMyThread::threadProc(LPARAM lParam)
{
	CMyThread* pThis = (CMyThread*)lParam;
	while (true)
	{
		if (pThis->m_jobCallBack == INVALID_HANDLE_VALUE || pThis->m_jobFunc == INVALID_HANDLE_VALUE)
		{
			break;
			printf("thread %08X see byebye\n", pThis->m_hThread);
		}
		if (pThis->m_jobCallBack == 0 || pThis->m_jobFunc == 0)
		{
			pThis->jobDone();
		}
		pThis->bIsWorking = true;
		unsigned int result = pThis->m_jobFunc(pThis->wParam, pThis->lParam);
		printf("thread %08X job result %d\n", pThis->m_hThread, result);
		pThis->m_jobCallBack(result);
		pThis->jobDone();
	}
	return 0;
}
