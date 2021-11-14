#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 20)개의 문제의 풀이 시간이 주어질 때, 시간 내 가장 많이 풀면서 페널티를 최소로 할 때의
푼 문제 수, 마지막으로 푼 시각, 페널티를 각각 출력한다.

해결 방법 : 풀이 시간이 짧은 순으로 푸는 것이 이득이다. 따라서, 오름차순으로 정렬한 다음, 시간이 끝나기 전까지
각 문제들을 풀어나가며 세 결괏값들을 구해나가면 된다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : Phuket 2015 B번
*/

int a[32];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int t, n, l, r1, r2, r3;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %d", &n, &l);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        qsort(a, n, sizeof(int), cmp1);
        r1 = 0, r2 = 0, r3 = 0;
        for (int i = 0; i < n; i++) {
            if (r2 + a[i] <= l) {
                r1++;
                r2 += a[i];
                r3 += r2;
            }
            else break;
        }
        printf("Case %d: %d %d %d\n", tt, r1, r2, r3);
    }
    return 0;
}