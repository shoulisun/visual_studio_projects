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
#define STACK_INIT_SIZE 100	//存储空间的初始分配量
#define STACKINCREMENT 10	//存储空间的分配增量
//定义数据SElemType
typedef char SElemType;
//定义栈
typedef struct {
	SElemType *base;	//在栈顶构造之前和销毁之后，base的值为NULL
	SElemType *top;		//栈顶指针
	int stacksize;		//当前已分配的存储空间，以元素为单位
}SqStack;
//栈的初始化
Status InitStack(SqStack *S){
	//构造一个空栈
	(*S).base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if (!(*S).base)exit(OVERFLOW);		//存储分配失败
	(*S).top = (*S).base;
	(*S).stacksize = STACK_INIT_SIZE;
	return OK;
}
//栈的入栈操作
Status Push(SqStack *S,SElemType e) {
	//插入元素e为新的栈顶元素
	if ((*S).top - (*S).base >= (*S).stacksize) {//栈满，追加存储空间
		(*S).base = (SElemType *)malloc((*S).base,((*S).stacksize+STACKINCREMENT)*sizeof(SElemType));
		if (!(*S).base)exit(OVERFLOW);		//存储分配失败
		(*S).stacksize += STACKINCREMENT;
		(*S).top = (*S).base + (*S).stacksize;
	}
	*((*S).top) = e;
	(*S).top++;
	return OK;
}
//栈的出栈操作
Status Pop(SqStack *S,SElemType *e) {
	//若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK，否则返回ERROR
	if ((*S).top == (*S).base)return ERROR;
	*e = *(--(*S).top);
	return OK;
}
//取栈顶元素
Status GetTop(SqStack S,SElemType *e) {
	//若栈不空，则用e返回S的栈顶元素，并返回OK，否则返回ERROR
	if (S.top == S.base)return ERROR;
	*e = *(S.top-1);
	return OK;
}
int main2(){
	printf("*********************括号匹配算法*********************\n");
	printf("请切换英文输入法，仅限小括号或者中括号;输入e退出程序\n");
	printf("请输入一串括号字符串，仅限最多20个字符，超出部分不计\n");
	SqStack S;
	SElemType element[20],top_e=' ';//栈顶元素
	int count=0;
	while (1) {
		//初始化栈
		printf("正在初始化栈......\n");
		if(InitStack(&S))printf("初始化栈成功！\n");
		//初始化字符串
		count = 0;
		printf("请输入括号串：");
		gets(element);
		while(count<20&&element[count]!='\0'){
			printf("取得第%d个字符:%c\n",count+1,element[count]);
			if(S.top != S.base)GetTop(S,&top_e);//每读入一个括号之前先取得栈顶元素
			switch (element[count]) {
				case '(':
					printf("正在入栈......\n");
					if (Push(&S, element[count]))printf("入栈成功！\n");
					break;
				case '[':
					printf("正在入栈......\n");
					if (Push(&S, element[count]))printf("入栈成功！\n");
					break;//只要是正括号就入栈
				case ']':
					if (top_e == '[') {
						printf("括号匹配成功！正在出栈...... ");
						if (Pop(&S, &top_e))printf("出栈成功！\n");
					}//只要栈顶元素是反括号就出栈
					else {
						printf("此括号不匹配！\n\n");
						count = 20;
					}
					break;
				case ')':			
					if (top_e == '(') {
						printf("括号匹配成功！正在出栈...... ");
						if (Pop(&S, &top_e))printf("出栈成功！\n");
					}//只要栈顶元素是反括号就出栈
					else {
						printf("此括号不匹配！\n\n");
						count = 20;
					}
					break;
				case 'E':;
				case 'e':exit(0);//输入e退出程序
				default:printf("发现非法字符！操作失败！\n\n");
					count = 20;//发现非法字符强行退出循环
					break;
			}
			count += 1;
			Sleep(1000);
		}
		if (count != 21)printf("此括号串匹配成功，合法嵌套！\n\n");
	}
	return 0;
}