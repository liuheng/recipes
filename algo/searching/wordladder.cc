#include <string>
#include <utility>
#include <queue>
#include <unordered_set>
#include <vector>
#include <cstdio>

using namespace std;

class Solution {
public:
    typedef struct {
        bool jump;
        int fi;
        int fj;
        int i;
        int j;
        int color;
    } Info;
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<Info> > table;
        vector<string> S;
        S.push_back(start);
        for (auto it=dict.begin(); it!=dict.end(); ++it) S.push_back(*it);
        S.push_back(end);
        for (int i=0; i<S.size(); ++i) {
            vector<Info> b;
            for (int j=0; j<S.size(); ++j) {
                Info temp;
                temp.fi = -1;
                temp.fj = -1;
                temp.i = i;
                temp.j = j;
                temp.color = 0;
                temp.jump = oneJump(S.at(i), S.at(j));
                b.push_back(temp);
            }
            table.push_back(b);
        }
        printB(table);
        return bfs(table, S);
    }
private:
    void printB(vector<vector<Info> > &V) {
        for (auto v: V) {
            for(auto b: v) printf("%d ", b.jump);
            printf("\n");
        }
    }

    vector<vector<string> > bfs(vector<vector<Info> > &table, vector<string> &S) {
        vector<vector<string> > result;
        queue<Info> Q;
        Q.push(table[S.size()-1][S.size()-1]);
        while (!Q.empty()) {
            Info k = Q.front();
            Q.pop();
            k.color = 2;
            for (int j=0; j<table.size(); ++j) {
                if (table[k.j][j].color == 0 && table[k.j][j].jump) {
                    Q.push(table[k.j][j]);
                    table[k.j][j].fi = k.i;
                    table[k.j][j].fj = k.j;
                    table[k.j][j].color = 1;
                    if (j == 0) {
                        vector<string> temp;
                        Info info = table[k.j][j];
                        while (true) {
                            temp.push_back(S.at(info.j));
                            if (info.j == S.size()-1) {
                                break;
                            }
                            info = table[info.fi][info.fj];
                        }
                        result.push_back(temp);
                    }
                }
            }
        }
        return result;
    }
    bool oneJump(const string &str1, const string &str2) {
        int diff = 0;
        for (int i=0; i<str1.length(); ++i) {
            if (str1.at(i) != str2.at(i)) diff++;
        }
        return diff == 1;
    }
};

void printV(vector<vector<string> > &V) {
    for (auto v: V) {
        for(string s: v) printf("%s ", s.c_str());
        printf("\n");
    }
}

int main() {
    Solution S;
    unordered_set<string> dict = {"hot","dot","dog","lot","log"};
    vector<vector<string> > V = S.findLadders("hit", "cog", dict);
    printV(V);
    return 0;
}
