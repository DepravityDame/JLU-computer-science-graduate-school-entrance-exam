#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
using namespace std;

int sum(int n) {
	int ans = 0;//�����
	while (n != 0) {
		ans += n % 10;//��λȡ�������
		n = n / 10;
	}
	return ans;//���ش�
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {//��������
		printf("%d",sum(n));//�����
	}
}