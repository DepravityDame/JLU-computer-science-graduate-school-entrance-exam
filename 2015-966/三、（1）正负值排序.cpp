#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>.
#include<string.h>



void sort(int a[], int n) {//��������
	int i = 0;//��ָ��
	int j = n - 1;//��ָ��
	while (i <j) {
		while (a[i] < 0)i++;//Ѱ�ҵ�һ������
		while (a[j] >= 0)j--;//����Ѱ�ҵ�һ���Ǹ�
		if (i < j) {//����
			int tmp = a[i];//��ʱ����
			a[i] = a[j];
			a[j] = tmp;
		}
	}
}

int main() {
	int a[8] = { 7,4,-1,-5,-6,3,-4,8 };
	sort(a, 8);
	for (int i = 0; i < 8; i++) {
		printf("%d ", a[i]);
	}
}