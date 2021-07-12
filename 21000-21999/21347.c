#include <stdio.h>

/*
문제 : 1000자 이하의 문자열 2개가 주어질 때, 2번째 문자열은 첫 번째 문자열에서 일부 글자들이 중복된 문자열이라고 한다.
이때 중복된 문자를 모두 찾는다.

해결 방법 : 두 문장의 모든 문자에 대해 등장 횟수를 저장한 다음, 두 번째 문자열에서 더 많이 등장한 문자들을 전부 출력한다.

주요 알고리즘 : 문자열, 구현

출처 : NWERC 2020 K번
*/

int cnt1[256], cnt2[256];
char s1[1024], s2[1024];

int main(void) {
    fgets(s1, 1013, stdin);
    fgets(s2, 1013, stdin);
    for (int i = 0; s1[i]; i++) cnt1[s1[i]]++;
    for (int i = 0; s2[i]; i++) cnt2[s2[i]]++;
    for (int i = 0; i < 256; i++) {
        if (cnt1[i] < cnt2[i]) printf("%c", i);
    }
    return 0;
}