#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<string>

double pai() {
	int i = 1;//��ĸ����
	double tmp = 1;//ÿ��ֵ
	double ans=0;//��
	while (fabs(tmp) > 1e-5) {//����δ�ﵽ��ѭ��
		ans += tmp;//�ۼ�
		i++;//���·�ĸ����
		if (i % 2 != 0) {//������Ϊ����ż����Ϊ��
			tmp = 1.0/ (2 * i - 1);
		}
		else {
			tmp = -1.0 / (2 * i - 1);
		}
		
	}
	return ans * 4;//����У�Ҫ���ݹ�ʽ��4
}


int main() {
	printf("%lf", pai());
}