#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stack>
using namespace std;

void sort(int a[], int n) {
	int i = 0;//ͷָ��
	int j = n - 1;//βָ��
	while (i < j) {//ѭ��
		while (a[i] < 0)i++;//���ҵ�һ������
		while (a[j] >= 0)j--;//������ҵ�һ������
		if (i < j) {//��λ
			int tmp;
			tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
	}
}



int main() {
	const int n = 8;
	int a[n] = { 7,4,2,-1,3,-2,-8,1 };
	sort(a, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}