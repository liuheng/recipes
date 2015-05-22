#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	freopen("data.in", "r", stdin);
	int N = 0;
	int C = 0;
	while (EOF != scanf("%d %d", &N, &C)) {
		int w, v;
		int *R = new int[C+1];
		memset(R, 0, (C+1)*sizeof(int));
		for (int i=0; i<=N; ++i) {
			if (i>0) scanf("%d %d", &v, &w);
			for (int j=C; j>=0; --j) {
				if (i>0 && j>=v)
					R[j] = max(R[j], R[j-v] + w);
			}
		}
		printf("%d\n", R[C]);
		delete []R;
	}
	return 0;
}
