#include <stdio.h>

/*
문제 : 길이 N(N <= 100)의 서로 다른 자연수(<= 2000)로 이루어진 배열에서
최댓값의 왼쪽에 있는 수들의 합과 오른쪽에 있는 수들의 합을 각각 구한다.

해결 방법 : 우선 최댓값의 위치를 구한 다음, 그 왼쪽의 수들과 그 오른쪽의 수들에 대해 합을 각각 구하면 된다.

주요 알고리즘 : 구현

출처 : JOI 2021예1 2-3번
*/

int a[128];

int main(void) {
    int n, h = -1, hn = -1, sl = 0, sr = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] > h) {
            h = a[i];
            hn = i;
        }
    }
    for (int i = 0; i < hn; i++) sl += a[i];
    for (int i = hn + 1; i < n; i++) sr += a[i];
    printf("%d\n%d\n", sl, sr);
    return 0;
}