#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;



int main() {
	int a[20][10];//��������
	for (int i = 0; i < 20; i++) {//����ѭ����������
		for (int j = 0; j < 10; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	double sum = 0;//����˫�����������
	for (int i = 0; i < 20; i++) {//�ۼ����ұ�
		sum += a[i][0] + a[i][9];
	}
	for (int j = 1; j < 9; j++) {//�ۼ����±ߣ���1��9��Ϊ�����������ϱ��Ѿ������һ��
		sum += a[0][j] + a[19][j];
	}
	sum = sum / 56;//��ƽ����
	printf("%lf", sum);//���
}