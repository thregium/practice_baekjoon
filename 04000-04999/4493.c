#include <stdio.h>

/*
문제 : 2명의 가위바위보에서 낸 것이 N(N < 100)개 주어질 때, 누가 더 많이 이겼는지 구한다.

해결 방법 : 2명이 낸 것을 입력받을 때 마다 결과를 확인하고 각각의 이긴 횟수를 센 다음 더 많이 이긴 사람을 출력하면 된다.

주요 알고리즘 : 구현, 케이스 워크

출처 : PacNW 2007 A번
*/

int main(void) {
    int t, n, p1, p2;
    char c1, c2;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        p1 = 0, p2 = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf(" %c %c", &c1, &c2);
            if ((c1 == 'R' && c2 == 'S') || (c1 == 'S' && c2 == 'P') || (c1 == 'P' && c2 == 'R')) p1++;
            else if ((c1 == 'S' && c2 == 'R') || (c1 == 'P' && c2 == 'S') || (c1 == 'R' && c2 == 'P')) p2++;
        }
        if (p1 > p2) printf("Player 1\n");
        else if (p1 < p2) printf("Player 2\n");
        else printf("TIE\n");
    }
    return 0;
}