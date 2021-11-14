#include <stdio.h>

/*
문제 : 육각형 좌표계 상의 좌표(0 <=, <= 10^6)가 주어질 때, 몇 번 칸인지를 구한다.

해결 방법 : 좌표의 범위가 O(N)에 가능한 범위이므로 X좌표와 Y좌표를 옮겨다니며 칸을 확인하면 된다.

주요 알고리즘 : 수학, 케이스 워크
*/

int main(void) {
    int ex, ey, x = 0, y = 0;
    long long p = 1, r = 1;
    scanf("%d %d", &ex, &ey);
    while (x < ex + ey) {
        r += p * 6;
        x++;
        p++;
    }
    if (ex == x && ey == y) {
        printf("%lld", r);
        return 0;
    }
    while (ex != x && ey != y) {
        r++;
        x--;
        y++;
    }
    printf("%lld", r - (p - 1) * 6);
    return 0;
}
