#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int main() {
	int n;
	int a[10];//����ÿλ����
	int k = 0;//��������λ��
	while (scanf("%d", &n) != EOF) {//����������
		k = 0;
		while (n != 0) {
			a[k++] = n % 10;
			n = n / 10;
		}
		sort(a, a + k, greater<int>());//���������ֽ�������
		for (int i = 0; i < k; i++) {//�����
			printf("%d", a[i]);
		}
		printf("\n");
	}
	
}