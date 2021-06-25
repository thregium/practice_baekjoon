#include <stdio.h>
#include <ctype.h>

/*
문제 : 5000자 이하의 알파벳 소문자, 공백, 엔터로 이루어진 문자열이 주어질 때,
이 문자열에서 가장 많이 쓰인 알파벳을 사전순으로 출력한다.

해결 방법 : 문자열을 입력받으며 문자열을 살펴보다가 알파벳인 경우 해당 알파벳의 카운트를 1 올린다.
모든 문자열을 살펴보면 가장 많이 쓰인 알파벳의 개수를 찾고 다시 알파벳의 개수가 그와 같은 알파벳들을 사전순으로 출력하면 된다.

주요 알고리즘 : 문자열
*/

char buff[5120];
int cnt[26];

int main(void) {
    int biggest = 0;
    while (fgets(buff, 5100, stdin)) {
        for (int i = 0; buff[i]; i++) {
            if (islower(buff[i])) cnt[buff[i] - 'a']++;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (cnt[i] > biggest) biggest = cnt[i];
    }
    for (int i = 0; i < 26; i++) {
        if (cnt[i] == biggest) printf("%c", i + 'a');
    }
    return 0;
}