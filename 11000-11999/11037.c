#include <stdio.h>
#include <stdlib.h>

/*
문제 : 자연수 N(N < 10^9)이 주어질 때, 1에서 9 사이 수로 모든 자릿수가 다르면서 N보다 큰 수 가운데
가장 작은 수를 출력한다.

해결 방법 : 9자리 이하의 1에서 9 사이 수로 이루어진 모든 자릿수가 다른 수는 약 100만개 정도이다.
이는 직접 모두 확인하는 것이 가능한 양으로, 직접 모든 수를 배열에 저장한 다음, 정렬해 둔다.
그 뒤로 N이 들어올 때 마다 987654321 이상인 경우 더 큰 값이 없으므로 0을,
그 외 경우 이분 탐색으로 그 값보다 1 큰 가장 작은 값을 구해서 출력하면 된다.

주요 알고리즘 : 브루트 포스, 정렬, 이분 탐색

출처 : VHSPC 2014 L번
*/

int a[1048576], chk[16];
int acnt = 0;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

void track(int rem, int n) {
    a[acnt++] = n;
    for (int i = 1; i <= 9; i++) {
        if (chk[i]) continue;
        chk[i] = 1;
        track(rem - 1, n * 10 + i);
        chk[i] = 0;
    }
}

int main(void) {
    int n, lo, hi, mid;
    track(9, 0);
    qsort(a, acnt, sizeof(int), cmp1);
    while (scanf("%d", &n) != EOF) {
        if (n >= 987654321) {
            printf("0\n");
            continue;
        }
        n++;
        lo = 0, hi = acnt - 1;
        while (lo < hi) {
            mid = (lo + hi) >> 1;
            if (a[mid] >= n) hi = mid;
            else lo = mid + 1;
        }
        printf("%d\n", a[lo]);
    }
    return 0;
}
