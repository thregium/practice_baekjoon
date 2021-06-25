#include <stdio.h>
#include <unordered_set>
using namespace std;

/*
문제 : N(N <= 10000)개의 문자열이 먼저 주어지고, 이후로 M(M <= 10000)개의 문자열이 주어진다. M개의 문자열 가운데
N개의 문자열에서 나왔던 것의 개수를 구한다. 모든 문자열의 길이는 500 이하이다.

해결 방법 : N개의 문자열을 해시셋에 저장한 후 M개의 문자열 가운데 해시셋에서 존재하던 문자열의 수를 구하면 된다.

주요 알고리즘 : 문자열, 자료구조, 해시셋
*/

char buff[512];
unordered_set<string> us;

int main(void) {
    int n, m, r = 0;
    string s;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", buff);
        s.assign(buff);
        us.insert(s);
    }
    for (int i = 0; i < m; i++) {
        scanf("%s", buff);
        s.assign(buff);
        if (us.find(s) != us.end()) r++;
    }
    printf("%d", r);
    return 0;
}