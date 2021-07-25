#include <stdio.h>

/*
문제 : A * C(A, C <= 10000) 크기의 직사각형을 레이저로 깎아 각 칸을 원하는 높이로 만들려고 한다.
이때, 깎아야 하는 횟수를 구한다. 레이저로는 한번에 연속된 곳의 높이를 1씩 깎을 수 있다.

해결 방법 : 깎아야 하는 칸의 개수를 각각의 칸에 대해 저장한다. 이 개수가 늘어나는 칸에 대해
이전 칸과의 깎을 칸 수 차이만큼 추가로 깎는 것을 반복하면 된다.

주요 알고리즘 : 구현

출처 : Brasil 2009 H번
*/

int x[10240];

int main(void) {
    int a, c, r;
    //freopen("E:\\PS\\ICPC\\Latin America\\Brasil\\2009\\laser.in", "r", stdin);
    while (1) {
        scanf("%d %d", &a, &c);
        if (a == 0) break;
        r = 0;
        for (int i = 1; i <= c; i++) {
            scanf("%d", &x[i]);
            x[i] = a - x[i];
            if (x[i] > x[i - 1]) r += (x[i] - x[i - 1]);
        }
        printf("%d\n", r);
    }
    return 0;
}