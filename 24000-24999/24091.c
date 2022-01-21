#include <stdio.h>

/*
문제 : 문제에 주어진 수도코드를 통해 만들어진 정렬 알고리즘에서 K(K <= 10^8)번
교환이 일어난 후의 배열을 출력한다. 배열의 크기는 N(N <= 10000)이다.
각 배열의 원소는 10^9 이하의 자연수이다. K번 교환이 일어나지 않는다면 -1을 출력한다.

해결 방법 : 주어진 수도코드를 코드로 구현한 뒤 K번 교환이 일어나면 정렬을 멈추고 배열을 출력한다.
단, 전부 정렬해도 K번 교환이 일어나지 않는다면 -1을 출력한다.

주요 알고리즘 : 구현, 정렬
*/

int a[10240];
long long n, k;

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int part(int s, int e) {
    int x = a[e];
    int i = s - 1;
    for (int j = s; j < e; j++) {
        if (a[j] <= x) {
            swap(&a[++i], &a[j]);
            if (--k <= 0) return 0;
        }
    }
    if (i + 1 != e) {
        swap(&a[i + 1], &a[e]);
        k--;
    }
    return i + 1;
}

void quick(int s, int e) {
    if (s < e) {
        int m = part(s, e);
        if (k <= 0) return;
        quick(s, m - 1);
        if (k <= 0) return;
        quick(m + 1, e);
        if (k <= 0) return;
    }
}

int main(void) {
    scanf("%lld %lld", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    quick(1, n);
    if (k) printf("-1");
    else {
        for (int i = 1; i <= n; i++) {
            printf("%d ", a[i]);
        }
    }
    return 0;
}