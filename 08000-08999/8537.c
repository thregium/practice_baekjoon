#include <stdio.h>
#include <string.h>

/*
문제 : I(I <= 100)개의 알파벳 소문자로 이루어진 20자 이하의 문자열이 주어질 때,
가장 많은 가짓수의 문자로 된 문자열의 문자 가짓수를 구한다.

해결 방법 : 각 문자열마다 각 문자의 개수를 센 다음 1개 이상인 문자의 수를 세서 가짓수를 구하고 그들 중 가장 큰 값을 구하면 된다.

주요 알고리즘 : 문자열, 구현

출처 : PA 2002.05 0-1번
*/

char buff[32];
int cnt[26];

int main(void) {
    int n, r = 0, t;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", buff);
        for (int j = 0; buff[j]; j++) {
            cnt[buff[j] - 'a']++;
        }
        t = 0;
        for (int j = 0; j < 26; j++) {
            if (cnt[j]) t++;
            cnt[j] = 0;
        }
        if (t > r) r = t;
    }
    printf("%d", r);
    return 0;
}