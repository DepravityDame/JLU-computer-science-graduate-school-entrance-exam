#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
int fact(int n) {//�׳˼���
	if (n == 0 or n == 1)return 1;
	else return n * fact(n - 1);
}



double fun(int n) {
	if (n == 0)return 0;//���n=0����0
	else return n*1.0 / (n + 1) / fact(n + 2) + fun(n - 1);//���ص�ǰ���֮ǰ��
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {//��������
		printf("%lf",fun(n));//������
	}
}