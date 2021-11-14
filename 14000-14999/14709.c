#include <stdio.h>

/*
문제 : N(N <= 10)개의 서로 다른 두 자연수(<= 5)가 주어질 때, 이 자연수들이 1-3, 1-4, 3-4로 이루어져 있는지 구한다.
순서는 신경쓰지 않고 서로 같은 쌍은 주어지지 않는다.

해결 방법 : 각 자연수의 등장 횟수를 구한 다음, 1, 3, 4는 2회, 나머지는 0회 등장했는지 확인하면 된다.

주요 알고리즘 : 구현?

출처 : 서울대 2017D2 A번
*/

int cnt[6];

int main(void) {
    int n, a, b;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        cnt[a]++;
        cnt[b]++;
    }
    if (cnt[1] == 2 && cnt[2] == 0 && cnt[3] == 2 && cnt[4] == 2 && cnt[5] == 0) printf("Wa-pa-pa-pa-pa-pa-pow!");
    else printf("Woof-meow-tweet-squeek");
    return 0;
}