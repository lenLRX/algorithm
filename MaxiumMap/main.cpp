#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

long long str2long(map<char, long> ch2long, string str){
	long long r = 0;
	long long pos = 1;
	long size = str.length();
	//cout << "original: " << str << endl;
	for (long i = 0; i < size; i++){
		//cout << str[size - i - 1];
		r += pos * ch2long[str[size - i - 1]];
		pos *= 10;
	}
	//cout << endl;
	return r;
}

/*
map<char, long> getmap(vector<string>& raw, long start, long pos){
long nums = raw.size();

map<char, long> ch2long;
long j = start;
{
pair<long, long> freq[10];

for (long i = 0; i < 10; i++){
freq[i].first = i;
freq[i].second = 0;
}

for (long i = 0; i<nums; i++){
if (j < raw[i].size()){
freq[raw[i][j] - 'A'].second++;
}
}
sort(freq, freq + 10);

for (long i = 9; i >= 1; i--){
if (ch2long.find('A' + freq[i].first) != ch2long.end())
continue;
if (freq[i].second != freq[i - 1].second){
ch2long.insert(pair<char, long>('A' + freq[i].first, pos));
pos--;
}
else{
map<char, long> tmp = getmap(raw, j + 1, 9);
long freq_i1 = tmp['A' + freq[i].first];
long freq_i2 = tmp['A' + freq[i - 1].first];

if (freq_i1 < freq_i1)
}
}

if (ch2long.find('A' + freq[0].first) != ch2long.end() && freq[0].second != freq[1].second){
ch2long.insert(pair<char, long>('A' + freq[0].first, pos));
pos--;
}
}

}
*/

int main(){
	long nums;
	cin >> nums;
	vector<string> raw(nums);
	set<char> heads;
	for (long i = 0; i<nums; i++){
		cin >> raw[i];
	}

	vector<pair<int,long long>> score(10);
	for (long i = 0; i < 10; i++){
		score[i].first = i;
		score[i].second = -1;
	}
	long long pos[13];
	long long t = 1;
	for (long i = 0; i < 13; i++){
		pos[i] = t;
		t *= 10;
	}

	for (int j = 0; j < nums; j++){
		heads.insert(raw[j][0]);
	}

	for (long i = 0; i < 12; i++){
		for (int j = 0; j < nums; j++){
			if (i < raw[j].size()){
				auto p = raw[j].size() - i;
				long long tmp = pos[p];
				if (score[raw[j][i] - 'A'].second < 0)
					score[raw[j][i] - 'A'].second = 0;
				score[raw[j][i] - 'A'].second += tmp;
			}
		}
		
	}
	auto cmp = [](const pair<int,long long>& lhs, const pair<int,long long>& rhs)->bool{return lhs.second < rhs.second; };
	sort<vector<pair<int,long long>>::iterator, decltype(cmp)>
		(score.begin(), score.end(), cmp);

	if (heads.count('A' + score[0].first)){
		int NotInHead = -1;

		for (int i = 0; i < 10; i++){
			if (heads.count('A' + score[i].first) == 0){
				NotInHead = i;
				score[i].second = score[0].second;
				score[0].second++;
				sort<vector<pair<int, long long>>::iterator, decltype(cmp)>
					(score.begin(), score.end(), cmp);
				break;
			}
				
		}
		/*
		if (score[0].first != NotInHead){
			for (int i = 0; i < 10; i++){
				if (score[i].first == NotInHead){
					score[i].second = 0;
					sort<vector<pair<int, long long>>::iterator, decltype(cmp)>
						(score.begin(), score.end(), cmp);
					break;
				}
			}
		}
		*/
	}
	

	map<char, long> ch2long;

	for (int i = 0; i < 10; i++){
		ch2long['A' + score[i].first] = i;
	}

	


	long long sum = 0;
	for (long i = 0; i<nums; i++){
		sum += str2long(ch2long, raw[i]);
	}

	cout << sum << endl;

	return 0;
}