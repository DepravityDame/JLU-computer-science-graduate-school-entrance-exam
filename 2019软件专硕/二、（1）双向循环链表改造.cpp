#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;

typedef struct Node {
	int data;
	Node*left;
	Node*right;
}*List;
List head = (List)malloc(sizeof(Node));
void build() {//β�巨����˫������
	int a[7] = { 1,2,3,4,5,6,7 };
	List p,q;
	q = head;
	head->right = NULL;
	for (int i = 0; i < 7; i++) {
		List p = (List)malloc(sizeof(Node));
		p->data = a[i];
		p->right = q->right;
		q->right = p;
		p->left = q;
		q = p;
	}
	q->right = head;
	head->left = q;

}

void change(List head) {
	List tail = head->left;//β���ָ��
	int num = 1;//��ż��������
	List p = head->right;//pָ���һ����ͷ�ڵ�
	while (p != tail) {
		if (num % 2 == 0) {//ż��ʱ
			List cur=p;//���浱ǰ�ڵ�
			p = p->right;//pָ����
			cur->left->right = p;//��ǰ�ڵ��ǰ�����ӵ���ǰ�ڵ���
			p->left = cur->left;//��ǰ�ڵ������ӵ�ǰ��
			cur->right = tail->right;//����ǰ�ڵ�����β
			tail->right->left = cur;//���±�βָ����һ���ڵ�ǰ��
			tail->right = cur;//���±�βָ����Ϊ��ǰ�ڵ�
			cur->left = tail;//��ǰ�ڵ�ǰ����Ϊβ�ڵ㣨��ǰ��β���ֻ��ԭ����β����δʵ�������ϵĸ���������β��
		}
		else {//����ʱ���λ�ò��䣬ֱ����һ���ڵ�
			p = p->right;
		}
		num++;//��������++
	}

}

int main() {
	build();
	change(head);
}