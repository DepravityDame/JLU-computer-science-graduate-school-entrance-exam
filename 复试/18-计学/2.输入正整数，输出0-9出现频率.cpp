#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
int main() {
	int num[10];//0-9����
	memset(num, 0, sizeof(num)); //��ʼ�����ִ���Ϊ0
	int n;//�����������
	while (scanf("%d", &n) != EOF) {//��������
		while (n != 0) {//��Ӧ���ֵ����ָ���++
			num[n % 10]++;
			n = n / 10;
		}
		for (int i = 0; i < 10; i++) {//������
			printf("%d:%d\n", i, num[i]);
		}
	}
}