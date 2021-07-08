#pragma once
#include<stdio.h>
#include<malloc.h>
#include "queue.h"
// ��ʼ�� 
Queue CreateQueue() {
	Queue Q;
	Q = (Queue)malloc(sizeof(struct QNode));
	Q->front = -1;
	Q->rear = -1;
	return Q;
}

// �ж϶����Ƿ�����
int IsFull(Queue Q) {
	return ((Q->rear + 1) % MaxSize == Q->front);
}

// ��� 
void AddQ(Queue Q, ElementType item) {
	if (IsFull(Q)) {
		printf("������");
		return;
	}
	else {
		Q->rear = (Q->rear + 1) % MaxSize;
		Q->Data[Q->rear] = item;
	}
}

//�ж϶����Ƿ�Ϊ��
int IsEmpty(Queue Q) {
	return (Q->front == Q->rear);
}

// ����
ElementType DeleteQ(Queue Q) {
	if (IsEmpty(Q)) {
		printf("���п�");
		return 0;
	}
	else {
		Q->front = (Q->front + 1) % MaxSize;
		return Q->Data[Q->front];
	}
} 