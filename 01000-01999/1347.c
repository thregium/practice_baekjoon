#include <stdio.h>

/*
문제 : 길이 N(N <= 50)의 'F', 'L', 'R'로 이루어진 문자열이 주어질 때, 처음 위치에서 해당 문자열을 이용해
이동한 지역들을 출력한다. 가장 적은 넓이로 출력해야 한다. 'F'인 경우 직진, 'L'인 경우 왼쪽으로 90도 회전,
'R'인 경우 오른쪽으로 90도 회전이다.

해결 방법 : 배열을 100 * 100 이상으로 크게 잡고, 가운데서 시작한다. 가장 바깥쪽 방문한 지점의 X, Y좌표들을 저장해둔다.
각 지점들을 방문하는 것을 시뮬레이션하며 방문 위치들을 저장하고, 가장 바깥쪽 지점들을 업데이트 한다.
방문이 끝나면 가장 바깥쪽 이내 구간의 방문 여부들을 출력해내면 된다.

주요 알고리즘 : 구현, 시뮬레이션
*/

char s[64], chk[128][128];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int main(void) {
    int n, x = 64, y = 64, d = 1, xl = 64, yl = 64, xh = 64, yh = 64;
    scanf("%d", &n);
    scanf("%s", s);
    chk[x][y] = 1;
    for (int i = 0; s[i]; i++) {
        if (s[i] == 'F') {
            x += dxy[d][0];
            y += dxy[d][1];
            chk[x][y] = 1;
            if (x < xl) xl = x;
            if (y < yl) yl = y;
            if (x > xh) xh = x;
            if (y > yh) yh = y;
        }
        else if (s[i] == 'R') d = ((d + 1) & 3);
        else if (s[i] == 'L') d = ((d + 3) & 3);
        else return 1;
    }
    for (int i = xl; i <= xh; i++) {
        for (int j = yl; j <= yh; j++) {
            printf("%c", chk[i][j] ? '.' : '#');
        }
        printf("\n");
    }
    return 0;
}