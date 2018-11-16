#include "stdio.h"
#include "windows.h"
#include "malloc.h"
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
//Status�Ǻ��������ͣ���ֵ�Ǻ������״̬����
typedef int Status;
typedef char TElemType;
//�������Ķ�������洢��ʾ
typedef struct BiTNode {
	TElemType data;
	struct BiTNode *lchild, *rchild;//���Һ���ָ��
}BiTNode,*BiTree;
//���������
Status CreateBiTree(BiTree *T) {
	//�������������������нڵ��ֵ���ո��ַ���ʾ����
	//������������ʾ�Ķ�����
	TElemType ch = getche();
	if (ch ==' ')*T = NULL;
	else {
		if (!(*T = (BiTNode *)malloc(sizeof(BiTNode))))exit(OVERFLOW);
		(**T).data = ch;				//���ɸ��ڵ�
		CreateBiTree(&((**T).lchild));		//����������
		CreateBiTree(&((**T).rchild));		//����������
	}
	return OK;
}
Status Visit(TElemType e) {//���ʽڵ㺯��
	printf(" %c ",e);
	return OK;
}
Status InOrderTraverse(BiTree T) {//�������������
	//���ö�������洢�ṹ��Visit�ǶԽڵ���ʵĲ���
	//�������������T�ĵݹ��㷨
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
	printf("*********************�������Ĵ洢�����*********************\n");
	printf("��Ӽ��������ַ������򽫰����������д������������ո��ַ�Ϊ����\n�����룺");
	BiTree T;
	if(CreateBiTree(&T))printf("�����ɹ���\n");
	Sleep(1000);
	printf("���ڱ���......\n");
	if(InOrderTraverse(T))printf("\n�����ɹ���\n");
	system("pause");
	return 0;
}