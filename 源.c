#include<stdio.h>//ͷ�ļ�
int main()//������
{
	char ch;//�����ַ�����
	printf("������һ���ַ�:");//��ʾ���
	scanf_s("%c",&ch);//��������
	if (ch >='a'&& ch <='z'|| ch >='A'&& ch <='Z')//��ĸ��ȡֵ��Χ
		printf("%c��һ����ĸ\n", ch);//����ַ�ch�����
	else if (ch >='0'&& ch <='9')//���ֵ�ȡֵ��Χ
		printf("%c��һ������\n", ch);//����ַ�ch�����
	else
		printf("%c��һ�������ַ�\n", ch);//����ַ�ch�����
	return 0;////��������ֵΪ0 
}
