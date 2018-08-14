//
//  TFQString.c
//  DataStructure
//
//  Created by 王立志 on 2018/8/10.
//  Copyright © 2018年 Thread_Fight_Queue. All rights reserved.
//

#include "TFQString.h"

/**
 *  串其实就是字符串，这里感觉讨论串没什么意义，直接就开始整模式匹配算法把。
 *  返回子串在主串中的位置，若不存在，返回0
 */
#define ERROR 0
#define OK 1
typedef int Status;

#pragma mark - 朴素的模式匹配算法
/**
 *  第一种就是大家都能想到的双层for循环
 *  这里给大家写while里边指针回溯的方法，其实本质也就是两层循环，
 *  那我费半天话干什么skr
 */
int indexWithBigString(String shortStr, String longStr){
    int i=0, j=0;
    while(i<shortStr.len && j<longStr.len){
        if(shortStr.data[i] == longStr.data[j]){
            i++;
            j++;
        }else{
            j=j-i+1;
            i=0;
        }
        if(i == shortStr.len){
            return j-i;
        }
    }
    return 0;
}

#pragma mark - KMP模式匹配算法
/**
 *  KMP模式匹配算法的重点就是next[]的计算，
 *  while 的条件里要有一个 i==0 的情况，这样j才能一直+
 */
int KMPIndex(String shortStr, String longStr){
    int next[shortStr.len];
    calNext(shortStr.data, next);
    int i=0, j=0;
    while(j<longStr.len){
        if(i==0 || shortStr.data[i]==longStr.data[j]){
            j++;
            i++;
        }else{
            i = next[i];
        }
        if(i==shortStr.len){
            return j-i;
        }
    }
    return 0;
}

//这个推荐大家看阮一峰的博客 http://www.ruanyifeng.com/blog/2013/05/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm.html
void calNext(const char p[],int next[]){
    int len = (int)strlen(p);//匹配字符串的长度
    next[0] = 0;
    //i:模版字符串下标；j:最大前后缀长度
    for(int i=1,j=0; i<len; i++){
        while(j>0 && p[i] != p[j]){
            j = next[j-1];
        }
        if(p[i] == p[j]){
            j++;
        }
        next[i] = j;
    }
}

#pragma mark - KMP模式匹配算法改进
/**
 *
 *
 *
 *
 *
 *
 *
 *
 */
int KMPIndexOptimize(String shortStr, String longStr){
    
    return 0;
}




















































