#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
using namespace std;

bool isshowonce(int f[], int size, int n) {
	bool *visit = new bool[size];//��������
	memset(visit, 0, sizeof(bool)*size);//��ʼ��
	for (int i = 0; i < size; i++) {//������������ϳ�������
		int num = 0;//��ʼ��Ϊ0
		for (int j = 0; j < n; j++) {
			num = num * 2 + f[(i + j) % size];//�������㵱ǰnλ����ʾ������
		}
		if (visit[num]) {//����ǰ�����Ѿ�����ʾ��
			delete[]visit;//�����ظ����ͷ�visit����
			return false;//����flase
		}
		else {
			visit[num] =true;//��ǵ�ǰ����Ϊ�ѷ���
		}
	}
	delete[]visit;//�ͷű������
	return true;//����true
}

void fun(int n) {
	const int MAXN = pow(2, n);//����nλ���������
	int *f = new int[MAXN];//��������������
	memset(f, 0, sizeof(int)*MAXN);//��ʼ��Ϊ0
	while (1) {//ѭ��
		int j = 0;//������������飬ִ��+1����
		while (f[j] == 1) {
			f[j++] = 0;
		}
		f[j] = 1;
		if (isshowonce(f, MAXN, n) == true) {//�����ǰ������������
			for (int i = 0; i < MAXN; i++) {
				printf("%d ", f[i]);//�����ǰ����
			}
			return;//����ѭ��
		}
	}
}


int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		fun(n);
	}
}