#include<stdio.h>//ͷ�ļ�
int main()//������ 
{
    float grade; //����ɼ��ַ����� 
    printf("\n��������ĩ���Գɼ���");//��ʾ��� 
    scanf_s("%f", &grade); //�������� 
    printf("�ɼ�������");//��ʾ��� 
    switch ((int)grade / 10) //switch���֧ 
    {
    case 10:printf("��\n"); break;//���100�ֵĳɼ�����
    case 9:printf("��\n"); break;//���90�ֵĳɼ�����
    case 8:printf("��\n"); break;//���80�ֵĳɼ����� 
    case 7:printf("��\n"); break;//���70�ֵĳɼ�����
    case 6:printf("��\n"); break;//���60�ֵĳɼ�����
    default:printf("��\n");//����ɼ�����Ϊ��
    }
    return 0;//��������ֵΪ0 
}