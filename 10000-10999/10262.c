#include <stdio.h>

/*
문제 : 2명이 각각 [A1, B1]과 [A2, B2]의 범위를 가지는 주사위 2개를 던진 합으로 이길 가능성이 더 높은 사람을 찾는다.
(A1, B1, A2, B2 <= 100)

해결 방법 : 모든 경우에 대해 각각 누가 이기는지 확인하고 더 이긴 적이 많은 사람을 출력하면 된다.

주요 알고리즘 : 브루트 포스

출처 : NCPC 2014 D번
*/

int main(void) {
    int ka1, kb1, ka2, kb2, sa1, sb1, sa2, sb2, kw = 0, sw = 0;
    scanf("%d %d %d %d%d %d %d %d", &ka1, &kb1, &ka2, &kb2, &sa1, &sb1, &sa2, &sb2);
    for (int a = ka1; a <= kb1; a++) {
        for (int b = ka2; b <= kb2; b++) {
            for (int c = sa1; c <= sb1; c++) {
                for (int d = sa2; d <= sb2; d++) {
                    if (a + b > c + d) kw++;
                    else if (a + b < c + d) sw++;
                }
            }
        }
    }
    if (kw > sw) printf("Gunnar");
    else if (kw < sw) printf("Emma");
    else printf("Tie");
    return 0;
}