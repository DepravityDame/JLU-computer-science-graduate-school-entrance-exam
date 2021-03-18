#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

typedef struct Tree {//����������ṹ
	int data;
	Tree *left;
	Tree *right;
}*tree;

string qx = "1243567";
string zx = "2413657";

tree build(string qx, string zx) {//ǰ���򹹽�������
	if (qx.size() == 0)return NULL;
	tree root = (tree)malloc(sizeof(Tree));
	root->data = qx[0] - '0';
	int pos = zx.find(qx[0]);
	root->left = build(qx.substr(1, pos), zx.substr(0, pos));
	root->right = build(qx.substr(pos + 1), zx.substr(pos + 1));
	return root;
}

void revlevel(tree root) {//�������� �����൱�ڷ����α�������α������ʱ��ջ�������ջ��Ԫ�ؼ���
	queue<tree>q;//��������q
	stack<int>s;//����ջs
	q.push(root);//���ڵ����
	while (!q.empty()) {//q�ǿ�ʱѭ��
		tree cur = q.front();//ȡ��ͷ�ڵ�
		s.push(cur->data);//��ջ
		q.pop();
		if (cur->left != NULL) {//��������Ϊ�����
			q.push(cur->left);
		}
		if (cur->right != NULL) {//��������Ϊ�����
			q.push(cur->right);
		}
	}
	while (!s.empty()) {//���ջ��Ԫ��
		printf("%d ", s.top());
		s.pop();
	}
}



int main() {
	tree root = build(qx, zx);//����������
	revlevel(root);
}