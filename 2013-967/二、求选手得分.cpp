#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<queue>
#include<iostream>
using namespace std;

int main() {
	int a[10];
	int max = 0;//��ʼ����Сֵ
	int min = 999;//��ʼ�����ֵ
	double sum = 0;//��ʼ���ܷ�
	for (int i = 0; i < 10; i++) {
		scanf("%d", &a[i]);
		sum += a[i];//��¼�ܷ�
		if (max < a[i])max = a[i];//��¼�����Сֵ
		if (min > a[i])min = a[i];
	}
	printf("%.3lf", (sum - max - min) / 8);//�ܺ�ȥ����߷�ȥ����ͷֳ�8
	
}