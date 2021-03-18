#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string>
#include<algorithm>
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
void preorder(tree root, int level) {//��������
	if (root == NULL) return;//����ֱ�ӷ���
	printf("data:%d level:%d\n", root->data,level);//����ڵ����ݼ�����
	preorder(root->left, level + 1);//�ݹ����������
	preorder(root->right, level + 1);//�ݹ����������
}

int main() {
	tree root=build(qx, zx);
	preorder(root,0);//��������
}