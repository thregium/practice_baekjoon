#include <stdio.h>

/*
문제 : R * C(R, C <= 400) 크기의 배열에 '.', 'o', '<', '>', '^', 'v'의 여섯 문자가 있다. 이때, 이 배열에서
가로로 연속해서 ">o<" 또는 세로로 연속해서 "vo^"가 있는 부분의 개수를 구한다.

해결 방법 : 배열 전체를 살피면서 그러한 부분의 개수를 찾으면 된다. 배열 범위를 넘어 탐색하는 경우 초기화에 유의한다.

주요 알고리즘 : 구현, 브루트 포스

출처 : IPSC 2012 A번
*/

char candy[512][512];

int main(void) {
    int t, r, c, res = 0;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &r, &c);
        res = 0;
        for (int i = 0; i < r; i++) {
            scanf("%s", candy[i]);
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c - 2; j++) {
                if (candy[i][j] == '>' && candy[i][j + 1] == 'o' && candy[i][j + 2] == '<') res++;
            }
        }
        for (int i = 0; i < c; i++) {
            for (int j = 0; j < r - 2; j++) {
                if (candy[j][i] == 'v' && candy[j + 1][i] == 'o' && candy[j + 2][i] == '^') res++;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}