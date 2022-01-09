#include <stdio.h>
#include <string.h>

/*
문제 : N * M(N, M <= 10) 크기의 격자판에서 상하좌우대각선으로 이동하며 주어진 K(K <= 1000)개의 문자열에 대해
각각을 만드는 방법의 가짓수를 출력한다. 모든 문자는 알파벳이며, 문자열의 길이는 5 이하로 주어진다.
같은 문자열이 주어질 수 있다. 또한, 격자는 환형으로 이루어져 있다.

해결 방법 : 각 방향으로 이동하는 경우를 모두 살펴보며 문자열을 만드는 방법의 가짓수를 센다.
환형 이동은 나머지 연산을 통해, 이동 방향은 방향 배열을 통해 간단히 구현할 수 있다.
모든 경우의 수를 세면 되지만, 문자열의 개수가 많기 때문에 시간 초과가 날 수 있다.
따라서, 각 문자열마다의 기록을 저장해 두고, 이미 나온 문자열은 다시 탐색하지 않고 기록에서 꺼내다 쓰는 것이 좋다.

주요 알고리즘 : 브루트 포스, 백트래킹, DP?

출처 : 류호석배 1회 3번
*/

typedef struct record {
    char s[16];
    int r;
} record;

char grid[16][16], s[16];
int dxy[8][2] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };
record rec[1024];
int n, m, l = 0;

int track(int x, int y, int c) {
    int r = 0, xx, yy;
    if (c == l) return 1;
    for (int i = 0; i < 8; i++) {
        xx = (x + dxy[i][0] + n) % n;
        yy = (y + dxy[i][1] + m) % m;
        if (grid[xx][yy] == s[c]) r += track(xx, yy, c + 1);
    }
    return r;
}

int main(void) {
    int k, r = 0, rc = 0;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        scanf("%s", grid[i]);
    }
    for (int i = 0; i < k; i++) {
        scanf("%s", s);
        for (int j = 0; j < rc; j++) {
            if (!strcmp(s, rec[j].s)) {
                printf("%d\n", rec[j].r);
                r = -1;
                break;
            }
        }
        if (r < 0) {
            r = 0;
            continue;
        }
        l = strlen(s);
        r = 0;
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                if (grid[x][y] == s[0]) r += track(x, y, 1);
            }
        }
        printf("%d\n", r);
        strcpy(rec[rc].s, s);
        rec[rc++].r = r;
    }
    return 0;
}