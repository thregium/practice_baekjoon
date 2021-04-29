#include <stdio.h>
#include <string.h>

/*
문제 : N(N <= 1000)명의 예상과 실제 선수 순위가 이름으로 주어질 때, 예상에 비해 순위가 가장 많이 오른 선수를 출력한다.
순위표가 완전히 동일한 경우 suspicious를 출력한다.

해결 방법 : 실제 결과를 기준으로 같은 선수의 예상 순위를 찾은 순위가 현재까지의 최댓값보다 많이 올랐다면,
오른 값과 그 순위를 저장한다. 이를 마지막까지 반복한 다음, 가장 많이 등장한 선수의 순위를 통해 그 선수의 이름을 출력한다.
초기값과 같다면 suspicious를 출력한다.

주요 알고리즘 : 문자열, 구현

출처 : BAPC 2020P F번
*/

char p[1024][128], f[1024][128];

int main(void) {
    int n, r = 0, rp = -1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", p[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%s", f[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!strcmp(f[i], p[j])) {
                if (j - i > r) {
                    r = j - i;
                    rp = i;
                }
                break;
            }
        }
    }
    if (rp < 0) printf("suspicious");
    else printf("%s", f[rp]);
    return 0;
}