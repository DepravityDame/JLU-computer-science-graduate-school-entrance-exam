#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<string>

typedef struct Node {
	int data;
	Node *next;
}node, *List;

List head = (List)malloc(sizeof(Node));
List head2 = (List)malloc(sizeof(Node));
void build() {
	int a[5] = { 1,3,5,17,91 };
	List p, p1;
	p1 = head;
	for (int i = 0; i < 5; i++) {
		p = (List)malloc(sizeof(Node));
		p->data = a[i];
		p1->next = p;
		p1 = p;
	}
	p1->next = NULL;
}
void build2() {
	int a[5] = { 2,3,6,17,22 };
	List p, p1;
	p1 = head2;
	for (int i = 0; i < 5; i++) {
		p = (List)malloc(sizeof(Node));
		p->data = a[i];
		p1->next = p;
		p1 = p;
	}
	p1->next = NULL;
}

void jj(List head1,List head2) {//�󽻼�
	List p = head1->next;//��һ������ָ��
	List q = head2->next;//�ڶ�������ָ��
	List newhead= (List)malloc(sizeof(Node));//������ͷ
	newhead->next = NULL;//��ʼ��������β
	List k = newhead;//��ͷָ��
	while (p != NULL && q != NULL) {//��������
		if (p->data == q->data) {//�ڵ���ֵ��ȣ������������
			List tmp = (List)malloc(sizeof(Node));//�½��ڵ�Ϊ�˷�ֹ�ƻ�ԭ����ṹ
			tmp->data = p->data;
			k->next = tmp;
			k = tmp;
			p = p->next;
			q = q->next;
		}
		else if (p->data > q->data) {//q��С��q������Ҹ����
			q = q->next;
		}
		else {//p��С��p������Ҹ����
			p = p->next;
		}
	}
	k->next = NULL;//������β
	p = newhead->next;//����ָ��
	while (p != NULL) {//�����������
		printf("%d ", p->data);
		p = p->next;
	}
}

void bj(List head1, List head2) {
	List p = head1->next;//��һ������ָ��
	List q = head2->next;//�ڶ�������ָ��
	while (q != NULL) {//���ڶ���������뵽��һ��������
		while (p->next != NULL&&p->next->data < q->data) {//Ѱ�Ҳ���λ��
			p = p->next;
		}
		if (p->next == NULL) {//���ѵ����β��ֱ�ӽ�q��������һβ��
			p->next = q;
		}
		if (p->next->data == q->data) {//�����ڵ���ȣ����������ڵ����
			q = q->next;
			continue;
		}
		List cur = q;//����q
		q = q->next;//q����
		cur->next = p->next;//��curβ�巨���뵽p��
		p->next = cur;//����
		p = cur;//����βָ��
	}
	p = head1->next;//�����������
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
}


int main() {
	build();
	build2();
	jj(head, head2);
	printf("\n");
	bj(head, head2);




}