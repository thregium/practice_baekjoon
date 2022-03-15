#include <stdio.h>
#define INF 103000

/*
문제 : N(N <= 100)개의 변수와 M(M <= 100)개의 커맨드가 존재한다. 각 커맨드는 K(K <= 100)개의 조건이
맞는 경우 해금된다. 각 조건은 변수가 일정값 이상 또는 이하인 경우로 주어진다.
각 변수는 올라갈 수만 있고 내려갈 수는 없다면 모든 조건을 해금하는 것이 가능한 지 구한다.

해결 방법 : 각 커맨드 사이 해금 순서를 간선으로 이은 다음, 이 그래프가 사이클이 있는 지 여부를
확인하는 것으로 전체 해금이 가능한 지 여부를 판별할 수 있다. 사이클이 없는 경우에만 전체 해금이 가능하다.
해금 순서가 생기는 경우는 두 커맨드 사이 변수 값이 겹치지 않는 경우로, 작은 쪽에서 큰 쪽의 순서로
해금을 해야만 한다(변수가 줄어들 수 없으므로). 이를 각 변수마다 해주면 그래프가 완성되고,
위에서 설명한대로 사이클을 찾으면 된다. N이 작으므로 사이클 여부는 여러 방법으로 찾을 수 있다.

주요 알고리즘 : 그래프 이론, 플로이드-워셜

출처 : JAG 2013SC A번
*/

char buff[8];
int comm[128][128][2], dist[128][128];

int small(int a, int b) {
    return a < b ? a : b;
}

int updown(int c1, int c2, int s) {
    int st1 = comm[c1][s][0], ed1 = comm[c1][s][1], st2 = comm[c2][s][0], ed2 = comm[c2][s][1];
    if (ed1 < st2) return -1;
    else if (ed2 < st1) return 1;
    else return 0;
}

int main(void) {
    int m, n, r = 1, k, s, t;
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            comm[i][j][0] = -INF;
            comm[i][j][1] = INF;
        }
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            scanf("%d %s %d", &s, buff, &t);
            if (buff[0] == '>' && t > comm[i][s][0]) comm[i][s][0] = t;
            if (buff[0] == '<' && t < comm[i][s][1]) comm[i][s][1] = t;
        }
        for (int j = 1; j <= n; j++) {
            if (comm[i][j][0] > comm[i][j][1]) r = 0;
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) dist[i][j] = INF;
    }
    
    for (int i = 1; i <= m; i++) {
        for (int j = i + 1; j <= m; j++) {
            for (int k = 1; k <= n; k++) {
                t = updown(i, j, k);
                if (t < 0) dist[i][j] = 1;
                else if (t > 0) dist[j][i] = 1;
            }
        }
    }

    for (int k = 1; k <= m; k++) {
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= m; j++) {
                dist[i][j] = small(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        if (dist[i][i] != INF) r = 0;
    }
    printf("%s\n", r ? "Yes" : "No");
    return 0;
}