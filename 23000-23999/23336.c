#include <stdio.h>
#define SZ 262144

/*
문제 : 1부터 N(N <= 200000)까지의 자연수로 이루어진 순열이 있다. 이 순열의 값 차이 1 이하인 수들끼리
순서를 바꾸어 순열을 정렬하기 위해 필요한 교환 횟수를 구한다.

해결 방법 : 번호와 수를 바꾸면 버블 소트에서 필요한 교환 횟수와 같다.
이는 각 위치에서 앞에 있는 더 큰 수의 개수와 같고, 이는 세그먼트 트리를 통해 간단히 찾아낼 수 있다.

주요 알고리즘 : 자료 구조, 세그먼트 트리

출처 : TOPC 2021 C번
*/

int a[204800], seg[SZ * 2];

int getsum(int s, int e, int ss, int se, int p) {
    if (e < ss || se < s) return 0;
    if (s <= ss && se <= e) return seg[p];
    else return getsum(s, e, ss, (ss + se) >> 1, p << 1) +
        getsum(s, e, ((ss + se) >> 1) + 1, se, (p << 1) + 1);
}

void upd(int p, int x) {
    seg[p + SZ] += x;
    for (int i = (p + SZ) >> 1; i >= 1; i >>= 1) {
        seg[i] = seg[i << 1] + seg[(i << 1) + 1];
    }
}

int main(void) {
    int n, x;
    long long r = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        a[x] = i;
    }
    for (int i = 1; i <= n; i++) {
        r += getsum(a[i] + 1, n, 0, SZ - 1, 1);
        upd(a[i], 1);
    }
    printf("%lld", r);
    return 0;
}