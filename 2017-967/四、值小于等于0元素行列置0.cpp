#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
using namespace std;

int main() {
	const int m = 5;
	const int n = 5;
	int a[m][m] = {
		11,12,13,14,15,
		21,0,23,24,25,
		31,32,33,34,35,
		41,42,43,-1,45,
		51,52,53,54,55
	};
	int col[n];//��ǵ�ǰ���Ƿ�����1Ϊ������
	int row[m];//��ǵ�ǰ���Ƿ�����1Ϊ������
	memset(col, 0, sizeof(col));
	memset(row, 0, sizeof(row));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] <=0) {
				row[i] = 1;//����ǰԪ��С�ڵ���0����ǵ�ǰ����Ϊ����״̬
				col[j] = 1;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		if (row[i] == 1) {//����ǰ�б����㣬ִ���������
			for (int j = 0; j < n; j++) {
				a[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (col[i] == 1) {//����ǰ�б����㣬ִ���������
			for (int j = 0; j < n; j++) {
				a[j][i] = 0;
			}
		}
	}
	for (int i = 0; i < m; i++) {//������������
		for (int j = 0; j < n; j++) {
			printf("%2d  ", a[i][j]);
			}
		printf("\n");
	}
}
