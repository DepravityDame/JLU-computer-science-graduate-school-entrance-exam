#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<algorithm>
using namespace std;
int main() {//��Ŀδ����������������100���
	long long a[101];//���������
	a[1] = 1;//��ʼ����һλ�ڶ�λ
	a[2] = 2;
	for (int i = 3; i <= 100; i++) {
		if (i % 2 != 0) {//��������
			a[i] = a[i - 1] + a[i - 2];
		}
		else {//ż������
			a[i] = a[i - 1] - a[i - 2];
		}
	}
	sort(a+1, a + 101, less<long long>());//��������
	for (int i = 1; i <= 100; i++) {//������
		printf("%lld ", a[i]);
	}
}