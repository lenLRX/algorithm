/*
有趣的数字
小Q今天在上厕所时想到了这个问题：有n个数，两两组成二元组，差最小的有多少对呢？差最大呢？


输入描述:

输入包含多组测试数据。

对于每组测试数据：

N - 本组测试数据有n个数

a1,a2...an - 需要计算的数据

保证:

1<=N<=100000,0<=ai<=INT_MAX.



输出描述:

对于每组数据，输出两个数，第一个数表示差最小的对数，第二个数表示差最大的对数。

输入例子:
6
45 12 45 32 5 6

输出例子:
1 2
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main(){
	int psize;
	while (cin >> psize){
		vector<int> data(psize);
		for (int i = 0; i < psize; i++){
			cin >> data[i];
		}

		sort(data.begin(), data.end());

		int mindiff = INT_MAX;
		int mincount = 0;
		int len = 0;

		for (int i = 0; i < psize - 1; i++){
			if (data[i + 1] - data[i] < mindiff){
				mincount = 0;
				len = 1;
				mindiff = data[i + 1] - data[i];
			}
			else if (data[i + 1] - data[i] == mindiff){
				len++;
			}
			else if (len){
				mincount += len * (len + 1) / 2;
				len = 0;
			}
		}

		mincount += len * (len + 1) / 2;

		cout << mincount << " ";

		int i = 0;
		while (data[i] == data[0]){
			i++;
		}

		int j = 0;

		while (data[psize - j - 1] == data[psize - 1]){
			j++;
		}

		cout << j * i << endl;

	}
	return 0;
}