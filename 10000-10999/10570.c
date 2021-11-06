#include <stdio.h>

/*
문제 : V(V <= 1000)개의 1000 이하인 자연수들 가운데 가장 많이 나온 수 중 가장 작은 수를 구한다.

해결 방법 : 각 자연수의 등장 횟수를 센 다음, 작은 수부터 값들을 확인하며 가장 많이 등장한 값을 찾으면 된다.

주요 알고리즘 : 구현

출처 : PacNW 2014 N번
*/

int cnt[1024];

int main(void) {
    int n, v, s, r, b;
    scanf("%d", &n);
    for (int nn = 0; nn < n; nn++) {
        scanf("%d", &v);
        for (int i = 0; i < v; i++) {
            scanf("%d", &s);
            if (s > 1000 || s <= 0) return 1;
            cnt[s]++;
        }
        r = -1, b = -1;
        for (int i = 1; i <= 1000; i++) {
            if (cnt[i] > b) {
                b = cnt[i];
                r = i;
            }
            cnt[i] = 0;
        }
        if (r < 0) return 2;
        printf("%d\n", r);
    }
    return 0;
}