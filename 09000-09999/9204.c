#include <stdio.h>

/*
문제 : 체스판의 비숍이 주어진 시작점에서 끝점으로 가는 4회 이내로 이동하는 경로가 있는 지 찾고
없다면 Impossible을, 있다면 그러한 경로를 출력한다.

해결 방법 : 두 칸의 홀짝성이 다른 경우 절대 서로 만날 수 없으므로 Impossible을 출력하면 된다.
홀짝성이 같다면 1칸을 이동했다가 돌아오면 서로 만날 수 있는 것을 알 수 있다.
따라서, 모든 칸에 대해 중간에서 만날 수 있는 지 확인하고 만날 수 있는 그 칸을 중간점으로 하는
경로를 출력하면 된다.

주요 알고리즘 : 브루트 포스, 구성적

출처 : GCPC 2013 C번
*/

int main(void) {
    int t, sy, ey, end;
    char sx, ex;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf(" %c %d %c %d", &sx, &sy, &ex, &ey);
        if (((sx + sy) - (ex + ey)) & 1) printf("Impossible\n");
        else if (sx == ex && sy == ey) printf("0 %c %d\n", sx, ey);
        else if (sx + sy == ex + ey || sx - sy == ex - ey) printf("1 %c %d %c %d\n", sx, sy, ex, ey);
        else {
            end = 0;
            for (char px = 'A'; px <= 'H'; px++) {
                for (int py = 1; py <= 8; py++) {
                    if ((sx + sy == px + py || sx - sy == px - py) &&
                        (px + py == ex + ey || px - py == ex - ey)) {
                        printf("2 %c %d %c %d %c %d\n", sx, sy, px, py, ex, ey);
                        end = 1;
                        break;
                    }
                }
                if (end) break;
            }
            if (!end) return 1;
        }
    }
    return 0;
}