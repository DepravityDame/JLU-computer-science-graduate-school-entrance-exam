#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<queue>
#include<string>
#include<iostream>
#include<vector>
using namespace std;

int main() {
	priority_queue<int,vector<int>,greater<int> > q;//�������ȶ��У�������ȼ���//���ﱣ֤��������Сֵ��top
	q.push(1);//��1ѹ�����ȶ���
	int cot = 1;//��������
	while (cot != 100) {//����û�ﵽ100
		int tmp = q.top();//�Ӷ�����
		printf("%d ",tmp);//���
		cot++;//��������++
		q.pop();//����
		q.push(tmp * 2);//��2xѹ���
		if (tmp * 3 % 6 == 0)continue;//���tmp*3Ϊ6�ı�������ô����2x�ظ���������
		q.push(tmp * 3);//ѹ��3x
	}
	
}