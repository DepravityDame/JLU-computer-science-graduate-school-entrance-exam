#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<algorithm>
using namespace std;

void ysh(int n) {
	int flag = 1;//�׸�����ǰ�޼Ӻ�
	int sum = 0;//��¼Լ����
	for (int i = 1; i <=n; i++) {
		if (n%i == 0) {
			sum += i;//Լ�����ۼ�
			if (flag == 1) {//���Լ��
				printf("%d", i);
				flag = 0;
			}
			else {
				printf("+%d", i);
			}
		}
	}
	printf("=%d\n",sum);//���Լ����
}



int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		ysh(n);
	}
}