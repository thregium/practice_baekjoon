#include <stdio.h>

/*
문제 : 10^6자 이하의 알파벳 소문자로만 이루어진 문자열에서 동일한 문자열들끼리 쌍을 지었을 때 모든 쌍이 사이에 짝수개의 문자를 갖는지 구한다.

해결 방법 : 두 문자 사이 짝수개의 문자를 갖기 위해서는 두 수가 홀수 칸만큼 차이 나야 한다. 그런데, 홀수 + 홀수는 짝수이므로
같은 문자가 3개 이상이 되면 조건을 맞추는 것이 불가능해진다. 따라서, 문자가 3개 이상 나오는지 보고 2개인 문자들은 사이의 거리를 확인해보면 된다.

주요 알고리즘 : 문자열, 애드 혹

출처 : GNY 2020 L번
*/

int lastpos[26], cnt[26];
char s[1048576];

int main(void) {
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        if (lastpos[s[i] - 'a'] == 0 || ((i - lastpos[s[i] - 'a']) & 1) == 0) {
            lastpos[s[i] - 'a'] = i + 1;
            cnt[s[i] - 'a']++;
            if (cnt[s[i] - 'a'] > 2) {
                printf("NO");
                return 0;
            }
        }
        else {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}