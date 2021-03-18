#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;

typedef struct Node {
	int data;
	Node*next;
}*List;

bool isprime(int n) {
	if (n < 0)n = -n;
	if (n < 2) return false;
	else {
		for (int i = 2; i <= n / 2; i++) {
			if (n%i == 0)return false;
		}
	}
	return true;
}
List head = (List)malloc(sizeof(Node));

void build() {
	List p1 = head;
	const int n = 10;
	int a[n] = { 4,7,2,5,8,6,9,12,11,3 };
	List p;
	for (int i = 0; i < n; i++) {
		p = (List)malloc(sizeof(Node));
		p->data = a[i];
		p1->next = p;
		p1 = p;
	}
	p1->next = NULL;
}

void print(List head) {

	List p = head->next;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}

}

List sort(List head) {
	List p;//ԭ����ָ��
	p = head->next;
	List newhead = (List)malloc(sizeof(Node));//������ͷ
	newhead->next = NULL;
	List q,qpre;
	while (p != NULL) {//����ԭ����
		if (isprime(p->data)) {//�����ǰ�ڵ�ֵ����ֵΪ����
			p = p->next;//������ýڵ�ֵ
			continue;
		}
		else {//�ڵ�ֵ��������
			q = newhead->next;//q��ʼ��Ϊ��ͷ�ڵ���һ���ڵ�
			qpre = newhead;//qpre��ʼΪ��ͷ�ڵ㡣
			while (q != NULL && p->data < q->data) {//�����½ڵ����λ��
				qpre = q;
				q = q->next;
			}
			List tmp= (List)malloc(sizeof(Node));//����p�ڵ㣨Ϊ���ı�ԭ����ṹ��
			tmp->data = p->data;
			qpre->next = tmp;//�����ƵĽڵ����������
			tmp->next = q;
			p = p->next;
		}
	}
	return newhead;//������ͷ
}

int main() {
	build();
	print(head);
	printf("\n");
	List newhead=sort(head);
	print(newhead);
}