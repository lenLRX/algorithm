#include <map>
#include <set>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		if (numCourses == 0)
			return vector<int>();

		int size = prerequisites.size();
		_prerequisites = prerequisites;
		for (int i = 0; i < size; i++){
			pmap[prerequisites[i].first].insert(prerequisites[i].second);
		}

		for (int i = 0; i < numCourses; i++){
			visited.clear();
			if (!Trace(i))
				;//return vector<int>();
		}
		if (ret.size() < numCourses)
			return vector<int>();
		else
			return ret;
	}

	bool Trace(int p){
		if (visited.count(p) && learnt.count(p) == 0)
			return false;
		visited.insert(p);

		if (pmap.find(p) == pmap.end()){
			if (learnt.count(p) == 0){
				learnt.insert(p);
				ret.push_back(p);
				return true;
			}
			else{
				//learnt.insert(p);
				//ret.push_back(p);
				return true;
			}
		}
		else{
			for (set<int>::iterator it = pmap[p].begin(); it != pmap[p].end(); it++){
				if (!Trace(*it))
					return false;
			}
			if (learnt.count(p) == 0){
				learnt.insert(p);
				ret.push_back(p);
			}

		}
		return true;
	}
	map<int, set<int>> pmap;
	vector<pair<int, int>> _prerequisites;
	vector<int> ret;
	set<int> learnt;
	set<int> visited;
};

int main(){
	Solution solution;
	int numCourses = 3;
	vector<pair<int, int>> prerequisites = 
	{ pair<int, int>(0, 1), pair<int, int>(0, 2), pair<int, int>(1, 2) };

	vector<int> result = solution.findOrder(numCourses,prerequisites);
	return 0;
}