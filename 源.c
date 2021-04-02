#include<stdio.h>//头文件
int main()//主函数
{
	char ch;//定义字符变量
	printf("请输入一个字符:");//提示语句
	scanf_s("%c",&ch);//键盘输入
	if (ch >='a'&& ch <='z'|| ch >='A'&& ch <='Z')//字母的取值范围
		printf("%c是一个字母\n", ch);//输出字符ch的类别
	else if (ch >='0'&& ch <='9')//数字的取值范围
		printf("%c是一个数字\n", ch);//输出字符ch的类别
	else
		printf("%c是一个特殊字符\n", ch);//输出字符ch的类别
	return 0;////函数返回值为0 
}
