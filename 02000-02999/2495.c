#include <stdio.h>

/*
문제 : 8자리 수 3개가 주어질 때, 3개 각각에 대해 같은 자리 수가 가장 많이 연속된 구간의 길이를 구한다.

해결 방법 : 각 수들을 문자열로 입력받은 다음 직접 가장 긴 연속구간의 길이를 구하면 된다.

주요 알고리즘 : 구현, 문자열

출처 : 정올 2009지 중1/고1번
*/

char s[16];

int main(void) {
    int cnt = 0, longest = 0;
    for (int i = 0; i < 3; i++) {
        scanf("%s", s);
        cnt = 1;
        longest = 1;
        for (int j = 1; j < 8; j++) {
            if (s[j] == s[j - 1]) {
                cnt++;
                if (cnt > longest) longest = cnt;
            }
            else cnt = 1;
        }
        printf("%d\n", longest);
    }
    return 0;
}