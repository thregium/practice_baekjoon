#include <stdio.h>

/*
문제 : 길이 N(N <= 100)의 대문자 'A', 'B', 'C', 'D', 'E'로만 이루어진 문자열이 주어질 때,
3가지 이상의 문자로 이루어졌는지 여부를 구한다.

해결 방법 : 각 문자의 등장 횟수를 배열에 저장한 다음, 등장 횟수가 1회 이상인 문자의 개수를 세고
그 값이 3 이상인지 여부를 확인하면 된다.

주요 알고리즘 : 문자열, 구현

출처 : JOI 2022예1 1-3번
*/

char s[128];
int cnt[32];

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; i++) {
        cnt[s[i] - 'A']++;
    }
    for (int i = 0; i < 26; i++) {
        r += !!cnt[i];
    }
    printf("%s", r >= 3 ? "Yes" : "No");
    return 0;
}