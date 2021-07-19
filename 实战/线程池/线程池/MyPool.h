#pragma once

#include <vector>

#include "MyThread.h"

using namespace std;

class CMyPool
{
public:
	CMyPool(int nSize);
	~CMyPool();
	bool pushJob(jobFunction jobProc, WPARAM wParam, LPARAM lParam, jobCallBack cb);
	int getPoolSize();
private:
	vector<CMyThread *> m_threadVector;
};

