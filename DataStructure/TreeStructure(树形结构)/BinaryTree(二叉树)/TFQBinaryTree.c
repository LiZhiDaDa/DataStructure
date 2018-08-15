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
typedef struct node BinaryTree;

#pragma mark 遍历二叉树
/**
 *  二叉树的遍历方式有很多，如果我们限制了从左到右的习惯，那么主要分为4种，前序、中序、后序、层序。
 */
//前序遍历  先根节点，次左子树，后右子树
void preorderTraversal(BinaryTree *t){
    if(t == NULL){
        return;
    }
    printf("%c",t->data);
    preorderTraversal(t->lchild);
    preorderTraversal(t->rchild);
}

//中序遍历  先左子树，次根节点，后右子树
void middleorderErgodic(BinaryTree *t){
    if(t == NULL){
        return;
    }
    preorderTraversal(t->lchild);
    printf("%c",t->data);
    preorderTraversal(t->rchild);
}

//后序遍历  先左子树，次右子树，后根节点
void postrderTraversal(BinaryTree *t){
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
/**
 *           A
 *         |   |
 *         B   C
 *          |
 *          D
 *  现有二叉树如上图所示，我们先把二叉树补全，保证每个结点都有左右孩子
 *            A
 *        |      |
 *        B      C
 *      |  |    | |
 *      #  D    # #
 *        | |
 *        # #
 *  这样二叉树的前序遍历结果为:AB#D##C##
 */
void createTree(BinaryTree *t){
    ElementType ch;
    scanf("%d", &ch);
    if(ch == '#'){
        t = NULL;
    }else{
        t = (BinaryTree *)malloc(sizeof(struct node));
        if(! t){
            exit(ERROR);
        }
        t->data = ch;
        createTree(t->lchild);
        createTree(t->rchild);
    }
    
}

#pragma mark 线索二叉树
/**
 *  二叉树按照某种次序遍历每个结点都有前驱后继指针，这样的二叉树就是线索二叉树
 *
 *  线索化的实质就是将二叉链表中的空指针改为指向前驱或后继的线索，所以线索化的过程就是遍历的过程
 *  感觉线索化的过程跟其他的思想简直一样，这里只实现结构。
 */
//线索二叉树的结构实现
enum child{
    lrChild, //lrChild=0 表示指向左右孩子的指针
    thread  //thread=1 表示指向前驱或后继的线索
};
typedef enum child pointerTag;

struct thrNode{
    ElementType data;
    struct thrNode *lchild, *rchild;
    pointerTag lTag;
    pointerTag rTag;
};
typedef struct thrNode thrTree;

#pragma mark - -----树、森林与二叉树的转换-----
/**
 *  树、森林与二叉树的转换这里不做赘述了。需要的时候查资料，按照步骤转换即可。
 */
#pragma mark 赫夫曼树及其应用
/**
 *  带权路径长度WPL最小的二叉树称做赫夫曼树，具体步骤：
 *  1、根据给定的n个权值{W1,W2,...,Wn}构成n棵二叉树的集合F={T1,T2,...Tn},其中每棵二叉树Ti中只有一个带权为Wi的根节点，其左右子树均为空。
 *  2、在F中选取两棵根节点的权值最小的树作为左右子树构造一棵新的二叉树，且置新的二叉树的根节点的权值为其左右子树上根结点的权值之和。
 *  3、在F中删除这两棵树，同时将新得到的二叉树加入F中。
 *  4、重复2和3步骤，直到F只含一棵树位置。这棵树便是赫夫曼树。
 */

/**
 *  赫夫曼编码： 把文字出现的频率当做权，然后用赫夫曼树来确定其表达的方式，形成了赫夫曼编码。
 *  这个概念可以具体google一下，只要懂了赫夫曼树，赫夫曼编码就很容易懂了。
 */
