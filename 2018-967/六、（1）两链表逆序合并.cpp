#include<stdio.h>
#include<stdlib.h>
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
	int a[m] = { 1,2,4,5,6,12};
	int b[n] = {2,3,7,8,11 };
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

void merge(List head1, List head2) {//�������壬���಻�Ǵ𰸲��֣�����������
	List p, q;
	p = head1->next;//pΪ��һ������ָ�� 
	head1->next = NULL;//��head1��Ϊ��ͷ
	q = head2->next;//qΪ�ڶ�������ָ��
	while (p != NULL && q != NULL)//�����һ������
	if (q->data < p->data) {//ѡ����Сֵ��ͷ�嵽head1֮��С��ֵ��������
		List cur = q;//��ʱ����q
		q = q->next;//qָ����һ�ڵ�
		cur->next = head1->next;//�Ե�ǰ�ڵ�ͷ��
		head1->next = cur;
	}
	else {
		List cur = p; //��ʱ����p
		p = p->next;//pָ����һ�ڵ�
		if (p->data == q->data) {//��p��q�ڵ�ֵ��ͬʱ������q��ǰ�ڵ�
			q = q->next;
		}
		cur->next = head1->next;//�Ե�ǰ�ڵ�ͷ��
		head1->next = cur;
	}
	if (p != NULL) {//��pδ������β����pʣ��Ԫ��ͷ���������
		while (p != NULL) {
			List cur = p;
			p = p->next;
			cur->next = head1->next;
			head1->next = cur;
			
		}
	}
	if (q != NULL) {//��qδ������β����qʣ��Ԫ��ͷ���������
		while (q != NULL) {
			List cur = q;
			q = q->next;
			cur->next = head1->next;
			head1->next = cur;
			
		}
	}
}


int main() { 
	build();
	merge(head1, head2);
	print(head1);
}