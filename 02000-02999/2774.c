#include <stdio.h>

/*
문제 : 자연수 X(X <= 10^9)가 주어질 때, X를 이루는 서로 다른 숫자의 개수를 구한다.

해결 방법 : 각 숫자별로 개수를 세어나간다. X의 뒷자리부터 하나씩 확인하며 몇인지 살피고 그 숫자를 나왔다고 표시한다.
모든 자리를 살피면 0부터 9까지 한번씩 찾아보면서 나온 숫자의 개수를 세면 된다.

주요 알고리즘 : 수학
*/

int cnt[10];

int main(void) {
    int t, n, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        r = 0;
        for (int i = n; i; i /= 10) cnt[i % 10]++;
        for (int i = 0; i < 10; i++) {
            if (cnt[i]) {
                cnt[i] = 0;
                r++;
            }
        }
        printf("%d\n", r);
    }
    return 0;
}