#include <stdio.h>

/*
문제 : N개의 파편들이 주어진다. 각 파편은 4개 중 일부 조각들로 이루어져 있다.
위아래 조각 중 2개와 좌우 조각 중 2개를 모으면 칼을 만들 수 있을 때, 만들 수 있는 칼의 수와
각 방향에서 남은 조각의 수를 구한다.

해결 방법 : 각 방향 조각들을 전부 세 놓은 다음, 만들 수 있는 칼의 수를 구한다.
이는 양쪽 가운데 더 작은 쪽 값 / 2이다. 이 값의 2배를 각각 빼면 각 방향의 남은 조각의 수가 된다.

주요 알고리즘 : 구현

출처 : VTH 2018 E번
*/

char s[8];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n, tb = 0, lr = 0, res = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        tb -= s[0] - '1' + s[1] - '1';
        lr -= s[2] - '1' + s[3] - '1';
    }
    res = small(tb, lr) >> 1;
    printf("%d %d %d", res, tb - res * 2, lr - res * 2);
    return 0;
}
