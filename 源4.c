#include<stdio.h>//ͷ�ļ�
#include<math.h>//����math.h�⺯��
int main()//������
{
	int num = 100;//�����ַ�����
	int i = 2;//�����ַ�����
	for (num = 100; num <= 200; num++)//ѭ�����
	{
		//num = a*b a,b��С�ڿ�ƽ��num��
		//sqrt��һ���⺯�� ��num��ƽ�� math.h
		for (i = 2; i <= sqrt(num); i++)//�ж�һ�����ǲ�������
		{
			if (num % i == 0)//������������
				break;
		}
		if (i > sqrt(num))//������
		{
			printf("%d ", num);//��ӡ������
		}
	}
	return 0;//��������ֵΪ0 
}