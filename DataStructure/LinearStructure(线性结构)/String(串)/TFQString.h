//
//  TFQString.h
//  DataStructure
//
//  Created by 王立志 on 2018/8/10.
//  Copyright © 2018年 Thread_Fight_Queue. All rights reserved.
//

#ifndef TFQString_h
#define TFQString_h

#define MAXSIZE 20
#define ERROR 0
#define OK 1
typedef int Status;
struct string{
    char data[MAXSIZE];
    int len;
};
typedef struct string String;

#include <stdio.h>
#include <string.h>
///普通的匹配模式算法
int indexWithBigString(String shortStr, String longStr);
///KMP模式匹配算法
int KMPIndex(String shortStr, String longStr);
///计算next[]
void calNext(const char p[],int next[]);
    
#endif /* TFQString_h */
