#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stack>
using namespace std;
typedef struct Tree {
	int data;
	Tree *left;
	Tree *right;
}*tree;

tree build(char * str) {//����ʹ��ջ�ṹ������ݹ�
	int i = 0;
	int len = strlen(str);
	stack<tree>s;
	while (i < len) {
		if (str[i] == '0') {//0ʱ��Ҷ�ӽ�㣬���������������ÿգ���ջ
			tree p = (tree)malloc(sizeof(Tree));
			p->left = NULL;
			p->right = NULL;
			s.push(p);
		
		}
		else if (str[i] == '1') {//1ʱ�������ӣ�������������������ջ��Ԫ�أ��������ÿգ���ջ
			tree p = (tree)malloc(sizeof(Tree));
			p->left = s.top();
			s.pop();
			p->right = NULL;
			s.push(p);
		}
		else if (str[i] == '2') {//2ʱ�������ӣ�������������������������ջ��Ԫ�أ���ջ
			tree p = (tree)malloc(sizeof(Tree));
			p->left = s.top();
			s.pop();
			p->right = s.top();
			s.pop();
			s.push(p);
		}
		i++;
	}
	return s.top();//�ַ����������ջ��Ԫ�ؼ�Ϊ���ڵ㣬����
}

void rev(char str[]) {
	reverse(str, str + strlen(str));//��ת�ַ���
}


int main() {
	char str[100];
	while (scanf("%s", str) != EOF) {
		rev(str);
		build(str);
	}
}