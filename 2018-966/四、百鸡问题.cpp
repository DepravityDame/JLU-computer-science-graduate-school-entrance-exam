#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>

int  main() {
	int jz = 1;//����Ǯ�ȱ�����������������ʡȥС������
	int jm = 9;
	int jw = 15;
	for (int i = 0; i < 21; i++) {//ֻ�������20ֻ
		for (int j = 0; j < 34; j++) {//ֻ��ĸ�����33ֻ
			int k = 100 - i - j;//С����Ŀ��100-����-ĸ������ĿҪ��һ��һ��ֻ����
				if (i*jw + j * jm + k * jz == 300) {//��۸�����3����Ǯ���ȱ�����������
					printf("%d %d %d\n", i, j, k);//������ܽ��
				}
			
		}
	}
}