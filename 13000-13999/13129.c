#include <stdio.h>

/*
문제 : 종이컵 N(N <= 1000)개를 쌓을 때 나올 수 있는 전체 높이를 오름차순으로 전부 출력한다.
겹치지 않는 부분의 높이는 A, 겹치는 부분의 높이는 B이다.

해결 방법 : 가장 낮은 높이는 A * N + B이고, 겹치지 않는 컵이 하나 나올 때 마다 B씩 추가된다.
최대 N - 1개까지 가능하므로 그렇게 N개를 출력하면 된다.

주요 알고리즘 : 기하학

출처 : Function 2016 DC번
*/

int main(void) {
    int a, b, n;
    scanf("%d %d %d", &a, &b, &n);
    for (int i = 0; i < n; i++) {
        printf("%d ", a * n + b * (i + 1));
    }
    return 0;
}
