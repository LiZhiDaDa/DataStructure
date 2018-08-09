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
/**
 *  用数组描述的链表叫静态链表
 *  让数组的元素由data、cur两个数据域组成，data存放数据，cur存放该元素后继
 *  元素的下标，相当于单链表中的next指针，我们把cur叫做游标。
 *
 *  优点：插入删除时只需要修改游标，不需要移动元素
 *  缺点：1、没有解决连续存储分配带来的表长难以确定的问题
 *       2、失去了顺序存储结构随机存取的特性（并没有理解。。。）
 *  tips：
 *  1、把未被使用的数组元素称为备用链表。
 *  2、数组的第一个跟最后一个元素做特殊处理，不存数据。第0个元素的cur存放备用链表第1个结点
 *     的下标，数组的最后一个元素存放第一个有数值元素的下标，
 */
//静态链表结构代码
typedef struct {
    ElementType data;
    int cur;
}StaticLinkList[MAXSIZE];//因为静态链表本质还是数组，所以要声明为数组，

//由于是数组，所以我们来模仿malloc数组的操作,返回当前备用链表的第一个游标
int malloc_SLL(StaticLinkList space){
    int i = space[0].cur; //取出备用链表的第一个元素
    if(space[0].cur){
        space[0].cur = space[i].cur;//备用链表的第一个要被使用了，把第二个拿来做备用
    }
    return i;
}

//free操作,把i回收到备用链表
void free_SLL(StaticLinkList space, int i){
    space[i].cur = space[0].cur;
    space[0].cur = i;
}

//静态链表获取元素，都是数组了，直接用下标拿就可以了

//静态链表插入元素
Status staticLinkListInsert(StaticLinkList l, int i, ElementType e){
    if(i<1 || i>MAXSIZE){
        return ERROR;
    }
    int j = malloc_SLL(l);
    l[j].data = e;
    int m = MAXSIZE-1;//最后一个元素的下标，cur存放的就是第一个元素的下标
    for(int k=1; k<i; k++){
        m = l[m].cur;
    }
    l[j].cur = l[m].cur;
    l[m].cur = j;
    return OK;
}

//静态链表删除元素
Status staticLinkListDelete(StaticLinkList l,int i){
    if(i<0 || i>MAXSIZE){
        return ERROR;
    }
    int j = MAXSIZE-1;
    for(int k=0; k<i-1; k++){
        j = l[j].cur;
    }
    l[j].cur = l[l[j].cur].cur;
    free_SLL(l, l[j].cur);
    return OK;
}

//静态链表长度
int StaticLinkListLength(StaticLinkList l){
    int i=0;
    int j = l[MAXSIZE-1].cur;
    while (j) {
        j = l[j].cur;
        i++;
    }
    return i;
}

#pragma mark 循环链表 cycle
/**
 *  循环链表其实就是让最后一个节点的指针指向头节点。
 *  如果需要合并ab两个循环链表，只需要让a的尾指针指向b的第一个结点，让b的尾指针指向a的头结点。
 *  然后把b的头节点free掉即可。
 *  如果不懂可以去google一下网上的图片。
 */


#pragma mark 双向链表 double
/**
 *  双向链表：在单链表的每个节点中，再设置一个指向其前驱结点的指针域，
 *  可以google图片，比较通俗易懂。
 */












































