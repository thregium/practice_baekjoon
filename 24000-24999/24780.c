#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
문제 : 나무의 각 가지에서 뻗어나가는 가지들이 주어질 때, K번 가지에서 기둥으로 내려오는 방법을 구한다.
각 가지의 번호는 100 이하의 자연수이며, 연속하지 않을 수 있다.
가지들이 다시 합쳐지는 경우는 없다.

해결 방법 : 트리 형태의 그래프이므로 파싱한 후 루트 정점을 찾고, 이 위치로 가는 방법을
DFS를 통해 찾아낸 다음 경로를 출력하면 된다.

주요 알고리즘 : 그래프 이론, DFS, 트리, 파싱

출처 : VTH 2015 F번
*/

char buff[1024];
int branch[128][128], chk[128], path[128];
int root = -1;

void dfs(int x, int p, int d) {
    if (x == root) {
        for (int i = 0; i < d; i++) {
            printf("%d ", path[i]);
        }
        return;
    }
    for (int i = 1; i <= branch[x][0]; i++) {
        if (branch[x][i] == p) continue;
        path[d] = branch[x][i];
        dfs(branch[x][i], x, d + 1);
    }
}

int main(void) {
    int k, a, b;
    char* c;
    scanf("%d\n", &k);
    while (1) {
        fgets(buff, 103000, stdin);
        if (buff[strlen(buff) - 1] == '\n') buff[strlen(buff) - 1] = '\0';
        a = strtoll(strtok(buff, " "), NULL, 10);
        if (a < 0) break;
        chk[a] = 1;
        while (1) {
            c = strtok(NULL, " ");
            if (!c) break;
            b = strtoll(c, NULL, 10);
            branch[b][++branch[b][0]] = a;
        }
    }
    for (int i = 1; i <= 100; i++) {
        if (branch[i][0] == 0 && chk[i]) {
            if (root >= 0) return 1;
            root = i;
        }
    }
    path[0] = k;
    dfs(k, -1, 1);
    return 0;
}