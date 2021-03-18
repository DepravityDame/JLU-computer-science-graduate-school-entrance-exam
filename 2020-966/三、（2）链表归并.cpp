#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
const int MAXN = 100;

typedef struct Node {
	int data;
	Node *next;
}node, *List;
List head1 = (List)malloc(sizeof(Node));
List head2 = (List)malloc(sizeof(Node));
void build() {
	List ppre, p, q, qpre;
	ppre = head1;
	const int m = 6;
	const int n = 5;
	qpre = head2;
	int a[m] = { 1,2,4,5,6,12 };
	int b[n] = { 2,3,7,8,11 };
	for (int i = 0; i < m; i++) {
		List p = (List)malloc(sizeof(Node));
		p->data = a[i];
		ppre->next = p;
		ppre = p;

	}
	ppre->next = NULL;
	for (int i = 0; i < n; i++) {
		List q = (List)malloc(sizeof(Node));
		q->data = b[i];
		qpre->next = q;
		qpre = q;
	}
	qpre->next = NULL;
}
void print(List head) {
	List p = head->next;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	return;
}

List merge(List head1, List head2) {//�������壬���಻�Ǵ𰸲��֣�����������
	List p = head1->next;//head1 ָ��
	List q = head2->next;//head2 ָ��
	List newhead = (List)malloc(sizeof(Node));//��ͷ����
	List k = newhead;//��ͷָ��
	while (p != NULL && q != NULL) {//��������鲢
		if (p->data > q->data) {//q�Ƚ�С����qβ�����������
			k->next = q;
			k = q;
			q = q->next;
			
		}
		else {//p�Ƚ�С����pβ�����������
			k->next = p;
			k = p;
			p = p->next;
			if (p ->data== q->data) {
				q = q->next;
			}
		}
	}
	if (p != NULL) {//����ʣ������
		k->next = p;
	}
	if (q != NULL) {//����ʣ������
		p->next = q;
	}
	return newhead;//��������ͷ
}


int main() {
	build();
	List newhead= merge(head1, head2);
	print(newhead);
	
}