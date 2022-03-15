#include <stdio.h>

/*
문제 : 1부터 100까지의 자연수 가운데 하나인 N이 주어진다. 1 ~ 100 범위에서 우선 홀수인지 짝수인지 여부를
판별한 다음, 이분 탐색을 통해 N을 찾아나갈 때, N을 찾기까지 몇 회 걸리는 지 구한다.
짝수 개의 수가 남은 경우 더 작은 값을 검사한다.

해결 방법 : 처음에 홀짝 여부를 확인한 다음 범위를 적절히 바꾸어준다. 그리고 이분 탐색을 구현하면 된다.

주요 알고리즘 : 구현, 이분 탐색

출처 : NZPC 2007 G번
*/

int main(void) {
    int n, lo, hi, mid, r = 0;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        if (n & 1) {
            r = 1;
            lo = 0, hi = 49;
        }
        else {
            r = 0;
            lo = 1, hi = 50;
        }
        n >>= 1;
        while (1) {
            r++;
            mid = (lo + hi) >> 1;
            if (mid == n) break;
            else if (mid < n) lo = mid + 1;
            else hi = mid - 1;
        }
        printf("%d\n", r);
    }
    return 0;
}