#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
using namespace std;

/*
����һ����k[n]
		|1			n=1;
k[n]=	|-2k(n-1)+1 nΪż��
		|-3k(n-1)+1	nΪ����
*/
//����Ӧ������Ŀ�����⡣�������ﵽ2��100�η����ϣ���û�з�ĸ���л��򡣴𰸽���Ѿ����������˼·�ο���
int main() {
	long long a[101];//�������鴢������
	
	a[1] = 1;//��������
	long long sum = 1;//�����
	for (int i = 2; i <=100; i++) {
		if (i % 2 == 0) {//iΪż��
			a[i] = a[i - 1] * -2 + 1;
		}
		else {//iΪ����
			a[i] = a[i - 1] * 3 + 1;
		}
		sum += a[i];//�ۼ����
	}
	printf("%lld\n", sum);//�����
}
