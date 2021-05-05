#include <stdio.h>

/*
문제 : N(N <= 100)개의 문자열이 주어질 때, 한 개 이하의 문자를 삭제, 추가, 교체하여 첫 번째 문자열과 같은 구성으로 만들 수 있는 문자열의 수를 구한다.

해결 방법 : 우선 첫 번째 문자열의 구성을 확인한다. 다른 문자열들의 구성이 첫 번째 구성보다 많은 경우와 적은 경우의 차가 모두 1 이하인 경우
구성으로 만들 수 있는 경우이고, 2 이상이 하나라도 나오면 만들 수 없는 경우이다.

주요 알고리즘 : 문자열

출처 : 정올 2004지 초4/중2번
*/

char fwd[16], wd[16];
int fwc[26], wc[26];

int main(void) {
    int n, r = 0, t1, t2;
    scanf("%d", &n);
    scanf("%s", fwd);
    for (int i = 0; fwd[i]; i++) {
        fwc[fwd[i] - 'A']++;
    }
    for (int i = 1; i < n; i++) {
        scanf("%s", wd);
        for (int j = 0; wd[j]; j++) {
            wc[wd[j] - 'A']++;
        }
        t1 = 0;
        t2 = 0;
        for (int j = 0; j < 26; j++) {
            if (wc[j] > fwc[j]) t1 += wc[j] - fwc[j];
            if (wc[j] < fwc[j]) t2 += fwc[j] - wc[j];
            wc[j] = 0;
        }
        if (t1 <= 1 && t2 <= 1) r++;
    }
    printf("%d", r);
    return 0;
}