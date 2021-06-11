#include<stdio.h>//头文件
int main()//主函数 
{
	long ge, shi, bai, qian, wan, x;//定义长整数字符变量
	printf("\n 请输入一个五位整数：");//提示语句 
	scanf_s("%ld", &x);//键盘输入
	wan = x / 10000;//分解出万位数
	qian = x % 10000 / 1000;//分解出千位数
	shi = x % 100 / 10;//分解出十位数
	ge = x % 10;//分解出个位数
	if (ge == wan && shi == qian)//判断个位数与万位数相等的同时十位数是否与千位数相等
		printf("\n这个数是回文数\n");//输出这个数是回文数
	else
		printf("\n这个数不是回文数\n");//输出这个数不是回文数
	return 0;//函数返回值为0 
}