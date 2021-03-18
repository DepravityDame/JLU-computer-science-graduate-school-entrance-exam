#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;
typedef struct Tree {
	int data;
	Tree *left;
	Tree *right;
}*tree;

string qx = "64215879";
string zx = "12456789";

tree build(string qx, string zx) {//ǰ���򹹽�������
	if (qx.size() == 0)return NULL;
	tree root = (tree)malloc(sizeof(Tree));
	root->data = qx[0] - '0';
	int pos = zx.find(qx[0]);
	root->left = build(qx.substr(1, pos), zx.substr(0, pos));
	root->right = build(qx.substr(pos + 1), zx.substr(pos + 1));
	return root;
}
void del(tree root,tree father, int x) {//xΪ����ֵ��fatherΪ���ڵ�
	if (root->data == x) {//�ҵ���ǰ�ڵ�
		if (root->left == NULL && root->right == NULL) {//����ǰ�ڵ����Ҷ�Ϊ�գ�ֱ��ɾ��//��ڵ��Ӧָ����NULL
			if (father->left == root) {
				father->left = NULL;
			}
			else {
				father->right = NULL;
			}
			free(root);
		}
		else if (root->left != NULL&&root->right==NULL) {//��������ʱ
			if (father->left = root) {//������ֱ�ӽӵ�father�Ķ�Ӧ�ڵ�
				father->left = root->left;
			}
			else {
				father->right = root->left;
			}
			free(root);
		}
		else if(root->right!=NULL && root->left == NULL){//��������ʱ
			if (father->right == root) {//������ֱ�ӽӵ�father�Ķ�Ӧ�ڵ�
				father->right = root->right;
			}
			else {
				father->left = root->right;
			}
			
			free(root);
		}
		else {
			tree p = root->left;//�����ҽڵ�
			while (p->right != NULL) {//Ѱ��ֱ��ǰ��
				p = p->right;
			}
			root->data = p->data;//��ֱ��ǰ���滻�ýڵ�
			free(p);//�ͷ�ֱ��ǰ��
		}
	}
	else {
		if (root->data > x) {//��ǰ�ڵ��x��������
			del(root->left, root, x);
		}
		else {//��ǰ�ڵ��xС��������
			del(root->right, root, x);
		}
	}
}


int main() {
	tree root = build(qx, zx);//����������
	del(root, NULL,2);
}