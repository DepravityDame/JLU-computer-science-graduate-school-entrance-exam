#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
using namespace std;

typedef struct Tree {
	int data;
	Tree *left;
	Tree *right;
}*tree; 

bool judge(tree a, tree b) {
	if (!a && !b) {//ab��Ϊ�գ���Գ�
		return true;
	}
	else if (!a || !b) {//ab��һ�������򲻶Գ�
		return false;
	}
	if (a->data == b->data) {//ab��ȣ��ݹ�a��������b����������a��������b��������
		return judge(a->left, b->right)&&judge( a->right,b->left);
	}
	return false;
}

bool fun(tree root) {//�жϺ���
	if (!root) {//���Ϊ��������true
		return true;
	}
	return judge(root->left, root-> right);//�ݹ��ж���������
}
string qx = "1234243";
string zx = "3241423";

tree build(string qx, string zx) {//ǰ���򹹽�������
	if (qx.size() == 0)return NULL;
	tree root = (tree)malloc(sizeof(Tree));
	root->data = qx[0] - '0';
	int pos = zx.find(qx[0]);
	root->left = build(qx.substr(1, pos), zx.substr(0, pos));
	root->right = build(qx.substr(pos + 1), zx.substr(pos + 1));
	return root;
}





int main() {
	tree root = build(qx, zx);//����������
	printf("%d",fun(root));
	
}