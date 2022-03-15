#include <stdio.h>
#include <stdlib.h>

/*
문제 : M(M <= 16, 짝수)개의 정수 점이 평면상에 주어진다. 이때, 각 점들을 2개씩 짝지어서
선분을 그었을 때 나타나는 평행선의 최대 개수를 구한다. 각 점의 좌표 범위는 절댓값 1000 이하다.
주 선분이 만나더라도 방향만 같다면 평행선이다.

해결 방법 : 브루트 포스로 점들을 2개씩 짝짓는 모든 방법을 해 본다.
그리고 점들을 모두 짝지으면 모든 쌍에 대해 평행선인지 여부를 내적을 통해 판별하고
그 개수가 최대가 될 때를 찾아 출력하면 된다.

주요 알고리즘 : 브루트 포스, 기하학

출처 : Tsukuba 2017 B번
*/

int point[16][2], pair[8][2], vis[16];
int best = 0;

long long sqr(long long a) {
    return a * a;
}

int ispararell(int a, int b) {
    long long dxa = point[pair[a][0]][0] - point[pair[a][1]][0];
    long long dya = point[pair[a][0]][1] - point[pair[a][1]][1];
    long long dxb = point[pair[b][0]][0] - point[pair[b][1]][0];
    long long dyb = point[pair[b][0]][1] - point[pair[b][1]][1];
    if (sqr(dxa * dxb + dya * dyb) == (sqr(dxa) + sqr(dya)) * (sqr(dxb) + sqr(dyb))) return 1;
    else return 0;
}

void track(int n, int m, int x) {
    int r;
    if (m == x) {
        r = 0;
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                if (ispararell(i, j)) r++;
            }
        }
        if (r > best) best = r;
        return;
    }
    r = -1;
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        if (r < 0) {
            r = i;
            pair[x][0] = i;
            vis[i] = 1;
            continue;
        }
        pair[x][1] = i;
        vis[i] = 1;
        track(n, m, x + 1);
        vis[i] = 0;
    }
    vis[r] = 0;
}

int main(void) {
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &point[i][0], &point[i][1]);
    }
    track(m, m >> 1, 0);
    printf("%d\n", best);
    return 0;
}