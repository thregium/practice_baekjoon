#include <stdio.h>

/*
문제 : 100자 이하의 대문자로 이루어진 문자열에서 부분 수열 "IOI"가 있는 지 찾는다.

해결 방법 : 모든 3개의 글자 쌍에 대해 'I', 'O', 'I'가 순서대로 나오는 지 확인한다.
나온다면 그러한 부분 수열이 있는 것이고, 나오지 않는다면 그러한 부분 수열은 없는 것이다.

주요 알고리즘 : 문자열, 브루트 포스

출처 : JOI 2021예1 2-2번
*/

char s[128];

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (s[i] == 'I' && s[j] == 'O' && s[k] == 'I') r = 1;
            }
        }
    }
    printf("%s\n", r ? "Yes" : "No");
    return 0;
}