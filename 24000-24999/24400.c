#include <stdio.h>

/*
문제 : N(N <= 10000)개의 자연수(<= 10^9)로 이루어진 수열 A에서 Q(Q <= N)번째로 작은 수를 찾는
방법을 문제에서 주어진 수도 코드대로 할 때, 중간에 수열 B와 같아지는 지점이 있는 지 구한다.

해결 방법 : 주어진 수도코드를 구현한 후, 수열을 매번 확인한다.
수열엥서 같은 수인 지점과 그 개수를 배열, 변수로 관리하며
같은 수인 지점의 수가 N이 되는 지점이 있는 지 확인하면 된다.

주요 알고리즘 : 구현, 애드 혹
*/

int a[10240], b[10240], same[10240];
int n, scnt = 0, res = 0;

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int select(int p, int r, int q) {
    if (p == r) return a[p];
    int t = partition(p, r);
    int k = t - p + 1;
    if (q < k) return select(p, t - 1, q);
    else if (q == k) return a[t];
    else return select(t + 1, r, q - k);
}

int partition(int p, int r) {
    int x = a[r];
    int i = p - 1;
    int tmp;
    for (int j = p; j <= r - 1; j++) {
        if (a[j] <= x) {
            swap(&a[++i], &a[j]);
            tmp = same[i] + same[j];
            same[i] = (a[i] == b[i]);
            same[j] = (a[j] == b[j]);
            scnt += (same[i] + same[j]) - tmp;
            if (scnt == n) res = 1;
        }
    }
    if (i + 1 != r) {
        swap(&a[i + 1], &a[r]);
        tmp = same[i + 1] + same[r];
        same[i  + 1] = (a[i + 1] == b[i + 1]);
        same[r] = (a[r] == b[r]);
        scnt += (same[i + 1] + same[r]) - tmp;
        if (scnt == n) res = 1;
    }
    return i + 1;
}

int main(void) {
    int q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
        same[i] = (a[i] == b[i]);
        scnt += same[i];
    }
    if (scnt == n) res = 1;
    select(1, n, q);
    printf("%d", res);
    return 0;
}