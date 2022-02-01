#include <stdio.h>
#include <string.h>

/*
문제 : 50자 이하의 대문자로 이루어진 문자열이 주어질 때, 이 문자열의 앞에서부터 순서대로
1자, 2자, 3자, ... N자까지 뒤집거나 뒤집지 않은 후 나오는 사전순으로 가장 빠른 문자열을 구한다.

해결 방법 : 마지막 문자는 결과 문자열의 맨 앞 또는 맨 뒤에만 올 수 있음을 알 수 있다.
이를 반복하면 앞 또는 뒤쪽으로 문자열을 배치해 나갈 수 있고, 이때 배치하는 위치는
앞에 사전순으로 더 빠른 문자열이 있으면 뒤, 없으면 앞이다. 이렇게 배치하면 가장 빠른 문자열이 된다.

주요 알고리즘 : 그리디 알고리즘, 문자열
*/

char s[64], res[64];
int cnt[26];

int main(void) {
    int l, t, lt, rt;
    scanf("%s", s);
    l = strlen(s);
    lt = 0, rt = l - 1;
    for (int i = 0; i < l; i++) {
        cnt[s[i] - 'A']++;
    }
    for (int i = l - 1; i >= 0; i--) {
        t = 1;
        for (int j = 0; j < s[i] - 'A'; j++) {
            if (cnt[j]) t = 0;
        }
        if (t) res[lt++] = s[i];
        else res[rt--] = s[i];
        cnt[s[i] - 'A']--;
    }
    printf("%s", res);
    return 0;
}