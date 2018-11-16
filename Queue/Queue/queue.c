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
//循环队列---队列的顺序存储结构
#define MAXQSIZE 20	//最大队列长度
//定义数据SElemType
typedef char QElemType;
typedef struct {
	QElemType *base;	//初始化的动态分配存储空间
	int front;			//头指针，若队列不空，指向队列头元素
	int rear;			//尾指针，若队列不空，指向队列尾元素的下一个位置
}SqQueue;
//队列初始化,构造一个空队列
Status InitQueue(SqQueue *Q) {
	(*Q).base = (QElemType *)malloc(MAXQSIZE*sizeof(QElemType));
	if (!(*Q).base)exit(OVERFLOW);		//存储分配失败
	(*Q).front = (*Q).rear = 0;
	return OK;
}
//入队操作，即在队尾插入元素
Status EnQueue(SqQueue *Q,QElemType e) {
	if (((*Q).rear + 1) % MAXQSIZE == (*Q).front)return ERROR;//队列满
	(*Q).base[(*Q).rear] = e;
	(*Q).rear = ((*Q).rear + 1) % MAXQSIZE;
	return OK;
}
//出队操作，即在队头删除元素,并用e返回其值
Status DeQueue(SqQueue *Q,QElemType *e) {
	if ((*Q).front == (*Q).rear)return ERROR;
	*e = (*Q).base[(*Q).front];
	(*Q).front = ((*Q).front + 1) % MAXQSIZE;
	return OK;
}
//遍历输出
void ergodicQueue(SqQueue Q) {
	for (int i = Q.front; i < Q.rear; i++) {
		printf(" %d%c ",i,Q.base[i]);
	}
	printf("\n");
}
//求队长操作，函数返回队列长度
int QueueLength(SqQueue Q) {
	return  (Q.rear - Q.front + MAXQSIZE)%MAXQSIZE;
}
//初始化随机队列元素-食物
Status InitFood(QElemType *food) {
	srand(time(NULL));
	*food = 65 + rand() % 26;
	return OK;
}
int main() {
	printf("*********************生产者消费者问题*********************\n");
	int productOrConsume = 1;//该变量等于1为生产，0为消费
	QElemType food;//用于存储生产出来的“食物”
	SqQueue Q;
	//初始化队列
	if (InitQueue(&Q))printf("初始化队列成功\n");
	//首先让队列中有10个食物
	printf("正在生成10个食物......剩余：10秒");
	for (int i = 0; i < 10; i++) {
		InitFood(&food);
		EnQueue(&Q,food);
		Sleep(1000);
		printf(" %d秒",9-i);
	}
	printf("\n生成10个食物并入队成功:");
	ergodicQueue(Q);
	while (QueueLength(Q)!=0&&QueueLength(Q)!=19) {
		InitFood(&food);//初始化食物
		productOrConsume =0;
		if (productOrConsume == 1) {//生产者生产
			EnQueue(&Q, food);
			printf("%c生产成功,队长：%d 队列：",food, QueueLength(Q));
			ergodicQueue(Q);
		}
		else {//消费者消费
			DeQueue(&Q, &food);
			printf("%c消费成功,队长：%d 队列：", food, QueueLength(Q));
			ergodicQueue(Q);
		}
		Sleep(1000);
	}
	if (QueueLength(Q) == 0)printf("队列空，消费者消费完毕！");
	else printf("队列满，生产者生产完毕！");
	system("pause");
	return 0;
}