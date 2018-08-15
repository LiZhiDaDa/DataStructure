//
//  main.c
//  DataStructure
//
//  Created by 王立志 on 2018/7/25.
//  Copyright © 2018年 Thread_Fight_Queue. All rights reserved.
//


/**
 *  项目说明：
 *
 *  一、项目架构参考文章《大话数据结构》中的思维导图：https://juejin.im/post/5b6976a2f265da0f61322df6
 *
 *  二、每种结构又分别按照 顺序存储结构、链式存储结构两个物理结构来实现
 *
 *  三、每个结构下都有一个对应的头文件，用来存放该结构的所有头文件
 *
 *  tips：
 *
 *  一、线性表、栈、队列、串的关系？
 *  答:1、四个都是线性结构
 *     2、栈和队列都是线性表，栈FIFO 队列FILO
 *
 *  二、树、二叉树、红黑树的关系？
 *  答:二叉树是特殊的树，红黑树是特殊的二叉树
 *
 */


#include <stdio.h>
#include "TFQLinearStructure.h"
#include "TFQTreeStructure.h"
#include "TFQGraphStructure.h"

int main(int argc, const char * argv[]) {
    
    //打印斐波那契数列结果
    printf("斐波那契数列  %d \n", fbi(6));
    
    //朴素匹配模式算法
    String sStr = {"aaaaaa",6};
    String lStr = {"aaadaaaaaa",10};
    int index = indexWithBigString(sStr, lStr);
    printf("普通模式匹配算法  %d \n", index);
    
    /*
     这两个算法没写对，乱七八糟很拗口。思想倒是懂得透透的，但是代码落实上就很苦逼。建议大家理解思想，不用死抠代码。
    //KMP模式匹配算法
    int indexKMP = KMPIndex(sStr, lStr);
    printf("KMP模式匹配算法  %d \n", indexKMP);
    
    //KMP模式匹配算法优化
    int indexKMPOptimize = KMPIndexOptimize(sStr, lStr);
    printf("KMP模式匹配算法优化  %d \n", indexKMPOptimize);
    */
    
    
    
    
    
    
    
    return 0;
}


 
















