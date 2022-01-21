#include <stdio.h>

/*
문제 : 9 * 9 이내 크기의 격자판에 공이 있거나 비어있다. jfen 형태로 공의 위치들이 주어질 때,
(a, b) 위치의 공을 (c, d)로 옮기고 jfen 형태로 이를 출력한다. jfen 형태는 각 행별로 연속된 빈칸을
숫자로, 공이 있는 칸을 'b'로 나타내고 각 행을 '/'로 구분한 것이다.

해결 방법 : 우선 격자판의 크기와 공의 위치를 알아낸다. 이는 1번 행부터 시작하며 문자열을 읽어나가면 된다.
/나 문자열의 끝이 되기까지 b면 1칸, 숫자면 해당 칸만큼을 위치에 맞게 추가하고, 마지막 칸의 위치를 확인하면
그것이 행의 길이이며, 마지막 줄의 위치가 행의 개수이다.
공을 옮기는 것은 2차원 배열에서는 매우 간단한 일이며, jfen형태로 다시 바꿀 때에는 위에서 행과 열의
크기를 확인했으므로 그만큼을 이동하며 공이 있으면 'b'를 추가, 빈 칸이라면 왼칸이 빈칸인 경우
거기에 1을 더하고, 그 외에는 '1'을 문자열에 추가하는 방식으로 간단히 구할 수 있다.

주요 알고리즘 : 구현, 파싱

출처 : JAG 2016DB B번
*/

char s[1024];
int ball[16][16];

int main(void) {
    int p, sp, h, w, a, b, c, d;
    while (1) {
        scanf("%s", s);
        if (s[0] == '#') break;
        sp = -1, h = 0, w = 99;
        for (int i = 1;; i++) {
            p = 1, h = i;
            sp++;
            while (s[sp] != '/' && s[sp] != '\0') {
                if (s[sp] == 'b') ball[i][p++] = 1;
                else {
                    for (int j = 0; j < s[sp] - '0'; j++) ball[i][p++] = 0;
                }
                sp++;
            }
            w = p - 1;
            if (!s[sp]) break;
        }

        scanf("%d %d %d %d", &a, &b, &c, &d);
        ball[a][b] = 0, ball[c][d] = 1;
        sp = 0;
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                if (ball[i][j]) s[sp++] = 'b';
                else if (sp == 0 || s[sp - 1] == 'b' || s[sp - 1] == '/') s[sp++] = '1';
                else s[sp - 1]++;
            }
            if (i < h) s[sp++] = '/';
        }
        s[sp] = '\0';
        printf("%s\n", s);
    }
    return 0;
}