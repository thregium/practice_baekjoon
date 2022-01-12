#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 10000)개의 역에 도착/역에서 출발하는 열차의 일정이 시:분:초 단위로 주어진다.
이 노선은 순환선이기 때문에 역에서 출발한 열차가 다시 역에 도착할 수 있고 심지어 0초만에 다시 도착하는 것도 가능하다.
이때, 주어진 시간표를 맞추기 위해 필요한 열차의 최소 대수를 구한다. 단, 자정을 넘겨 역에 서있는 열차는 없다.
(제한시간 8초)

해결 방법 : 일찍 출발한 열차를 가능한 빠른 다음 일정에 다시 역으로 들어오게 한다. 이렇게 되면 해당 일정이 포함된 열차를
가장 많이 재활용할 수 있으며, 이를 반복하면 열차의 최소 대수가 된다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : JAG 2007D B번
*/

int tm[10240][2], chk[10240];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, h, m, s, r, end, arv;
    //freopen("E:\\PS\\Contest\\Japanese Alumni Group\\2007D\\judge-data\\B\\B4", "r", stdin);
    //freopen("E:\\PS\\Contest\\Japanese Alumni Group\\2007D\\judge-data\\B\\B4_t.ans", "w", stdout);
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                scanf("%d:%d:%d", &h, &m, &s);
                tm[i][j] = h * 3600 + m * 60 + s;
            }
        }
        qsort(tm, n, sizeof(int) * 2, cmp1);

        r = 0, arv = 0;
        while (arv < n) {
            end = 0;
            for (int i = 0; i < n; i++) {
                if (!chk[i] && tm[i][0] >= end) {
                    chk[i] = 1;
                    arv++;
                    end = tm[i][1];
                }
            }
            r++;
        }
        printf("%d\n", r);

        for (int i = 0; i < n; i++) chk[i] = 0;
    }
    return 0;
}