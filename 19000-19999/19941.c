#include <stdio.h>

/*
문제 : N(N <= 20000)개의 햄버거와 사람이 있다. 각 사람은 자신에게서 K(K <= 10) 거리에 있는 햄버거를 먹을 수 있다면,
햄버거를 먹을 수 있는 사람을 최대로 할 때, 몇 명까지 가능한지 구한다.

해결 방법 : 각 사람은 가장 왼쪽에 있는 햄버거를 먹는 것이 최적이다. 그 방법을 구현하면 된다.

주요 알고리즘 : 그리디 알고리즘

출처 : 정올 2020_1 중1/고2번
*/

char s[20480];

int main(void) {
    int n, k, r = 0;
    scanf("%d %d", &n, &k);
    scanf("%s", s);
    for (int i = 0; i < n; i++) {
        if (s[i] != 'P') continue;
        for (int j = i - k; j <= i + k; j++) {
            if (j < 0 || j > n) continue;
            if (s[j] == 'H') {
                r++;
                s[j] = 'X';
                break;
            }
        }
    }
    printf("%d", r);
    return 0;
}