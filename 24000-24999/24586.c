#include <stdio.h>
#include <string.h>

/*
문제 : 2명이 1에서 9까지의  카드 가운데 서로 다른 2장씩을 뽑았다.(뽑은 카드는 모두 다르다).
1명이 뽑은 카드와 뽑은 카드들의 오름차순 순서가 주어질 때, 다른 1명이 뽑은 카드를 유일하게 알 수 있다면
그 카드들을, 없다면 -1을 출력한다.

해결 방법 : 순서에 따라 경우를 나누어 유일하게 알 수 있는 경우와 없는 경우에 따라 답을 출력한다.

주요 알고리즘 : 케이스 워크

출처 : MidAtl 2021 J번 // NCNA 2021 G번
*/

char s[8];

int main(void) {
    int p, q;
    scanf("%d %d", &p, &q);
    scanf("%s", s);
    if (!strcmp(s, "AABB")) {
        if (q == 7) printf("8 9");
        else printf("-1");
    }
    else if (!strcmp(s, "ABAB")) {
        if (p == 6 && q == 8) printf("7 9");
        else printf("-1");
    }
    else if (!strcmp(s, "ABBA")) {
        if (q - p == 3) printf("%d %d", p + 1, p + 2);
        else printf("-1");
    }
    else if (!strcmp(s, "BAAB")) {
        if (p == 2 && q == 8) printf("1 9");
        else printf("-1");
    }
    else if (!strcmp(s, "BABA")) {
        if (p == 2 && q == 4) printf("1 3");
        else printf("-1");
    }
    else if (!strcmp(s, "BBAA")) {
        if (p == 3) printf("1 2");
        else printf("-1");
    }
    else return 1;
    return 0;
}