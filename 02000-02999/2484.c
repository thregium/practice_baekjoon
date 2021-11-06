#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 1000)번 주사위 4개를 던졌을 때 점수가 가장 높은 것의 점수를 구한다. (점수 기준 생략)

해결 방법 : 문제의 조건대로 점수를 구한다. 정렬을 하면 좀더 조건의 수가 줄어들어 간단해진다.
그 다음 최댓값을 구해서 출력하면 된다.

주요 알고리즘 : 구현, 정렬, 케이스 워크

출처 : 정올 2010지 고1번
*/

int a[4];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, r = -1, t = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &a[j]);
        }
        qsort(a, 4, sizeof(int), cmp1);
        t = 0;
        if (a[0] == a[3]) t = 50000 + a[0] * 5000; //4개가 모두 같을 때
        else if (a[0] == a[2] || a[1] == a[3]) t = 10000 + a[1] * 1000; //3개만 같을 때
        else if (a[0] == a[1] && a[2] == a[3]) t = 2000 + (a[0] + a[2]) * 500; //2개씩 두 쌍이 같을 때
        else if (a[0] == a[1] || a[1] == a[2]) t = 1000 + a[1] * 100; //2개만 같을 때(2번째가 같은 것에 있을 때)
        else if (a[2] == a[3]) t = 1000 + a[2] * 100; //2개만 같을 때(3, 4번째가 같을 때)
        else t = a[3] * 100; //모두 다를 때
        if (t > r) r = t;
    }
    if (r < 0) return 1;
    printf("%d", r);
    return 0;
}