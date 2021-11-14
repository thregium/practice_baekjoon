#include <stdio.h>

/*
문제 : N(N <= 1000)개의 칸으로 이루어진 돌림판의 색을 규칙에 맞게 K(K <= 1000)번 바꾼 결과를 출력한다.

해결 방법 : 문제의 규칙에 맞게 구현한다. 시작과 끝점 처리에 유의한다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : KAIST 2016S A1번
*/

char s[1024][1024];
int cnt[1024];

int main(void) {
    int n, k;
    char a, b, c, t = '\0', o = '\0';
    scanf("%d %d", &n, &k);
    scanf("%s", s[0]);
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            a = s[i - 1][(j + n - 1) % n];
            b = s[i - 1][j];
            c = s[i - 1][(j + 1) % n];
            if ((a == b && a == c) || (a != b && a != c && b != c)) {
                s[i][j] = 'B';
                continue;
            }
            else if (a == b) {
                t = a;
                o = c;
            }
            else if (a == c) {
                t = a;
                o = b;
            }
            else {
                t = b;
                o = a;
            }
            if ((t == 'R' && o == 'G') || (t == 'G' && o == 'B') || (t == 'B' && o == 'R')) s[i][j] = 'R';
            else s[i][j] = 'G';
        }
    }
    for (int i = 0; i < n; i++) {
        if (s[k][i] == 'R') cnt[0]++;
        else if (s[k][i] == 'G') cnt[1]++;
        else if (s[k][i] == 'B') cnt[2]++;
    }
    printf("%d %d %d", cnt[0], cnt[1], cnt[2]);
    return 0;
}