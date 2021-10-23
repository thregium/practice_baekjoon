#include <stdio.h>

/*
문제 : A(A <= 2000)명이 번데기 게임을 할 때, T(T <= 10000)번째 오는 번 또는 데기는 몇 번째 사람이 외치게 되는지 구한다.

해결 방법 : T가 작은 편이므로 게임을 직접 진행해 나간다. 매번 번 또는 데기를 외칠 때 마다 T번이 되었는지 확인하고
T번이 되는 순간 탐색을 종료하고 해당 번째까지의 횟수를 출력하면 된다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : 중앙대 2018R 3번
*/

int check(int g, int t, int cb, int cd) {
    if ((g == 0 && cb < t) || (g == 1 && cd < t)) return 0;
    else return 1;
}

int main(void) {
    int a, t, g, cb = 0, cd = 0, cn = 2, r = 0;
    scanf("%d%d%d", &a, &t, &g);
    while (!check(g, t, cb, cd)) {
        for (int i = 0; i < 2; i++) {
            cb++;
            if (check(g, t, cb, cd)) break;
            r++;
            cd++;
            if (check(g, t, cb, cd)) break;
            r++;
        }
        for (int i = 0; i < cn; i++) {
            cb++;
            if (check(g, t, cb, cd)) break;
            r++;
        }
        if (check(g, t, cb, cd)) break;
        for (int i = 0; i < cn; i++) {
            cd++;
            if (check(g, t, cb, cd)) break;
            r++;
        }
        if (check(g, t, cb, cd)) break;
        cn++;
    }
    printf("%d", r % a);
    return 0;
}