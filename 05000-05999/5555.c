#include <stdio.h>
#include <string.h>

/*
문제 : N(N <= 100)개의 문자열에 대해 문자열의 시작과 끝을 이었을 때 찾으려는 문자열이 존재하는 문자열의 수를 구한다.
단, 각 문자열의 길이는 10이고, 찾으려는 문자열의 길이는 10 이하이다.

해결 방법 : 문자열을 2번 반복시키면 끝에서 시작으로 돌아오는 점을 포함하는 모든 조합을 탐색 가능하다.
해당하는 값들은 strstr를 통해 확인하면 된다.

주요 알고리즘 : 문자열, 브루트 포스

출처 : JOI 2011P 2번
*/

char find[16], rings[128][32];

int main(void) {
    int n, r = 0;
    char tmp[16];
    scanf("%s", find);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", rings[i]);
        strcpy(tmp, rings[i]);
        strcat(rings[i], tmp);
        if (strstr(rings[i], find)) r++;
    }
    printf("%d", r);
    return 0;
}