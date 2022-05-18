#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100)개의 강의와 M(M <= 100)의 마일리지가 있을 때, 이 마일리지로 수강 성공 가능한 강의의
개수를 구한다. 각 강의에는 L(L <= 100)명의 수강 신청자와 D(D <= 100)명의 수강 자리가 주어진다.
각 수강 신청자의 신청 마일리지(<= 36)를 볼 수 있다. 마일리지가 다른 사람과 같을 때 우선권이 있다.
수강 신청시에는 반드시 마일리지를 1 이상 넣어야 한다.

해결 방법 : 각 강의마다 D가 L보다 크다면 1만큼의 마일리지만 넣어도 된다. 그 외의 경우에는
마일리지가 높은 순으로 D등인 사람의 마일리지만큼 넣으면 된다. 이를 이용해 모든 강의의 필요한 마일리지를
저장한 다음, 적게 필요한 것 부터 순서대로 신청해서 가능한 개수를 세면 된다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : 연세대 2016 A번
*/

int a[128], b[128];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int cmp2(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m, l, d, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &l, &d);
        for (int i = 0; i < l; i++) {
            scanf("%d", &a[i]);
        }
        qsort(a, l, sizeof(int), cmp1);
        if (d > l) b[i] = 1;
        else b[i] = a[d - 1];
    }
    qsort(b, n, sizeof(int), cmp2);
    for (int i = 0; i < n; i++) {
        if (b[i] <= m) {
            m -= b[i];
            r++;
        }
    }
    printf("%d", r);
    return 0;
}