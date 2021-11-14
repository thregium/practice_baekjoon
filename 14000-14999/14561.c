#include <stdio.h>

/*
문제 : 자연수 A(A <= 10^12)와 N(2 <= N <= 16)이 주어질 때, A를 N진법으로 나타내면 회문인지 구한다.

해결 방법 : A를 자릿수 단위로 분해해서 배열에 저장한 다음, 배열이 회문 형태인지 검사하면 된다.

주요 알고리즘 : 수학, 구현

출처 : 중앙대 2017R A번
*/

int num[64];

int main(void) {
    int t, n, p, r;
    long long a;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%lld %d", &a, &n);
        for (p = 0; a; p++, a /= n) {
            num[p] = a % n;
        }
        r = 1;
        for (int i = 0, j = p - 1; i < j; i++, j--) {
            if (num[i] != num[j]) r = 0;
        }
        printf("%d\n", r);
    }
    return 0;
}