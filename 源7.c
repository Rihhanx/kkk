#include<stdio.h>//ͷ�ļ�
#include<string.h>//����sring.h�⺯��
char str[10], temp[10];//tmpt�������ȫ���е�ÿһ�����
int len;//�����ַ�����
int flag[10];//�����ж�str�еĵ�i��λ���ַ��Ƿ�����˴˴����� 
void dfs(int step) 
{                       //��step=0,ִ�е�dfs(0),ѡ����tmpt��һλ��ĸ��ִ��dfs(1),ѡ��tmpt�ڶ�λ��ĸ
	if (step == len)  
	{ 
		temp[step] = '\0';//ֻҪִ�е���dfs(step),tmpt�ĵ�step+1λ����ĸ�ͱ�ѡ��
		printf("%s\n", temp);
	}
	for (int i = 0; i < len; i++) //ѭ�����
	{
		if (flag[i] == 0) 
		{
			flag[i] = 1;
			temp[step] = str[i]; //tmpt[step]��ֵ��i�� flag[i]��ͬ����
			dfs(step + 1);
			flag[i] = 0;	//ÿһ��dfs(step+1)������ɺ�flag[i]����Ϊ0��str[i]�ֻص���δ�������״̬ 
		}
	}
}
int main()//������
{
	while (scanf("%s", str) != EOF) 
	{
		len = strlen(str);
		dfs(0);
	}
	return 0;//��������ֵΪ0 
}