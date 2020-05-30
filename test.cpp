#include<iostream>
#include<cstdio>
#include<queue>
#include<string>
#include<algorithm>
#include<vector>
#include<cstring>
#include<sstream>
#include<cmath>
using namespace std;
const int maxn = 100000;
//char pre[maxn];     /**先序遍历后对应的串*/
char ino[maxn];     /**中序遍历后对应的串*/
char post[maxn];    /**后序遍历后对应的串*/
typedef struct BiNode
{
    char data;
    BiNode *Left;
    BiNode *Right;
}BiNode, *BiTree;

BiTree build(char *ino, char *post, int len)
{
    if(len <= 0)
        return NULL;
    BiTree T = new BiNode;
    char *root = post + len - 1;
    char *p = ino;
    T->data = *root;
    while(p)
    {
        //找到根节点在中序中对应的位置
        if(*p == *root)
            break;
        ++p;
    }

    //左子树的长度
    int left_len = p - ino;
    T->Left = build(ino, post, left_len);
    T->Right = build(p + 1, post + left_len , len - left_len - 1);
    return T;
}

//先序遍历
void preOrder(BiTree T)
{
    if(T)
    {
        printf(" %c", T->data);
        preOrder(T->Left);
        preOrder(T->Right);
    }
}

int main()
{
    /**N指二叉树节点的个数*/
    int N;
    scanf("%d %s %s", &N, ino, post);
    BiTree T = build(ino, post, N);
    printf("preorder:");
    preOrder(T);
    printf("\n");
}