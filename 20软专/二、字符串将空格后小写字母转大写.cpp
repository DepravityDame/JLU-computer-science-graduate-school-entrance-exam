#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

int main() { 
	string str;//�����ַ���
	while (getline(cin,str)) {//�����ַ���
		for (int i = 0; i < str.length(); i++) {//�����ַ���
			if (str[i] == ' ') {//��ǰ�ַ�Ϊ�ո�ʱ����һ�ַ�תΪ��д 
				str[i + 1] -= 32;//Сдת��д��ͨ��ASCII��������
			}
		}
		cout << str << endl;//���ת������ַ���
	}
	
}