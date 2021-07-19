// 线程池.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <conio.h>

#include "MyPool.h"

unsigned int job(WPARAM wParam, LPARAM lParam) {
	printf("job doing: %d +%d = ?\n", wParam, lParam);
	Sleep(1000);
	return wParam + lParam;
}

void cb(unsigned int pResult) {
	printf("job result:%d\n", pResult);
}

int main()
{
	CMyPool* myPool = new CMyPool(2);
	while (true)
	{
		char cmd = _getch();
		if (cmd == 'q' || cmd == 'Q')
		{
			break;
		}
		printf("thread pool size: %d\n", myPool->getPoolSize());
		myPool->pushJob(job, 10, 20, cb);
	}
	printf("thread exit\n");
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
