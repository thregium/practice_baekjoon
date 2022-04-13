#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

/*
문제 : 자연수 N(N <= 10^20)이 주어질 때, N과 0이 아닌 숫자의 개수가 같은 수 가운데
N보다 큰 가장 작은 수를 구한다.

해결 방법 : 앞에 0을 추가한 후 다음 순열을 구하면 이것이 다음 값이 된다. 단, 앞의 0을 제거해야 한다.

주요 알고리즘 : 그리디 알고리즘, 문자열

출처 : GCJ 2009B B2번
*/

char n[32];

int main(void) {
    int t;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        n[0] = '0';
        scanf("%s", n + 1);
        next_permutation(n, n + strlen(n));
        if (n[0] == '0') printf("Case #%d: %s\n", tt, n + 1);
        else printf("Case #%d: %s\n", tt, n);
    }
    return 0;
}