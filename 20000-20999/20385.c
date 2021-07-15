#include <stdio.h>
#include <string.h>

/*
문제 : N * N(N <= 50) 크기의 격자에 문자들이 적혀있다. 여기서 찾으려는 단어들이 주어질 때, 격자에서 단어들을 찾을
수 있는 위치와 방향을 모두 구한다. 방향은 상하좌우대각선으로 8방향이 가능하고, 단어 중간의 공백은 무시할 수 있다.
단어의 순서는 행->열->위쪽부터 시계방향 순서로 출력한다.

해결 방법 : 먼저 격자를 입력받은 후, 모든 위치와 방향에 대해 단어를 찾을 수 있는지 살펴보면 된다.
중간에 다른 문자가 나오거나 격자를 벗어나거나 처음에 공백이 나오면 단어를 찾을 수 없는 것이고,
그렇지 않고 단어의 끝까지 가면 찾을 수 있는 것이다.

주요 알고리즘 : 구현, 브루트 포스, 문자열

출처 : MidC 1993 3번
*/

char s[64][64], find[64];
char* dir[8] = { "N", "NE", "E", "SE", "S", "SW", "W", "NW" };
int dxy[8][2] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };

int main(void) {
    int n, len, x, y, t, p, cnt = 0; //len = 찾을 단어의 길이, (x, y) = 현재 탐색 중인 위치의 좌표, //t = 성공 여부 변수
    //p = 현재 찾는 문자의 번호, cnt = 단어를 찾은 횟수

    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\1993\\space1.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\1993\\space1_t.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%c", &s[i][j]);
            if (s[i][j] == '\n' || s[i][j] == '\r') j--; //개행 문자는 무시한다.
        }
    }
    while (scanf("%s", find) != EOF) {
        len = strlen(find);
        cnt = 0;
        printf("%s\n", find);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int d = 0; d < 8; d++) {
                    t = 1, x = i, y = j, p = 0;
                    if (s[x][y] == ' ') continue;
                    while (p < len) {
                        if (x < 0 || y < 0 || x >= n || y >= n) {
                            t = 0;
                            break;
                        }
                        if (s[x][y] == ' ');
                        else if (s[x][y] == find[p]) p++;
                        else {
                            t = 0;
                            break;
                        }
                        x += dxy[d][0];
                        y += dxy[d][1];
                    }
                    if (t) {
                        printf("(%d,%d) - %s\n", i + 1, j + 1, dir[d]);
                        cnt++;
                    }
                }
            }
        }

        if (!cnt) printf("not found\n");
        printf("\n");
    }
    return 0;
}