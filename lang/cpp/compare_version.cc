#include <cstdio>
#include <string>

using namespace std;

int compareVersion(string version1, string version2) {
    int i = version1.find('.');
    int j = version2.find('.');
    while (i != -1 && j != -1) {
        int va = atoi(version1.substr(0, i).c_str());
        int vb = atoi(version2.substr(0, j).c_str());
        printf("%d - %d\n", va, vb);
        if (va != vb) {
            return va > vb ? 1 : -1;
        }
        version1 = version1.substr(i+1);
        version2 = version2.substr(j+1);
        printf("%s - %s\n", version1.c_str(), version2.c_str());
        i = version1.find('.');
        j = version2.find('.');
    }
    if (i != -1) {
        int va = atoi(version1.c_str());
        int vb = atoi(version2.substr(0, j).c_str());
        if (va != vb) {
            return va > vb ? 1 : -1;
        } else {
            return 1;
        }
    } else if (j != -1) {
        int va = atoi(version1.substr(0, i).c_str());
        int vb = atoi(version2.c_str());
        if (va != vb) {
            return va > vb ? 1 : -1;
        } else {
            return -1;
        }
    } else {
        int va = atoi(version1.c_str());
        int vb = atoi(version2.c_str());
        if (va != vb) {
            return va > vb ? 1 : -1;
        } else {
            return 0;
        }
    }
}

int main() {
    printf("%d\n", compareVersion("2.10", "2.5"));
    printf("%d\n", compareVersion("2.0.1", "2.5"));
    printf("%d\n", compareVersion("0.0.1", "0.1"));
    return 0;
}
