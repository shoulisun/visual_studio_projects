#include "stdio.h"


#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
//Status�Ǻ��������ͣ���ֵ�Ǻ������״̬����
typedef int Status;

#define LIST_INIT_SIZE 100	//���Ա�洢�ռ�ĳ�ʼ������
#define LISTINCREMENT 10	//���Ա�洢�ռ�ķ�������

//��������Elemtype
typedef struct {
	int i;
}ElemType;

//���Ա�Ķ�̬����˳��洢�ṹ
typedef struct {
	ElemType *elem;		//�洢�ռ��ַ
	int length;			//��ǰ����
	int listsize;		//��ǰ����Ĵ洢��������sizeof(ElemType)Ϊ��λ��
}SqList;

//���Ա�ĳ�ʼ��
Status InitList_Sq(SqList *L) {
	//����һ���յ����Ա�
	(*L).elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if (!(*L).elem)exit(OVERFLOW);		//�洢����ʧ��
	(*L).length = 0;					//�ձ���Ϊ0
	(*L).listsize = LIST_INIT_SIZE;		//��ʼ�洢����
	return OK;
}

//���Ա�Ĳ���
Status ListInsert_Sq(SqList *L, int i, ElemType e) {
	//��˳�����Ա�L�е�i��λ��֮ǰ�����µ�Ԫ��e��
	//i�ĺϷ�ֵΪ1<=i<=ListLength_Sq(L)+1
	if (i<1 || i>(*L).length + 1)return ERROR;		//iֵ���Ϸ�
	if ((*L).length >= (*L).listsize) {				//��ǰ�洢�ռ����������ӷ���
		ElemType *newbase = (ElemType *)realloc((*L).elem,((*L).listsize+ LISTINCREMENT)*sizeof(ElemType));
		if (!newbase)exit(OVERFLOW);				//�洢����ʧ��
		(*L).elem = newbase;						//�»�ַ
		(*L).listsize += LISTINCREMENT;				//���Ӵ洢����
	}
	ElemType *q = &((*L).elem[i-1]),*p;				//qΪ����λ��
	for (p = &((*L).elem[(*L).length - 1]); p >= q; --p)
		*(p + 1) = *p;								//����λ�ü�֮���Ԫ������
	*q = e;				//����e
	++(*L).length;		//����1
	return OK;
}

//���Ա��ɾ��
Status ListDelete_Sq(SqList *L,int i,ElemType *e) {
	//��˳�����Ա�L��ɾ����i��Ԫ�أ�����e������ֵ
	//i�ĺϷ�ֵΪ1<=i<=ListLength_Sq(L)
	if (i<1 || i>(*L).length)return ERROR;		//iֵ���Ϸ�
	ElemType *p = &((*L).elem[i-1]),*q;			//pΪ��ɾ��Ԫ�ص�λ��
	*e = *p;									//��ɾ��Ԫ�ص�ֵ����e
	q = (*L).elem + (*L).length - 1;			//��βԪ�ص�λ��
	for (++p; p <= q; ++p)*(p - 1) = *p;		//��ɾ��Ԫ��֮���Ԫ������
	--(*L).length;								//����1
	return OK;
}

//���Ա�ĺϲ�
void MergeList_Sq(SqList La,SqList Lb,SqList *Lc) {
	//��֪˳�����Ա�La��Lb��Ԫ�ذ�ֵ�ǵݼ�����
	//�鲢La��Lb�õ����µ�˳�����Ա�Lc��Lc��Ԫ��Ҳ��ֵ�ǵݼ�����
	ElemType *pa = La.elem, *pb = Lb.elem,*pc;
	(*Lc).listsize = (*Lc).length = La.length + Lb.length;
	pc = (*Lc).elem = (ElemType *)malloc((*Lc).listsize*sizeof(ElemType));
	if (!(*Lc).elem)exit(OVERFLOW);			//�洢����ʧ��
	ElemType *pa_last = La.elem + La.length - 1;
	ElemType *pb_last = Lb.elem + Lb.length - 1;

	//�ǵݼ�˳���Ĺ鲢�����ݵ�ֵ�����á�<���͡�>���Ƚ�
	while (pa <= pa_last&&pb <= pb_last) {	//�鲢
		/*if (*pa <= *pb)*/*pc++ = *pa++;
		/*else */*pc++ = *pb++;
	}
	while (pa <= pa_last)*pc++ = *pa++;		//����La��ʣ��Ԫ��
	while (pb <= pb_last)*pc++ = *pb++;		//����Lb��ʣ��Ԫ��
}

//����Ԫ��
int LocateElem_Sq(SqList L, ElemType e) {
	//��˳�����Ա�L�в��ҵ�һ��ֵ��e��ȵ�Ԫ�ص�λ��
	//���ҵ����򷵻�����L�е�λ�򣬷��򷵻�0
	int i = 1;				//i�ĳ�ʼֵΪ��һ��Ԫ�ص�λ��
	ElemType *p = L.elem;	//p�ĳ�ֵΪ��һ��Ԫ�صĴ洢λ��
	while (i <= L.length/*&&(((*p)++)!=e)*/)++i;		//���ݵ�ֵ�����á�=���Ƚ�
	if (i <= L.length)return i;
	else return 0;
}











