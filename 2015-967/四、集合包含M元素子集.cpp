#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<math.h>
int main() {
	const int n = 4;
	int a[n] = { 1,2,3,4 };
	int b[n] = { 0 };
	int x;
	scanf("%d", &x);
	for (int i = 0; i < pow(2, n); i++) {//һ��2^n�����
		int cot = 0;//ͳ�Ƶ�ǰѡ��Ԫ����
		b[0]++;//����������+1
		for (int j = 0; j < n - 1;j++) {//������������飬��2�Ľ�λ
			b[j + 1] += b[j] / 2;
			b[j] = b[j] % 2;
		}
		for (int j = 0; j < n; j++) {//�жϵ�ǰ����������ѡ��Ԫ�ظ���
			if (b[j] == 1)cot++;
		}
		if (cot == x) {//��ǰ����ѡ��Ԫ�ظ�������Ҫ���򰴸�ʽ���
			printf("{ ");
			for (int j = 0; j < n; j++) {
				if (b[j] == 1)printf("%d ", a[j]);
			}
			printf("}");
		}
	}
}