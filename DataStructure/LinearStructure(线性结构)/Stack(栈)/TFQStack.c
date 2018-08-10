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
 *  其实我都超级不想写了。一模一样的东西。
 */

#pragma mark - -----栈的应用-----
#pragma mark 递归-斐波那契数列
/**
 *  当前项的值等于前面两项的和
 */
//求第n项的值
int fbi(int n){
    if(n == 1){
        return 1;
    }else if(n == 2){
        return 1;
    }else{
        return fbi(n-1) + fbi(n-2);
    }
}

#pragma mark 后缀表达式
/**
 *  感觉是反人类的表达式哈哈
 *
 *  中缀表达式转后缀表达式规则：
 *  从左到右遍历中缀表达式的每个数字和符号，若是数字就输出，即成为后缀表达式的一部分；
 *  若是符号，则判断其与栈顶符号的优先级，是右括号或优先级不高于栈顶符号则栈顶元素依次出栈并输出，
 *  并将当前符号进栈，一直到最终输出后缀表达式为止。
 *
 *  eg. 中缀表达式 9+(3-1)*3+10/2
 *    转化为后缀表达式 
 */















