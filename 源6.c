#include<stdio.h>//ͷ�ļ�
#include <stdlib.h>//����stdlib.h�⺯��
int total_peach(int rest)
{
	return (rest + 1) * 2;
}
int main()//������
{
	int peach = 0;//��������
	int rest = 1;//��10 ��ֻʣһ������
	int day = 9;//�����ַ�����
	while (day--)//ѭ�����
	{
		peach = total_peach(rest);//�ݹ�ʵ��
		rest = peach;
	}
	printf("���ӵ�һ��һ��ժ��%d������\n", peach);//������ӵ�һ��ժ�����ӵĽ����
	return 0;//��������ֵΪ0 
}