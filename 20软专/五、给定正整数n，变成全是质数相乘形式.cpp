#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

int main() {
	int n;
	int flag;
	scanf("%d", &n); //��������
	flag = 1;
	int cot = 0;//��¼��������
	printf("%d=", n);//��ʽ���
	for (int i = 2; n!=1; i++) {
		while (n%i == 0) {//����������ʹ��while��Ӧn���Զ�α�i�������
			if (flag) {//flag����*�����
				printf("%d", i);//���������
				flag = 0;
			}
			else {
				printf("*%d", i);
			}
			n = n / i;//n����
			cot++;//��¼��������
		}
	}
	return cot;//������������
}