#define _CRT_SECURE_NO_DEPRECATE //��֤VS�����scanf����
#include<stdio.h>

int main() {
	char a[100];//����������ַ������ַ�����
	int sum=0;//�洢ʮ������
	scanf("%c", &a[0]);//�����һ���ַ�
	int len=0;//����ܳ���
	while (a[len] != '*') {//ѭ���������з�*�ַ�
		len++;
		scanf("%c", &a[len]);
	}
	a[len] = '\0';//�ض��ַ���
	for (int i = 0; a[i]!='\0'/* or i<len*/; i++) {
		sum = sum*2+(a[i] - '0');//��������תʮ������
	}
	printf("%d", sum);//�����

}

