#pragma once
#include<iostream>
#include "queue.h"
#define max
#ifdef max
#pragma message("#undefing marco max")
#undef max
#endif // max
int main() {
	Queue Q;
	Q = CreateQueue();
	AddQ(Q, 3);
	printf("3入队\n");
	AddQ(Q, 5);
	printf("5入队\n");
	AddQ(Q, 11);
	printf("11入队\n");
	printf("%d出队\n", DeleteQ(Q));
	printf("%d出队\n", DeleteQ(Q));
	return 0;
}