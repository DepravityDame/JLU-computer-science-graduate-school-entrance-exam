#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;

double dist(int x1, int y1, int x2, int y2) {
	return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));//计算两点间距离
}
int main() {//题目未给出具体项数，按100解答
	int x[100] = {//测试数据
		-90,87,-1,40,19,7,45,32,-32,17,-28,19,33,0,-2,6,-20,25,-44,-24,-47,48,32,-1,19,-21,34,-4,-12,34,20,36,22,18,-11,3,-28,7,34,47,-29,-30,2,49,-8,5,36,-21,-34,42,-32,42,41,0,-41,42,45,29,47,-32,-26,-18,-49,-50,-16,-34,28,-43,-17,24,-48,-42,-19,20,-8,30,37,35,-38,-11,-31,-30,-21,-39,41,32,-26,6,-10,31,34,-48,-45,42,11,36,18,19,-47,31
	};
	int y[100] = {//测试数据
		-89,93,48,4,21,-26,9,-50,-15,23,37,44,49,-48,19,-40,-1,-38,21,-10,11,36,7,21,-18,12,-19,12,45,-49,-27,13,-43,26,13,-34,34,31,20,49,13,23,26,24,-39,-21,39,14,-10,1,-33,21,49,16,7,49,-28,19,44,-19,37,-12,23,34,2,-36,-36,-29,-24,34,-45,-37,29,8,34,9,-23,38,1,-32,-49,12,44,-31,-23,-9,-49,37,-20,21,-21,35,17,-28,-32,-29,-50,15,-42,31
	};
	double max = 0.0;//定义最大值
	for (int i = 0; i < 99; i++) {//遍历所有节点
		for (int j = i + i; j < 100; j++) {
			double dis = dist(x[i], y[i], x[j], y[j]);//计算两点距离
			if (dis > max) {//比max大，则更新max
				max = dis;
			}
		}
	}
	printf("%lf", max);//输出max
}