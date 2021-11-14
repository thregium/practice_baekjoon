#include <stdio.h>

/*
문제 : N * M(N, M <= 20) 크기의 판에서 동전 두 개를 같은 방향으로 움직인다. 만약 그곳에 벽이 있다면 그 동전은 움직이지 않는다.
동전끼리는 겹쳐도 상관 없다면 두 동전 가운데 한 개만 판 밖으로 내보내기 위해 필요한 이동 횟수를 구한다.
10회 초과 또는 한 개만 내보낼 수 없다면 -1을 출력한다. 두 동전이 모두 동시에 나가서는 안 된다.

해결 방법 : 먼저 두 동전의 위치를 확인한다. 그 뒤로는 그 곳에서부터 두 동전의 위치를 확인하며 최소 횟수를 구해 나간다.
만약 두 동전이 모두 밖에 나간다면 잘못 움직인 것이므로 경우에서 제외한다. 마찬가지로 두 동전을 같은 방향으로 움직이는 경우도
턴 낭비이므로 경우에서 제외한다. 한 동전만 밖으로 빼는 이동에 대해서는 그때의 이동 횟수를 최댓값으로 갱신한 후
해당 탐색을 종료한다. 그 외에는 일반적인 이동이므로 경우를 나누어 처리한다.

주요 알고리즘 : 브루트 포스, 구현
*/

char s[32][32];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n, m, best = 99;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m) return -10;
    if (s[x][y] == '#') return 0;
    return 1;
}

void track(int c, int x1, int y1, int x2, int y2) {
    if (c >= 10) return; //10회를 초과하는 경우 더 이상 보면 안 된다.
    int t;
    for (int i = 0; i < 4; i++) {
        t = isvalid(x1 + dxy[i][0], y1 + dxy[i][1]) + isvalid(x2 + dxy[i][0], y2 + dxy[i][1]);
        if (t == -10 || t == -9) {
            //하나만 밖으로 나감
            if (c + 1 < best) best = c + 1;
            continue;
        }
        else if (t == 2) track(c + 1, x1 + dxy[i][0], y1 + dxy[i][1], x2 + dxy[i][0], y2 + dxy[i][1]); //둘 다 이동
        else if (t == 1) {
            //하나만 벽에 걸림
            if (isvalid(x1 + dxy[i][0], y1 + dxy[i][1])) track(c + 1, x1 + dxy[i][0], y1 + dxy[i][1], x2, y2);
            else track(c + 1, x1, y1, x2 + dxy[i][0], y2 + dxy[i][1]);
        }
        //그 외에는 생각할 필요 X
    }
}

int main(void) {
    int cnt = 0, x1 = -1, y1 = -1, x2 = -1, y2 = -1;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'o') {
                //두 동전의 위치 확인
                if (cnt == 0) {
                    x1 = i;
                    y1 = j;
                }
                else if (cnt == 1) {
                    x2 = i;
                    y2 = j;
                }
                else return 1;
                cnt++;
            }
        }
    }
    if (cnt < 2) return -1;
    track(0, x1, y1, x2, y2);
    printf("%d", best > 10 ? -1 : best);
    return 0;
}