#pragma once
#define MaxSize 100
typedef int ElementType;
typedef struct QNode *Queue;
struct QNode {
	ElementType Data[MaxSize];
	int front;   // 记录队头 
	int rear;    // 记录队尾 
};

Queue CreateQueue();  // 初始化队列 
void AddQ(Queue Q, ElementType item);  //  入队
int IsFull(Queue Q); // 判断队列是否已满 
ElementType DeleteQ(Queue Q);  // 出队 
int IsEmpty(Queue Q); // 判断队列是否为空 

