#include <cstdio> 
#include <vector>
#include <algorithm>
#include <iterator>
#include <unordered_map>

using namespace std;

void permute(const int N, const vector<pair<int, int> > &nums,
		vector<int> &path,
		vector<vector<int> > &ret) {

	if (N == path.size()) {
		ret.push_back(path);
	} else {
		for (auto i: nums) {
			int count = 0;
			for (auto j: path) {
				if (i.first == j) {
					count ++;
				}
			}
			if (count < i.second) {
				path.push_back(i.first);
				permute(N, nums, path, ret);
				path.pop_back();
			}
		}
	}
}

void print_result(const vector<vector<int> > &ret) {
	for (vector<int> v: ret) {
		for (int i: v) {
			printf("%d ", i);
		}
		printf("\n");
	}
}

void permute1(const vector<int> &nums) {
	vector<int> path;
	unordered_map<int, int> counts;
	for (int i: nums) {
		if (counts.find(i) == counts.end())
			counts[i] = 1;
		else
			counts[i]++;
	}
	vector<pair<int, int> > n;
	for_each(counts.begin(), counts.end(), [&n](const pair<int, int> &e) {
		n.push_back(e);
	});
	vector<vector<int> > ret;
	permute(nums.size(), n, path, ret);
	print_result(ret);
}

void permute2(const vector<int> &nums) {
	vector<int> n(nums);
	do {
		for (int i: n) {
			printf("%d ", i);
		}
		printf("\n");
	} while (next_permutation(n.begin(), n.end()));
}

template <typename T>
bool next_p(T begin, T end) {
	const auto rbegin = reverse_iterator<T>(end);
	const auto rend = reverse_iterator<T>(begin);

	auto pivot = next(rbegin);
	while(pivot != rend && *pivot >= *prev(pivot))
		++ pivot;

	if (pivot == rend) {
		reverse(rbegin, rend);
		return false;
	} else {
		auto change = find_if(rbegin, pivot, bind1st(less<int>(), *pivot));
		swap(*change, *pivot);
		reverse(rbegin, pivot);
		return true;
	}
}

void permute3(const vector<int> &nums) {
	vector<int> n(nums);
	do {
		for (int i: n) {
			printf("%d ", i);
		}
		printf("\n");
	} while (next_p(n.begin(), n.end()));
}

int main() {
	vector<int> nums = {1, 2, 2, 3};
	permute1(nums);
	printf("----------------\n");
	permute2(nums);
	printf("----------------\n");
	permute3(nums);
	return 0;
}
