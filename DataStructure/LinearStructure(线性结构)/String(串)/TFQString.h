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
int indexWithBigString(String shortStr, String longStr);
    
#endif /* TFQString_h */
