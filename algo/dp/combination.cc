#include <cstdio>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

unordered_set<string> S;

void print_result(const vector<vector<int> > &ret) {
	for (vector<int> v: ret) {
		for (int i: v) {
			printf("%d ", i);
		}
		printf("\n");
	}
}

bool in_set(const vector<int> &path) {
	vector<int> num(path);
	sort(num.begin(), num.end());
	char buf[1024] = {0};
	char *p = buf;
	for (int i: num) {
		sprintf(p++, "%d", i);
	}
	return S.find(buf) != S.end();
}

void comb(const vector<int> & nums, int n, int k, int s, vector<int> &path, vector<vector<int> > &ret) {
	if (k == path.size()) {
		if (!in_set(path)) {
			ret.push_back(path);
			vector<int> num(path);
			sort(num.begin(), num.end());
			char buf[1024] = {0};
			char *p = buf;
			for (int i: num) {
				sprintf(p++, "%d", i);
			}
			S.insert(buf);
		}
	} else {
		for (int i=s; i<n; ++i) {
			path.push_back(nums.at(i));
			comb(nums, n, k, i+1, path, ret);
			path.pop_back();
		}
	}
}

int main() {
	vector<int> nums = {2, 1, 3, 2, 2, 3, 4};	
	vector<int> path;
	vector<vector<int> > ret;
	comb(nums, 7, 2, 0, path, ret);
	print_result(ret);
	return 0;
}
