#include <stdio.h>

/*
문제 : H * W(H, W <= 11) 크기의 격자에서 알파벳 소문자로 각 덩어리들이 주어진다. 이때, 모든 덩어리들을 뒤집은 형태 가운데
아무거나 출력한다. 덩어리가 없는 칸은 '.'로 표시된다. 같은 덩어리 끼리는 같이 뒤집어야 한다.

해결 방법 : 격자 전체를 뒤집으면 모든 덩어리를 뒤집을 수 있다.

주요 알고리즘 : 구성적

출처 : Coder's High 2014 F번 / 2016N PB번
*/

char s[16][16];

int main(void) {
    int t, h, w;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &h, &w);
        for (int i = 0; i < h; i++) {
            scanf("%s", s[i]);
        }
        for (int i = h - 1; i >= 0; i--) {
            printf("%s\n", s[i]);
        }
    }
    return 0;
}