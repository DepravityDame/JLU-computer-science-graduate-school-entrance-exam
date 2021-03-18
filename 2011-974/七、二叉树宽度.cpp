#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<math.h>
#include<queue>
using namespace std;

typedef struct Tree {
	int data;
	Tree *left;
	Tree *right;
}*tree;


int width(tree root) {//��������
	int maxwidth = 0;//���������
	queue<tree>q;//�����α����ڵ�
	q.push(root);//���ڵ����
	while (!q.empty()) {
		int wid = q.size();//��¼��ǰ��ڵ���Ŀ
		if (wid > maxwidth)maxwidth = wid;//���ִ����ֵ�Ƚ�
		while (wid--) {//��ǰ�������ӽڵ����
			tree cur = q.front();
			q.pop();
			if (cur->left != NULL) {
				q.push(cur->left);
			}
			if (cur->right != NULL) {
				q.push(cur->right);
			}
		}
	}
	return maxwidth;//���������
}

string qx = "1248530";
string zx = "8425103";

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
	printf("%d\n",width(root));
}