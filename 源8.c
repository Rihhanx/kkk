#include<stdio.h>//ͷ�ļ�
void Move(int n, char A, char B, char C)//���庯��
{
	if (n == 1)
	{
		printf("%c-->%c\n", A, C);//����ƶ����
	}
	else
	{
		Move(n - 1, A, C, B);//��A��n-1������ͨ������������(C��)�Ƶ���B��
		printf("%c-->%c\n", A, C);//������һ��������A�Ƶ�C��ȥ
		Move(n - 1, B, A, C); //��B��n-1������ͨ������������(A��)�Ƶ���C��
	}
}
int main()//������
{
	int n = 0;//�����ַ�����
	printf("�����뺺ŵ����������:");//��ʾ���
	scanf_s("%d", &n);//��������
	Move(n, 'A', 'B', 'C');
	return 0;//��������ֵΪ0
}