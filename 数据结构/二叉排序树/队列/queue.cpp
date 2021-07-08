#pragma once
#include<stdio.h>
#include<malloc.h>
#include "queue.h"
// 初始化 
Queue CreateQueue() {
	Queue Q;
	Q = (Queue)malloc(sizeof(struct QNode));
	Q->front = -1;
	Q->rear = -1;
	return Q;
}

// 判断队列是否已满
int IsFull(Queue Q) {
	return ((Q->rear + 1) % MaxSize == Q->front);
}

// 入队 
void AddQ(Queue Q, ElementType item) {
	if (IsFull(Q)) {
		printf("队列满");
		return;
	}
	else {
		Q->rear = (Q->rear + 1) % MaxSize;
		Q->Data[Q->rear] = item;
	}
}

//判断队列是否为空
int IsEmpty(Queue Q) {
	return (Q->front == Q->rear);
}

// 出队
ElementType DeleteQ(Queue Q) {
	if (IsEmpty(Q)) {
		printf("队列空");
		return 0;
	}
	else {
		Q->front = (Q->front + 1) % MaxSize;
		return Q->Data[Q->front];
	}
} 