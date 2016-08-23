#include <string>
#include <iostream>
using namespace std;
int main(){
	string origin;
	while (cin >> origin)
	{
		size_t s = origin.size();
		size_t pointer = s - 1;
		for (int i = s - 1; i >= 0; i--){
			if (origin[i] >= 'A' && origin[i] <= 'Z'){
				char capital = origin[i];
				for (int j = i; j < pointer; j++)
					origin[j] = origin[j + 1];
				origin[pointer] = capital;
				pointer--;
			}
		}
		cout << origin << endl;
	}

	return 0;
}