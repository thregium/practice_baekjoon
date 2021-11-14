#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100000)명의 전투력이 주어진다. 두 명이 전투를 하면 전투력이 낮은 사람은 죽고 높은 사람은 낮은 사람의
전투력만큼을 더할 수 있다고 하면, 첫 번째 사람이 모두를 이길 수 있는지 구한다.

해결 방법 : 첫 번째 사람은 그를 제외한 전투력이 가장 낮은 사람부터 전투를 하는 것이 이득이다.
따라서, 전투력에 따라 오름차순으로 정렬을 하고, 그 사람의 전투력이 현재 첫 번째 사람의 전투력 이상인 경우가 없는지
확인한다. 있다면 이길 수 없고, 없다면 이길 수 있다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : 선린 2021 A번
*/

int a[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    long long x;
    scanf("%d", &n);
    if (n == 1) {
        printf("Yes");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a + 1, n - 1, sizeof(int), cmp1);
    x = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] >= x) {
            printf("No");
            return 0;
        }
        x += a[i];
    }
    printf("Yes");
    return 0;
}