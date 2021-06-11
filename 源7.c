#include<stdio.h>//头文件
#include<string.h>//调用sring.h库函数
char str[10], temp[10];//tmpt用来输出全排列的每一个结果
int len;//定义字符变量
int flag[10];//用来判断str中的第i个位置字符是否进行了此次排列 
void dfs(int step) 
{                       //当step=0,执行的dfs(0),选定了tmpt第一位字母，执行dfs(1),选定tmpt第二位字母
	if (step == len)  
	{ 
		temp[step] = '\0';//只要执行的是dfs(step),tmpt的第step+1位的字母就被选定
		printf("%s\n", temp);
	}
	for (int i = 0; i < len; i++) //循环语句
	{
		if (flag[i] == 0) 
		{
			flag[i] = 1;
			temp[step] = str[i]; //tmpt[step]的值由i和 flag[i]共同决定
			dfs(step + 1);
			flag[i] = 0;	//每一次dfs(step+1)调用完成后flag[i]被置为0，str[i]又回到了未被排序的状态 
		}
	}
}
int main()//主函数
{
	while (scanf("%s", str) != EOF) 
	{
		len = strlen(str);
		dfs(0);
	}
	return 0;//函数返回值为0 
}