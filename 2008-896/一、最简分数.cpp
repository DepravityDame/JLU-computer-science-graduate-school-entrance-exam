#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>

using namespace std;

int gys(int m, int n) {//��m,n���Լ��
	if (m%n == 0)return n;
	else return gys(n, m%n);
}

int main() {
	int m, n;
	scanf("%d %d", &m, &n);//������ӷ�ĸ
	printf("%d/%d", m / gys(m, n), n / gys(m, n));//���������
}