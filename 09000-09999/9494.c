#include <stdio.h>
#include <string.h>

/*
문제 : 주어진 N(N <= 1000)개의 문자열을 기울였을 때 맨 왼쪽 위에 공을 떨어뜨린다면 몇 번째 문자에 떨어지는지 구한다.
공백 또는 문자열 끝 이후 문자라면 공이 떨어지고, 그 외에는 기울어지며 이동한다.

해결 방법 : 각 줄마다 공이 마지막으로 떨어진 곳 이후 칸 중 첫 공백 또는 문자열 종료 시점에 공이 떨어지게 된다.
매 줄마다 마지막 공백을 확인한 후 해당 위치에서부터 공백이나 문자열 종료점을 찾아나가는 것을 반복하면 된다.

주요 알고리즘 : 구현, 문자열

출처 : SEUSA 2013D2 J번
*/

char text[1024][128];

int main(void) {
    int n, r;
    while (1) {
        scanf("%d\n", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            memset(text[i], 0, 128);
            fgets(text[i], 120, stdin);
        }
        r = 0;
        for (int i = 0; i < n; i++) {
            while (text[i][r] != ' ' && text[i][r] != '\n' && text[i][r] != '\0') r++;
        }
        printf("%d\n", r + 1);
    }
    return 0;
}