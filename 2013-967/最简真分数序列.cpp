#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<queue>
#include<iostream>
using namespace std;

typedef struct Node{//����ڵ�
	int fz;//����
	int fm;//��ĸ
	Node *next;//��һ�ڵ�ָ��
}*List;
int gys(int a, int b) {//�����Լ������
	if (a%b == 0)return b;
	else return (b, a%b);
}


int main() {
	int n;
	List head = (List)malloc(sizeof(Node));//��ʼ��ͷ���
	head->fz = 0;//��ʼ��ͷ���
	head->fm = 1;//��ʼ��ͷ���
	head->next = NULL;//��ʼ��ͷ���
	List p, q;//pΪ�½ڵ�ָ�룬qΪ�������ָ��
	while (scanf("%d", &n)!=EOF) {//���ѭ���ã�ֻ��ִ��һ��ʱ��ɾȥ
		head->next = NULL;//���ѭ���ã�ֻ��ִ��һ��ʱ��ɾȥ
		for (int i = 1; i <= n; i++) {//ѭ��������ĸ
			for (int j = 1; j < i; j++) {//ѭ����������
				p= (List)malloc(sizeof(Node));//�����½ڵ�
				p->fz = j/gys(i,j);//�������
				p->fm = i / gys(i, j);//�����ĸ
				q = head;//q��ʼ��Ϊͷָ��
				while (q->next != NULL && p->fz*1.0 / p->fm > q->next->fz*1.0 / q->next->fm) {//Ѱ�Ҳ���λ��
					q = q->next;
				}
				if (q->next !=NULL &&p->fz*1.0 / p->fm == q->next->fz*1.0 / q->next->fm)continue;//�ظ�ֵ����
				p->next = q->next;//�������
				q->next = p;//�������
			}
		}
		p = head->next;
		while (p != NULL) {//�������� �����
			printf("%d/%d ", p->fz, p->fm);
			p = p->next;
		}
	}
}