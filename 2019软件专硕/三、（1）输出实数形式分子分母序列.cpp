#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;

int main() {
	int fz = 2;//����
	int fm = 1;//��ĸ
	int tmp;
	int n = 20;
	while (n--) {//��������
		printf("%d/%d ", fz, fm);//�����
		tmp = fm + fz;//��ʱ�������+��ĸ
		fm = fz;//fm������һ�����
		fz = tmp;//fz������һ���ĸ�ӷ���
	}
}