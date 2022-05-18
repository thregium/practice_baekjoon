#include <stdio.h>
#include <string.h>

/*
문제 : N * M(N, M <= 100) 크기의 문자판에 대문자들이 쓰여있다. 그리고 길이 80 이하의 대문자로 이루어진
문자열이 주어질 때, 문자판에서 상하좌우로 K(K <= 5)칸 이내로 움직여가며
주어진 문자열을 만드는 방법의 가짓수를 구한다.

해결 방법 : 각 위치의 각 번째마다 가짓수를 저장하면서 다이나믹 프로그래밍을 하면 된다.
K가 작으므로 굳이 최적화를 할 필요는 없다.

주요 알고리즘 : DP
*/

char alph[128][128], word[96];
int mem[96][128][128];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int main(void) {
    int n, m, k, l, xx, yy, res = 0;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        scanf("%s", alph[i]);
    }
    scanf("%s", word);
    l = strlen(word);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (alph[i][j] == word[0]) mem[0][i][j] = 1;
        }
    }
    for (int wi = 1; wi < l; wi++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (alph[i][j] != word[wi]) continue;
                for (int d = 0; d < 4; d++) {
                    for (int dd = 1; dd <= k; dd++) {
                        xx = i + dxy[d][0] * dd;
                        yy = j + dxy[d][1] * dd;
                        if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
                        if (alph[xx][yy] != word[wi - 1]) continue;
                        mem[wi][i][j] += mem[wi - 1][xx][yy];
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res += mem[l - 1][i][j];
        }
    }
    printf("%d", res);
    return 0;
}