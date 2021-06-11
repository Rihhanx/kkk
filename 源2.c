#include<stdio.h>//头文件
int main()//主函数
{
	int number = 8, guess;//定义字符变量
	printf("猜一个介于1与10之间的数\n");//提示语句 
	do//条件语句
	{
		printf("请输入您猜测的数：");//提示语句
		scanf_s("%d", &guess);//键盘输入
		if (guess > number)
			printf("太大\n");//输出提示太大
		else if (guess < number)
			printf("太小\n");//输出提示太小
	} while (guess != number);
	printf("您猜中了！答案为%d\n", number);//输出游戏结果
	return 0;//函数返回值为0 
}