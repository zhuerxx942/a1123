#include <stdio.h>
#include <stdlib.h>

/* 二叉链表结点定义 */
typedef char TElemType;
typedef struct BiTNode {
    TElemType data;            // 数据域
    struct BiTNode* lchild;    // 左孩子指针
    struct BiTNode* rchild;    // 右孩子指针
} BiTNode, * BiTree;

/* 1. 先序递归创建二叉树，# 表示空树 */
void CreateBiTree(BiTree* T) {
    char ch;
    ch = getchar();            // 扫描字符序列，读入字符 ch
    if (ch == '#') {
        *T = NULL;             // ch 为 '#'，说明是空树
    }
    else {
        *T = (BiTree)malloc(sizeof(BiTNode));  // 申请结点空间
        if (*T == NULL) {
            printf("内存分配失败！\n");
            exit(1);
        }
        (*T)->data = ch;       // 将 ch 赋值给 T->data
        CreateBiTree(&(*T)->lchild);  // 递归创建左子树
        CreateBiTree(&(*T)->rchild);  // 递归创建右子树
    }
}

/* 2. 先序遍历：根 -> 左 -> 右 */
void PreOrder(BiTree T) {
    if (T != NULL) {
        printf("%c ", T->data);   // 访问根结点
        PreOrder(T->lchild);      // 递归遍历左子树
        PreOrder(T->rchild);      // 递归遍历右子树
    }
}

/* 3. 中序遍历：左 -> 根 -> 右 */
void InOrder(BiTree T) {
    if (T != NULL) {
        InOrder(T->lchild);       // 递归遍历左子树
        printf("%c ", T->data);   // 访问根结点
        InOrder(T->rchild);       // 递归遍历右子树
    }
}

/* 4. 后序遍历：左 -> 右 -> 根 */
void PostOrder(BiTree T) {
    if (T != NULL) {
        PostOrder(T->lchild);     // 递归遍历左子树
        PostOrder(T->rchild);     // 递归遍历右子树
        printf("%c ", T->data);   // 访问根结点
    }
}

int main() {
    BiTree T;
    printf("请输入先序序列（用#表示空）：");
    CreateBiTree(&T);

    printf("\n先序遍历结果：");
    PreOrder(T);
    printf("\n中序遍历结果：");
    InOrder(T);
    printf("\n后序遍历结果：");
    PostOrder(T);
    printf("\n");
    return 0;
}

