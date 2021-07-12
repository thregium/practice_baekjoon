#include <stdio.h>
#include <string.h>

/*
문제 : 길이 1000 이하의 문자열이 주어질 때, 이 문자열의 뒤에 문자들을 추가해 만들 수 있는 가장 짧은 팰린드롬의 길이를 구한다.

해결 방법 : 각 팰린드롬의 길이일 때 현재 문자열로 만들 수 있는지 확인하다 가장 먼저 나오는 것을 출력하면 된다.
각 팰린드롬의 길이에서 만들 수 있는 조건은 팰린드롬의 중심에서부터 확인해 나가다 원래 문자열의 길이를 벗어나기 전까지
모든 문자가 대칭인 경우이다.

주요 알고리즘 : 브루트 포스, 문자열
*/

char s[1024];

int main(void) {
    int len, t = 0;
    scanf("%s", s);
    len = strlen(s);
    for (int i = len; i <= len * 2; i++) {
        t = 1;
        for (int j = i / 2; j < len; j++) {
            if (s[j] != s[i - j - 1]) {
                t = 0;
                break;
            }
        }
        if (t) {
            printf("%d", i);
            break;
        }
    }
    return 0;
}