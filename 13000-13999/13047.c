#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(3 <= N <= 100000)개의 자연수(<= 10^9)로 된 배열이 있다. 이 배열에서 임의의 세 자연수를 고르고 제거한 다음,
세 자연수 가운데 임의의 두 수의 평균을 2개 배열에 추가하는 연산을 배열의 크기가 2가 될 때 까지 반복한다.
이때, 남는 두 수의 평균으로 가능한 값 가운데 최댓값을 구한다.

해결 방법 : 가장 큰 2개의 수와 가장 작은 수를 고른 다음 가장 큰 2개의 수의 평균을 넣는 것을 반복한다.
그러면 최종적으로 가장 큰 2개의 수의 평균만 남게 되고, 이것이 최댓값이 된다.
이는 정렬을 통해 간단히 구할 수 있다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : RCC 2016W B번
*/

int a[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    printf("%d", (a[0] + a[1]) >> 1);
    return 0;
}