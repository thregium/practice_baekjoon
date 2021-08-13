#include <stdio.h>
#include <ctype.h>

/*
문제 : 256자 미만 길이의 소문자 또는 공백으로 이루어진 문자열이 주어질 때, 가장 많이 등장한 문자를 구한다.
여러개인 경우 ?를 출력한다.

해결 방법 : 먼저 문자열의 소문자들의 종류별로 개수를 세 놓는다. 그 다음으로는 각 문자별로 가장 많이 등장한 문자를 찾는다.
이때, 가장 많이 등장한 횟수를 갱신할 때에는 해당 문자를 결괏값으로 놓고, 그와 같은 횟수로 등장한 문자가 나오면
결괏값을 ?로 바꾸면 한번의 반복만으로 답을 구할 수 있다.

주요 알고리즘 : 문자열, 구현

출처 : Seoul 2008I A번
*/

char s[320];
int cnt[26];

int main(void) {
    int t, h, r;
    scanf("%d\n", &t);
    for (int tt = 0; tt < t; tt++) {
        fgets(s, 300, stdin);
        for (int i = 0; s[i]; i++) {
            if (islower(s[i])) cnt[s[i] - 'a']++;
        }
        h = 0, r = -1;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > h) {
                h = cnt[i];
                r = i;
            }
            else if (cnt[i] == h) r = -1;
            cnt[i] = 0;
        }
        if (r < 0) printf("?\n");
        else printf("%c\n", r + 'a');
    }
    return 0;
}