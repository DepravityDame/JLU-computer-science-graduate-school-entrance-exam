#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>

int main() {
	int a[10][10];
	memset(a, 0, sizeof(a));
	int n = 10;
	int num = 1;
	for (int i = 0; i <= n / 2; i++) {//��������
		for (int j = i; j <n - i; j++) {//��ֵ����
			a[i][j] = num++;
		}
		for (int j = i + 1; j < n - i;j++) {//��ֵ����
			a[j][n - i - 1] = num++;
		}
		for (int j = n - i - 2; j >= i; j--) {//��ֵ����
			a[n - i - 1][j] = num++;
		}
		for (int j = n - i - 2; j > i; j--) {//��ֵ����
			a[j][i] = num++;
		}
	}
	for (int i = 0; i < 10; i++) {//�������
		for (int j = 0; j < 10; j++) {
			printf("%3d", a[i][j]);
		}
		printf("\n");
	}
}