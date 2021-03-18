#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;

double sin(double x) {
	double sum = 0;//��ʼ��sum�����
	double tmp = x;//ÿ��ֵ
	int n = 1;//�仯�ı����
	while (fabs(tmp) > 1e-5) {
		sum += tmp;//�ۼ�
		tmp = -tmp * x*x / (n + 1) / (n + 2);//����ÿ��ֵ
		n+=2;//����n
	}
	return sum;//���ش�
}
int main() {
	double x;
	while (scanf("%lf", &x) != EOF) {
		printf("%lf",sin(x));//���ú���
	}
}