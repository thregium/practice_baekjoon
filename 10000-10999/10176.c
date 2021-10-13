#include <stdio.h>
#include <ctype.h>

/*
문제 : 15자 이하의 문자열이 주어질 때, 이 문자열이 Opposite한 문자열인지 구한다. 이러한 문자열은 문자열에서 알파벳인 것들이
반전된 것과 짝을 지을 수 있는 것이다. 반전된 것은 A-Z, B-Y, ... M-N 등의 쌍이다. 대소문자는 구별하지 않는다.

해결 방법 : 문자열에서 알파벳이 나오면 각 알파벳의 개수를 센다. 그 다음, 개수를 양쪽에서부터 확인하며
양쪽 알파벳의 개수가 모두 같은지 확인한다. 하나라도 다르다면 opposite 하지 않은 것이고, 전부 같다면 opposite한 것이다.

주요 알고리즘 : 구현, 문자열

출처 : PLU 2014N 7번
*/

char s[32];
int cnt[26];

int main(void) {
    int t, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%s", s);
        for (int i = 0; s[i]; i++) {
            if (isupper(s[i])) cnt[s[i] - 'A']++;
            else if (islower(s[i])) cnt[s[i] - 'a']++;
        }
        r = 1;
        for (int i = 0; i < 13; i++) {
            if (cnt[i] != cnt[25 - i]) r = 0;
            cnt[i] = 0, cnt[25 - i] = 0;
        }
        printf("%s\n", r ? "Yes" : "No");
    }
    return 0;
}