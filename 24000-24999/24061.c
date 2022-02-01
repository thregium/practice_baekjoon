#include <stdio.h>

/*
문제 : N(N <= 500000) 길이의 자연수(<= 10^9)로 이루어진 배열이 있다. 이 배열을 문제에 주어진 수도코드대로
병합 정렬하였을 때, K(K <= 10^8)번째로 수가 저장된 후의 배열을 출력한다.
K번 이하로 저장된다면 -1을 출력한다.

해결 방법 : 문제에 주어진 수도코드를 구현한 다음, K번동안 수가 저장될 때 마다 저장 횟수를 1씩 줄여나간다.
저장 횟수가 0이 되면 현재 확인한 수까지 원래 배열에 옮긴 다음 정렬을 종료하고 배열을 출력한다.
저장 횟수가 남은 경우 -1을 출력한다.

주요 알고리즘 : 구현, 정렬
*/

int a[524288], tmp[524288];
int k = 0;

void rest(int* a, int p, int r) {
    int i = p, t = 1;
    while (i <= r) a[i++] = tmp[t++];
}

void merge(int* a, int p, int q, int r) {
    int i = p, j = q + 1, t = 1;
    while (i <= q && j <= r) {
        if (a[i] <= a[j]) tmp[t++] = a[i++];
        else tmp[t++] = a[j++];
        if (--k == 0) {
            rest(a, p, p + t - 2);
            return;
        }
    }
    while (i <= q) {
        tmp[t++] = a[i++];
        if (--k == 0) {
            rest(a, p, p + t - 2);
            return;
        }
    }
    while (j <= r) {
        tmp[t++] = a[j++];
        if (--k == 0) {
            rest(a, p, p + t - 2);
            return;
        }
    }
    rest(a, p, r);
}

void msort(int* a, int p, int r) {
    int q;
    if (p < r) {
        q = (p + r) >> 1;
        msort(a, p, q);
        if (k == 0) return;
        msort(a, q + 1, r);
        if (k == 0) return;
        merge(a, p, q, r);
        if (k == 0) return;
    }
}

int main(void) {
    int n;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    msort(a, 1, n);
    if (k) printf("-1");
    else {
        for (int i = 1; i <= n; i++) {
            printf("%d ", a[i]);
        }
    }
    return 0;
}