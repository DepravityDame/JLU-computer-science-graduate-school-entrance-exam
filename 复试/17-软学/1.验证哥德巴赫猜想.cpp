#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
using namespace std;
bool isprime(int n) {//�жϵ�ǰ�����Ƿ�������
	if (n < 2)return false;
	for (int i = 2; i <= n / 2; i++) {
		if (n%i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {//��������
		if (n < 6 || n % 2 != 0) {//���벻�淶����������
			printf("input error!\n");
		}
		else {
			for (int i = 2; i < n; i++) {//����
				if (isprime(i) && isprime(n - i)) {//i��n-iͬΪ�������
					printf("%d=%d+%d\n", n, i, n - i);
					break;//��Ҫ���ȫ�����ܿ�ȥ��break���������һ��
				}
			}
		}
	}
}