#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;

typedef struct Node {
	int data;
	Node* LLink;
	Node* RLink;
	int Freq;
}node,*List;

List head = (List)malloc(sizeof(node));
void build() {//˫������������
	int a[6] = { 3,4,2,1,5,7 };
	List p, ppre;
	ppre = head;
	for (int i = 0; i < 6; i++) {
		p = (List)malloc(sizeof(node));;
		p->data = a[i];
		p->Freq = 0;
		ppre->RLink = p;
		p->LLink = ppre;
		ppre = p;
	}
	ppre->RLink = NULL;
}

void Locate(int x) {//��������
	List p, q;
	p = head->RLink;//Pָ��ͷ�����һ���ڵ�
	while (p != NULL) {
		if (p->data == x) {//���p�����ݵ���x
			p->Freq++;//pƵ��++
			break;//�˳�ѭ��
		}
		p = p->RLink;//pָ����һ���ڵ�
	}
	if (p->LLink == head)return;//���p������ǵ�һ�����ݽ�㲻���д���
	else {
		p->LLink->RLink = p->RLink;//��p��ԭ����ժ��
		if (p->RLink != NULL)p->RLink->LLink = p->LLink;
		q = head->RLink;//Ѱ��p����λ��
		while (q != NULL && q->Freq > p->Freq) {
			q = q->RLink;
		}
		q->LLink->RLink = p;//p���뵽q֮ǰ
		p->LLink = q->LLink;
		q->LLink = p;
		p->RLink = q;
	}
	
}


void print(List head) {//�����������
	List p = head->RLink;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->RLink;
	}
}
int main() {
	build();
	int x;
	print(head);
	while (scanf("%d", &x) != EOF) {//����X
		Locate(x);//���ú���
		print(head);//�������
	}
}