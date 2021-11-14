#include <stdio.h>

/*
문제 : N * M(N, M <= 50) 크기의 '-'와 '|'로 이루어진 배열이 주어질 때, 이 배열에서 연속한 '-'와 '|'를 판자 하나로 친다면
판자의 개수를 구한다.

해결 방법 : 왼쪽 위 칸부터 확인하며 '-'인 경우 오른쪽으로 연속한 '-'에 모두 방문 처리를 한다.
마찬가지로 '|'인 경우 아래로 연속한 '|'에 모두 방문 처리를 한다. 방문 처리를 한 칸은 넘어가도록 하면
방문한 횟수가 판자의 개수와 같다.

주요 알고리즘 : 그리디 알고리즘
*/

char fl[64][64], vis[64][64];

int main(void) {
    int n, m, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", fl[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j]) continue;
            r++;
            if (fl[i][j] == '-') {
                for (int k = j; k < m && fl[i][k] == '-'; k++) {
                    if (vis[i][k]) return 1;
                    vis[i][k] = 1;
                }
            }
            else if (fl[i][j] == '|') {
                for (int k = i; k < n && fl[k][j] == '|'; k++) {
                    if (vis[k][j]) return 1;
                    vis[k][j] = 1;
                }
            }
            else return 1;
        }
    }
    printf("%d", r);
    return 0;
}