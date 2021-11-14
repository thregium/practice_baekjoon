#include <stdio.h>

/*
문제 : 1부터 50까지의 자연수 중 N이 주어질 때, 이분 탐색을 통해 N을 찾는 과정을 시뮬레이션 한다.

해결 방법 : 매번 중간값을 고른 다음, 그 수를 출력한다. 그 수가 N보다 크면 그 수보다 작은 범위에서 탐색을 진행하고
작으면 그 수보다 큰 범위에서 탐색을 진행한다. 이를 반복해 N이 되면 탐색을 종료하면 된다.

주요 알고리즘 : 구현, 시뮬레이션, 이분 탐색

출처 : NZPC 2016 G번
*/

int main() {
    int n, l, r, m;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        l = 1, r = 50;
        while (l <= r) {
            m = ((l + r) >> 1);
            printf("%d ", m);
            if (m == n) break;
            if (m > n) r = m - 1;
            else l = m + 1;
        }
        printf("\n");
    }
    return 0;
}