#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	freopen("data.in", "r", stdin);
	int N = 0;
	int C = 0;
	while (EOF != scanf("%d %d", &N, &C)) {
		int *w = new int[N];
		int *v = new int[N];
		int **R = new int*[N+1];
		for (int i=0; i<N; ++i) scanf("%d %d", &v[i], &w[i]);
		for (int i=0; i<=N; ++i) R[i] = new int[C+1];
		

		/* check input
		printf("%d %d\n", N, C);
		for (int i=0; i<N; ++i) printf("%d %d\n", w[i], v[i]);
		printf("\n");
		*/

		// do the work
		for (int i=0; i<=N; ++i) {
			for (int j=0; j<=C; ++j) {
				R[i][j] = i == 0 ? 0 : R[i-1][j];
				if (i>0 && j>=v[i-1])
					R[i][j] = max(R[i][j], R[i-1][j-v[i-1]] + w[i-1]);
			}
		}
		printf("%d\n", R[N][C]);

		int j = C;
		int *X = new int[N];
		for (int i=N; i>0; --i) {
			if (R[i][j] > R[i-1][j]) {
				X[i-1] = 1;
				j = C - v[i-1];
			} else {
				X[i-1] = 0;
			}
		}
		for (int i=0; i<N; ++i) printf("%d ", X[i]);
		printf("\n");

		for (int i=0; i<=N; ++i) delete [] R[i];
		delete []R;
		delete []w;
		delete []v;
		delete []X;
	}
	return 0;
}
