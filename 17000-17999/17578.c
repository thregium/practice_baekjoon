#include <stdio.h>
#include <stdlib.h>

/*
문제 : H * W(H, W <= 50) 크기의 스크린에 문자들이 있다. 길이 1000 이하의 문자열이 주어질 때,
스크린의 문자들을 모두 치는데 필요한 버튼 조작 횟수를 구한다.
처음에 커서는 가장 왼쪽 위 칸에 있고, 버튼을 1회 눌러 커서를 상하좌우로 움직일 수 있다.
그리고 확인 버튼을 눌러 문자를 칠 수 있다. 스크린 밖으로는 커서가 이동하지 않는다.
스크린에 한 가지 문자는 한 곳에만 있다.

해결 방법 : 최근 커서의 위치를 저장하며 각 문자마다 문자가 있는 위치를 찾고
최근 위치와의 맨해튼 거리 + 1을 답에 더해나간다. 이를 반복한 다음 나온 답을 출력하면 된다.

주요 알고리즘 : 문자열, 구현

출처 : JDC 2019 B번
*/

char osk[64][64], s[1024];

int main(void) {
    int h, w, x, y, r;
    while (1) {
        scanf("%d %d", &h, &w);
        if (h == 0) break;
        for (int i = 0; i < h; i++) {
            scanf("%s", osk[i]);
        }
        x = 0, y = 0, r = 0;
        scanf("%s", s);
        for (int i = 0; s[i]; i++) {
            for (int j = 0; j < h; j++) {
                for (int k = 0; k < w; k++) {
                    if (osk[j][k] == s[i]) {
                        r += abs(x - j) + abs(y - k) + 1;
                        x = j, y = k;
                    }
                }
            }
        }
        printf("%d\n", r);
    }
    return 0;
}