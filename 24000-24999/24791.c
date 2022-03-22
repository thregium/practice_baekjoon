#include <stdio.h>
#include <string.h>

/*
문제 : 10개의 포지션간의 관계와 각 선수들의 국적, 리그, 팀이 주어질 때, 각 선수의 시너지가
관계 수 이상이 되도록 포지션을 짤 수 있는 지 구한다. (제한시간 4초)
국적, 리그, 팀은 15자 이하의 대소문자 및 '-'로 주어진다.
선수들이 같은 팀에서 뛰는 경우 시너지 2, 같은 팀은 아니지만 같은 리그인 경우 시너지 1,
같은 국적인 경우 시너지 1이 주어진다.

해결 방법 : 10!가지의 모든 경우에 대해 확인해 보면서 각 선수들을 배치했을 때
시너지가 관계 수 이상이 되는 경우가 있는 지 매번 확인해 보면 된다.

주요 알고리즘 : 그래프 이론, 브루트 포스

출처 : VTH 2016 I번
*/

char info[16][4][32];
int pos[16], vis[16], ed[16][16];
int res = 0;

void track(int x) {
    int syn;
    if (x == 10) {
        for (int i = 0; i < 10; i++) {
            syn = 0;
            for (int j = 1; j <= ed[i][0]; j++) {
                if (!strcmp(info[pos[i]][3], info[pos[ed[i][j]]][3])) syn += 2;
                else if (!strcmp(info[pos[i]][2], info[pos[ed[i][j]]][2])) syn += 1;
                if (!strcmp(info[pos[i]][1], info[pos[ed[i][j]]][1])) syn += 1;
            }
            if (syn < ed[i][0]) return;
        }
        res = 1;
        return;
    }

    for (int i = 0; i < 10; i++) {
        if (vis[i]) continue;
        pos[x] = i;
        vis[i] = 1;
        track(x + 1);
        vis[i] = 0;
    }
}

int main(void) {
    int c, a, b;
    scanf("%d", &c);
    for (int i = 0; i < c; i++) {
        scanf("%d %d", &a, &b);
        ed[a][++ed[a][0]] = b;
        ed[b][++ed[b][0]] = a;
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%s", info[i][j]);
        }
    }
    track(0);
    printf("%s", res ? "yes" : "no");
    return 0;
}