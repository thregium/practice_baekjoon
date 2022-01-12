#include <stdio.h>
#include <string.h>

/*
문제 : N(N <= 1000)개의 서로 다른 자연수(<= 10000)가 주어질 때, 곱한 값의 숫자가 공차가 1인 등차수열이 되는
가장 큰 곱한 값을 구한다. 그러한 값이 없다면 -1을 출력한다.

해결 방법 : 모든 쌍에 대해 곱을 구해나가며 공차가 1인 등차수열인지 확인하고 가장 큰 값을 찾으면 된다.
공차가 1인 등차수열 여부는 sprintf() 함수를 이용해 문자열로 바꾸어 간단히 해결 가능하다.

주요 알고리즘 : 문자열, 브루트 포스

출처 : JAG 2016P A번
*/

int a[1024];
char buff[16];

int main(void) {
    int n, r = -1, t;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] * a[j] <= r) continue;
            sprintf(buff, "%d", a[i] * a[j]);
            t = 1;
            for (int k = 1; buff[k]; k++) {
                if (buff[k] != buff[k - 1] + 1) t = 0;
            }
            if (t) r = a[i] * a[j];
        }
    }
    printf("%d", r);
    return 0;
}