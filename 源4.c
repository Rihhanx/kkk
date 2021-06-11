#include<stdio.h>//头文件
#include<math.h>//调用math.h库函数
int main()//主函数
{
	int num = 100;//定义字符变量
	int i = 2;//定义字符变量
	for (num = 100; num <= 200; num++)//循环语句
	{
		//num = a*b a,b是小于开平方num的
		//sqrt是一个库函数 对num开平方 math.h
		for (i = 2; i <= sqrt(num); i++)//判断一个数是不是素数
		{
			if (num % i == 0)//不是素数跳出
				break;
		}
		if (i > sqrt(num))//是素数
		{
			printf("%d ", num);//打印输出结果
		}
	}
	return 0;//函数返回值为0 
}