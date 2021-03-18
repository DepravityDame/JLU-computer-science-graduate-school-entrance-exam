#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
using namespace std;

bool judge(char str[], double x) {
	double ans = 0.0;
	int len = strlen(str);//��ȡ�ַ�������
	int pos=0;//��λС����
	for (int i = 0; i < len; i++) {
		if (!((str[i] >= '0'&&str[i] <= '9') || str[i] == '.')) {//��������ֺ�С������ֱ�ӷ���false
			return false;
		}
		else if (str[i] >= '0'&&str[i] <= '9') {//�������֣����¼�Ȳ�����С����
			ans = ans * 10 + str[i]-'0';
		}
		if (str[i] == '.') {//��λС����
			pos = i;
		}
	}
	ans = ans / pow(10, len-pos-1);//����С������Ҫ������
	if (ans > x)return true;//���ans��x�󣬷���true
	else return false;//���򷵻�false
}


int main() {
	char str[100];
	double x;
	while (scanf("%s", str) != EOF) {
		scanf("%lf", &x);
		printf("%d\n", judge(str, x));
	}
}

