#include "stdio.h"
#include "windows.h"
//��ŵ������������
void Hanoi(int, char, char, char);
int n = 0;//��Ϊ�ƶ��Ĳ���
void main()
{
	int num;//num��Ϊ���ĸ���
	printf("��������������");
	scanf_s("%d", &num);
	printf("=================================\n");
	//�������ֱ�ΪA��B��C
	Hanoi(num, 'A', 'B', 'C');
	printf("=================================\n");
	system("pause");
}
void Hanoi(int num, char a, char b, char c)
{
	//���ֻ��һ������ֱ�Ӵ�A��C
	if (num == 1)
		printf("step%3d:%c-->%c\n", ++n, a, c);
	else
	{
		Hanoi(num - 1, a, c, b);//��ǰnum-1���ƶ���B
		printf("step%3d:%c-->%c\n", ++n, a, c);//�����һ���ƶ���C
		Hanoi(num - 1, b, a, c);//��B�ϵ�num-1���ƶ���C
	}
}