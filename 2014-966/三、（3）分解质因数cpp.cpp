#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>

void fj(int n) {
	int i;
	int flag = 1;//����������
	if (n == 1)printf("0\n");//n=1ʱ���0
	else {
		printf("%d=", n);//���ԭ��
		for (int i = 2; i <= n; i++) {
			while (n%i == 0) {//�������˵�������ӣ����ܶ����������ʹ��while
				if (flag) {//��һ�����ֲ�����˺�
					printf("%d", i);
					flag = 0;
				}
				else {
					printf("*%d", i);//��������˺�
				}
				n = n / i;//����n
			}
		}
		
	}
}


int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		fj(n);
	}
}