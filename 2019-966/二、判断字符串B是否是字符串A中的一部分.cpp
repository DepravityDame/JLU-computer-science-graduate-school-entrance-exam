#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
typedef struct Node//�ṹ�嶨��
{
	char data;
	Node *next;
}*List ;
List head = (List)malloc(sizeof(Node));//����ͷ���

void build() {//����������
	List p1 = head;
	const int n = 10;
	char a[n] = { 'h','e','l','l','o' };
	List p;
	for (int i = 0; i < n; i++) {
		p = (List)malloc(sizeof(Node));
		p->data = a[i];
		p1->next = p;
		p1 = p;
	}
	p1->next = NULL;
}


bool cmp(char str[], List head) {//��������
	List p = head->next;//pָ���һ�����ݽڵ�
	List pos=p;
		for (int i = 0; i < strlen(str)&&p!=NULL;) {//ѭ���Ƚ�
			if (str[i] == p->data) {//�����ǰstr[i]��p.data���
				i++; p = p->next;//i+1��pָ����һ���ڵ�
			}
			else {//��������ͷ��ʼ�Ƚϣ�pָ����һ�ڵ�
				i = 0;
				pos = pos->next;//��ǰ�ڵ��޷�ƥ�䣬pos����
				p = pos;//p�ӵ�ǰ�ڵ㿪ʼ
			}
			if (i == strlen(str)) {//str��Ԫ��ƥ����ϣ�����
				return true;
			}
		}

	return false;//������βҲδƥ��ɹ�����ʧ��
}


int main() {
	build();
	char str[100];
	while (scanf("%s", str) != EOF) {
		if (cmp(str, head))printf("YES\n");
		else {
			printf("NO\n");
		}
	}
}