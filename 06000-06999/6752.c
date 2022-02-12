#include <stdio.h>
#include <stdlib.h>

/*
문제 : C(C <= 100)개의 일에 대한 소요 시간(<= 100000)이 주어질 때, T(T <= 100000)분 내로
할 수 있는 일의 최대 개수를 구한다. 일은 한번에 하나씩만 할 수 있다.

해결 방법 : 일들을 시간순으로 정렬한 다음, 그 순서대로 시간 안에 가능한 만큼 일을 하면 된다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : CCC 2013 J4번
*/

int chore[128];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int t, c, r = 0;
    scanf("%d%d", &t, &c);
    for (int i = 0; i < c; i++) {
        scanf("%d", &chore[i]);
    }
    qsort(chore, c, sizeof(int), cmp1);
    for (int i = 0; i < c; i++) {
        t -= chore[i];
        if (t >= 0) r++;
        else break;
    }
    printf("%d", r);
    return 0;
}