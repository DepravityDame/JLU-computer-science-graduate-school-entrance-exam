#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<queue>
#include<iostream>
using namespace std;
bool isprime(int n) {//�ж��Ƿ�������
	if (n < 2) {
		return false;
	}
	for (int i = 2; i < n / 2; i++) {
		if (n%i == 0)return false;
	}
	return true;
}
void fj(int n) {//�ֽ���̺�����
	if (n % 2 != 0) {
		printf("It is not even number\n");//����ż���˳�
		return;
	}
	for (int i = 2; i <=n; i++) {
		if (isprime(i) && isprime(n - i)) {//i��n-iͬΪ����ʱ�������ֻҪ�����һ�飬���Լ���break�������ȫ�����ܿ���ȥ��break
			printf("%d=%d+%d\n", n,i,n - i);
			break;
		}
	}
}


int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		fj(n);
	}
}