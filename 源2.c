#include<stdio.h>//ͷ�ļ�
int main()//������
{
	int number = 8, guess;//�����ַ�����
	printf("��һ������1��10֮�����\n");//��ʾ��� 
	do//�������
	{
		printf("���������²������");//��ʾ���
		scanf_s("%d", &guess);//��������
		if (guess > number)
			printf("̫��\n");//�����ʾ̫��
		else if (guess < number)
			printf("̫С\n");//�����ʾ̫С
	} while (guess != number);
	printf("�������ˣ���Ϊ%d\n", number);//�����Ϸ���
	return 0;//��������ֵΪ0 
}