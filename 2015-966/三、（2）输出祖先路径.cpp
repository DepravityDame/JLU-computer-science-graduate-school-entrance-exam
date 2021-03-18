#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>.
#include<string.h>
#include<stack>
using namespace std;
typedef struct Tree {
	int data;
	Tree * left;
	Tree *right;
}*tree;

typedef struct jd{
	tree treep;
	int num;
	jd(tree t, int n) :treep(t), num(n) {};
};
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






void count(tree root,int x) {//����˼�룬���÷ǵݹ�������������ҵ��ڵ�ʱ��ջ��Ԫ�ؼ�Ϊ�����ȡ�ʱ�临�Ӷ�O(n);
	stack<jd>s;//����ջ���зǵݹ��������
	s.push(jd(root, 0));//���ڵ���ջ
	while (!s.empty()) {//ջ�ɿ�ѭ��
		jd c = s.top();//ջ���ڵ��ջ
		s.pop();
		if (c.treep->data == x) {//����ڵ�ǰ�ڵ�
			s.push(jd(c.treep, 0));
			break;
		}
		if (c.num == 0) {//��һ�α�������ջ
			s.push(jd(c.treep, 1));
			if (c.treep->left != NULL) {//����������Ϊ������ջ
				s.push(jd(c.treep->left, 0));
			}
		}
		if (c.num == 1) {
			s.push(jd(c.treep, 2));//�ڶ��α�������ջ
			if (c.treep->right != NULL) {//����������Ϊ������ջ
				s.push(jd(c.treep->right, 0));
			}
		}
	}
	while (!s.empty()) {//���ջ��Ԫ��
		printf("%d ", s.top().treep->data);
		s.pop();
	}
}

int main() {
	tree root = build(qx, zx);//����������
	count(root,8);
}