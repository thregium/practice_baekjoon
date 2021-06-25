#include <stdio.h>

/*
문제 : N(N <= 1000)명의 사람들이 각각 사람들 중 참말을 말하는 사람이 A명 이상 B명 이하라고 말했다. 이때 참을 말한 사람의 수가
될 수 있는 수 중 가장 큰 것을 구한다. 없다면 -1을 출력한다.

해결 방법 : 0명부터 N명까지에 대해 일일히 확인해보며 맞는 것 중 가장 큰 것을 구하면 된다.

주요 알고리즘 : 브루트 포스

출처 : PacNW 2018 L/Y번
*/

int a[1024], b[1024];

int main(void) {
    int n, cnt, best = -1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i], &b[i]);
    }
    for (int i = 0; i <= n; i++) {
        cnt = 0;
        for (int j = 0; j < n; j++) {
            if (i >= a[j] && i <= b[j]) cnt++;
        }
        if (cnt == i) best = i;
    }
    printf("%d", best);
    return 0;
}