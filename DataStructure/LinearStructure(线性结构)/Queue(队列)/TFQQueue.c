//
//  TFQQueue.c
//  DataStructure
//
//  Created by 王立志 on 2018/8/10.
//  Copyright © 2018年 Thread_Fight_Queue. All rights reserved.
//

#include "TFQQueue.h"

typedef int ElementType;
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
 */



#pragma mark - -----队列的链式存储结构-----
