#include <stdio.h>

/*
문제 : N(N <= 100)개의 자연수(<= 2000)가 주어질 때, 주어진 수 가운데 가장 등장 횟수가 적은 것을 출력한다.
그러한 것이 여러 개인 경우 그 중 가장 작은 수를 출력한다.

해결 방법 : 각 수마다 등장 횟수를 구한 다음, 등장 횟수가 가장 작은 것을 구한다.
작은 수부터 확인하면 그 중 가장 작은 수를 찾을 수 있다.

주요 알고리즘 : 구현, 브루트 포스

출처 : JOI 2022예1 2-4번
*/

int a[128], cnt[2048];

int main(void) {
    int n, best = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= 2000; i++) {
        for (int j = 0; j < n; j++) {
            if (a[j] == i) cnt[i]++;
        }
    }
    cnt[0] = 103000;
    for (int i = 1; i <= 2000; i++) {
        if (cnt[i] != 0 && cnt[i] < cnt[best]) best = i;
    }
    printf("%d", best);
    return 0;
}