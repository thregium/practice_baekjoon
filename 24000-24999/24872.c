#include <stdio.h>
#include <stdlib.h>
#define INF 1234567890987654321

/*
문제 : 10^17 이하의 자연수 X와 0 또는 1인 K가 주어질 때, X 이상이면서 최대 K개 이하의 수를 제외하면
모두 같은 숫자인 가장 작은 수를 구한다.

해결 방법 : 1개 이하의 숫자를 제외한 모두 같은 숫자로 이루어진 수는 많지 않기 때문에
이러한 수들을 브루트 포스로 전부 찾아낸 다음 그 수들 모두와 비교하는 방식으로 답을 찾아낼 수 있다.

주요 알고리즘 : 브루트 포스, 수학

출처 : ROI 2021R 6번
*/

char s[32];
long long k0[2048], k1[16384];

int main(void) {
    int p0 = 0, p1 = 0;
    long long x, k, r = INF;
    for (int i = 1; i <= 18; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k < i; k++) s[k] = j + '0';
            for (int k = 0; k < i; k++) {
                for (int l = 0; l <= 9; l++) {
                    if (k + l == 0 || (j == 0 && k != 0)) continue;
                    s[k] = l + '0';
                    if (l == j) k0[p0++] = strtoll(s, NULL, 10);
                    else k1[p1++] = strtoll(s, NULL, 10);
                }
                s[k] = j + '0';
            }
        }
    }
    scanf("%lld%lld", &x, &k);
    for (int i = 0; i < p0; i++) {
        if (k0[i] < r && k0[i] >= x) r = k0[i];
    }
    if (k == 1) {
        for (int i = 0; i < p1; i++) {
            if (k1[i] < r && k1[i] >= x) r = k1[i];
        }
    }
    printf("%lld", r);
    return 0;
}