#include <stdio.h>

/*
문제 : N * M(N, M <= 32) 크기의 색종이를 왼쪽 또는 위쪽 방향으로 T(T <= 20)번 접는다.
매번 접을 때마다의 접는 위치가 주어지면 P(P <= 20)개의 위치에 대해 구멍을 뚫었을 때
구멍이 몇 개 뚫릴 지 구한다.

해결 방법 : 매번 접을 때 마다 방향과 위치를 확인하고 매 칸마다 종이가 겹친 개수를 구해둔다.
이를 반복한 다음 구멍이 뚫리는 개수는 종이가 겹친 개수이므로 이를 출력하면 된다.
종이가 겹친 개수를 구할 때, N - C 또는 M - C보다 C가 큰 경우에 유의한다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : JDC 2018 B번
*/

int paper[48][48], temp[48][48];

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int n, m, t, p, d, c;
    while (1) {
        scanf("%d %d %d %d", &n, &m, &t, &p);
        if (n == 0) break;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) paper[i][j] = 1;
        }
        for (int i = 0; i < t; i++) {
            scanf("%d %d", &d, &c);
            if (d == 1) {
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < n - c; j++) temp[i][j] = paper[i][j + c];
                    for (int j = 0; j < c; j++) temp[i][j] += paper[i][c - j - 1];
                }
                n = big(n - c, c);
            }
            else if (d == 2) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m - c; j++) temp[j][i] = paper[j + c][i];
                    for (int j = 0; j < c; j++) temp[j][i] += paper[c - j - 1][i];
                }
                m = big(m - c, c);
            }
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) paper[i][j] = temp[i][j];
            }
            for (int i = 0; i < 48; i++) {
                for (int j = 0; j < 48; j++) temp[i][j] = 0;
            }
            continue;
        }
        for (int i = 0; i < p; i++) {
            scanf("%d %d", &d, &c);
            printf("%d\n", paper[c][d]);
        }
    }
    return 0;
}