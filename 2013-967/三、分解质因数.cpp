#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<queue>
#include<iostream>
using namespace std;

void fj(int n) {//��������
	int i;
	printf("%d=", n);
	for ( i = 2; i < n; i++) {
		while (n%i == 0) {//���������ͬ����
			printf("%d*", i);
			n /= i;
		}
	}
	
	printf("%d\n",i);//������һ������
}


int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		fj(n);
	}
}