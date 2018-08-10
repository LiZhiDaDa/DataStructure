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
 *  这里给大家写while里边指针回溯的方法，其实也就是两层循环，
 *  那我费半天话干什么skr
 */
int indexWithBigString(String shortStr, String longStr){
    int i=0, j=0;
    while(i<shortStr.len && j<longStr.len){
        if(shortStr.data[i] == longStr.data[j]){
            i++;
            j++;
        }else{
            i=0;
            j=j-i;
        }
        if(i == shortStr.len-1){
            return j-1;
        }
    }
    return 0;
}


#pragma mark - KMP模式匹配算法


#pragma mark - KMP模式匹配算法改进
