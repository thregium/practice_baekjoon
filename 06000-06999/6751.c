#include <stdio.h>

/*
문제 : 10000 이하의 자연수가 주어질 때, 이 수보다 큰 수 가운데 모든 자릿수가 다른 가장 작은 수를 구한다.

해결 방법 : 아무리 커도 10234 이내로는 답이 나오기 때문에 직접 모든 경우를 해보면 된다.

주요 알고리즘 : 구현, 브루트 포스

출처 : CCC 2013 J3/S1번
*/

int cnt[10];

int main(void) {
    int n, r;
    scanf("%d", &n);
    for (int i = n + 1;; i++) {
        for (int j = i; j; j /= 10) cnt[j % 10]++;
        r = 1;
        for (int j = 0; j < 10; j++) {
            if (cnt[j] > 1) r = 0;
            cnt[j] = 0;
        }
        if (r) {
            printf("%d", i);
            break;
        }
    }
    return 0;
}