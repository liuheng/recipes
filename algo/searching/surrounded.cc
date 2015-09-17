#include <vector>
#include <queue>
#include <cstdio>
#include <utility>

using namespace std;

void printC(vector<vector<int> > &board) {
    for (auto v: board) {
        for (int i: v)
            printf("%d ", i);
        printf("\n");
    }
}

class Solution {
public:
    void solve(vector<vector<char> >& board) {
        vector<vector<int> > color; // 0-未探索过，1-正在探索，2-探索完且失败，3-探索完且成功
        for (int i=0; i<board.size(); ++i) {
            vector<int> line;
            for (int j=0; j<board.size(); ++j) {
                line.push_back(0);
            }
            color.push_back(line);
        }
        for (int i=0; i<board.size(); ++i) {
            for (int j=0; j<board.size(); ++j) {
                bfs(board, i, j, color);
            }
        }
        for (int i=0; i<board.size(); ++i) {
            for (int j=0; j<board.size(); ++j) {
                if (color[i][j] == 3) board[i][j] = 'X';
            }
        }
    }
private:
    void bfs(vector<vector<char> > &board, int i, int j, vector<vector<int> > &color) {
        if (color[i][j] != 0) return;
        queue<pair<int, int> > Q;
        bool match = true;
        Q.push(make_pair(i, j));
        while (!Q.empty()) {
            auto item = Q.front();
            Q.pop();
            int m = item.first;
            int n = item.second;
            color[m][n] = 1;
            if (m==0 || m==board.size()-1 || n==0 || n==board.size()-1)
                match = false;
            if (m-1>=0 && board[m-1][n] == 'O' && color[m-1][n] == 0) {
                Q.push(make_pair(m-1, n));
            }
            if (n-1>=0 && board[m][n-1] == 'O' && color[m][n-1] == 0) {
                Q.push(make_pair(m, n-1));
            }
            if (m+1<board.size() && board[m+1][n] == 'O' && color[m+1][n] == 0) {
                Q.push(make_pair(m+1, n));
            }
            if (n+1<board.size() && board[m][n+1] == 'O' && color[m][n+1] == 0) {
                Q.push(make_pair(m, n+1));
            }
        }
        if (match) {
            Q.push(make_pair(i, j));
            while (!Q.empty()) {
                auto item = Q.front();
                Q.pop();
                int m = item.first;
                int n = item.second;
                color[m][n] = 3;
                if (m-1>=0 && board[m-1][n] == 'O' && color[m-1][n] == 1) {
                    Q.push(make_pair(m-1, n));
                }
                if (n-1>=0 && board[m][n-1] == 'O' && color[m][n-1] == 1) {
                    Q.push(make_pair(m, n-1));
                }
                if (m+1<board.size() && board[m+1][n] == 'O' && color[m+1][n] == 1) {
                    Q.push(make_pair(m+1, n));
                }
                if (n+1<board.size() && board[m][n+1] == 'O' && color[m][n+1] == 1) {
                    Q.push(make_pair(m, n+1));
                }
            }
        } else {
            Q.push(make_pair(i, j));
            while (!Q.empty()) {
                auto item = Q.front();
                Q.pop();
                int m = item.first;
                int n = item.second;
                color[m][n] = 2;
                if (m-1>=0 && board[m-1][n] == 'O' && color[m-1][n] == 1) {
                    Q.push(make_pair(m-1, n));
                }
                if (n-1>=0 && board[m][n-1] == 'O' && color[m][n-1] == 1) {
                    Q.push(make_pair(m, n-1));
                }
                if (m+1<board.size() && board[m+1][n] == 'O' && color[m+1][n] == 1) {
                    Q.push(make_pair(m+1, n));
                }
                if (n+1<board.size() && board[m][n+1] == 'O' && color[m][n+1] == 1) {
                    Q.push(make_pair(m, n+1));
                }
            }
        }
    }
};

void printV(vector<vector<char> > &board) {
    for (auto v: board) {
        for (char i: v)
            printf("%c ", i);
        printf("\n");
    }
}

int main() {
    freopen("data.in", "r", stdin);
    int N = 0;
    int input = 0;
    vector<vector<char> > board;
    scanf("%d\n", &N);
    for (int i=0; i<N; ++i) {
        vector<char> v;
        for (int j=0; j<N; ++j) {
            scanf("%c ", &input);
            v.push_back(input);
        }
        board.push_back(v);
    }
    printV(board);
    printf("------------------------------------\n");

    Solution S;
    S.solve(board);
    printV(board);
    return 0;
}
