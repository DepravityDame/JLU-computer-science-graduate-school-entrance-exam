#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
int sum = 0;
void DFS(int n, int step,char str[]) {//������ȱ������
	if (step == n) {//����λ��Ҫ��
		str[n] = '\0';//����ַ�����β
		sum++;//��������
		printf("%s\n", str);//����ַ���
		return;//������һ��
	}
	str[step] = 'A';//��λ��A��ʼ
	DFS(n, step + 1, str);
	str[step] = 'B';//��λ��B��ʼ
	DFS(n, step + 1, str);
	str[step] = 'C';//��λ��C��ʼ
	DFS(n, step + 1, str);//���ݱ�֤��������п�����
}



int main() {
	int n;
	char str[100];
	while (scanf("%d", &n) != EOF) {
		DFS(n,0,str);//��ȱ������
		printf("the number of answer is :%d\n", sum);
	}
}