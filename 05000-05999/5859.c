#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : N(N <= 1000)명의 사람이 있고, 모든 사람들은 참말만 하거나 거짓말만 한다. 이 사람들 에게 M(M <= 10000)개의 질문을 하였다.
각 질문은 x에게 y가 참말만 하는지 거짓말만 하는지 물어본 것이다. 여기서 x와 y는 서로 다른 사람이다.
이때, 질문을 앞쪽부터 하였을 때, 질문의 결과가 일관성을 갖는 질문 개수의 최댓값을 구한다.

해결 방법 : 매개 변수 탐색을 통해 질문 개수를 옮겨가며 값을 구하면 log(M) * (탐색 시간) 내에 답을 구할 수 있다.
질문의 결과가 일관성을 갖는지는 이분 그래프 판별과 유사한 방식을 이용해 풀 수 있다.
각 질문에서 결과가 거짓말이라면 두 사람은 참말과 거짓말 여부가 다른 것이고, 참말이라면 여부가 같은 것이다.

따라서, 모든 사람들에 대해 확인해보면서 아직 확인하지 않은 사람이 나오면 그 사람이 참말만 한다고 가정하고
서로 반대인 관계의 사람이 나오면 참/거짓을 바꿔서 이동한다. 이때, 현재와 모순되는 경우가 나오는지 확인하면 된다.
관계를 설정할 때에는 한 쪽의 관계가 설정되면 반대쪽의 관계도 설정된다. 그렇기에 한 쪽의 결과로 반대쪽 간선까지 이을 수 있다.
이를 이용해 해당하는 결과의 반대가 이미 간선으로 있다면 바로 모순임을 알 수 있다.

주요 알고리즘 : 그래프 이론, 플러드필, 파라메트릭

출처 : USACO 2013J B3번
*/

int que[10240][3], ed[1024][1024], color[1024];

int dfs(int n, int x, int c) {
    int r = 0;
    color[x] = c;
    for (int i = 1; i <= n; i++) {
        if (ed[x][i] < 0) {
            if (color[i] == c) return 1; //서로 반대여야 하는데 같은 경우
            if (color[i] == 0) r |= dfs(n, i, (c == 1) ? 2 : 1);
        }
        else if (ed[x][i] > 0) {
            if (color[i] && color[i] != c) return 1; //서로 같아야 하는데 반대인 경우
            if (color[i] == 0) r |= dfs(n, i, c);
        }
    }
    return r; //모순이 있으면 1, 없으면 0
}

int getres(int n, int m) {
    int x, y, tl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) ed[i][j] = 0;
    }
    for (int i = 0; i < m; i++) {
        x = que[i][0], y = que[i][1], tl = que[i][2];
        if (ed[x][y]) {
            if (tl != ed[x][y]) return 0; //이미 있는 간선과 반대라면 모순이다.
            else continue;
        }
        else {
            if (tl < 0) {
                ed[x][y] = -1;
                ed[y][x] = -1;
            }
            else if (tl > 0) {
                ed[x][y] = 1;
                ed[y][x] = 1;
            }
        }
    }

    for (int i = 1; i <= n; i++) color[i] = 0;
    for (int i = 1; i <= n; i++) {
        if (color[i]) continue;
        if (dfs(n, i, 1)) return 0; //모순이 생긴 경우
    }
    return 1; //가능한 경우
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("truth.in", "r");
        fo = fopen("truth.out", "w");
    }

    int n, m, x, y, lo, hi, mid;
    char tl;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %c", &que[i][0], &que[i][1], &tl);
        if (tl == 'L') que[i][2] = -1;
        else if (tl == 'T') que[i][2] = 1;
        else return 1;
    }

    lo = 0, hi = m; //파라메트릭을 이용해 답을 찾는다.
    while (lo < hi) {
        mid = ((lo + hi + 1) >> 1);
        if (getres(n, mid)) lo = mid;
        else hi = mid - 1;
    }
    printf("%d", lo);
    return 0;
}