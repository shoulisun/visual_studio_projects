#include "stdio.h"

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
//Status是函数的类型，其值是函数结果状态代码
typedef int Status;

#define STACK_INIT_SIZE 100	//存储空间的初始分配量
#define STACKINCREMENT 10	//存储空间的分配增量

//定义数据SElemType
typedef struct {
	char ch;
}SElemType;

//定义栈
typedef struct {
	SElemType *base;	//在栈顶构造之前和销毁之后，base的值为NULL
	SElemType *top;		//栈顶指针
	int stacksize;		//当前已分配的存储空间，以元素为单位
}SqStack;

//栈的初始化
Status InitStack(SqStack *S) {
	//构造一个空栈
	(*S).base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if (!(*S).base)exit(OVERFLOW);		//存储分配失败
	(*S).top = (*S).base;
	(*S).stacksize = STACK_INIT_SIZE;
	return OK;
}

//栈的入栈操作
Status Push(SqStack *S, SElemType e) {
	//插入元素e为新的栈顶元素
	if ((*S).top - (*S).base >= (*S).stacksize) {//栈满，追加存储空间
		(*S).base = (SElemType *)malloc((*S).base, ((*S).stacksize + STACKINCREMENT)*sizeof(SElemType));
		if (!(*S).base)exit(OVERFLOW);		//存储分配失败
		(*S).top = (*S).base + (*S).stacksize;
		(*S).stacksize += STACKINCREMENT;
	}
	*(*S).top = e;
	(*S).top++;
	return OK;
}

//栈的出栈操作
Status Pop(SqStack *S, SElemType *e) {
	//若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK，否则返回ERROR
	if ((*S).top == (*S).base)return ERROR;
	*e = *(--(*S).top);
	return OK;
}

//取栈顶元素
Status GetTop(SqStack S, SElemType *e) {
	//若栈不空，则用e返回S的栈顶元素，并返回OK，否则返回ERROR
	if (S.top == S.base)return ERROR;
	*e = *(S.top - 1);
	return OK;
}


int main() {




	return 0;
}