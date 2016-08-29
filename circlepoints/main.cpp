/*
赫柏在绝域之门击败鲁卡斯后，从鲁卡斯身上掉落了一本高级技能书，赫柏打开后惊喜地发现这是一个早已失传的上古技能---禁忌雷炎。
该技能每次发动只需扣很少的精神值，而且输出也非常高。
具体魔法描述如下：
把地图抽象为一个二维坐标，技能发动者位于(0,0)位置。以技能发动者为中心，做一个半径为r的圆，满足r^2=S，如果敌人位于这个圆上，且位置为整点坐标，这个敌人将收到该技能的输出伤害。。
例如当S=25时，将有12个敌人受到该技能的输出伤害，如下图所示：

更厉害的是，禁忌雷炎可以通过改变魔法输入来控制S的大小，因此数学好的魔法师可以通过该技能攻击到更多的敌人。
赫柏想将这个技能学会并成为自己的主技能，可数学是他的硬伤，所以他请求你为他写一个程序，帮帮他吧，没准他就把禁忌雷炎与你分享了 : )
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