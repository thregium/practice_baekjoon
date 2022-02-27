#include <stdio.h>

/*
문제 : N(N <= 10000)개의 주사위 각 면에 쓰인 수들이 주어지면, 모든 주사위를 쌓아서 만들 수 있는
앞면의 합 중 가장 큰 값을 구한다. 단, 위아래로 인접한 주사위는 아래 주사위의 윗면과
위 주사위의 아랫면에 쓰인 수가 같아야 한다. 각 주사위는 1에서 6까지의 수가 1번씩만 쓰여 있다.

해결 방법 : 맨 밑 주사위를 고정하면 나머지 주사위를 쌓는 방법은 위아래가 고정이므로
좌우로 돌리는 4가지 경우밖에 없다. 나머지 주사위들은 그 중 앞면을 가장 크게 하는 것으로 잡고,
맨 밑 주사위를 6가지 모두 한 번씩 돌려보며 확인하면 된다.

주요 알고리즘 : 구현, 그리디, 브루트 포스

출처 : 정올 2003 초2번 // IIPC 2005 C번
*/

int dice[10240][6];

int big(int a, int b) {
    return a > b ? a : b;
}

int getfront(int n, int x) {
    if (x == 0 || x == 5) return big(big(dice[n][1], dice[n][2]), big(dice[n][3], dice[n][4]));
    else if(x == 1 || x == 3) return big(big(dice[n][0], dice[n][2]), big(dice[n][4], dice[n][5]));
    else return big(big(dice[n][0], dice[n][1]), big(dice[n][3], dice[n][5]));
}

int gettop(int n, int x) {
    if (x == 0) return dice[n][5];
    else if (x == 1) return dice[n][3];
    else if (x == 2) return dice[n][4];
    else if (x == 3) return dice[n][1];
    else if (x == 4) return dice[n][2];
    else return dice[n][0];
}

int main(void) {
    int n, c, l, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            scanf("%d", &dice[i][j]);
        }
    }
    for (int i = 0; i < 6; i++) {
        l = dice[0][i];
        c = getfront(0, i);
        for (int j = 1; j < n; j++) {
            for (int k = 0; k < 6; k++) {
                if (dice[j][k] == l) {
                    c += getfront(j, k);
                    l = gettop(j, k);
                    break;
                }
            }
        }
        r = big(r, c);
    }
    printf("%d", r);
    return 0;
}