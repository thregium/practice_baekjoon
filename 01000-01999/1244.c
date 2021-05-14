#include <stdio.h>

/*
문제 : 길이가 N(N <= 100)인 0과 1로 이루어진 수열에 대해 다음과 같은 S(S <= 100)개의 연산을 수행한 결과를 출력한다.
1. Y의 배수 번호의 수를 반전시킨다. 2. Y가 중심이고 가장 넓은 범위를 갖는 팰린드롬에 대해 해당 범위의 모든 수를 반전시킨다.

해결 방법 : 문제의 설명대로 구현한다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : 정올 2000전 초2번
*/

int a[128];
int n;

void press(int x, int y) {
    if (x == 1) {
        for (int i = y; i <= n; i += y) {
            //y에서 시작해서 N이하의 수까지 모든 y의 배수에 대해
            a[i] = !a[i];
        }
    }
    else {
        for (int i = y, j = y; a[i] == a[j] && i > 0 && j <= n; i--, j++) {
            //y에서 i와 j값을 시작시키고 i와 j범위가 범위 안이며 i와 j번째 값이 같다면 범위를 1칸씩 넓힌다.
            a[i] = !a[i];
            a[j] = !a[j];
            if (i == j) a[i] = !a[i]; //처음에는 중복으로 뒤집히므로 한번 더 뒤집는다.
        }
    }
}

int main(void) {
    int s, x, y;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &s);
    for (int i = 0; i < s; i++) {
        scanf("%d %d", &x, &y);
        press(x, y);
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
        if (i % 20 == 0) printf("\n");
    }
    return 0;
}