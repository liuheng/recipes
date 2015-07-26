#include <string>
#include <iostream>

using namespace std;

string countAndSay(int n) {
    if (n == 1) {
        return "1";
    } else if (n == 2) {
        return "11";
    } else {
        string s("11");
        while (--n > 1) {
            string s1;
            int count = 1;
            char value = s.at(0);
            int size = s.length();
            int i = 1;
            for (; i<size; ++i) {
                if (s[i] == s[i-1]) {
                    count++;
                } else {
                    s1 += to_string(count);
                    s1 += value;
                    count = 1;
                    value = s[i];
                }
            }
            s1 += to_string(count);
            s1 += value;
            s = s1;
        }
        return s;
    }
}

int main() {
    cout<<countAndSay(6)<<endl;
}
