//
//  TFQBinaryTree.c
//  DataStructure
//
//  Created by 王立志 on 2018/8/14.
//  Copyright © 2018年 Thread_Fight_Queue. All rights reserved.
//

#include "TFQBinaryTree.h"

/**
 *  特殊的二叉树：
 *
 *  1、斜树  又包括左斜树，右斜树
 *  2、满二叉树  每个节点都存在左右子树，而且所有的叶子都要在同一层上
 *  3、完全二叉树  对一颗有n个结点的二叉树按层序编号，如果编号为i的结点与同样深度的满二叉树中编号为i的结点在二叉树中的位置完全相同，
 */

/**
 *  二叉树的性质：
 *
 *  1、在二叉树的第i层上之多有2^i-1 个结点
 *  2、深度为k的二叉树之多有2^k-1个结点
 *  3、对于任何一个二叉树T，如果其终端结点数为n0,度为2的结点数为n2,则n0=n2+1
 *  4、具有n个结点的完全二叉树的深度为|log2N| +1  (|x| 表示不大于x的最大整数)
 *  5、第五个贼繁琐，懒得抄了。
 */
#pragma mark - -----二叉树的顺序存储结构-----
//按照序号存储，如果是满二叉树那么比较好，如果不是满二叉树就比较浪费内存，所以直接介绍链式存储结构

#pragma mark - -----二叉树的链式存储结构-----

#define ERROR 0
#define OK 1
typedef int ElementType;
typedef int Status;

#pragma mark 二叉链表
/**
 *  二叉链表：二叉树每个节点最多有两个孩子，所以为它涉及一个数据域和两个指针域，这样的链表就是二叉链表。
 */
//结构定义
struct node{
    ElementType data;
    struct node *lchild, *rchild;
};
typedef struct node Node;

#pragma mark 遍历二叉树
/**
 *  二叉树的遍历方式有很多，如果我们限制了从左到右的习惯，那么主要分为4种，前序、中序、后序、层序。
 */
//前序遍历  先根节点，次左子树，后右子树
void preorderTraversal(Node *t){
    if(t == NULL){
        return;
    }
    printf("%c",t->data);
    preorderTraversal(t->lchild);
    preorderTraversal(t->rchild);
}

//中序遍历  先左子树，次根节点，后右子树
void middleorderErgodic(Node *t){
    if(t == NULL){
        return;
    }
    preorderTraversal(t->lchild);
    printf("%c",t->data);
    preorderTraversal(t->rchild);
}

//后序遍历  先左子树，次右子树，后根节点
void postrderTraversal(Node *t){
    if(t == NULL){
        return;
    }
    preorderTraversal(t->lchild);
    preorderTraversal(t->rchild);
    printf("%c",t->data);
}

//层序遍历  从第一层开始，从上而下每一层遍历，同一层中从左到右顺序遍历

//推倒遍历结果
/*
  已知前序为ABCDEF  中序为CBAEDF  求后序
  答：你们自己百度吧，简单的一逼
*/

#pragma mark - -----二叉树的建立-----











































