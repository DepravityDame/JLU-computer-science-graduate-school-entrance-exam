#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<math.h>
#include<stack>
using namespace std;

int main() {
	char str[100];//�����ַ���
	stack<char>s;//����ջ
	while (scanf("%s", str) != EOF) {//�����ַ���
		for (int i = 0; str[i] != '\0'; i++) {//�����ַ���
			if (str[i] == '+' || str[i] == '*') {//�������Ϊ+��*ѹջ
				s.push(str[i]);
			}
			else if (str[i] == ')') {//����������ʱԭ������������ջ�����ţ�ջ�����ų�ջ
				printf("%c", str[i]);
				printf("%c", s.top());
				s.pop();
			}
			else {
				printf("%c", str[i]);//�����ַ�ԭ�����
			}
		}
	}
}

//test data
//+(*(a, +(a, a)), a)