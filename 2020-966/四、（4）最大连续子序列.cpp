#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int MAXN = 100;
int max(int a, int b) {//�����߽ϴ��
	if (a > b)return a;
	else return b;
}
int main() {
	int a[10] = { 7,1,2,3,-5,6,4,-8,0,2};//test arr
	int dp[10];//dp���飬dp[i]��ʾ��
	memset(dp, 0, sizeof(dp));//��ʼ��dp����
	int Max = 0;//�������ֵ
	int tmp = 0;
	int head=0, tail=0;
	for (int i = 0; i < 10; i++) {//��������
		if (i == 0) {
			dp[i] = a[i];//��ʼ����һ��dpԪ��
		}
		else {
			if (dp[i - 1] + a[i] < a[i]) {//�����ǰ�ڵ��֮ǰ���кʹ�
				dp[i] = a[i];//dp[i]����Ϊ��ǰ�ڵ�
				head = i;//��¼ͷ�ڵ�
			}
			else {
				dp[i] = dp[i - 1] + a[i];//����ϴ˽ڵ��dp[i]������ۼ�
			}
		}
		if (dp[i] > Max) {//�жϵ�ǰ�������кͺ���������кʹ�С
			Max = dp[i];//�����ǰ���򴢴�ΪMax
			tail = i;//���Ϊβ�ڵ�
		}
	}
	printf("��ʼ�ڣ�%d ��ֹ�ڣ�%d Ԫ�ظ�����%d\n", head,tail,tail-head+1);//���Ԫ�ظ���
	for (int i = head; i <= tail; i++) {//������������
		printf("%d ", a[i]);
	}
}