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
void build() {
	List p1 = head1;
	const int n = 8;
	int a[n] = { 1,3,4,5,0,2,8,7};
	List p;
	for (int i = 0; i < n; i++) {
		p = (List)malloc(sizeof(Node));
		p->data = a[i];
		p1->next = p;
		p1 = p;
	}
	p1->next = NULL;
}


int main() {
	build();
	List p = head1->next;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
	int k;
	scanf("%d", &k);//����Ҫ���ҽڵ�
	List ppre = head1;//��ʼ��ǰ���ڵ�ָ��
	List pprepre = NULL;//��ʼ��ǰ����ǰ��
	p = head1->next;//p����
	while (p != NULL) {//��������
		if (p->data == k) {//���p.data==k,�򽻻�p����ǰ��
			ppre->next = p->next;
			p->next = ppre;
			pprepre->next = p;
		}
		pprepre = ppre;//����pǰ����ǰ��
		ppre = p;//����pǰ��
		p = p->next;//����p
	}
	p = head1->next;
	while (p != NULL) {
		printf("%d ", p->data);//�������
		p = p->next;
	}
}