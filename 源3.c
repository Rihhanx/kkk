#include <stdio.h>//头文件
int main()//主函数
{
    int year;//定义变量为整型
    printf("请输入所查年份：");//提示语句
    scanf_s("%d", &year);//键盘输入
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)//条件语句判断
        printf("是闰年\n");//输出年份判断闰年
    else
        printf("不是闰年\n");//输出年份判断非闰年
    return 0;//函数返回值为0 
}