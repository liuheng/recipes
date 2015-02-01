#include <cctype>
#include <cassert>
#include <cstdio>
#include <cfenv>
#include <cinttypes>
#include <clocale>
#include <ctime>
#include <cstdlib>

using namespace std;

#define BUF_SIZE 1024

int main() {
    char *pEnd1 = NULL;
    char *pEnd2 = NULL;
    printf("%d - %f - %f\n", atoi("3"), strtof("3.14abcdefghi", &pEnd1), strtold("3.14jdksafo", &pEnd2));
    printf("%s\n", pEnd1);
    printf("%s\n", pEnd2);
    return 0;
}
