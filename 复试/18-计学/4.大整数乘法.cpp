#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
using namespace std;




int main() {
	char a[100];
	char b[100];
	scanf("%s %s", a, b);
	int l1 = strlen(a);
	int l2 = strlen(b);
	reverse(a, a + l1);//��ת�ַ���������λ����ǰ
	reverse(b, b + l2);//��ת�ַ���������λ����ǰ
	int *ans = new int[l1+l2];//�����˻������ܳ�������λ����
	memset(ans, 0, sizeof(int)*(l1 + l2));//��ʼ��Ϊ0
	for (int i = 0; i < l1; i++) {//��λ���
		for (int j = 0; j < l2; j++) {
			ans[i + j] += (a[i]-'0') * (b[j]-'0');
		}
	}
	for (int i = 0; i < l1 + l2; i++) {//�Գ���10�����������λ
		if (ans[i] > 10) {
			ans[i + 1] += ans[i] / 10;//��λ
			ans[i] = ans[i] % 10;//ȡ�ౣ���ڵ�ǰλ��
		}
	}
	int k;
	for (int i = l1 + l2-1; i >= 0; i--) {//ɾ����ǰ��0Ԫ��
		if (ans[i] != 0) {
			k = i;//��¼��λλ��
			break;
		}
	}
	for (int i =k; i >=0; i--) {//������
		printf("%d", ans[i]);
	}
}