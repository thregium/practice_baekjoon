#include <stdio.h>

/*
문제 : H * W(H, W <= 200) 크기의 격자에 대문자들이 쓰여 있다. 대문자로 이루어진 길이 L(L <= 100)의
문자열이 주어질 때, 주어진 격자에서 상하좌우대각선으로 이동해가며 주어진 문자열을 만드는
방법의 가짓수를 구한다.

해결 방법 : 각 문자의 번째수마다 DP 배열을 채워가면서 인접한 8칸의 이전 상태를 더해 나간다.
이를 반복하여 최종 문자의 상태에 대해 가능한 가짓수를 세면 된다.

주요 알고리즘 : 문자열, DP

출처 : BtOI 2010 P1번
*/

char grid[256][256], word[128];
long long mem[128][256][256];
const int dxy[8][2] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };

int main(void) {
    int h, w, l, lx, ly;
    long long res = 0;
    scanf("%d %d %d", &h, &w, &l);
    for (int i = 0; i < h; i++) {
        scanf("%s", grid[i]);
    }
    scanf("%s", word);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[i][j] == word[0]) mem[0][i][j] = 1;
        }
    }
    for (int i = 1; i < l; i++) {
        for (int j = 0; j < h; j++) {
            for (int k = 0; k < w; k++) {
                if (grid[j][k] != word[i]) continue;
                for (int d = 0; d < 8; d++) {
                    lx = j + dxy[d][0];
                    ly = k + dxy[d][1];
                    if (lx < 0 || ly < 0 || lx >= h || ly >= w) continue;
                    mem[i][j][k] += mem[i - 1][lx][ly];
                }
            }
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            res += mem[l - 1][i][j];
        }
    }
    printf("%lld", res);
    return 0;
}