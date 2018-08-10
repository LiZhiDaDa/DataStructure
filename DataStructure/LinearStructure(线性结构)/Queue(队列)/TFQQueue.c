//
//  TFQQueue.c
//  DataStructure
//
//  Created by 王立志 on 2018/8/10.
//  Copyright © 2018年 Thread_Fight_Queue. All rights reserved.
//

#include "TFQQueue.h"

typedef int ElementType;
typedef int Status;
#define ERROR 0
#define OK 1
#define MAXSIZE 20
struct queue{
    ElementType data[MAXSIZE];
    int front;//头指针
    int rear;//尾指针
};
typedef struct queue Queue;

#pragma mark - -----队列的顺序存储结构-----
/**
 *  队列的顺序存储结构跟线性表的顺序存储结构一毛一样，不再赘述。
 *  队列就跟排队一样，队头出队，那么剩下的元素都要往前移动，所以缺点明显，就引入的循环队列
 */
#pragma mark 循环队列的顺序存储结构
/**
 *  空队列时，front=rear，但是队列满时front也=rear，那怎么判断队列是空还是满呢？
 *  方法一：设置flag，当front=rear，且flag=0，队列为空；当front==rear，且flag=1，队列满。
 *  方法二：front=rear队列空，当队列满时我们保留一个元素空间，这样就好判断了。
 *  下面介绍的就是第二种方法。
 */
//初始化一个空队列
Status initQueue(Queue *q){
    q->front = 0;
    q->rear = 0;
    return OK;
}

/**
 *  循环队列长度  这个可以推倒，一种情况是rear>front len=rear-front
 *  另一种情况是rear<front,一部分长度是rear另一部分长度是maxsize-front ==> rear+maxsize-front
 *  这样可以推倒出通用长度公式就是下边的部分。
 */
int queueLength(Queue q){
    return (q.rear - q.front+MAXSIZE)%MAXSIZE;
}

//入队列操作
Status inQueue(Queue *q, ElementType e){
    if(queueLength(*q) == MAXSIZE -1){
        return ERROR;
    }
    q->data[q->rear] = e;
    q->rear = (q->rear+1)%MAXSIZE;
    return OK;
}

//出队列操作
Status outQueue(Queue *q, ElementType *e){
    if(q->rear == q->front){
        return ERROR;
    }
    *e = q->data[q->front];
    q->front = (q->front+1)%MAXSIZE;
    return OK;
}

#pragma mark - -----队列的链式存储结构-----
/**
 *  完全参考单链表的链式存储就可以了。很简单，插入的时候插尾部，取出的时候取头部 LIFO last in first out.
 */



























