#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 50)개의 자연수(<= 10^9)로 이루어진 배열에서 어떠한 수도 다른 두 수의 합 이상이 되는
경우가 없도록 하는 부분 배열 가운데 가장 큰 것의 크기를 구한다.

해결 방법 : 각 수들을 정렬한 다음, 왼쪽 끝과 오른쪽 끝이 되는 모든 경우에 대해 반례가 되기 가장 쉬운 경우
(1번째, 2번째, 마지막)를 테스트해 보고, 반례가 되지 않거나 만들 수 없는 경우 가운데
가장 넓은 구간의 길이를 구하면 된다.

주요 알고리즘 : 그리디 알고리즘, 브루트 포스, 정렬
*/

int a[64];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, res = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            if (r - l < 2 || a[l] + a[l + 1] > a[r]) {
                if (r - l + 1 > res) res = r - l + 1;
            }
        }
    }
    printf("%d", res);
    return 0;
}