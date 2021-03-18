#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<queue>
#include<iostream>
using namespace std;

typedef struct node{//�ṹ�嶨��
	int data;
	node *next;
}*List;


List build() {//�����������������ʱ����д��
	int a[7] = { 7,4,2,1,5,6,8 };
	List head = (List)malloc(sizeof(node));
	head->data = a[0];
	List p1 = head;
	for (int i = 1; i < 7; i++) {
		List p= (List)malloc(sizeof(node));
		p->data = a[i];
		p1->next = p;
		p1 = p;
	}
	p1->next = NULL;
	return head;
}

List merge(List h1, List h2) {//�鲢����
	List head = (List)malloc(sizeof(node));//������ͷ����ʼ��
	head->data = -999;
	List p = head;//����ָ��
	while (h1 != NULL && h2 != NULL) {
		if (h1->data < h2->data) {//��·�鲢����������
			p->next = h1;
			p = h1;
			h1 = h1->next;
			
		}
		else {
			p->next = h2;
			p = h2;
			h2 = h2->next;
		}
	}
	if (h1 != NULL) {//h1Ԫ��û���ֱ꣬�ӽӵ���β
		p->next = h1;
	}
	else if (h2 != NULL) {//h2Ԫ��û���ֱ꣬�ӽӵ���β
		p->next = h2;
	}
	return head->next;//������Ԫ��ָ��
}

List Sort(List r) {//���ֹ���
	if (r == NULL or r->next == NULL) {//��ֻ��һ��Ԫ�ػ���򷵻�
		return r;
	}
	List slow = r;//��ָ��
	List fast = r->next;//��ָ��
	while (fast != NULL && fast->next != NULL) {//��ָ���ߵ�NULLʱ��slow�����������м�λ��
		slow = slow->next;
		fast = fast->next->next;
	}
	List h1 = Sort(slow->next);//��ȡ��벿�������������
	slow->next = NULL;//�Ͽ�����
	return merge(Sort(r), h1);//ǰ�벿�������ͺ�벿�������������й鲢
}


int main() {
	List head = build();//����������
	head=Sort(head);
	List p = head->next;
	while (p != NULL) {//�����������
		printf("%d ", p->data);
		p = p->next;
	}
}