#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

void add(int a[], int n) {
	int i = n - 1;
	while (a[i] == 1) {//����������1�����0�������ĵ�һ��0�����1��
		a[i] = 0;
		i--;
	}
	if (i != -1) {//�ж�λ���Ƿ���Ҫ����
		a[i] = 1;
	}
	else {
		for (int i = 1; i <= n; i++) {//������Ԫ��ȫΪ1����һ������һλ
			a[i] = 0;
		}
		a[0] = 1;//��λ��Ԫ��Ϊ1
		n++;//���鳤��+1
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);//�������
	}
	printf("\n");
}




int main() {
	int a[5] = { 1,1,1,1 };
	add(a, 4);
}