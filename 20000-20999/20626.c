#include <stdio.h>

/*
문제 : 직선상의 L(L <= 100)개의 칸에 바둑돌이 놓여있거나 비어 있다. 이때, 이 중 한 곳에
흰 바둑돌을 놓아 잡을 수 있는 검은 바둑돌의 가장 많은 개수를 구한다.
두 흰 바둑돌 사이 빈 칸 없이 검은 바둑돌만 있는 경우 사이에 있는 검은 바둑돌은 모두 잡힌다.
반대로 흰 바둑돌을 놓았을 때 빈 칸 없이 흰 바둑돌들이
검은 바둑돌 사이에 끼이게 되는 칸에는 흰 돌을 놓을 수 없다.
처음에는 바둑돌이 잡히는 경우가 없고 빈 칸이 하나는 남아있는 상태이다.

해결 방법 : 가능한 모든 빈 칸에 바둑돌을 놓아보면서 그 칸에 바둑돌을 놓을 수 있는 지,
그렇다면 그 중 검은 돌을 가장 많이 잡을 수 있는 경우의 잡는 검은 돌 수를 구하고
그 중 최댓값을 출력하면 된다.

주요 알고리즘 : 구현, 브루트 포스

출처 : JAG 2019S1 A번 // Petro 2020S5 A번
*/

char s[128], t[128];

int main(void) {
    int l, r = 0, wb, e, c, rt;
    scanf("%d %s", &l, s);
    for (int i = 0; i < l; i++) {
        if (s[i] != '.') continue;
        for (int j = 0; j < l; j++) t[j] = s[j];
        t[i] = 'W';
        wb = 0, e = 0, c = 0, rt = 0;
        for (int j = 0; j < l; j++) {
            if (t[j] == 'B') {
                if (c && wb && !e) rt = 1;
                c++, wb = 0, e = 0;
            }
            else if (t[j] == 'W') wb++;
            else if (t[j] == '.') e++;
        }
        if (rt) continue;
        wb = 0, e = 0, c = 0, rt = 0;
        for (int j = 0; j < l; j++) {
            if (t[j] == 'W') {
                if (c && wb > rt && !e) rt = wb;
                c++, wb = 0, e = 0;
            }
            else if (t[j] == 'B') wb++;
            else if (t[j] == '.') e++;
        }
        if (rt > r) r = rt;
    }
    printf("%d\n", r);
    return 0;
}