#pragma once
#include<iostream>
#include "queue.h"

int main() {
	Queue Q;
	Q = CreateQueue();
	AddQ(Q, 3);
	printf("3���\n");
	AddQ(Q, 5);
	printf("5���\n");
	AddQ(Q, 11);
	printf("11���\n");
	printf("%d����\n", DeleteQ(Q));
	printf("%d����\n", DeleteQ(Q));
	return 0;
}