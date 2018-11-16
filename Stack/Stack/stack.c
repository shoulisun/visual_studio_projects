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
#define STACK_INIT_SIZE 100	//�洢�ռ�ĳ�ʼ������
#define STACKINCREMENT 10	//�洢�ռ�ķ�������
//��������SElemType
typedef char SElemType;
//����ջ
typedef struct {
	SElemType *base;	//��ջ������֮ǰ������֮��base��ֵΪNULL
	SElemType *top;		//ջ��ָ��
	int stacksize;		//��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ
}SqStack;
//ջ�ĳ�ʼ��
Status InitStack(SqStack *S){
	//����һ����ջ
	(*S).base = (SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if (!(*S).base)exit(OVERFLOW);		//�洢����ʧ��
	(*S).top = (*S).base;
	(*S).stacksize = STACK_INIT_SIZE;
	return OK;
}
//ջ����ջ����
Status Push(SqStack *S,SElemType e) {
	//����Ԫ��eΪ�µ�ջ��Ԫ��
	if ((*S).top - (*S).base >= (*S).stacksize) {//ջ����׷�Ӵ洢�ռ�
		(*S).base = (SElemType *)malloc((*S).base,((*S).stacksize+STACKINCREMENT)*sizeof(SElemType));
		if (!(*S).base)exit(OVERFLOW);		//�洢����ʧ��
		(*S).stacksize += STACKINCREMENT;
		(*S).top = (*S).base + (*S).stacksize;
	}
	*((*S).top) = e;
	(*S).top++;
	return OK;
}
//ջ�ĳ�ջ����
Status Pop(SqStack *S,SElemType *e) {
	//��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
	if ((*S).top == (*S).base)return ERROR;
	*e = *(--(*S).top);
	return OK;
}
//ȡջ��Ԫ��
Status GetTop(SqStack S,SElemType *e) {
	//��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR
	if (S.top == S.base)return ERROR;
	*e = *(S.top-1);
	return OK;
}
int main2(){
	printf("*********************����ƥ���㷨*********************\n");
	printf("���л�Ӣ�����뷨������С���Ż���������;����e�˳�����\n");
	printf("������һ�������ַ������������20���ַ����������ֲ���\n");
	SqStack S;
	SElemType element[20],top_e=' ';//ջ��Ԫ��
	int count=0;
	while (1) {
		//��ʼ��ջ
		printf("���ڳ�ʼ��ջ......\n");
		if(InitStack(&S))printf("��ʼ��ջ�ɹ���\n");
		//��ʼ���ַ���
		count = 0;
		printf("���������Ŵ���");
		gets(element);
		while(count<20&&element[count]!='\0'){
			printf("ȡ�õ�%d���ַ�:%c\n",count+1,element[count]);
			if(S.top != S.base)GetTop(S,&top_e);//ÿ����һ������֮ǰ��ȡ��ջ��Ԫ��
			switch (element[count]) {
				case '(':
					printf("������ջ......\n");
					if (Push(&S, element[count]))printf("��ջ�ɹ���\n");
					break;
				case '[':
					printf("������ջ......\n");
					if (Push(&S, element[count]))printf("��ջ�ɹ���\n");
					break;//ֻҪ�������ž���ջ
				case ']':
					if (top_e == '[') {
						printf("����ƥ��ɹ������ڳ�ջ...... ");
						if (Pop(&S, &top_e))printf("��ջ�ɹ���\n");
					}//ֻҪջ��Ԫ���Ƿ����žͳ�ջ
					else {
						printf("�����Ų�ƥ�䣡\n\n");
						count = 20;
					}
					break;
				case ')':			
					if (top_e == '(') {
						printf("����ƥ��ɹ������ڳ�ջ...... ");
						if (Pop(&S, &top_e))printf("��ջ�ɹ���\n");
					}//ֻҪջ��Ԫ���Ƿ����žͳ�ջ
					else {
						printf("�����Ų�ƥ�䣡\n\n");
						count = 20;
					}
					break;
				case 'E':;
				case 'e':exit(0);//����e�˳�����
				default:printf("���ַǷ��ַ�������ʧ�ܣ�\n\n");
					count = 20;//���ַǷ��ַ�ǿ���˳�ѭ��
					break;
			}
			count += 1;
			Sleep(1000);
		}
		if (count != 21)printf("�����Ŵ�ƥ��ɹ����Ϸ�Ƕ�ף�\n\n");
	}
	return 0;
}