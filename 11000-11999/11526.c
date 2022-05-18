#include <stdio.h>

/*
문제 : 무한 유리수 트리의 기약분수 P / Q(P, Q < 2^31)는 몇 번 정점인 지 구한다.

해결 방법 : 왼쪽과 오른쪽의 이동을 확인해 나가면서 답을 찾으면 된다.

주요 알고리즘 : 수학, 트리

출처 : GNY 2015 E번 // IIPC 2015 E번
*/

int main(void) {
    int t, o, stt;
    unsigned long long n, p, q;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %llu/%llu", &o, &p, &q);
        n = 0;
        for (int i = 0; i < 64; i++) {
            if (p > q) {
                n += (1ULL << i);
                p -= q;
            }
            else if (p < q) q -= p;
            else {
                n += (1ULL << i);
                break;
            }
        }
        printf("%d %llu\n", o, n);
    }
    return 0;
}