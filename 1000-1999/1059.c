#include <stdio.h>
#include <stdlib.h>

/*
문제 : 정수 집합 S가 주어질 때, A < B를 만족하고, [A, B]에 S의 원소가 없는 구간 가운데 N을 포함하는 자연수 구간의 수를 구한다.
(L <= 50, Si <= 1000)

해결 방법 : Si의 최댓값이 크지 않으므로 브루트 포스를 통해 모든 구간을 확인하고 조건에 맞는 경우만 확인해도 충분하다.

주요 알고리즘 : 브루트 포스
*/

int s[64];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int l, n, r = 0;
    scanf("%d", &l);
    for (int i = 0; i < l; i++) {
        scanf("%d", &s[i]);
    }
    scanf("%d", &n);
    qsort(s, l, sizeof(int), cmp1);
    for (int j = 1; j < s[0]; j++) {
        for (int k = j + 1; k < s[0]; k++) {
            if (n >= j && n <= k) r++; //맨 앞 구간 처리
        }
    }
    for (int i = 1; i < l; i++) {
        for (int j = s[i - 1] + 1; j < s[i]; j++) {
            for (int k = j + 1; k < s[i]; k++) {
                if (n >= j && n <= k) r++; //이외 구간 처리
            }
        }
    }
    printf("%d", r);
    return 0;
}