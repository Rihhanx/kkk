#include<stdio.h>//头文件
void Move(int n, char A, char B, char C)//定义函数
{
	if (n == 1)
	{
		printf("%c-->%c\n", A, C);//输出移动结果
	}
	else
	{
		Move(n - 1, A, C, B);//把A上n-1个盘子通过借助辅助塔(C塔)移到了B上
		printf("%c-->%c\n", A, C);//把最大的一个盘子由A移到C上去
		Move(n - 1, B, A, C); //把B上n-1个盘子通过借助辅助塔(A塔)移到了C上
	}
}
int main()//主函数
{
	int n = 0;//定义字符变量
	printf("请输入汉诺塔的盘子数:");//提示语句
	scanf_s("%d", &n);//键盘输入
	Move(n, 'A', 'B', 'C');
	return 0;//函数返回值为0
}