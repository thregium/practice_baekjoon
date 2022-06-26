#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100)개의 음이 아닌 정수(<= 10^15)로 이루어진 비내림차순 배열이 주어진다.
이 배열의 한 숫자를 바꾸어 배열의 정렬 상태를 깰 수 있는 지 구한다.
단, 수가 0이 아닌 경우 0으로 시작할 수 없고, 숫자를 삭제하거나 삽입할 수 없다.

해결 방법 : 각 자리마다 하나씩 숫자를 바꾸어 보면서 그 중 양 옆 수에 대해 내림차순이 되는
경우가 있는지 확인한다. 있다면 그겋게 바뀐 수와 나머지 수열을 출력하고,
없는 경우 impossible을 출력하면 된다.

주요 알고리즘 : 브루트 포스, 구성적

출처 : NCPC 2020 A번
*/

char s[32], t[32];
long long a[128];

int main(void) {
    int n;
    long long x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 32; j++) {
            s[j] = '\0';
            t[j] = '\0';
        }
        sprintf(s, "%lld", a[i]);
        sprintf(t, "%lld", a[i]);
        for (int j = 0; t[j]; j++) {
            for (int k = 0; k <= 9; k++) {
                if (j == 0 && k == 0 && t[j + 1] != '\0') continue;
                if (k + '0' == s[j]) continue;
                t[j] = k + '0';
                x = strtoll(t, NULL, 10);
                if ((i > 0 && x < a[i - 1]) || (i < n - 1 && x > a[i + 1])) {
                    a[i] = x;
                    for (int ii = 0; ii < n; ii++) {
                        printf("%lld ", a[ii]);
                    }
                    return 0;
                }
            }
            t[j] = s[j];
        }
    }
    printf("impossible");
    return 0;
}