#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

void bj(int a[], int m, int b[], int n) {//�󲢼�������
	int max;//���泤�����ֵ
	if (m > n) {
		max = m;
	}
	else max = n;
	int *ans = new int[max];//��������Ԫ�ش�СΪ��������Ԫ�ؽ϶��Ǹ�
	memset(ans, 0, sizeof(ans));//��ʼ��������Ϊ0
	for (int i = 0; i < m; i++) {
		ans[i] = a[i];//������1д�������
	}
	for (int i = 0; i < n; i++) {//������������
		if (ans[i] or b[i]) {
			ans[i] = 1;
		}
		else ans[i] = 0;
	}
	for (int i = 0; i < max; i++) {//�����
		printf("%d ", ans[i]);
	}
}

void jj(int a[], int m,int b[], int n) {//�󽻼�
	int min;//�������ϳ��Ƚ�С��
	if (m > n) {
		min = n;
	}
	else {
		min = m;
	}
	int *ans = new int[min];//�½���������
	memset(ans, 0, sizeof(ans));//��ʼ����������
	for (int i = 0; i < min; i++) {//a,b����������
		ans[i] = a[i] && b[i];
	}
	for (int i = 0; i < min; i++) {
		printf("%d ", ans[i]);//�����
	}
}

int main() {
	int a[9] = { 0,0,0,1,1,0,1,0,1 };
	int b[7] = { 0,0,1,1,1,1,1 };
	 bj(a, 9, b, 7);
	 printf("\n");
	 jj(a, 9, b, 7);
}