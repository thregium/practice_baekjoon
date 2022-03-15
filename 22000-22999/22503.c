#include <stdio.h>

/*
문제 : M * N(M, N <= 500) 크기의 칸에 '.'들과 대문자들이 있다. 각 대문자들은 없거나 정확히 2개 있다.
임의의 칸을 누르면 그 칸의 상하좌우로 만나는 첫 문자까지 선이 이어진다. 그 문자들 가운데
서로 같은 문자가 있는 경우 사라진다고 한다. 이때, 사라지게 만들 수 있는 문자의 최대 개수를 구한다.

해결 방법 : 각 문자들을 확인하면서 눌러서 문자를 지울 수 있는 칸들을 추려낸다.
두 문자가 일직선상에 있는 경우 두 문자 사이의 위치들을, 그 외의 경우에는 서로 반대쪽 꼭지점 위치 2개만이
그 문자들을 지울 수 있기 때문에 이 칸들만 남기면 된다.
그 다음, 해당 칸들을 계속 눌러보면서 더이상 문자가 사라지지 않을 때 까지 이를 반복하면 된다.
문자가 있는 칸을 누르거나 범위를 벗어나는 경우 등에 주의한다.

주요 알고리즘 : 구현, 브루트 포스?, 케이스 워크

출처 : JAG 2011S2 J번
*/

char tile[512][512];
int pos[16384][2], look[4][2];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main(void) {
    int m, n, x1, y1, x2, y2, p = 0, c, r = 0;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++) {
        scanf("%s", tile[i]);
    }
    for (char i = 'A'; i <= 'Z'; i++) {
        x1 = -1, y1 = -1, x2 = -1, y2 = -1, c = 0;
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                if (tile[j][k] == i) {
                    if (c == 0) {
                        x1 = j, y1 = k;
                    }
                    else if (c == 1) {
                        x2 = j, y2 = k;
                    }
                    else return 1;
                    c++;
                }
            }
        }
        if (c != 0 && c != 2) return 1;
        if (c == 0) continue;
        if (x1 > x2) {
            swap(&x1, &x2);
            swap(&y1, &y2);
        }
        else if (x1 == x2 && y1 > y2) {
            swap(&x1, &x2);
            swap(&y1, &y2);
        }
        if (x1 < x2 && y1 != y2) {
            pos[p][0] = x1;
            pos[p++][1] = y2;
            pos[p][0] = x2;
            pos[p++][1] = y1;
        }
        else if (x1 == x2) {
            for (int i = y1 + 1; i < y2; i++) {
                pos[p][0] = x1;
                pos[p++][1] = i;
            }
        }
        else if (y1 == y2) {
            for (int i = x1 + 1; i < x2; i++) {
                pos[p][0] = i;
                pos[p++][1] = y1;
            }
        }
        else return 2;
    }

    c = 1;
    while (c) {
        c = 0;
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0;; k++) {
                    x1 = pos[i][0] + dxy[j][0] * k;
                    y1 = pos[i][1] + dxy[j][1] * k;
                    if (x1 < 0 || y1 < 0 || x1 >= m || y1 >= n) {
                        look[j][0] = -1;
                        look[j][1] = -1;
                        break;
                    }
                    if (tile[x1][y1] != '.') {
                        look[j][0] = x1;
                        look[j][1] = y1;
                        break;
                    }
                }
            }
            for (int i = 0; i < 4; i++) {
                if (look[i][0] < 0) continue;
                for (int j = i + 1; j < 4; j++) {
                    if (look[j][0] < 0) continue;
                    if (tile[look[i][0]][look[i][1]] != '.' && tile[look[i][0]][look[i][1]] ==
                        tile[look[j][0]][look[j][1]] && !(look[i][0] == look[j][0] &&
                            look[i][1] == look[j][1])) {
                        tile[look[i][0]][look[i][1]] = '.';
                        tile[look[j][0]][look[j][1]] = '.';
                        c += 2;
                        r += 2;
                        break;
                    }
                }
            }
        }
    }
    printf("%d\n", r);
    return 0;
}