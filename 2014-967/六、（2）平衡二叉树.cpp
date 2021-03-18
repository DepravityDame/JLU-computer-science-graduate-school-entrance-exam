#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

typedef struct Tree {
	int data;
	Tree *left;
	Tree *right;
}*tree;

int abs(int a) {
	if (a < 0)return -a;
	else return a;
}

string qx = "124875309";
string zx = "784251039";

tree build(string qx, string zx) {//ǰ���򹹽�������
	if (qx.size() == 0)return NULL;
	tree root = (tree)malloc(sizeof(Tree));
	root->data = qx[0] - '0';
	int pos = zx.find(qx[0]);
	root->left = build(qx.substr(1, pos), zx.substr(0, pos));
	root->right = build(qx.substr(pos + 1), zx.substr(pos + 1));
	return root;
}

int getdeep(tree root) {//��ȡ�����
	if (root == NULL)return 0;//�ռ��Ϊ0
	else {
		return max(getdeep(root->left), getdeep(root->right)) + 1;//�������ҽڵ��������+1���ǵ�ǰ�ڵ����
	}
}


bool isbalance(tree root) {
	if (root == NULL)return true;//�սڵ�Ҳ��ƽ�������
	else {
		if (abs(getdeep(root->right)- getdeep(root->left)) > 1) {//�ж����������߶Ȳ��Ƿ񳬹�һ
			return false;
		}
	}
	return isbalance(root->left) && isbalance(root->right);//�ݹ��жϵ�ǰ�ڵ���������
}

int main() {
	tree root = build(qx, zx);//����������
	if (isbalance(root)) { printf("YES\n"); }
	else {
		printf("NO\n");
	}
}