#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<queue>
#include<iostream>
using namespace std;

typedef struct Tree {
	int data;
	Tree *left;
	Tree *right;
}*tree;

string qx = "12485309";
string zx = "84251039";

tree build(string qx, string zx) {//ǰ���򹹽�������
	if (qx.size() == 0)return NULL;
	tree root = (tree)malloc(sizeof(Tree));
	root->data = qx[0] - '0';
	int pos = zx.find(qx[0]);
	root->left = build(qx.substr(1, pos), zx.substr(0, pos));
	root->right = build(qx.substr(pos + 1), zx.substr(pos + 1));
	return root;
}

int Width(tree root) {
	queue<tree>q;//����ڵ�ջ
	int widthmax = 0;//���������
	q.push(root);//���ڵ���ջ
	while (!q.empty()) {
		int width = q.size();//���浱ǰ���
		if (width > widthmax) {//�����ǰ��ȴ�������ȣ����¼
			widthmax = width;
		}
		while (width--) { //width��ʾ����ڵ�������ǰ�����ڵ�ȫ��������������ʣ��ļ�Ϊ��һ��ڵ���Ŀ
			tree cur = q.front();//��ǰ�ڵ���ӷ���
			q.pop();
			if (cur->left != NULL) {//�����Ӵ��������
				q.push(cur->left);
			}
			if (cur->right != NULL) {//���Һ��Ӵ��������
				q.push(cur->right);
			}
		}
	}
	return widthmax;//���������
}



int main() {
	tree root = build(qx, zx);//����������
	printf("%d\n",Width(root));
}