#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;

int main() {
	char str[100];
	int cot;//�㴮���ȱ���
	int totalcot;//�㴮�ַ�����
	while (scanf("%s", str) != EOF) {
		cot = 0;//��������
		totalcot = 0;//�㴮����
		for (int i = 0; i < strlen(str); i++) {//�����ַ���
			while (str[i] == '0') {//����0������
				cot++;//��������++
				i++;//i����
			}
			if (cot > 1){//��ǰ���㴮
			totalcot++;//�㴮����++
			}
			cot = 0;//�㴮����������������
		}
		if (totalcot >= 2) {//�㴮�������ڵ���2������Ҫ��
			printf("1\n");

		}
		else printf("0\n");
	}
}