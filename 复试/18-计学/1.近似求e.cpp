#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main() {//��������

	double ans = 1;//��ʼ����Ϊ1
	int n = 1;//��ʼ����ĸ����
	double tmp = 1;//��ʼ��ÿ��
	while (tmp > 1e-5) {//��ǰ��û�ﵽ����1e-5��ѭ��
		ans += tmp;//�ۼ�
		tmp = tmp*1.0 / ++n;//�׳�ֻ����ǰһ������ٳ���n����
	}
	printf("%lf", ans);//�����

}