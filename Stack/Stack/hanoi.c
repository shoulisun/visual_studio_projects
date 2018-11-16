#include "stdio.h"

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
//Status�Ǻ��������ͣ���ֵ�Ǻ������״̬����
typedef int Status;

#define STACK_INIT_SIZE 100	//�洢�ռ�ĳ�ʼ������
#define STACKINCREMENT 10	//�洢�ռ�ķ�������

//��������SElemType
typedef struct {
	char ch;
}SElemType;

//����ջ
typedef struct {
	SElemType *base;	//��ջ������֮ǰ������֮��base��ֵΪNULL
	SElemType *top;		//ջ��ָ��
	int stacksize;		//��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ
}SqStack;

//ջ�ĳ�ʼ��
Status InitStack(SqStack *S) {
	//����һ����ջ
	(*S).base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if (!(*S).base)exit(OVERFLOW);		//�洢����ʧ��
	(*S).top = (*S).base;
	(*S).stacksize = STACK_INIT_SIZE;
	return OK;
}

//ջ����ջ����
Status Push(SqStack *S, SElemType e) {
	//����Ԫ��eΪ�µ�ջ��Ԫ��
	if ((*S).top - (*S).base >= (*S).stacksize) {//ջ����׷�Ӵ洢�ռ�
		(*S).base = (SElemType *)malloc((*S).base, ((*S).stacksize + STACKINCREMENT)*sizeof(SElemType));
		if (!(*S).base)exit(OVERFLOW);		//�洢����ʧ��
		(*S).top = (*S).base + (*S).stacksize;
		(*S).stacksize += STACKINCREMENT;
	}
	*(*S).top = e;
	(*S).top++;
	return OK;
}

//ջ�ĳ�ջ����
Status Pop(SqStack *S, SElemType *e) {
	//��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
	if ((*S).top == (*S).base)return ERROR;
	*e = *(--(*S).top);
	return OK;
}

//ȡջ��Ԫ��
Status GetTop(SqStack S, SElemType *e) {
	//��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR
	if (S.top == S.base)return ERROR;
	*e = *(S.top - 1);
	return OK;
}


int main() {




	return 0;
}