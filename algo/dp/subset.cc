#include <cstdio>
#include <vector>

using namespace std;

void print_result(const vector<vector<int> > &ret) {
	for (vector<int> v: ret) {
		for (int i: v) {
			printf("%d ", i);
		}
		printf("\n");
	}
}

void subset1(const vector<int> &nums,
		vector<int> &path,
		vector<vector<int> > &ret,
		int s, int p) {
	for (int i=s; i<nums.size(); ++i) {
		if (path.size() > p)
			path[p] = nums.at(i);
		else
			path.push_back(nums.at(i));
		vector<int> temp;
		for (int j=0; j<=p; ++j)
			temp.push_back(path.at(j));
		ret.push_back(temp);
		subset1(nums, path, ret, i+1, p+1);
	}	
}

void subset2(const vector<int> &nums,
		vector<int> &path,
		vector<vector<int> > &ret,
		int cur) {

	if (cur == nums.size()) {
		ret.push_back(path);
		return;
	}
	subset2(nums, path, ret, cur+1);
	path.push_back(nums.at(cur));
	subset2(nums, path, ret, cur+1);
	path.pop_back();
}

int main() {
	vector<int> nums = {1, 2, 3};
	vector<int> path;
	vector<vector<int> > ret;
	ret.push_back(vector<int>());
	subset1(nums, path, ret, 0, 0);
	print_result(ret);
	printf("------------------\n");
	ret.clear();
	path.clear();
	subset2(nums, path, ret, 0);
	print_result(ret);
}
