#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

void fj(int n) {
	int a[100];//�����λ����
	int k = 0;
	while (n != 0) {
		if ((n % 10) % 2 != 0){//�����λ������������
		a[k++] = n % 10;
		}
		n = n / 10;//ȡ��һλ
	}
	for (int i = k-1;i>=0; i--) {//��Ӹ�λ��ʼ����ģ����Դ�Ҫ�������
		printf("%d", a[i]);
	}
	printf("\n");
}



int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		fj(n);
	}
}