#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>

int main() {
	int n;
	int a[4];//�����λ����
	int k = 3;//���һλ��ʼ���汣��ԭ��
	while (scanf("%d", &n) != EOF) {
		while (n != 0) {//�����λ������a[4]��
			a[k--] = n % 10;
			n = n / 10;
		}
		for (int i = 0; i < 4; i++) {//���ܲ���
			a[i] = (a[i] + 5) % 10;
		}
		for (int i = 3; i >= 0; i--) {//����һ�ģ�����λ�൱�ڵ�������ֱ�����������Ϊ��
			printf("%d", a[i]);
		}
		printf("\n");
	}
}