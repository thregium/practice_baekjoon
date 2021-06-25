#include <stdio.h>
#include <string>
#include <unordered_map>
using namespace std;

/*
문제 : N(N <= 100000)개의 문자열 쌍이 주어진다. 그리고 M(M <= 100000)개의 문자열이 주어지는데, 각 문자열마다 해당 문자열에 대응하는 문자열을 구한다.
M개의 모든 문자열은 N개의 쌍에서 첫 번째로 주어진 문자열 중에 있다.

해결 방법 : 해시맵에 N개의 문자열 쌍을 대응시킨다. 이후로 M개의 문자열이 주어지면, 각 문자열마다 해시맵에서 대응하는 쌍을 찾아 출력하면 된다.

주요 알고리즘 : 자료구조, 해시맵, 문자열

출처 : 한양대E 2019HM F번
*/

unordered_map<string, string> um;
char buff1[32], buff2[32];

int main(void) {
    int n, m;
    string s1, s2;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s %s", buff1, buff2);
        s1.assign(buff1);
        s2.assign(buff2);
        um.insert(pair<string, string>(s1, s2));
    }
    for (int i = 0; i < m; i++) {
        scanf("%s", buff1);
        s1.assign(buff1);
        printf("%s\n", um.find(buff1)->second.data());
    }
    return 0;
}