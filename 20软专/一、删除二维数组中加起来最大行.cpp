#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<algorithm>
#include<map>
using namespace std;

int main() {
	const int n = 5;
	const int m = 5;
	int a[n][m] = {//ԭʼ����
		5,7,8,8,38,
		41,14,37,39,37,
		48,32,46,17,30,
		50,41,28,9,6,
		0,42,10,29,42
	};
	int max[n];
	memset(max, 0, sizeof(max));//��ʼ���кʹ�������
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			max[i] += a[i][j];//�����к�
		}
	}
	int maxi,Max=0;
	for (int i = 0; i < n; i++) {
		if (max[i] > Max) {//Ѱ�������
			Max = max[i];
			maxi = i;//��¼���������
		}
	}
	for (int i = maxi; i < n; i++) {//�ñ���������н��串��
		for (int j = 0; j < m; j++) {
			a[i][j] = a[i + 1][j];
		}
	}
	for (int i = 0; i < n-1; i++) {//������
		for (int j = 0; j < m; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}