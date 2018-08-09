//
//  TFQStack.c
//  DataStructure
//
//  Created by 王立志 on 2018/8/9.
//  Copyright © 2018年 Thread_Fight_Queue. All rights reserved.
//

#include "TFQStack.h"

typedef int ElementType;
typedef int Status;
#define MAXSIZE 20
#define ERROR 0
#define OK 1
struct stack{
    ElementType data[MAXSIZE];
    int top;
};
typedef struct stack Stack;

#pragma mark - -----栈的顺序存储结构-----
#pragma mark 栈
//进栈操作
Status push(Stack *s, ElementType e){
    if(s->top == MAXSIZE-1){//栈满
        return ERROR;
    }
    s->top ++;
    s->data[s->top] = e;
    return OK;
}

//出栈操作
Status pop(Stack *s, ElementType *e){
    if(s->top == -1){//空栈
        return ERROR;
    }
    *e = s->data[s->top];
    s->top--;
    return OK;
}

#pragma mark 两栈共享空间

// 空间结构
struct doubleStack{
    ElementType data[MAXSIZE];
    int top1;//栈1 栈顶指针
    int top2;//栈2 栈顶指针
};
typedef struct doubleStack DoubleStack;

//插入元素
Status pushDouble(DoubleStack *d, ElementType e, int stackNumber){
    if(d->top1 + 1 == d->top2){//栈满了
        return ERROR;
    }
    if(stackNumber == 1){
        d->data[d->top1+1] = e;
    }else if(stackNumber == 2){
        d->data[d->top2-1] = e;
    }
    return OK;
}

//删除元素
Status popDouble(DoubleStack *d, ElementType *e, int stackNumber){
    if(stackNumber == 1){
        if(d->top1 == -1){
            return ERROR;
        }
        *e = d->data[d->top1];
        d->top1--;
    }else if(stackNumber == 2){
        if(d->top2 == MAXSIZE){
            return ERROR;
        }
        *e = d->data[d->top2];
        d->top2++;
    }
    
    return OK;
}

#pragma mark - -----栈的链式存储结构-----
/**
 *  其实栈的链式存储结构跟单链表非常非非常类似了
 *
 *
 *
 *
 */




















