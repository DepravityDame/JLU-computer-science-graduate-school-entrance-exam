#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int jqh(int a[], int n) {
	int i = 0;//��ָ��
	int j = n - 1;//��ָ��
	int sum=0;//��Ȩ��
	int k = 1;//Ȩ��
	while (i <=j) {//ʹ��̰���㷨ÿ��Ѱ�ҵ�ǰ��С��ȥ��Ȩ��
		if (a[i] > a[j]) {//�Ҷ����ֽ�С
			sum += a[j] *( k++);
			j--;
		}
		else {
			sum += a[i] * (k++);//������ֽ�С
			i++;
		}

	}
	return sum;//���ؼ�Ȩ��
}



int main() {
	int a[8] = { 7,4,5,3,2,8,9,6 };
	printf("%d\n",jqh(a, 8));
}