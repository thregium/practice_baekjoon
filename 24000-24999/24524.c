#include <stdio.h>
#include <string.h>

/*
문제 : 길이 10^6 이하의 소문자로 이루어진 문자열 S와 길이 26 이하의 서로 다른 소문자로 이루어진
문자열 T가 주어진다. 문자열 S의 부분 수열을 이용하여 만들 수 있는 T의 최대 개수를 구한다.

해결 방법 : T의 모든 문자는 다르기 때문에 S에 T를 이루는 문자가 들어올 때 마다
부분 문자열에 추가할 수 있는 지 여부를 확인 가능하다. 만일 이 문자를 추가하더라도
T의 앞 문자보다 더 많이 남지 않는다면 부분 문자열에 추가하면 되는 것이다.

주요 알고리즘 : 그리디 알고리즘, 문자열

출처 : 성균관대 2022 B번
*/

char s[1048576], t[32];
int cnt[32];

int main(void) {
    int l;
    scanf("%s%s", s, t);
    l = strlen(t);
    for (int i = 0; s[i]; i++) {
        for (int j = 0; j < l; j++) {
            if (s[i] == t[j]) {
                if (j == 0 || cnt[j] < cnt[j - 1]) cnt[j]++;
                break;
            }
        }
    }
    printf("%d", cnt[l - 1]);
    return 0;
}