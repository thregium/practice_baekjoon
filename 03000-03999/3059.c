#include <stdio.h>

/*
문제 : 알파벳 대문자로 이루어진 1000자 이하의 문자열이 주어질 때, 해당 문자열에 등장하지 않는 대문자의 아스키코드의 합을 구한다.

해결 방법 : 문자열의 각 대문자의 등장 횟수를 센 다음, 0회인 것의 아스키 코드를 전부 더하면 된다.

주요 알고리즘 : 구현, 문자열
*/

char buff[1024];
int cnt[26];

int main(void) {
    int t, r = 0;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%s", &buff);
        r = 0;
        for (int i = 0; buff[i]; i++) {
            cnt[buff[i] - 'A']++;
        }
        for (int i = 0; i < 26; i++) {
            if (cnt[i] == 0) r += i + 'A';
            else cnt[i] = 0;
        }
        printf("%d\n", r);
    }
    return 0;
}