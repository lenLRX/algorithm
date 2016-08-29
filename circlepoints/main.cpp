/*
�հ��ھ���֮�Ż���³��˹�󣬴�³��˹���ϵ�����һ���߼������飬�հش򿪺�ϲ�ط�������һ������ʧ�����Ϲż���---�������ס�
�ü���ÿ�η���ֻ��ۺ��ٵľ���ֵ���������Ҳ�ǳ��ߡ�
����ħ���������£�
�ѵ�ͼ����Ϊһ����ά���꣬���ܷ�����λ��(0,0)λ�á��Լ��ܷ�����Ϊ���ģ���һ���뾶Ϊr��Բ������r^2=S���������λ�����Բ�ϣ���λ��Ϊ�������꣬������˽��յ��ü��ܵ�����˺�����
���統S=25ʱ������12�������ܵ��ü��ܵ�����˺�������ͼ��ʾ��

���������ǣ��������׿���ͨ���ı�ħ������������S�Ĵ�С�������ѧ�õ�ħ��ʦ����ͨ���ü��ܹ���������ĵ��ˡ�
�հ��뽫�������ѧ�Ტ��Ϊ�Լ��������ܣ�����ѧ������Ӳ�ˣ�������������Ϊ��дһ�����򣬰�����ɣ�û׼���Ͱѽ���������������� : )
*/

#include <iostream>
#include <set>
#include <cmath>
#include <vector>

using namespace std;

int main(){
	int S;
	while (cin >> S){
		if (S == 1){
			cout << 4 << endl;
			continue;
		}
			
		int range = sqrt(S);
		vector<int> square(range + 2);
		set<int> squareset;
		for (int i = 0; i < range + 2; i++){
			square[i] = i*i;
			squareset.insert(square[i]);
		}
		int count = 0;
		for (int i = 0; i < range + 1 && square[i] !=S; i++){
			if (squareset.count(S - square[i]))
				count++;
			/*
			for (int j = range; j >= 0; j--){
				if (square[i] + square[j] == S){
					count++;
				}
			}
			*/
		}

		cout << count * 4 << endl;
	}

	return 0;
}