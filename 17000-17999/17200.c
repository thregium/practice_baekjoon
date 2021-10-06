#include <stdio.h>
#include <string.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : N(N <= 25)마리의 소들이 있고, 각 소들은 25개 이하의 형질을 갖고 있다. 각 소들은 아무 형질도 없는 소에서
분화하여 형질이 추가되었다고 할 때, 형질당 한 번씩만 분화하여 각 소들의 형질이 모두 만족될 수 있는지 구한다.
단, 형질이 완벽히 같은 소의 쌍은 없다.

해결 방법 : 만약 어떤 소의 형질이 다른 소의 모든 형질을 포함한다면 그 소는 다른 소의 자손일 것이다.
이를 이용해 각 형질에 대해 자손인 형질을 갖는 소들을 전부 단방향 간선으로 연결시킨다.
이때, 자식 뿐 아니라 손자, 증손자... 등도 연결이 되게 된다. 이는 각 자손에 대해 자손의 자손들을 확인하며
자손의 자손인 소들로 향하는 간선은 지워주는 방식으로 자식들만 남길 수 있다.

자식들만 남길 수 있게 되면 마지막으로, 각 소들(+ 아무 형질도 없는 가상의 조상 소)에서
출발하여 모든 소들을 2회 이상 거치지 않고 자식 관계로 도달 가능한지 확인한다.
그러한 경우가 존재하면 그러한 소가 조상인 경우로 만족이 가능한 것이다.
존재하지 않는다면 만족할 수 없는 경우이다.

주요 알고리즘 : 그래프 이론, 트리, 위상 정렬?

출처 : USACO 2019O B3번
*/

char evo[32][32][32];
int ed[32][32], cnt[32], vis[32];
int dup = 0;

int dfs(int x) {
    //dfs를 통해 서브트리의 크기를 구함
    int r = 1;
    vis[x] = 1;
    for (int i = 1; i <= ed[x][0]; i++) {
        if (vis[ed[x][i]]) dup++;
        else r += dfs(ed[x][i]);
    }
    return r;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("evolution.in", "r");
        fo = fopen("evolution.out", "w");
    }
    int n, tmp, adde;
    scanf("%d", &n);
    tmp = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &cnt[i]);
        tmp += cnt[i];
        for (int j = 0; j < cnt[i]; j++) {
            scanf("%s", evo[i][j]);
        }
    }
    n += !tmp; //형질이 없는 소가 없다면 그러한 가상의 소를 추가함
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            adde = 1;
            for (int k = 0; k < cnt[i]; k++) {
                tmp = 0;
                for (int l = 0; l < cnt[j]; l++) {
                    if (strcmp(evo[i][k], evo[j][l]) == 0) {
                        tmp = 1;
                        break;
                    }
                }
                if (tmp == 0) {
                    adde = 0;
                    break;
                }
            }
            if (adde) ed[i][++ed[i][0]] = j; //만약 모든 형질이 포함되는 소가 있다면 그 소의 자손 노드로 들어감
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= ed[j][0]; k++) {
                if (k < 1) continue;
                tmp = 0;
                for (int l = 1; l <= n; l++) vis[l] = 0;
                dfs(ed[j][k]);
                vis[ed[j][k]] = 0;
                for (int l = 1; l <= ed[j][0]; l++) {
                    if (!vis[ed[j][l]]) continue;
                    for (int m = l; m < ed[j][0]; m++) {
                        ed[j][m] = ed[j][m + 1];
                    }
                    ed[j][ed[j][0]] = 0;
                    ed[j][0]--; //자손의 자손인 소들로 향하는 간선을 제거함
                    k--;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) vis[j] = 0;
        dup = 0; //트리 형태가 아니면 안됨
        if (dfs(i) == n) {
            //i번 노드가 루트
            if (dup == 0) {
                printf("%s", "yes");
                return 0;
            }
        }
    }
    printf("%s", "no");
    return 0;
}