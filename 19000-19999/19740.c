#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
문제 : K(K <= 1000)개의 수가 있다. 이 수들의 길이는 전부 같고, 1 이상 9999...99(같은 자리 수) 이하라고 한다.
수의 길이는 9 이하라고 할 때, 주어진 수들이 1부터 N까지의 모든 자연수들 가운데 일부라면 N이 될 수 있는 최솟값과 최댓값을 구한다.
모든 수는 N의 자릿수와 길이가 같다.

해결 방법 : N의 최댓값은 주어진 자릿수를 모두 9로 채웠을 때의 값과 같다.
최솟값은 주어진 수들 가운데 최댓값의 첫 자리가 0이라면 10...0이고, 0이 아니라면 주어진 수들의 최댓값과 같다.

주요 알고리즘 : 문자열, 파싱

출처 : ROI 2018H L번
*/

char s[16];

int main(void) {
    int k, l = 0;
    long long n, h = 0, p = 1;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%s", s);
        l = strlen(s);
        n = strtoll(s, NULL, 10);
        if (n > h) h = n;
    }
    for (int i = 0; i < l; i++) p *= 10;
    p--;
    printf("%lld\n%lld", h <= p / 10 ? p / 10 + 1 : h, p);
    return 0;
}