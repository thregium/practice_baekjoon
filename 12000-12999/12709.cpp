#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

/*
문제 : 길이 N(N <= 5) 단위로 순열을 만들어 그 단위로 주어진 길이 L(L <= 1000, N의 배수)의
소문자로 이루어진 문자열을 섞은 후 연속하는 덩어리의 가능한 가장 작은 크기를 구한다.

해결 방법 : 가능한 모든 순열에 대해 문자열을 만들어 보고 그 가운데 가장 덩어리의 수가
짧아지는 것을 선택하면 된다.

주요 알고리즘 : 문자열, 브루트 포스

출처 : GCJ 2008_2 D1번
*/

char s[1024], sd[1024];
int perm[16];

int main(void) {
    int t, n, l, res, cnt;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d", &n);
        if (n > 5) return 1;
        scanf("%s", s);
        l = strlen(s);
        for (int i = 0; i < n; i++) perm[i] = i;

        res = l;
        do {
            cnt = 0;
            for (int i = 0; i < l; i++) sd[i] = s[i / n * n + perm[i % n]];
            for (int i = 0; i < l; i++) {
                if (i == 0 || sd[i] != sd[i - 1]) cnt++;
            }
            if (cnt < res) res = cnt;
            
        } while (next_permutation(perm, perm + n));
        printf("Case #%d: %d\n", tt, res);
    }
    return 0;
}