#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>


int main() {
	int a[10] = { 7,4,-3,-1,5,-6,8,2 };
	int i = 0, j = 9;//��ʼ��ǰ������
	while (i < j) {//ѭ��
		while (a[i] < 0)i++;//Ѱ�ҵ�һ����ֵ
		while (a[j] >= 0)j--;//�Ӻ���ǰ�ҵ�һ����ֵ
		if (i < j) {//����ֵ
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
	}
	for (int i = 0; i < 10; i++) {//���ֵ
		printf("%d ", a[i]);
	}
}