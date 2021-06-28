#include <stdio.h>

/*
문제 : N * M 크기의 좌석의 L4번 좌석이 몇 번째 좌석인지 구한다. 없다면 -1을 출력한다.

해결 방법 : L4번 좌석은 12번째 행 4번째 칸이다. 따라서, N이 12보다 작거나 M이 4보다 작으면 그런 좌석은 있을 수 없다.
그런 좌석이 있다면 M * 11 + 4로 쉽게 구할 수 있다.

주요 알고리즘 : 수학, 사칙연산

출처 : GoodBye 2019 A번
*/

int main(void) {
    int t, n, m;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &n, &m);
        if (n < 12 || m < 4) printf("-1\n");
        else printf("%d\n", m * 11 + 4);
    }
    return 0;
}