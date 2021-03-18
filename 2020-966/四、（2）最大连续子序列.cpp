#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

typedef struct Node {
	int data;
	Node *next;
}*List;


void del(List head) {//��������
	List p = head->next;
	List qpre;//����ָ��ǰ��
	while (p != NULL) {
		List q = p->next;//��p��һԪ�ؿ�ʼ������������
		qpre = p;//��ʼ��qǰ��
		while (q!= NULL) {//δ������βѭ��
			if (p->data == q->data) {//���pq��ȣ���ɾ��q�ڵ�
				qpre->next = q->next;//��q�������з���
				free(q);//�ͷ�q
				q = qpre->next;//qָ��������ڴ�qpre���ý��иı�
				continue;//�����´�ѭ��
			}
			qpre = q;//qpre����
			q = q->next;//q����
		}
		p = p->next;//p����
	}
}

List head = (List)malloc(sizeof(Node));

void build() {//����ԭ����
	List p1 = head;
	const int n = 10;
	int a[n] = { 4,7,2,5,7,6,9,12,2,3 };
	List p;
	for (int i = 0; i < n; i++) {
		p = (List)malloc(sizeof(Node));
		p->data = a[i];
		p1->next = p;
		p1 = p;
	}
	p1->next = NULL;
}

void print(List head) {//�������
	List p = head->next;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int main() {
	build();
	print(head);
	del(head);//ɾ������
	print(head);
}