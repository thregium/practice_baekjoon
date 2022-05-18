#include <stdio.h>

/*
문제 : 네 자연수 A, B, C, D(A, B, C, D <= 10000)가 주어질 때, 0 이상 100만 이내에 이 수들에 0 이상의
정수를 곱해서 더한 값으로 만들 수 없는 수의 개수를 구하고, 그 중 Frobenius number(그러한 수 가운데
가장 큰 수)가 있다면 그 수를, 없다면 -1을 출력한다.

해결 방법 : 간단한 냅색 DP를 통해 100만 이내에서 선형 결합으로 만들 수 없는 수의 개수를 구할 수 있다.
그리고 max(A, B, C, D) + 1만큼 더 세는 것을 통해 그 범위에 만들 수 없는 수가 있으면
F-num이 범위 안에 없는 것이고, 그 범위동안 없다면 F-num이 100만 안에서 가장 큰 만들 수 없는 수이다.

주요 알고리즘 : DP, 냅색, 수학

출처 : BAPC 2006Q B번
*/

char ex[1048576];

int main(void) {
    int t, a, b, c, d, r1, r2;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        ex[0] = 1;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        for (int i = a; i < 1048576; i++) ex[i] |= ex[i - a];
        for (int i = b; i < 1048576; i++) ex[i] |= ex[i - b];
        for (int i = c; i < 1048576; i++) ex[i] |= ex[i - c];
        for (int i = d; i < 1048576; i++) ex[i] |= ex[i - d];

        r1 = 0, r2 = -1;
        for (int i = 0; i < 1048576; i++) {
            if (!ex[i]) {
                if (i <= 1000000) r1++;
                r2 = i;
            }
            ex[i] = 0;
        }
        printf("%d\n%d\n", r1, r2 > 1000000 ? -1 : r2);
    }
    return 0;
}