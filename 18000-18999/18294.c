#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
문제 : N(N <= 200000)마리의 동물 종류가 주어진다. 이때, 한 동물이 전체의 절반을 넘는지 확인하고,
넘는다면 그 동물의 이름을, 넘지 않는다면 "NONE"을 출력한다.

해결 방법 : 모든 동물의 이름을 정렬한 다음, 각 동물 그룹의 수를 센다. 그 중 전체의 절반을 넘는 것이 있으면
그 동물의 이름을 출력하면 된다.

주요 알고리즘 : 문자열, 정렬

출처 : SWERC 2019 B번
*/

char anim[204800][24];

int main(void) {
    int n, cnt = 1, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", anim[i]);
    }
    qsort(anim, n, sizeof(char) * 24, strcmp);
    for (int i = 1; i < n; i++) {
        if (strcmp(anim[i], anim[i - 1])) {
            if (cnt * 2 > n) {
                printf("%s", anim[i - 1]);
                r = 1;
            }
            cnt = 1;
        }
        else cnt++;
    }
    if (cnt * 2 > n) {
        printf("%s", anim[n - 1]);
        r = 1;
    }
    if (!r) printf("NONE");
    return 0;
}