#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

typedef struct Student {
	int xh;
	char name[20];
	int score;
	Student*next;
}*stu;

stu build() {
	stu head = (stu)malloc(sizeof(Student));
	int n = 6;
	stu p1 = head;
	while (n--) {
		stu p= (stu)malloc(sizeof(Student));
		scanf("%d %s %d", &p->xh, p->name, &p->score);
		p1->next = p;
		p1 = p;
	}
	p1->next = NULL;
	return head;
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

void print(stu head) {
	stu p = head->next;
	while (p != NULL) {
		printf("%d %s %d\n", p->xh, p->name, p->score);
		p = p->next;
	}
}
int main() {
	stu head =build();
	stu heead2 = build2();
	sort(head);
	printf("\n");
	print(head);

}