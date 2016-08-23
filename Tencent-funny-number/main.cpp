/*
��Ȥ������
СQ�������ϲ���ʱ�뵽��������⣺��n������������ɶ�Ԫ�飬����С���ж��ٶ��أ�������أ�


��������:

�����������������ݡ�

����ÿ��������ݣ�

N - �������������n����

a1,a2...an - ��Ҫ���������

��֤:

1<=N<=100000,0<=ai<=INT_MAX.



�������:

����ÿ�����ݣ��������������һ������ʾ����С�Ķ������ڶ�������ʾ�����Ķ�����

��������:
6
45 12 45 32 5 6

�������:
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