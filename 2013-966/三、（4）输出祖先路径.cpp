#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<stack>
using namespace std;

typedef struct Tree {
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

typedef struct jd {//�����������������ṹ��
	tree treep;
	int num;
	jd(tree t, int i) :treep(t), num(i) {}
};

void find(tree root,int x) {
	stack<jd>mystk;//������ջ
	mystk.push(jd(root, 0));//���ڵ���ջ
	while (!mystk.empty()) {//ջ�ɿ�ʱѭ��
		jd c = mystk.top();//ջ���ڵ��ջ
		mystk.pop();
		if (c.treep->data == x) {//�����ǰ�ڵ����Ҫ���ҽڵ㣬��ǰ�ڵ���ջ���˳�ѭ��
			mystk.push(jd(c.treep, 0));
			break;
		}
		if (c.num == 0) {//��һ�α������ýڵ�
			mystk.push(jd(c.treep, 1));//��ջ�����1
			if (c.treep->left != NULL) {//������������գ���������ջ
				mystk.push(jd(c.treep->left, 0));
			}
		}
		else if (c.num == 1) {//�ڶ��α������ýڵ�
			mystk.push(jd(c.treep, 2));//��ջ�����2
			if (c.treep->right != NULL) {//���������գ���������ջ
				mystk.push(jd(c.treep->right, 0));
			}
		}
	}
	while (!mystk.empty()) {//���ջ��Ԫ��
		printf("%d ", mystk.top().treep->data);
		mystk.pop();
	}
	
	


}




int main() {
	tree root = build(qx, zx);//����������
	find(root, 7);
}