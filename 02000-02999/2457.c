#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100000)가지의 월/일 단위로 된 구간이 주어질 때, 각 구간들을 합해서 3월 1일부터 11월 30일까지
끊임 없는 구간을 만들 수 있는지 확인하고 가능하다면 가장 적은 수의 구간을 합했 을 때의 구간의 수를 구한다.

해결 방법 : 각 구간들을 정렬한다. 그 다음으로는 3월 1일 이전에 시작하는 구간에서 가장 늦게 끝나는 구간의 끝점을 찾는다.
다음으로는 3월 1일 이후부터 이 끝 점 이전까지 시작하는 구간에서 가장 늦게 끝나는 구간의 끝점을 찾는다.
이를 반복해 끝점이 11월 30일 이후가 되는 첫 날까지 구간의 수를 세면 된다.

주요 알고리즘 : 그리디 알고리즘

출처 : 정올 2011지 초3/중2번
*/

int flowers[103000][2];
int days[13] = { 0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m1, d1, m2, d2, lday = 60, next = -1, r = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &m1, &d1, &m2, &d2);
        flowers[i][0] = days[m1] + d1;
        flowers[i][1] = days[m2] + d2;
    }
    qsort(flowers, n, sizeof(int) * 2, cmp1);
    for (int i = 0; i < n; i++) {
        if (flowers[i][0] > lday) {
            if (next < 0) {
                printf("0");
                return 0;
            }
            lday = next;
            next = -1;
            if (lday >= 335) break;
            r++;
        }
        if (flowers[i][1] > next) next = flowers[i][1];
    }
    if (next < 335 && lday < 335) printf("0");
    else printf("%d", r);
    return 0;
}