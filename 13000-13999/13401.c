#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 200000)개의 생산 라인과 M(M <= 100000)개의 로봇 팔이 있다.
각 로봇 팔들은 두 라인 사이에 위치하고, 두 라인 사이의 물건들을 서로 옮기게 해 준다
(물론 옮기지 않을 수도 있다). 이때, 각 라인에 도달하도록 할 수 있는 출발 라인의 개수를 구한다.
로봇 팔의 X좌표(시작점에서의 거리)는 100000 이하로 모두 다르다.

해결 방법 : 로봇 팔을 X좌표의 내림차순으로 정렬한 다음, 시작 라인의 하한과 상한에 대해
해당 값이 나오는 끝 라인의 첫 값들을 저장해 둔다. 그 후, 이 값들을 로봇 팔이 나올 때 마다 갱신해준다.
갱신할 때에는 로봇 팔의 뒤쪽 라인의 뒤에 있는 값을 뒤쪽 라인의 상한으로, 앞쪽 라인에 있는 값을
뒤쪽 라인의 하한으로 갱신하면 된다. 이를 반복한 후, 각 끝 라인의 상한 - 하한 + 1을 각각 구하면 답이 된다.

주요 알고리즘 : DP?, 정렬, 애드 혹

출처 : Tsukuba 2016 C번
*/

int gu[204800], gd[204800], rob[103000][2], res[204800];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        gu[i] = i;
        gd[i] = i;
    }
    gd[n + 1] = n + 1;
    gu[n + 1] = n + 1;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &rob[i][0], &rob[i][1]);
    }
    qsort(rob, m, sizeof(int) * 2, cmp1);
    for (int i = 0; i < m; i++) {
        gd[rob[i][1] + 1] = gd[rob[i][1] + 2];
        gu[rob[i][1] + 1] = gu[rob[i][1]];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = gu[i]; j < gu[i + 1]; j++) res[j] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = gd[i]; j < gd[i + 1]; j++) res[j] -= i - 1;
    }
    for (int i = 1; i <= n; i++) {
        printf("%d%c", res[i], i == n ? '\n' : ' ');
    }
    return 0;
}