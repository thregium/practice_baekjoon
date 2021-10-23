#include <stdio.h>
#include <stdlib.h>

/*
문제 : B개의 버거와 C개의 사이드 메뉴, D개의 음료(B, C, D <= 1000)의 가격이 주어질 때, 모든 메뉴를 정가에 사는데 필요한 가격과,
할인가에 사는데 필요한 가격을 구한다. 할인가는 버거, 사이드 메뉴, 음료를 선택할 때, 해당하는 메뉴를 10% 할인해 주는 것이다.
정상가는 모두 10000원 이하의 100의 배수이다. 또한, 각 메뉴는 1개씩만 사야 한다.

해결 방법 : 정상가는 그대로 전체의 합을 구하면 된다.
할인가의 경우에는 먼저 각 버거의 가격과, 각 사이드 메뉴의 가격, 각 음료의 가격을 내림차순으로 정렬한다.
그 다음, B, C, D 가운데 가장 작은 수 만큼의 세트 메뉴를 산다. 해당하는 메뉴들은 정가의 90% 가격이 된다.
그 외의 메뉴들은 정가 그대로 산 다음 가격을 확인하면 할인가이다.

주요 알고리즘 : 구현, 정렬, 그리디 알고리즘

출처 : 중앙대 2018R 2번
*/

int burg[1024], side[1024], bev[1024];

int small(int a, int b) {
    return a < b ? a : b;
}

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int b, c, d, e, r1 = 0, r2 = 0;
    scanf("%d %d %d", &b, &c, &d);
    for (int i = 0; i < b; i++) {
        scanf("%d", &burg[i]);
    }
    for (int i = 0; i < c; i++) {
        scanf("%d", &side[i]);
    }
    for (int i = 0; i < d; i++) {
        scanf("%d", &bev[i]);
    }
    e = small(b, small(c, d));
    qsort(burg, b, sizeof(int), cmp1);
    qsort(side, c, sizeof(int), cmp1);
    qsort(bev, d, sizeof(int), cmp1);
    for (int i = 0; i < b; i++) {
        r1 += burg[i];
        if (i < e) r2 += burg[i] / 10 * 9;
        else r2 += burg[i];
    }
    for (int i = 0; i < c; i++) {
        r1 += side[i];
        if (i < e) r2 += side[i] / 10 * 9;
        else r2 += side[i];
    }
    for (int i = 0; i < d; i++) {
        r1 += bev[i];
        if (i < e) r2 += bev[i] / 10 * 9;
        else r2 += bev[i];
    }
    printf("%d\n%d", r1, r2);
    return 0;
}