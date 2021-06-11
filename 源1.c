#include<stdio.h>//头文件
int main()//主函数 
{
    float grade; //定义成绩字符变量 
    printf("\n请输入期末考试成绩：");//提示语句 
    scanf_s("%f", &grade); //键盘输入 
    printf("成绩评定：");//提示语句 
    switch ((int)grade / 10) //switch多分支 
    {
    case 10:printf("优\n"); break;//输出100分的成绩评定
    case 9:printf("优\n"); break;//输出90分的成绩评定
    case 8:printf("良\n"); break;//输出80分的成绩评定 
    case 7:printf("中\n"); break;//输出70分的成绩评定
    case 6:printf("中\n"); break;//输出60分的成绩评定
    default:printf("差\n");//输出成绩评定为差
    }
    return 0;//函数返回值为0 
}