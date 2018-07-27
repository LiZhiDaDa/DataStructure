//
//  main.c
//  DataStructure
//
//  Created by 王立志 on 2018/7/25.
//  Copyright © 2018年 Thread_Fight_Queue. All rights reserved.
//

#include <stdio.h>
#include "TFQDataStructure.h"

//定义String结构体
#define MAXSIZE 20
typedef struct{
    char *ch;
    int len;
}String;
int subStringIndex(String S, String T, int pos);

int main(int argc, const char * argv[]) {
    // insert code here...
    //    printf("Hello, World!\n");
    //    test();
    String S,T;
    S.ch = "goodgoogle";
    T.ch = "google";
    S.len = 10;
    T.len = 6;
    int result = subStringIndex(S, T, 1);
    printf("%d\n\n", result);
    return 0;
}

/**
 *  模式匹配算法：子串的定位操作通常称做串的模式匹配
 *  假如要从S="goodgoogle" 中找到T="google"这个子串的位置
 *  S[0]、T[0]分别为两个串的长度。
 *  返回子串T在主串S中第pos个字符之后的位置。若不存在返回0
 *  T非空， 1<= pos <=StrLength(S)
 */
int subStringIndex(String S, String T, int pos){
    int i = pos;
    int j = 1;
    while(i<S.len && j<T.len){
        if(S.ch[i] == T.ch[j]){
            i++;
            j++;
        }else{
            i=i-j+2;
            j=1;
        }
    }
    if(j>T.len){
        return i-T.len;
    }else{
        return 0;
    }
}

