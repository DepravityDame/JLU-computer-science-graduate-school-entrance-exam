#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

bool fun(int a[], int n) {
	int sum = 0;//��¼ǰi-1���ܺ�
	for (int i = 0; i < n; i++) {
		if (a[i] == sum)return 1;//�Ƚ�ǰi-1��͵�ǰ������return 1
		sum += a[i];//�ۼӵ�ǰ��
	}
	return 0;
}

int main() {
	const int n=8;
	int a[n] = { 1,2,4,8,15,20,38,43 };//��������
	printf("%d\n",fun(a, 8));

}

