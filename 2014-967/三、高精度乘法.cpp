#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<queue>
#include<iostream>
using namespace std;

int main() {
	int a[100];//������
	int b[100];//����
	int c[100];//���
	int m, n;
	int l1 = 0, l2 = 0;

	while (scanf("%d %d", &m, &n) != EOF) {//�������������
		memset(a, 0, sizeof(a));//��ʼ��������Ϊ0
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		while (m != 0) {
			a[l1++] = m % 10;//�����λ
			m = m / 10;
		}
		while (n != 0) {
			b[l2++] = n % 10;//�����λ
			n = n / 10;
		}
		for (int i = 0; i <l1; i++) {//��λ���
			for (int j = 0; j < l2; j++) {
				c[i + j] += a[i] * b[j];
			}
		}
		for (int i = 0; i < l1+l2; i++) {//�Գ���10��λ���н�λ
			if (c[i] >= 10) {
				c[i + 1] += c[i] / 10;//��λ
				c[i] = c[i] % 10;//��λ��ʣ��
			}
		}
		int k = l1 + l2;//���������󲻳�������λ����
		while (c[k] == 0) { k--; }//ȥ������0λ
		while (k!=-1) {//������
			printf("%d",c[k--]);
		}
	}
}