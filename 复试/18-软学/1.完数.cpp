#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>

bool isfullnum(int n) {//��������
	int sum = 0;//����Լ����
	for (int i = 1; i < n; i++) {
		if (n%i == 0) {//����������Լ��
			sum += i;//�ۼ�
		}
	}
	if (sum == n) {//�����Լ�����ڱ�����������
		return true;
	}
	else {
		return false;//������
	}
}

int main() {
	for (int i = 1; i < 1000; i++) {//����1-1000������
		if (isfullnum(i)) {//�ж��Ƿ�������
			printf("%d ", i);
		}
	}
}