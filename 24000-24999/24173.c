#include <stdio.h>

/*
문제 : N(N <= 500000) 길이의 자연수(<= 10^9)로 이루어진 배열이 있다. 이 배열을 문제에 주어진 수도코드대로
힙 정렬하였을 때, K(K <= 10^8)번째 교환되는 수들을 오름차순으로 출력한다.
K번 이하로 저장된다면 -1을 출력한다.

해결 방법 : 문제에 주어진 수도코드를 구현한 다음, K번동안 수가 교환될 때 마다
교환 가능 횟수를 1씩 줄여나간다. 교환 가능 횟수가 0이 되면 정렬을 종료하고
마지막으로 교환된 두 수를 출력한다. 교환 가능 횟수가 남은 경우 -1을 출력한다.
오름차순으로 출력해야 함에 유의한다.

주요 알고리즘 : 구현, 정렬
*/

int a[524288];
int k, r1, r2;

void swap(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void hpf(int* a, int x, int n) {
    int lt = 2 * x, rt = 2 * x + 1, sml = 0;
    if (rt <= n) {
        if (a[lt] < a[rt]) sml = lt;
        else sml = rt;
    }
    else if (lt <= n) sml = lt;
    else return;

    if (a[sml] < a[x]) {
        swap(&a[x], &a[sml]);
        r1 = a[x], r2 = a[sml];
        if (--k == 0) return;
        hpf(a, sml, n);
        if (k == 0) return;
    }
}

void build_mheap(int* a, int n) {
    for (int i = n >> 1; i >= 1; i--) {
        hpf(a, i, n);
        if (k == 0) return;
    }
}

void hsort(int* a, int s, int e) {
    build_mheap(a, e);
    if (k == 0) return;
    for (int i = e; i > s; i--) {
        swap(&a[s], &a[i]);
        r1 = a[s], r2 = a[i];
        if (--k == 0) return;
        hpf(a, s, i - 1);
        if (k == 0) return;
    }
}

int main(void) {
    int n;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    hsort(a, 1, n);
    if (k) printf("-1");
    else {
        if (r1 > r2) swap(&r1, &r2);
        printf("%d %d", r1, r2);
    }
    return 0;
}