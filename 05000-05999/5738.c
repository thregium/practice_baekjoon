#include <stdio.h>
#include <stdlib.h>

/*
문제 : 두 팀의 공격수와 수비수(키퍼 포함)(<= 11)들의 골라인에서의 거리(<= 10000)가 주어질 때,
현재 상태가 오프사이드인 지 구한다.

해결 방법 : 두 팀의 선수들 위치를 골라인에서 가까운 순으로 정렬한 후,
공격팀의 가장 가까운 선수가 수비팀의 2번째로 가까운 선수보다 가까이 있는 지 확인한다.
그러하다면 오프사이드이고, 아니라면 오프사이드가 아니다.

주요 알고리즘 : 구현, 정렬

출처 : SARC 2007 H번 / 2008 PB번
*/

int b[16], c[16];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int a, d;
    while (1) {
        scanf("%d %d", &a, &d);
        if (a == 0) break;
        for (int i = 0; i < a; i++) {
            scanf("%d", &b[i]);
        }
        for (int i = 0; i < d; i++) {
            scanf("%d", &c[i]);
        }
        qsort(b, a, sizeof(int), cmp1);
        qsort(c, d, sizeof(int), cmp1);
        printf("%c\n", b[0] < c[1] ? 'Y' : 'N');
    }
    return 0;
}