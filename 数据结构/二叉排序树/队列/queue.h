#pragma once
#define MaxSize 100
typedef int ElementType;
typedef struct QNode *Queue;
struct QNode {
	ElementType Data[MaxSize];
	int front;   // ��¼��ͷ 
	int rear;    // ��¼��β 
};

Queue CreateQueue();  // ��ʼ������ 
void AddQ(Queue Q, ElementType item);  //  ���
int IsFull(Queue Q); // �ж϶����Ƿ����� 
ElementType DeleteQ(Queue Q);  // ���� 
int IsEmpty(Queue Q); // �ж϶����Ƿ�Ϊ�� 

