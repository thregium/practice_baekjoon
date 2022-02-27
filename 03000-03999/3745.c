#include <stdio.h>

/*
문제 : 길이 N(N <= 100000)의 자연수(<= 100000)로 이루어진 배열에서 가장 긴 증가하는 수열의 길이를 구한다.

해결 방법 : 이분 탐색을 이용해 구할 수 있다.

주요 알고리즘 : 이분 탐색, LIS

출처 : SEERC 2008 A번
*/

int a[103000], l[103000];

int get_pos(int x, int n) {
    int lo = 0, hi = n, mid;
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        if (l[mid] >= x) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

int main(void) {
    int n, p, r;
    //freopen("E:\\PS\\ICPC\\Europe\\SEERC\\2008\\input\\a.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Europe\\SEERC\\2008\\output\\a_t.out", "w", stdout);
    while (scanf("%d", &n) != EOF) {
        r = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            if (r == 0) l[r++] = a[i];
            else {
                p = get_pos(a[i], r);
                if (p == r) l[r++] = a[i];
                else l[p] = a[i];
            }
        }
        printf("%d\n", r);
    }
    return 0;
}