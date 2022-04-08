#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 300000)명의 재산(0 <=, <= 10^8)이 주어질 때, 상위 X%의 사람이 가진 재산 Y%에 대해
Y - X가 가장 클 때의 Y, X를 구한다.

해결 방법 : 재산을 내림차순으로 정렬한 다음, 전체 합을 구하고, 다시 누적 합을 구해나가면서
누적 합 / 전체 합의 비율이 사람 수 / 전체 사람 수에 비해 가장 차이가 커질 때의 두 값을 구하면 된다.

주요 알고리즘 : 수학, 브루트 포스, 정렬

출처 : COCI 16/17#5 2번
*/

int a[327680];
int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    long long sum = 0, psum = 0;
    double x = 0.0, y = 0.0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    qsort(a, n, sizeof(int), cmp1);

    for (int i = 0; i < n; i++) {
        psum += a[i];
        if (psum / (double)sum - (i + 1.0) / n > y - x) {
            x = (i + 1.0) / n;
            y = psum / (double)sum;
        }
    }
    printf("%.9f\n%.9f", x * 100.0, y * 100.0);
    return 0;
}