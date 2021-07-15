#include <stdio.h>

/*
문제 : N(N <= 100)개의 동전에 대해 K(K <= 100)번 저울을 사용한 기록이 주어진다. 이때 주어진 기록을 통해
무게가 다른 하나의 동전을 구할 수 있는지 확인하고 있다면 그 동전의 번호를 출력한다. 단, 모든 동전은 한개씩만 있다.

해결 방법 : N과 K의 크기가 작기 때문에 모든 동전에 대해 그 동전이 다른 동전보다 가볍거나 무겁다고 가정하고
결과에 대입해본다. 성립하면 그 동전이 가볍거나 무거울 수 있는 것이다. 모든 동전에 대해 확인한 후
무게가 다를 수 있는 동전의 수가 1개인 경우 그 동전의 번호를 출력하고 1개가 아니라면 구할 수 없다고 하면 된다.

주요 알고리즘 : 브루트 포스, 구현

출처 : NEERC 1998 A번
*/

int weight[128][128];

int main(void) {
    int n, k, res = 0, cnt = 0, twt, trs;
    char c;
    //freopen("E:\\PS\\ICPC\\Northern Eurasia\\Final\\1998\\TESTS\\COIN.20", "r", stdin);
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &weight[i][0]);
        for (int j = 1; j <= weight[i][0] * 2; j++) {
            scanf("%d", &weight[i][j]);
        }
        scanf(" %c", &c);
        if (c == '<') weight[i][127] = -1;
        else if (c == '>') weight[i][127] = 1;
    }
    for (int i = 1; i <= n; i++) {
        trs = 1;
        for (int j = 0; j < k; j++) {
            twt = 0;
            for (int ii = 1; ii <= weight[j][0]; ii++) {
                if (weight[j][ii] == i) twt++;
            }
            for (int ii = weight[j][0] + 1; ii <= weight[j][0] * 2; ii++) {
                if (weight[j][ii] == i) twt--;
            }
            if (twt != weight[j][127]) {
                trs = 0;
                break;
            }
        }
        if (trs) {
            res = i;
            cnt++;
            continue;
        }
        trs = 1;
        for (int j = 0; j < k; j++) {
            twt = 0;
            for (int ii = 1; ii <= weight[j][0]; ii++) {
                if (weight[j][ii] == i) twt--;
            }
            for (int ii = weight[j][0] + 1; ii <= weight[j][0] * 2; ii++) {
                if (weight[j][ii] == i) twt++;
            }
            if (twt != weight[j][127]) {
                trs = 0;
                break;
            }
        }
        if (trs) {
            res = i;
            cnt++;
        }
    }

    if (cnt == 1) printf("%d", res);
    else printf("0");
    return 0;
}