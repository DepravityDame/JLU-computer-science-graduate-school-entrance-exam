#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<algorithm>
using namespace std;
int main() {
	int a[4];
	int max;
	int min;
	int n;
	int k = 0;
	while (scanf("%d", &n) != EOF) {//��������
		while (n != 6174) {//����������ѭ��
			min = max = 0;
			k = 0;
			for (int i = 0; i < 4; i++) {//ȡ��λ����
				a[k++]= n % 10;
				n = n / 10;
			}
			sort(a, a + 4, less<int>());//��������
			for (int i = 0; i < 4; i++) {//���¹���max��min
				min = min * 10 + a[i];
				max = max * 10 + a[3 - i];
			}
			n = max - min;//����n
			printf("max:%d min:%d n:%d\n", max, min,n);//��ʽ���
			
		}
	}
}