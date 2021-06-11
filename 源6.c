#include<stdio.h>//头文件
#include <stdlib.h>//调用stdlib.h库函数
int total_peach(int rest)
{
	return (rest + 1) * 2;
}
int main()//主函数
{
	int peach = 0;//桃子总数
	int rest = 1;//第10 天只剩一个桃子
	int day = 9;//定义字符变量
	while (day--)//循环语句
	{
		peach = total_peach(rest);//递归实现
		rest = peach;
	}
	printf("猴子第一天一共摘了%d个桃子\n", peach);//输出猴子第一天摘下桃子的结果数
	return 0;//函数返回值为0 
}