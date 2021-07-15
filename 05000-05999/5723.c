#include <stdio.h>

/*
문제 : N(N <= 1000)일의 날짜와 검침기의 수가 순서대로 주어진다. 이때 연속한 날의 수와 연속한 날 사이 움직인
검침기의 값의 합을 구한다.

해결 방법 : 연, 월이 같고 날짜가 연속되었는지, 또는 연이 같고 일이 양 끝이며 월이 연속되었는지(윤년에 유의한다.)
아니면 연이 같고 월, 일이 양 끝인지 확인한다. 위 3가지에 포함된다면 연속한 날이다.

주요 알고리즘 : 구현

출처 : Latin 2008 E번
*/

int d[1024], m[1024], y[1024], c[1024];
int lday[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int lday2[] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int isleap(int y) {
    if (y & 3) return 0;
    else if (y % 100) return 1;
    else if (y % 400) return 0;
    else return 1;
}

int main(void) {
    int n, r1, r2;
    //freopen("E:\\PS\\ICPC\\Latin America\\Latin\\2008\\testset_2008\\electricity.in", "r", stdin);
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        r1 = 0, r2 = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d %d", &d[i], &m[i], &y[i], &c[i]);
            if (i == 0) continue;
            if (d[i] == d[i - 1] + 1 && m[i] == m[i - 1] && y[i] == y[i - 1]) {
                r1++;
                r2 += c[i] - c[i - 1];
            }
            else if (!isleap(y[i]) && y[i] == y[i - 1] && m[i] == m[i - 1] + 1 && d[i] == 1 && d[i - 1] == lday[m[i - 1]]) {
                r1++;
                r2 += c[i] - c[i - 1];
            }
            else if (isleap(y[i]) && y[i] == y[i - 1] && m[i] == m[i - 1] + 1 && d[i] == 1 && d[i - 1] == lday2[m[i - 1]]) {
                r1++;
                r2 += c[i] - c[i - 1];
            }
            else if (y[i] == y[i - 1] + 1 && m[i] == 1 && m[i - 1] == 12 && d[i] == 1 && d[i - 1] == 31) {
                r1++;
                r2 += c[i] - c[i - 1];
            }
        }
        printf("%d %d\n", r1, r2);
    }
    return 0;
}