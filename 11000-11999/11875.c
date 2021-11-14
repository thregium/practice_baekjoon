#include <stdio.h>
#include <string.h>

/*
문제 : 길이 100000 이하의 문자열이 주어질 때, 이 문자열에서 2개 이상의 서로 다른 아나그램을 합쳐 만들 수 있는 것이
있는지 확인하고 있는 경우 그 중 가장 짧은 것을 구한다.

해결 방법 : 먼저 문자열의 길이를 구하고 그 약수 길이인 부분 문자열마다 첫 아나그램의 문자 등장 횟수를 센다.
이후 문자열들의 문자 등장 횟수를 세며 다른 것이 있다면 다음 길이를 살펴본다.
같다면 그 길이가 가장 짧은 아나그램의 길이이다.

주요 알고리즘 : 문자열, 브루트 포스

출처 : COCI 15/16#5 2번
*/

char s[103000];
int cnt[26], cntp[26];

int main(void) {
    int l, d, r;
    scanf("%s", s);
    l = strlen(s);
    for (int i = 1; i * 2 <= l; i++) {
        if (l % i) continue;
        d = l / i;
        r = 1;
        for (int j = 0; j < i; j++) cnt[s[j] - 'a']++;
        for (int j = 1; j < d; j++) {
            for (int k = 0; k < i; k++) {
                cntp[s[j * i + k] - 'a']++;
            }
            for (int k = 0; k < 26; k++) {
                if (cnt[k] != cntp[k]) r = 0;
                cntp[k] = 0;
            }
        }
        if (r) {
            for (int j = 0; j < i; j++) printf("%c", s[j]);
            return 0;
        }
        for (int j = 0; j < 26; j++) cnt[j] = 0;
    }
    printf("-1");
    return 0;
}