#include "pch.h"
#include "MyPool.h"

CMyPool::CMyPool(int nSize)
{
	m_threadVector.clear();
	for (size_t i = 0; i < nSize; i++)
	{
		CMyThread* tmp = new CMyThread();
		m_threadVector.push_back(tmp);
	}
}

CMyPool::~CMyPool()
{
	vector<CMyThread *>::iterator iter = m_threadVector.begin();
	for (; iter != m_threadVector.end();)
	{
		CMyThread* tmp = *iter++;
		delete tmp;
	}
}

bool CMyPool::pushJob(jobFunction jobProc, WPARAM wParam, LPARAM lParam, jobCallBack cb)
{
	vector<CMyThread *>::iterator iter = m_threadVector.begin();
	for (; iter != m_threadVector.end(); iter++)
	{
		CMyThread* tmp = *iter;
		if (!tmp->isWorking())
		{
			tmp->doJob(jobProc, wParam, lParam, cb);
			return true;
		}
	}
	CMyThread* tmp = new CMyThread();
	m_threadVector.push_back(tmp);
	tmp->doJob(jobProc, wParam, lParam, cb);
	return true;
}

int CMyPool::getPoolSize()
{
	return m_threadVector.size();
}
