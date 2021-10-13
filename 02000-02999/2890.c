#include <stdio.h>
#include <ctype.h>

/*
문제 : R * C(R, C <= 50) 크기의 카약 경기장에서 각 선수들이 왼쪽에서 오른쪽으로 이동중이다. 모든 카약은 가로 길이가 3이고,
카약은 9개로, 각각 1부터 9까지의 수로 표시된다. 각 카약 선수들이 몇위인지 구한다. 단, 동점자가 나오는 경우에는
같은 순위로 보고, 다음 순위는 그에서 1을 더한 순위이다.

해결 방법 : 오른쪽부터 경기장을 살피며 아직 순위가 확정되지 않은 선수가 나올 때 마다 해당 선수의 순위를
앞쪽(오른쪽) 열 까지의 순위 가운데 가장 낮은 순위 + 1로 정한다. 동점자 처리에 유의한다.  

주요 알고리즘 : 구현

출처 : COCI 09/10#6 1번
*/

char kay[64][64];
int rank[16];

int main(void) {
    int r, c, rn = 1, upd = 0;
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++) {
        scanf("%s", kay[i]);
    }
    for (int i = c - 2; i > 0; i--) {
        upd = 0;
        for (int j = 0; j < r; j++) {
            if (isdigit(kay[j][i]) && !rank[kay[j][i] - '0']) {
                upd = 1;
                rank[kay[j][i] - '0'] = rn;
            }
        }
        rn += upd;
    }
    for (int i = 1; i <= 9; i++) {
        printf("%d\n", rank[i]);
    }
    return 0;
}