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

void sort(List head) {
	List p = head->next;//����ָ��
	while (p != NULL) {//ð����������
		List q = p->next;
		while (q != NULL) {
			if (p->data > q->data) {//���p����q�����߻���
				int tmp = p->data;
				p->data = q->data;
				q->data = tmp;
			}
			q = q->next;//ָ�����
		}
		p = p->next;//ָ�����
	}
}

List merge(List head1, List head2) {//�ϲ�
	List newhead = (List)malloc(sizeof(Node));//��ʼ��������ͷ
	List p = head1->next;//head1����ָ��
	List q = head2->next;//head2����ָ��
	newhead->next = NULL;//��ʼ�� β���
	List k = newhead;//������ָ��
	while (p != NULL && q != NULL) {//p��q����Ϊ��ѭ��
		if (p->data <= q->data) {//����С�Ĳ��뵽������
			if (q->data == p->data) {//���p��q��ȣ�����p������q
				q = q->next;
			}
			k->next = p;//��pβ�巨����������
			k = p;
			p = p->next;
			
		}
		else {
			k->next = q;//��qβ�巨����������
			k = q;
			q = q->next;
		}
	}
	if (p != NULL) {//��ʣ���������
		k->next = p;
	}
	if (q != NULL) {//��ʣ���������
		k->next = q;
	}
	return newhead;//������ͷ
}


int main() {
	build();
	build2();
	sort(head);
	sort(head2);
	printf("\n");

	List p= merge(head, head2)->next;
	while (p != NULL) {//�������
		printf("%d ", p->data);
		p = p->next;
	}



}