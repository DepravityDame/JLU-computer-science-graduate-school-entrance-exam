#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

typedef struct Student {
	int xh;
	char name[20];
	int score;
	Student*next;
}*stu;

stu build() {//������һ������
	stu head = (stu)malloc(sizeof(Student));
	int n = 6;
	stu p1 = head;
	while (n--) {
		stu p = (stu)malloc(sizeof(Student));
		scanf("%d %s %d", &p->xh, p->name, &p->score);
		p1->next = p;
		p1 = p;
	}
	p1->next = NULL;
	return head;
}
stu build2() {
	stu head = (stu)malloc(sizeof(Student));//�����ڶ�������
	stu p1 = head;//����β��ָ��
	FILE *fp;//�����ļ�ָ��
	fp = fopen("C:\\Users\\93482\\Desktop\\original.txt", "r");//ֻ�����ļ�,����������ϵľ���·������ɾ��ǰ�ߵģ����ļ��������ͬĿ¼
	if (fp == NULL) {//�ж��ļ���״̬
		printf("FILE OPEN ERROR\n");
	}
	while (!feof(fp)) {//δ���ļ���βʱ��ȡ
		stu p = (stu)malloc(sizeof(Student));//�����½ڵ�
		fscanf(fp,"%d %s %d", &p->xh, p->name, &p->score);//��ֵ����
		p1->next = p;//β���������
		p1 = p;
	}
	p1->next = NULL;//�������β
	return head;//����ͷ���
}

void sort(stu head) {//����������
	stu p = head->next;
	stu q;
	while (p != NULL) {//����ð���������
		q = p->next;
		while (q != NULL) {
			if (p->score > q->score) {
				Student tmp;//���������
				tmp = *p;
				*p = *q;
				*q = tmp;
				stu tmpnext;
				tmp.next = p->next;//�ٸ���nextָ��
				p->next = q->next;
				q->next = tmp.next;
			}
			q = q->next;//��һ�ڵ�
		}
		p = p->next;//��һ�ڵ�
	}
}

stu merge(stu head1,stu head2) {
	stu p = head1->next;//��һ����ָ��
	stu q = head2->next;//�ڶ�����ָ��
	stu newhead = (stu)malloc(sizeof(Student));//������ͷ
	newhead->next = NULL;//��ʼ��β���
	stu k = newhead;//������ָ��
	while (p != NULL && q != NULL) {
		if (p->score <=q->score) {//p��ָԪ�سɼ��ͣ���p����������
			k->next = p;
			k = p;
			p = p->next;
		}
		else { 
			k->next = q;//����q����������
			k = q;
			q = q->next;
		}
	}
	if (q != NULL) {//����δ��ĩβ����
		k->next = q;
	}
	if (p != NULL) {
		k->next = p;
	}
	return newhead;//������ͷ
}

void print(stu head) {
	stu p = head->next;
	while (p != NULL) {
		printf("%d %s %d\n", p->xh, p->name, p->score);
		p = p->next;
	}
}
int main() {
	stu head = build();//������һ������
	stu head2 = build2();//�����ڶ�������
	sort(head);//��һ����������
	sort(head2);//�ڶ�����������
	printf("\n");
	print(head);
	printf("\n");
	print(head2);
	stu newhead=merge(head, head2);//�鲢
	printf("\n");
	print(newhead);
}