#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<algorithm>
#include<map>;
using namespace std;

int main() {
	int a[5][5] = {
		3,2,4,5,1,
		10,9,3,4,2,
		8,7,6,7,7,
		3,3,4,1,2,
		4,5,3,1,1,
	};
	map<int, int>mymap;//��һά��Ԫ��ֵ���ڶ�ά�ǳ��ִ���
	for (int i = 0; i < 5; i++) {//��Ŀδ����Ԫ��ȡֵ��Χ����ʹ��mapӳ���Խ�ʡ�ռ�
		for (int j = 0; j < 5; j++) {
			mymap[a[i][j]]++;
		}
	}
	map<int, int>::iterator it;//����map������
	int max=0;//������ִ������ֵ
	int maxindex;//������ִ������ֵ��Ԫ��
	for (it=mymap.begin(); it != mymap.end(); it++) {//����mapѰ�����ֵ
		if (it->second > max) {
			maxindex = it->first;//�������ֵ�������ֵԪ��
			max = it->second;
		}
	}
	printf("%d", maxindex);//������ֵԪ�ص�ֵ
}
