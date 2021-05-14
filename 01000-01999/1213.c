#include <stdio.h>

/*
문제 : N(N <= 50)자의 문자열이 주어질 때, 이 문자열의 순서를 바꿔서 팰린드롬을 만들 수 있는지 확인하고,
만들 수 있는 경우 알파벳순으로 가장 빠른 것을 출력한다.

해결 방법 : 각 문자의 수를 세서 홀수인 수가 2개 이상인 경우 팰린드롬을 만들 수 없다.
1개 이하라면 먼저, 알파벳 오름차순으로 문자의 개수를 확인하고 그 문자를 개수의 절반(나머지 버림)만큼을 출력한다.
만약 홀수인 수가 1개라면 홀수인 문자를 출력한다. 다시 내림차순으로 문자 개수의 절반만큼을 출력하면 된다.

주요 알고리즘 : 문자열, 그리디 알고리즘
*/

char s[64];
int cnt[26];

int main(void) {
    int odd = -1;
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        cnt[s[i] - 'A']++;
    }
    for (int i = 0; i < 26; i++) {
        if (cnt[i] & 1) {
            if (odd >= 0) {
                printf("I\'m Sorry Hansoo");
                return 0;
            }
            odd = i;
        }
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < (cnt[i] >> 1); j++) printf("%c", i + 'A');
    }
    if (odd >= 0) printf("%c", odd + 'A');
    for (int i = 25; i >= 0; i--) {
        for (int j = 0; j < (cnt[i] >> 1); j++) printf("%c", i + 'A');
    }
    return 0;
}