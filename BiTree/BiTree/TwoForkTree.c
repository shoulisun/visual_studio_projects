#include "stdio.h"
#include "windows.h"
#include "malloc.h"
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
//Status是函数的类型，其值是函数结果状态代码
typedef int Status;
typedef char TElemType;
//二叉树的二叉链表存储表示
typedef struct BiTNode {
	TElemType data;
	struct BiTNode *lchild, *rchild;//左右孩子指针
}BiTNode,*BiTree;
//构造二叉树
Status CreateBiTree(BiTree *T) {
	//按先序次序输入二叉树中节点的值，空格字符表示空树
	//构造二叉链表表示的二叉树
	TElemType ch = getche();
	if (ch ==' ')*T = NULL;
	else {
		if (!(*T = (BiTNode *)malloc(sizeof(BiTNode))))exit(OVERFLOW);
		(**T).data = ch;				//生成根节点
		CreateBiTree(&((**T).lchild));		//构造左子树
		CreateBiTree(&((**T).rchild));		//构造右子树
	}
	return OK;
}
Status Visit(TElemType e) {//访问节点函数
	printf(" %c ",e);
	return OK;
}
Status InOrderTraverse(BiTree T) {//中序遍历二叉树
	//采用二叉链表存储结构，Visit是对节点访问的操作
	//中序遍历二叉树T的递归算法
	if (T) {
		if (InOrderTraverse(T->lchild))
			if (Visit(T->data))
				if (InOrderTraverse(T->rchild))
					return OK;
		return ERROR;
	}
	else return OK;
}
int main() {
	printf("*********************二叉树的存储与遍历*********************\n");
	printf("请从键盘输入字符，程序将按照先序序列创建二叉树，空格字符为空树\n请输入：");
	BiTree T;
	if(CreateBiTree(&T))printf("创建成功！\n");
	Sleep(1000);
	printf("正在遍历......\n");
	if(InOrderTraverse(T))printf("\n遍历成功！\n");
	system("pause");
	return 0;
}