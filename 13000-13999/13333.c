#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 1000)개의 논문에 대한 인용 횟수(<= 10000)가 주어질 때, H-인덱스를 구한다.

해결 방법 : 인용 횟수를 내림차순으로 정렬한 다음, 순위가 인용 횟수보다 커지는 지점의 순위 - 1을 출력하면 된다.
없다면 N을 출력한다.

주요 알고리즘 : 구현, 정렬

출처 : Daejeon 2016I I번
*/

int a[1024];

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
    for (int i = 0; i < n; i++) {
        if (a[i] <= i) {
            printf("%d", i);
            return 0;
        }
    }
    printf("%d", n);
    return 0;
}