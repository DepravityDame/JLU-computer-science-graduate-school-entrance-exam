#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
using namespace std;


int main() {
	int a[10] = { 1,2,2,3,3,3,4,4,4,4 };
	int i = 0;
	int max = 0;//���ƽ̨��
	int cot = 1;//ƽ̨��������
	int key = a[0];//���õ�һ����Ϊkey
	for (int i = 1; i <10; i++) {
		if (a[i] == key) {//����ǰ����ƽ̨key��ȣ���cot++��
			cot++;
		}
		else {
			if (cot > max)max = cot;//�����ǰcot����max���������ƽ̨��
			key = a[i];//����key
			cot = 1;
		}
	}
	if (cot > max)max = cot;//�������һλҲ��ƽ̨����δ�ܸ��µ�max��
	printf("%d", max);
	return 0;
}