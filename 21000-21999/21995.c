#include <stdio.h>

/*
문제 : N * 2(N <= 1000) 크기의 1부터 N * 2까지의 자연수로 이루어진 순열이 있다.
이 순열의 i번째와 N + i번째를 바꾸는 연산과 i * 2번째와 i * 2 + 1번째를 바꾸는 연산을 통해
주어진 순열을 정렬 가능한 지 구하고, 가능하다면 그렇게 하는 최소 연산 횟수를 구한다.
불가능한 경우 -1을 출력한다.

해결 방법 : 두 연산은 모두 연속으로 하는 경우 원래대로 돌아오므로 두 연산을 교대로 사용해야 한다.
두 연산을 교대해서 사용하다 보면 많아야 N * 2회 이내에는 원래대로 돌아오는 것을 알 수 있다.
따라서, 원래대로 돌아오는 과정을 양쪽 방향에 대해 시도해 보고 더 먼저 정렬되는 것을 답으로 하면 된다.
원래대로 돌아올 동안 주어진 순열이 정렬되지 않는다면 -1을 출력한다.

주요 알고리즘 : 구현, 시뮬레이션, 애드 혹?

출처 : NERC 2020 K번
*/

int a[2048], b[2048];

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int issame(int* a, int* b, int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

int issorted(int* a, int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] != i + 1) return 0;
    }
    return 1;
}

int main(void) {
    int n, p = 0, r1 = 0, r2 = 0;
    scanf("%d", &n);
    for (int i = 0; i < n * 2; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    if (issorted(a, n * 2)) {
        printf("0");
        return 0;
    }


    do {
        if ((p++) & 1) {
            for (int i = 0; i < n; i++) {
                swap(&b[i], &b[i + n]);
            }
        }
        else {
            for (int i = 0; i < n; i++) {
                swap(&b[i * 2], &b[i * 2 + 1]);
            }
        }
        if (issorted(b, n * 2)) {
            r1 = p;
            break;
        }
    } while (!issame(a, b, n * 2));

    for (int i = 0; i < n * 2; i++) b[i] = a[i];
    p = 0;
    do {
        if (~(p++) & 1) {
            for (int i = 0; i < n; i++) {
                swap(&b[i], &b[i + n]);
            }
        }
        else {
            for (int i = 0; i < n; i++) {
                swap(&b[i * 2], &b[i * 2 + 1]);
            }
        }
        if (issorted(b, n * 2)) {
            r2 = p;
            break;
        }
    } while (!issame(a, b, n * 2));
    if (!r1) printf("-1");
    else printf("%d", r1 < r2 ? r1 : r2);
    return 0;
}