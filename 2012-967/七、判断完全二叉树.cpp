#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<queue>
#include<iostream>
using namespace std;

typedef struct Tree {
	int data;
	Tree *left;
	Tree *right;
}*tree;

string qx = "12485309";
string zx = "48251039";//ɾ��8ʱ����ȫ������

tree build(string qx, string zx) {//ǰ���򹹽�������
	if (qx.size() == 0)return NULL;
	tree root = (tree)malloc(sizeof(Tree));
	root->data = qx[0] - '0'; 
	int pos = zx.find(qx[0]);
	root->left = build(qx.substr(1, pos), zx.substr(0, pos));
	root->right = build(qx.substr(pos + 1), zx.substr(pos + 1));
	return root;
}

bool isfulltree(tree root) {
	queue<tree>node;//������α�������
	node.push(root);//���ڵ����
	while (!node.empty()) {
		tree cur = node.front();//��ǰ�ڵ����
		node.pop();
		if (cur == NULL)break;//�����ǰ�ڵ�Ϊ�գ���������ҽڵ�
		node.push(cur->left);//������ҽڵ�
		node.push(cur->right);
	}
	while (!node.empty()) {//��������ʣ��Ԫ���Ƿ�Ϊ�գ���curΪ�ռ�ڵ�ʱ�������ڶ�Ϊ�գ�˵��Ϊ��ȫ���������������л���Ԫ�����ǡ�
		if (node.front())return false;
	}
	return true;
}




int main() {
	tree root = build(qx, zx);//����������
	if (isfulltree(root))return 1;
	else return 0;
}