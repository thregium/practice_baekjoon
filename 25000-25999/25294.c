#include <stdio.h>
#include <stdlib.h>

/*
문제 : N * N(N <= 9999) 크기의 달팽이 형태에 대해 다음 쿼리에 응답한다. 달팽이는 왼쪽 위에서 오른쪽으로
오름차순으로 이동한다.
1. N X Y가 주어질 때, (X, Y)에 있는 수를 출력한다.
2. N X가 주어질 때, X가 있는 칸의 좌표를 출력한다.

해결 방법 : 바퀴수를 센 다음 방향에 따라 각각 처리한다.

주요 알고리즘 : 수학, 구현, 케이스 워크
*/

int main(void) {
    int q, o, n, x, y, mid, base, res;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d %d %d", &o, &n, &x);
        mid = (n >> 1) + 1;
        if (o == 1) {
            scanf("%d", &y);
            base = abs(x - mid);
            if (abs(y - mid) > base) base = abs(y - mid);
            base = base * 2 - 1;
            if (base < 0) {
                printf("%d\n", n * n);
                continue;
            }
            res = n * n - base * base;
            if (x != y && y == mid - (base >> 1) - 1) {
                printf("%d\n", res - (x - (mid - (base >> 1))));
                continue;
            }
            else res -= base + 1;
            if (x == mid + (base >> 1) + 1) {
                printf("%d\n", res - (y - (mid - (base >> 1))));
                continue;
            }
            else res -= base + 1;
            if (y == mid + (base >> 1) + 1) {
                printf("%d\n", res - ((mid + (base >> 1)) - x));
                continue;
            }
            else res -= base + 1;
            if (x == mid - (base >> 1) - 1) {
                printf("%d\n", res - ((mid + (base >> 1)) - y));
                continue;
            }
            else return 3;
        }
        else if (o == 2) {
            x = n * n - x;
            for (base = 1; base * base <= x; base += 2);
            base -= 2;
            if (base < 0) {
                printf("%d %d\n", mid, mid);
                continue;
            }
            x -= base * base;
            if (x < base + 1) {
                printf("%d %d\n", mid - (base >> 1) + x, mid - (base >> 1) - 1);
                continue;
            }
            else x -= base + 1;
            if (x < base + 1) {
                printf("%d %d\n", mid + (base >> 1) + 1, mid - (base >> 1) + x);
                continue;
            }
            else x -= base + 1;
            if (x < base + 1) {
                printf("%d %d\n", mid + (base >> 1) - x, mid + (base >> 1) + 1);
                continue;
            }
            else x -= base + 1;
            if (x < base + 1) {
                printf("%d %d\n", mid - (base >> 1) - 1, mid + (base >> 1) - x);
                continue;
            }
            else return 2;
        }
        else return 1;
    }
    return 0;
}