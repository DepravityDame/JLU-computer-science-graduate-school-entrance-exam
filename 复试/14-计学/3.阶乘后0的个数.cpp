#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>

int js(int n) {
	int ans = 0;
	while (n) {//��5��ż����˻����0����֪ż��������Ȼ����5������������ֻ�����5�ı����ĸ������ɼ������β0�ĸ���
		ans += n/ 5;//�ۼ�0����
		n /= 5;//�൱�ڵ�һ��n/5�ڶ���n/25������n/125
	}
	return ans;//���ش�
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {//��������
		printf("%d\n", js(n));//�����
	}
}