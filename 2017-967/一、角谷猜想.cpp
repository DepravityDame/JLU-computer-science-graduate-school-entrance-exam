#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>

int main() {
	int n;
	int cot;//������
	while (scanf("%d", &n) != EOF) {//��������
		cot = 0;//��������0
		while (n != 1) {//n������0ʱѭ��
			cot++;//����+1
			if (n % 2 == 0) {//ż������
				n = n / 2;
			}
			else {//��������
				n = 3 * n + 1;
			}
		}
		printf("%d\n", cot);//�����
	}
}