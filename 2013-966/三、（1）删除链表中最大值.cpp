#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<queue>
#include<iostream>
using namespace std;
typedef struct Node {
	int data;
	Node*next;
}*List;
List head = (List)malloc(sizeof(Node));

void build() {
	List p1 = head;
	const int n = 10;
	int a[n] = { 4,7,2,5,8,6,9,4,11,3 };
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

void del(List head) {//��������
	List p;//����ָ��
	List max, maxpre;//ָ��ָ��max�ڵ���max�ڵ�ǰ����ָ��ǰ��Ϊ����ɾ��
	max = head->next;//�����һ�ڵ�������ڵ�
	maxpre = head;//ǰ��Ϊͷ���
	p = head->next;//p��ʼ��������
	while (p->next!= NULL) {//p��̽ڵ㲻Ϊ��ʱ����
		if (p->next-> data > max->data) {//��p��̽ڵ����ݱ�����max�󣬸�������max��maxpre
			max = p->next;
			maxpre = p;
		}
		p = p->next;//p����
	}
	head->data = max->data;//ͷ���������������ֵ
	maxpre->next = max->next;//�����ֵ��������ɾ��
	free(max);//�ͷ����ֵ�ڵ�
}

int main() {
	
	build();
	print(head);
	printf("\n");
	del(head);
	printf("%d\t", head->data);//�������ͷ�ڵ㣬�𰸲�Ҫ�����������
	print(head);

}