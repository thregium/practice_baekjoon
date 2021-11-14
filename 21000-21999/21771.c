#include <stdio.h>

/*
문제 : R * C(R, C <= 100) 크기의 격자에 P로 된 직사각형과 G로 된 직사각형이 있다. 각 직사각형의 크기와
격자의 형태가 주어지면 P의 일부를 G가 가리는지 확인한다.

해결 방법 : 격자에서 P의 개수를 세고, 이 개수가 P의 넓이보다 적은지 확인한다. 적은 경우 가리는 것이고,
그렇지 않다면 가리지 않는 것이다.

주요 알고리즘 : 애드 혹

출처 : 가희 1회 1번
*/

char s[128][128];

int main(void) {
    int r, c, rg, cg, rp, cp, cnt = 0;
    scanf("%d %d", &r, &c);
    scanf("%d %d %d %d", &rg, &cg, &rp, &cp);
    for (int i = 0; i < r; i++) {
        scanf("%s", s[i]);
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (s[i][j] == 'P') cnt++;
        }
    }
    if (cnt > rp * cp) return 1;
    printf("%d", cnt < rp * cp);
    return 0;
}