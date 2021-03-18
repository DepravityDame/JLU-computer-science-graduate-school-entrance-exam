#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;


typedef struct Teacher{//�ṹ�嶨��
	int num;
	int sex;
	char name[20];
	int year;
	Teacher *next;
}*tea;

void insert(tea head) {//�������//�������
	tea p= (tea)malloc(sizeof(Teacher));//�½��ڵ�
	printf("Please input the number ,sex,name and year:");//��������
	scanf("%d %d %s %d", &p->num, &p->sex, p->name, &p->year);
	tea q = head->next;
	while (q->next->num < p->num&&q->next !=NULL) {//���Ҳ���λ��
		q = q->next;
	}
	p->next = q->next;//��������
	q->next = p;
}

void build(tea head) {//�ļ��ж��벢��������
	FILE *fp = fopen("input.txt", "r");//���ļ�
	tea q = head;
	if (fp == NULL) {//�жϴ�״̬
		printf("FILE OPEN ERROR\n");
	}
	while (!feof(fp)) {
		tea p = (tea)malloc(sizeof(Teacher));//�½��ڵ�
		fscanf(fp,"%d %d %s %d", &p->num, &p->sex, p->name, &p->year);//��������
		q->next = p;//��������
		q = p;
	}
	q->next = NULL;//��������β
}

void sort(tea head) {//�������
	tea p = head->next;//ð������ָ��
	while (p != NULL) {
		tea q = p->next;
		while (q != NULL) {
			if (p->num > q->num) {//��ǰ�ڵ�Ⱥ���Ľڵ���ֵ�󣬵���λ��
				Teacher tmp = *p;//����ȫ������
				*p = *q;
				*q = tmp;
				tea tmpnext = q->next;//����next��
				q->next = p->next;
				p->next = tmpnext;
			}
			q = q->next;//ָ�����
		}
		p = p->next;//ָ�����
	}
}
void del(tea head) {
	printf("Please input the number you want to delete:");//����Ҫɾ���ڵ����
	int n;
	scanf("%d", &n);
	tea p = head;//����ָ��
	while (p->next != NULL) {
		if (n== p->next->num) {//����ڵ�ƥ����ɾ���ýڵ�
			p->next = p->next->next;
			return;
		}
		p = p->next;
	}
	return;
}
void print(tea head) {//�������
	tea p = head->next;
	while (p != NULL) {
		printf("%d %d %s %d\n", p->num, p->sex, p->name, p->year);
		p = p->next;
	}
	printf("\n");
}
int main() {//������
	tea head = (tea)malloc(sizeof(Teacher));
	head->next = NULL;
	build(head);//�ļ���������
	print(head);
	sort(head);//������
	print(head);
	insert(head);//������Ԫ�غ���;
	print(head);
	del(head);//ɾ��ָ��Ԫ��
	print(head);
}