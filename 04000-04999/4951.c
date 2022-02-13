#include <stdio.h>
#include <assert.h>

/*
문제 : N(N <= 24)개의 디스크가 놓여있다. 각 디스크의 위치와 반지름이 주어질 때, 제거할 수 있는 디스크의
최대 개수를 구한다. 디스크 2개가 다른 디스크와 겹치지 않고(한 점에서 만나는 경우는 겹치지 않는 것이다),
같은 색상인 경우 2개를 동시에 제거 가능하다. 제거한 다음 다른 디스크들이 해당 조건을 만족하는 경우
이를 반복하는 것이 가능하다. 문제에 주어진 순서개 위에서부터 본 디스크의 순서이다.
디스크의 색상은 최대 4개이고, 각 색상별 디스크는 최대 6개이다.

해결 방법 : 비트마스킹 DP를 이용하여 풀 수 있다.
각 남아있는 디스크에 대해 해당 상태가 가능한지 여부를 비트로 하여 그 중 가장 디스크가 적게 남았을 때의
디스크 개수를 원래 디스크 개수와 비교하면 된다.
각 같은 색상의 디스크 쌍마다 제거할 수 있는 지 보고 제거할 수 있는 경우
제거한 상태의 비트를 1로 바꾸어둔다. 이를 모든 디스크가 남은 상태에서 역순으로 0까지 반복하며
가능한 경우 가운데 가장 많이 제거한 경우의 답을 구해나가면 된다.
단, 불가능한 경우는 탐색하지 않아야 시간을 절약할 수 있다.

주요 알고리즘 : DP, 비트DP

출처 : JDC 2011 D번
*/

int disk[8][8][3], ccnt[8], pile[32], rpile[64]; //disk: 각 색상의 번째에 대한 디스크 정보
//ccnt: 각 색상별 디스크 개수, pile: 위에서부터 i번째의 디스크의 색상과 번째수,
//rpile: pile의 반대로 이동하는 배열
unsigned char mem[2097152]; //각 비트별로 해당 상태가 가능한 지 확인하는 배열

int main(void) {
    int n, x, y, r, c, tmp, res, sz;
    int* p, *q;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        res = -1;
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d %d", &x, &y, &r, &c);
            //값 저장
            pile[i] = (c << 3) + ccnt[c];
            rpile[(c << 3) + ccnt[c]] = i;
            disk[c][ccnt[c]][0] = x;
            disk[c][ccnt[c]][1] = y;
            disk[c][ccnt[c]++][2] = r;
        }
        r = (((1 << ccnt[4]) - 1) << 18) + (((1 << ccnt[3]) - 1) << 12) +
            (((1 << ccnt[2]) - 1) << 6) + (((1 << ccnt[1]) - 1));
        mem[r >> 3] |= (1 << (r & 7)); //초기값 저장
        sz = r;
        for (int i = r; i >= 0; i--) {
            if (!((mem[i >> 3] >> (i & 7)) & 1)) continue; //불가능한 경우 통과
            c = 0;
            for (int j = 0; j < 24; j++) c += ((i >> j) & 1);
            if (n - c > res) res = n - c; //결괏값 갱신
            for (int j = 1; j <= 4; j++) {
                for (int ii = 0; ii < ccnt[j]; ii++) {
                    //첫 번째 디스크를 확인한다.
                    if (!((i >> ((j - 1) * 6 + ii)) & 1)) continue;
                    tmp = 0;
                    for (int ix = rpile[(j << 3) + ii] - 1; ix >= 0; ix--) {
                        p = disk[j][ii];
                        q = disk[pile[ix] >> 3][pile[ix] & 7];
                        if (((i >> (((pile[ix] - 8) >> 3) * 6 + (pile[ix] & 7))) & 1) &&
                            (p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]) <
                            (p[2] + q[2]) * (p[2] + q[2])) {
                            tmp = 1;
                            break;
                        }
                    }
                    if (tmp) continue;
                    for (int jj = ii + 1; jj < ccnt[j]; jj++) {
                        //두 번째 디스크를 확인한다.
                        if (!((i >> ((j - 1) * 6 + jj)) & 1)) continue;
                        tmp = 0;
                        for (int ix = rpile[(j << 3) + jj] - 1; ix >= 0; ix--) {
                            p = disk[j][jj];
                            q = disk[pile[ix] >> 3][pile[ix] & 7];
                            if (((i >> (((pile[ix] - 8) >> 3) * 6 + (pile[ix] & 7))) & 1) &&
                                (p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]) <
                                (p[2] + q[2]) * (p[2] + q[2])) {
                                tmp = 1;
                                break;
                            }
                        }
                        if (tmp) continue;
                        r = i ^ (1 << ((j - 1) * 6 + ii)) ^ (1 << ((j - 1) * 6 + jj));
                        mem[r >> 3] |= (1 << (r & 7));
                        //둘을 제거 가능한 경우 둘을 제거한 결과를 배열에 저장한다.
                    }
                }
            }
        }

        assert(res >= 0);
        printf("%d\n", res);
        for (int i = 0; i <= 4; i++) ccnt[i] = 0;
        for (int i = 0; i <= (sz >> 3); i++) mem[i] = 0;
    }
    return 0;
}