#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<stack>


const int m = 5;
const int n = 5;

int main() {//���⼴�����������������
	int a[m][n] = {
		76,47,29,77,2,79,25,61,65,91,87,28,46,41,71,0,90,77,21,53,42,15,87,8,92
	};
	for (int i = 0; i < m*n - 1; i++) {//��ά������������һά�������棬�̵���һά�������ð������
		for (int j = i + 1; j < m*n; j++) {//ð���������
			if (a[0][i] > a[0][j]) {
				int tmp = a[0][i];
				a[0][i] = a[0][j];
				a[0][j] = tmp;
			}
		}
	}
	for (int i = 0; i < m; i++) {//������������
		for (int j = 0; j < n; j++) {
			printf("%3d ", a[i][j]);
		}
		printf("\n"); 
	}
}

