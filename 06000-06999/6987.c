#include <stdio.h>
#include <string.h>

/*
문제 : 6개 팀으로 이루어진 조별 리그의 승무패 결과가 가능한지 구한다.

해결 방법 : 먼저, 각 팀별 승무패 합이 5가 아니라면 불가능한 결과일 것이다.
그 외 경우에는 백트래킹을 통해 답을 찾아나간다. 매 경기마다의 승무패 결과를 추가하였을 때, 그 팀들의
승무패 수가 결과의 승무패 수보다 크지 않은 경우 그 상태에서 다음 결과를 살펴보는 방식이다.
마지막 경기까지 확인했을 때에는 모든 경기가 일치하는 상황일 것이고, 그러한 상황이 나오면 결과가 가능한 것이다.
나오지 않는다면 불가능하다.

주요 알고리즘 : 백트래킹

출처 : 정올 2008 초2/중1번
*/

int res[6][3], tmp[6][3];
const int play[15][2] = { {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {1, 2}, {1, 3}, {1, 4}, {1, 5},
    {2, 3}, {2, 4}, {2, 5}, {3, 4}, {3, 5}, {4, 5} };
int r;

void track(int x) {
    if (x == 15) {
        int t = 1;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                if (res[i][j] != tmp[i][j]) t = 0;
            }
        }
        if (t) r = 1;
        return;
    }
    if (tmp[play[x][0]][0] + 1 <= res[play[x][0]][0] && tmp[play[x][1]][2] + 1 <= res[play[x][1]][2]) {
        tmp[play[x][0]][0]++;
        tmp[play[x][1]][2]++;
        track(x + 1);
        tmp[play[x][0]][0]--;
        tmp[play[x][1]][2]--;
    }
    if (tmp[play[x][0]][1] + 1 <= res[play[x][0]][1] && tmp[play[x][1]][1] + 1 <= res[play[x][1]][1]) {
        tmp[play[x][0]][1]++;
        tmp[play[x][1]][1]++;
        track(x + 1);
        tmp[play[x][0]][1]--;
        tmp[play[x][1]][1]--;
    }
    if (tmp[play[x][0]][2] + 1 <= res[play[x][0]][2] && tmp[play[x][1]][0] + 1 <= res[play[x][1]][0]) {
        tmp[play[x][0]][2]++;
        tmp[play[x][1]][0]++;
        track(x + 1);
        tmp[play[x][0]][2]--;
        tmp[play[x][1]][0]--;
    }
}

int main(void) {
    int m;
    for (int i = 0; i < 4; i++) {
        r = 1;
        for (int j = 0; j < 6; j++) {
            scanf("%d %d %d", &res[j][0], &res[j][1], &res[j][2]);
            if (res[j][0] + res[j][1] + res[j][2] != 5) r = 0;
        }
        if (r == 0) {
            printf("0 ");
            continue;
        }
        r = 0;
        track(0);
        printf("%d ", r);
    }
    return 0;
}