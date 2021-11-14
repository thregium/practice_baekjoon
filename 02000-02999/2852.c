#include <stdio.h>
#include <stdlib.h>

/*
문제 : 48분의 농구 게임에서 양 팀의 득점이 N(N <= 100)회 주어진다.
모든 득점이 같은 점수라면 양 팀이 이기고 있던 시간을 각각 출력한다.

해결 방법 : 각 팀이 득점한 시각을 기준으로 오름차순으로 정렬한 다음, 현재 골 수를 바탕으로 이기고 있는 팀의
시간을 최근 득점부터의 시간만큼 추가한다. 그 다음 골을 추가한다. 이를 반복한 다음 양 팀의 승리 시간을 출력하면 된다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : COCI 10/11#5 2번
*/

int goal[128][2];

int cmp1(const void* a, const void* b) {
    int ai = *((int*)a + 1);
    int bi = *((int*)b + 1);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, h, m, x, l = 0, ag = 0, bg = 0, aw = 0, bw = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d:%d", &goal[i][0], &h, &m);
        goal[i][1] = h * 60 + m;
    }
    qsort(goal, n, sizeof(int) * 2, cmp1);
    for (int i = 0; i < n; i++) {
        if (ag > bg) aw += goal[i][1] - l;
        else if (ag < bg) bw += goal[i][1] - l;
        if (goal[i][0] == 1) ag++;
        else if (goal[i][0] == 2) bg++;
        l = goal[i][1];
    }
    if (ag > bg) aw += 2880 - l;
    else if (ag < bg) bw += 2880 - l;
    printf("%02d:%02d\n%02d:%02d", aw / 60, aw % 60, bw / 60, bw % 60);
    return 0;
}