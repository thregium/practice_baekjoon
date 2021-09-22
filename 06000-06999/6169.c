#include <stdio.h>

/*
문제 : T(T <= 100000)개의 지형이 있고, 각 지형은 오르막, 평지, 내리막 중 하나이다. 각 지형을 이동할 때의 소요시간이 주어질 때,
시간 M(M <= 10^7) 내로 첫 지형부터 출발해 다시 첫 지형 전으로 돌아올 수 있는 지형의 개수를 구한다.

해결 방법 : 각 지형을 입력받을 때 마다 올 때와 갈 때의 소요시간을 구한다. 두 소요시간의 합이 M보다 커질 때,
그때의 지형 - 1번째 지형을 출력하면 된다. 끝까지 M 이하인 경우에는 T를 출력하면 된다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : USACO 2008F B2번
*/

int terrain[103000];

int main(void) {
    int m, t, u, f, d, to = 0, from = 0;
    char c;
    scanf("%d %d %d %d %d", &m, &t, &u, &f, &d);
    for (int i = 0; i < t; i++) {
        scanf(" %c", &c);
        if (c == 'u') {
            to += u;
            from += d;
        }
        else if (c == 'f') {
            to += f;
            from += f;
        }
        else if (c == 'd') {
            to += d;
            from += u;
        }
        else return 1;
        if (to + from > m) {
            printf("%d", i);
            return 0;
        }
    }
    printf("%d", t);
    return 0;
}