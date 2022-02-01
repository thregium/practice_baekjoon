#include <stdio.h>

/*
문제 : 길이 N(N <= 5000)의 자연수(<= 5000)로 이루어진 수열이 주어질 때,
이 수열에 있는 산의 최대 길이를 구한다. 산은 순증가하다가 순감소하는 부분이다.
증가 또는 감소하는 부분의 길이는 0일 수 있다.

해결 방법 : 각 지점마다 해당 지점에서 시작하는 산의 길이를 구하고 가장 긴 것을 찾으면 된다.
산은 인접한 곳과 높이가 같은 구간을 포함할 수 없음에 유의한다.

주요 알고리즘 : 구현, 브루트 포스

출처 : 선린 5회 H번
*/

int a[5120];

int main(void) {
    int n, r = 1, p = 0, l = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        p = 0, l = 1;
        for (int j = i + 1; j < n; j++) {
            if (a[j] == a[j - 1]) break;
            else if (a[j] > a[j - 1]) {
                if (p) break;
            }
            else {
                if (!p) p = 1;
            }
            l++;
        }
        if (l > r) r = l;
    }
    printf("%d", r);
    return 0;
}