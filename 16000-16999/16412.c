#include <stdio.h>

/*
문제 : [L, R](123456 <= L < R <= 987654) 범위의 자연수 가운데 자릿수에 0이 없고 모든 자릿수가 다르며
모든 자릿수로 나누어 떨어지는 수의 개수를 구한다.

해결 방법 : L과 R의 범위가 작으므로 모든 수에 대해 개수를 세 보면 된다.

주요 알고리즘 : 브루트 포스

출처 : MidC 2018 H번
*/

int cnt[10];

int main(void) {
    int l, h, r = 0, t;
    scanf("%d %d", &l, &h);
    for (int i = l; i <= h; i++) {
        t = 1;
        for (int j = 0; j < 10; j++) cnt[j] = 0;
        for (int j = i; j; j /= 10) {
            cnt[j % 10]++;
            if (j % 10 == 0 || cnt[j % 10] > 1) t = 0;
            else if (i % (j % 10)) t = 0;
        }
        r += t;
    }
    printf("%d", r);
    return 0;
}