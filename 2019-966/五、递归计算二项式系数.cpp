#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<iostream>
#include<string>
#include<stdlib.h>

int xs(int n,int k) {//�������ʽϵ����k����n��������k��2
	if (k == 0 && n == k)return 1;//C00���
	if (k == 0)return 2 * xs(n - 1, k);//Cn0���
	if (k == n)return 3* xs(n - 1, k - 1);//Cnn���
	else return 2 * xs(n - 1, k) + 3 * xs(n - 1, k - 1);//Cnk���ʹ�ù�ʽCnk=Cn-1 k-1+Cn-1 k;
}


int main() {
	int n,k;
	while (scanf("%d %d", &n,&k) != EOF) {
		printf("%d\n", xs(n,k));//�������ʽϵ��
	}
}