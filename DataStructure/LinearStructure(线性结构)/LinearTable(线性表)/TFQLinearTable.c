//
//  TFQLinearTable.c
//  DataStructure
//
//  Created by 王立志 on 2018/8/8.
//  Copyright © 2018年 Thread_Fight_Queue. All rights reserved.
//

#include "TFQLinearTable.h"


#define MAXSIZE 20
typedef int ElementType;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;

#pragma mark - -----顺序存储结构-----
/**
 *  优点：可以快速的读取任何元素
 *  缺点：1、插入和删除需要移动大量元素
 *       2、长度变化较大时，难以确定存储空间的容量
 *       3、造成存储空间的“碎片”
 */

//结构代码
typedef struct{
    ElementType data[MAXSIZE];
    int length;
}SqList;

//获取元素
Status getElement(SqList *l, int i, ElementType *e){
    if(l->length == 0 || i<0 || i>(*l).length){
        return ERROR;
    }
    *e = l->data[i];
    return OK;
}

//插入元素
Status listInsert(SqList *l, int i, ElementType *e){
    if(l->length == MAXSIZE){
        return ERROR;
    }
    if(i<0 || i>l->length-1){
        return ERROR;
    }
    //将i之后的元素都往后移1位
    for(int j=l->length; j>i; j--){
        l->data[j] = l->data[j-1];
    }
    l->data[i] = *e;
    l->length ++;
    return OK;
}

//删除操作
Status listDelete(SqList *l, int i, ElementType *e){
    if(l->length == 0){
        return ERROR;
    }
    if(i<1 || i>l->length-1){
        return ERROR;
    }
    //i之后的元素往前移
    for(int j=i; j<l->length-2; j++){
        l->data[j] = l->data[j+1];
    }
    l->length --;
    return OK;
}

#pragma mark - -----链式存储结构-----
#pragma mark 单链表 single
/**
 *  与顺序存储结构对比
 *  优点：1、不需要分配存储空间，元素个数不受限制
 *       2、找对对应位置后，插入删除O(1)
 *  缺点：1、查找不方便O(n)
 */

//单链表结构代码 这里声明结构体跟给结构体取别名分开来写，方便大家理解
struct Node{
    ElementType data;
    struct Node *next;
};
typedef struct Node LinkList;

//单链表获取元素
Status getElementSingle(LinkList *l, int i, ElementType *e){
    LinkList *p = l->next;
    int j = 0;
    while (p && j<i) {
        //一般来说  p->用来指向p中的结构体,但是也跟声明方式有关系
        p = p->next;
        j++;
    }
    //循环到最后p都不存在了，也没找到第i个元素，这种情况就是i 比j大，但是只有循环完了才能知道i的比链表的长度大
    if(!p){
        return ERROR;
    }
    *e = p->data;
    return OK;
}

//单链表插入元素
Status listInsertSingle(LinkList *l, int i, ElementType *e){
    LinkList *p = l->next;
    int j = 0;
    while(p && j<i){
        p = p->next;
        j++;
    }
    if(!p){
        return ERROR;
    }
    LinkList *s = (LinkList *)malloc(sizeof(struct Node));
    s->data = *e;
    s->next = p->next;
    p->next = s;
    return OK;
}

//单链表删除元素
Status listDeleteSingle(LinkList *l, int i, ElementType *e){
    LinkList *p = l->next;
    int j=0;
    while(p && j<i){
        p = p->next;
        j++;
    }
    if(!p){
        return ERROR;
    }
    p->next = p->next->next;
    *e = p->next->data;
    free(p->next);
    return OK;
}

//单链表的整表创建--头插法
void createListHead(LinkList *l, int n){
    LinkList *p;
    //创建头结点
    l = (LinkList *)malloc(sizeof(struct Node));
    l->next = NULL;
    for(int i=0; i<n; i++){
        p = (LinkList *)malloc(sizeof(struct Node));
        p->data = rand()%100+1;
        p->next = l->next;
        l->next = p;
    }
}

//单链表的整表创建--尾插法
void createListTail(LinkList *l, int n){
    LinkList *p;
    l = (LinkList *)malloc(sizeof(struct Node));
    for(int i=0; i<n; i++){
        p = (LinkList *)malloc(sizeof(struct Node));
        p->data = rand()%100+1;
        l->next = p;
        l = p;
    }
}

//单链表的整表删除
Status clearList(LinkList *l){
    LinkList *p, *q;
    p = l->next;
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
    l->next = NULL;
    return OK;
}

#pragma mark 静态链表 static
//静态链表结构代码
//静态链表获取元素
//静态链表插入元素
//静态链表删除元素
#pragma mark 循环链表 cycle
//循环链表结构代码
//循环链表获取元素
//循环链表插入元素
//循环链表删除元素
#pragma mark 双向链表 double
//双向链表结构代码
//双向链表获取元素
//双向链表插入元素
//双向链表删除元素












































