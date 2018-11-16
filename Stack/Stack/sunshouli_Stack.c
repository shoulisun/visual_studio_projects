#include "stdio.h"
#include "windows.h"
//汉诺塔函数的声明
void Hanoi(int, char, char, char);
int n = 0;//作为移动的步数
void main()
{
	int num;//num作为塔的个数
	printf("请输入塔个数：");
	scanf_s("%d", &num);
	printf("=================================\n");
	//三根柱分别为A、B、C
	Hanoi(num, 'A', 'B', 'C');
	printf("=================================\n");
	system("pause");
}
void Hanoi(int num, char a, char b, char c)
{
	//如果只有一个塔，直接从A到C
	if (num == 1)
		printf("step%3d:%c-->%c\n", ++n, a, c);
	else
	{
		Hanoi(num - 1, a, c, b);//把前num-1个移动到B
		printf("step%3d:%c-->%c\n", ++n, a, c);//把最后一个移动到C
		Hanoi(num - 1, b, a, c);//把B上的num-1个移动到C
	}
}