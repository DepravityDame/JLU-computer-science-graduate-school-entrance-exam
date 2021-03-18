#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
using namespace std;

typedef struct Node {
	int data;
	Node*next;
}*List;
List head1 = (List)malloc(sizeof(Node));
List head2 = (List)malloc(sizeof(Node));
void build() {
	List p1 = head1;
	const int n = 3;
	int a[n] = { 1,3,4};
	List p;
	for (int i = 0; i < n; i++) {
		p = (List)malloc(sizeof(Node));
		p->data = a[i];
		p1->next = p;
		p1 = p;
	}
	p1->next = NULL;
}
void build2() {
	List p1 = head2;
	const int n = 3;
	int a[n] = { 1,5,3 };
	List p;
	for (int i = 0; i < n; i++) {
		p = (List)malloc(sizeof(Node));
		p->data = a[i];
		p1->next = p;
		p1 = p;
	}
	p1->next = NULL;
}
void sort(List head) {
	List p = head->next;
	List q = p->next;
	while (p->next != NULL) {
		q = p->next;
		while (q != NULL) {
			if (p->data > q->data) {
				int tmp = p->data;
				p->data = q->data;
				q->data = tmp;
			}
			q = q->next;
		}
		p = p->next; 
	}
}

List UnionSet(List q, List p) {
	sort(p);//��p����
	sort(q);//��q����
	List newhead = (List)malloc(sizeof(Node));//����������ڵ�
	newhead->next = NULL;//��βΪNULL
	List k = newhead;//kΪβ��ָ��
	p = p->next;//�Ƶ���һ�����ݽڵ�
	q = q->next;
	while (q != NULL && p != NULL) {//�鲢����
		if (q->data < p->data) {//qСʱ����q����new����
			List cur = q;
			q = q->next;//β�巨����
			cur->next = k->next;
			k->next = cur;
			k = cur;
		}
		else {
			List cur = p;//pСʱ����p����������
			if (p->data == q->data) {
				q = q->next;//p��qֵ��ͬʱ����
			}
			p = p->next;//β�巨����
			cur->next = k->next;
			k->next = cur;
			k = cur;

		}
	}
	if (q != NULL) {//����ʣ������
		k->next = q;
	}
	else if (p != NULL) {
		k->next = p;
	}
	return newhead;//������ͷ
}

int main() {
	build();
	build2();
	List newhead= UnionSet(head1, head2);
	List p = newhead->next;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}

}