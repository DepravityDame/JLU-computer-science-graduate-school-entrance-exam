#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
using namespace std;

int insert(int a[], int x, int n) {
	int i=0;
	while (a[i] < x&&i < n)i++;//Ѱ�Ҳ���λ��
	if (a[i] == x)return n;//��ͬԪ������
	else {
		for (int j =n-1; j >=i; j--) {//��Ԫ�غ���
			a[j + 1] = a[j];
		}
		a[i] = x;//����ֵ
	}
	return n + 1;//���ظ���
}


int main() {
	int a[100] = { 1,5,13,8,25,60,75,81 };
	int x;
	int n = 8;
	while (scanf("%d", &x) != EOF) {
		n=insert(a, x,n);
		for (int i = 0; i < n; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
	}

}