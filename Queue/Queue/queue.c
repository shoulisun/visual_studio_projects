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
//ѭ������---���е�˳��洢�ṹ
#define MAXQSIZE 20	//�����г���
//��������SElemType
typedef char QElemType;
typedef struct {
	QElemType *base;	//��ʼ���Ķ�̬����洢�ռ�
	int front;			//ͷָ�룬�����в��գ�ָ�����ͷԪ��
	int rear;			//βָ�룬�����в��գ�ָ�����βԪ�ص���һ��λ��
}SqQueue;
//���г�ʼ��,����һ���ն���
Status InitQueue(SqQueue *Q) {
	(*Q).base = (QElemType *)malloc(MAXQSIZE*sizeof(QElemType));
	if (!(*Q).base)exit(OVERFLOW);		//�洢����ʧ��
	(*Q).front = (*Q).rear = 0;
	return OK;
}
//��Ӳ��������ڶ�β����Ԫ��
Status EnQueue(SqQueue *Q,QElemType e) {
	if (((*Q).rear + 1) % MAXQSIZE == (*Q).front)return ERROR;//������
	(*Q).base[(*Q).rear] = e;
	(*Q).rear = ((*Q).rear + 1) % MAXQSIZE;
	return OK;
}
//���Ӳ��������ڶ�ͷɾ��Ԫ��,����e������ֵ
Status DeQueue(SqQueue *Q,QElemType *e) {
	if ((*Q).front == (*Q).rear)return ERROR;
	*e = (*Q).base[(*Q).front];
	(*Q).front = ((*Q).front + 1) % MAXQSIZE;
	return OK;
}
//�������
void ergodicQueue(SqQueue Q) {
	for (int i = Q.front; i < Q.rear; i++) {
		printf(" %d%c ",i,Q.base[i]);
	}
	printf("\n");
}
//��ӳ��������������ض��г���
int QueueLength(SqQueue Q) {
	return  (Q.rear - Q.front + MAXQSIZE)%MAXQSIZE;
}
//��ʼ���������Ԫ��-ʳ��
Status InitFood(QElemType *food) {
	srand(time(NULL));
	*food = 65 + rand() % 26;
	return OK;
}
int main() {
	printf("*********************����������������*********************\n");
	int productOrConsume = 1;//�ñ�������1Ϊ������0Ϊ����
	QElemType food;//���ڴ洢���������ġ�ʳ�
	SqQueue Q;
	//��ʼ������
	if (InitQueue(&Q))printf("��ʼ�����гɹ�\n");
	//�����ö�������10��ʳ��
	printf("��������10��ʳ��......ʣ�ࣺ10��");
	for (int i = 0; i < 10; i++) {
		InitFood(&food);
		EnQueue(&Q,food);
		Sleep(1000);
		printf(" %d��",9-i);
	}
	printf("\n����10��ʳ�ﲢ��ӳɹ�:");
	ergodicQueue(Q);
	while (QueueLength(Q)!=0&&QueueLength(Q)!=19) {
		InitFood(&food);//��ʼ��ʳ��
		productOrConsume =0;
		if (productOrConsume == 1) {//����������
			EnQueue(&Q, food);
			printf("%c�����ɹ�,�ӳ���%d ���У�",food, QueueLength(Q));
			ergodicQueue(Q);
		}
		else {//����������
			DeQueue(&Q, &food);
			printf("%c���ѳɹ�,�ӳ���%d ���У�", food, QueueLength(Q));
			ergodicQueue(Q);
		}
		Sleep(1000);
	}
	if (QueueLength(Q) == 0)printf("���пգ�������������ϣ�");
	else printf("��������������������ϣ�");
	system("pause");
	return 0;
}