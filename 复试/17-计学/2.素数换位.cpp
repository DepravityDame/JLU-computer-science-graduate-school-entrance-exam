#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>

bool isprime(int n) {//�ж��Ƿ�������
	if (n < 2)return false;
	else {
		for (int i = 2; i <= n / 2; i++) {
			if (n%i == 0)return false;
		}
	}
	return true;
}


void sort(int a[], int n) {//��������
	int i = 0;//ǰָ��
	int j = n - 1;//��ָ��
	while (i < j) {//iָ��δ�غ�ʱѭ��
		while (isprime(a[i]))i++;//Ѱ�ҵ�һ������
		while (!isprime(a[j]))j--;//����Ѱ�ҵ�һ��������
		if (i < j) {//���i<j�����
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
	}
}



int main() {
	int a[10] = { 7,4,2,8,5,1,6,3,9,0 };//��������
	sort(a,10);
	for (int i = 0; i < 10; i++) {//������
		printf("%d ", a[i]);
	}
	printf("\n");
}