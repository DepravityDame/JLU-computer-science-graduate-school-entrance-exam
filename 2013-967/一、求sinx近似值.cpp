#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<queue>
#include<iostream>
using namespace std;

void Sin(double x) {
	double sum = 0.0;//sinֵ
	double tmp = x;//����
	int n = 1;
	while (fabs(tmp) > 1e-8){//�ж��Ƿ�ﵽ����
		sum += tmp;//�ۼ�
		tmp = -tmp*x*x/ (n + 1) / (n + 2);//�������һ��
		n+=2;
	}
	printf("%lf\n", sum);
}





int main() {
	double x;
	while (scanf("%lf", &x) != EOF) {//����Xֵ
		Sin(x);
	}
}