#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
문제 : 생일과 N(N <= 1000)개의 날이 주어질 때, 각 날 가운데 가장 바이오리듬이 좋은 날 중 가장 빠른 날을 구한다.
바이오리듬은 문제에 주어진 방식대로 구한다.

해결 방법 : 각 날들을 문자열 형식으로 입력받은 다음, 문제에 주어진 방식대로 바이오리듬을 구하고 가장 큰 날을 찾아나간다.
최댓값과 같다면 strtoll 함수를 이용해 더 빠른 날을 찾는다.

주요 알고리즘 : 구현, 수학

출처 : 아주대 2021D1 A / 2021D2 A번
*/

char bd[16], cd[16], res[16];

int sqr(int x) {
    return x * x;
}

int main(void) {
    int n, t, best = -1;
    scanf("%s", bd);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", cd);
        t = 0;
        for (int j = 0; j < 4; j++) {
            t += sqr(bd[j] - cd[j]);
        }
        t *= sqr(bd[4] - cd[4]) + sqr(bd[5] - cd[5]);
        t *= sqr(bd[6] - cd[6]) + sqr(bd[7] - cd[7]);
        if (t > best || (t == best && strtoll(cd, NULL, 10) < strtoll(res, NULL, 10))) {
            strcpy(res, cd);
            best = t;
        }
    }
    printf("%s", res);
    return 0;
}