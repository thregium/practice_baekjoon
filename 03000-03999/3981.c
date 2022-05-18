#include <stdio.h>

/*
문제 : N(N <= 500)개의 자연수(<= 5 * 10^7)가 차례로 주어질 때, X가 i일 때의 값이 해당 자연수가 되도록
만들 수 있는 지 여부를 구한다.

해결 방법 : 인접한 수끼리 빼는 것을 3번 반복하면 3차항의 값이 된다.
이 값이 일정하다면 3차함수로 나타낼 수 있고, 일정하지 않다면 3차함수로 나타낼 수 없다.

주요 알고리즘 : 수학

출처 : GCPC 2010 H번
*/

long long a[512];

int main(void) {
    int t, n, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        if (n <= 4) {
            printf("YES\n");
            continue;
        }
        for (int i = 0; i < 3; i++) {
            for (int j = n - 1; j > i; j--) a[j] -= a[j - 1];
        }
        r = 1;
        for (int i = 4; i < n; i++) {
            if (a[i] != a[i - 1]) r = 0;
        }
        printf("%s\n", r ? "YES" : "NO");
    }
    return 0;
}