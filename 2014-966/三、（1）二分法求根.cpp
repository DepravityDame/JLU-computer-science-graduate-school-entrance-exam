#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<math.h>

double f(double x) {
	return x * x*x - x * x - 1;
}

int main() {
	double a, b, mid;//�������ҽ��ޣ���ֵ
	a = 0; b = 3;//��ʼ�����ҽ���
	mid = (a + b / 2);//��ʼ����ֵ
	while (fabs(f(mid)) > 1e-4) {//�Ա���ֵ�ĺ���ֵ�Ƿ�ﵽ����
		if (f(mid)*f(a) > 0) {//���������ͬ�ţ�����޸���Ϊmid
			a = mid;
		}
		else {
			b = mid;//�����ҽ���ͬ�ţ��ҽ��޸���Ϊmid
		}
		mid = (a + b) / 2;//���¼�����ֵ
	}
	printf("%lf\n", mid);//�����
}