#include <stdio.h>

/*
문제 : 10만자 이하의 문자열(소문자)이 주어질 때, 최근 K(K <= 10000)자의 문자에서 가장 많이 나온 문자 가운데
가장 사전순으로 앞선 문자를 이용해 문자를 바꾼 것을 출력한다.

해결 방법 : 첫 K자는 미리 합을 구해 놓으며 출력한다. 이후 글자들은 매번 가장 많이 나온 문자를 찾고,
그를 이용해 문자를 돌린 것을 출력한다. 그리고 K개 전의 문자를 개수 배열에서 지우고 현재 문자를 넣는 것을 반복한다.

주요 알고리즘 : 구현, 슬라이딩 윈도우

출처 : Waterloo 140920 B번
*/

char s[103000];
int cnt[26];

int main(void) {
    int k, best, bc;
    scanf("%d", &k);
    scanf("%s", s);
    for (int i = 0; i < k; i++) {
        cnt[s[i] - 'a']++;
        printf("%c", s[i]);
    }
    for (int i = k; s[i]; i++) {
        best = 0, bc = 0;
        for (int j = 0; j < 26; j++) {
            if (cnt[j] > best) {
                bc = j;
                best = cnt[j];
            }
        }
        printf("%c", (s[i] - 'a' + bc + 1) % 26 + 'a');
        cnt[s[i - k] - 'a']--;
        cnt[s[i] - 'a']++;
    }
    return 0;
}