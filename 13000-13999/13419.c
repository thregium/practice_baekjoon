#include <stdio.h>
#include <string.h>

/*
문제 : 2명이 26자 이하의 문자열을 번갈아가며 외칠 때, 2명이 외치게 되는 문자열을 가장 작은 반복 단위로 출력한다.

해결 방법 : 문자열의 길이가 짝수인 경우, 첫 번째 사람은 홀수번째, 두 번째 사람은 짝수번째 문자들만 외치면 된다.
문자열이 홀수라면 첫 번째 사람은 홀수번째, 두 번째 사람은 짝수번째를 외치되, 문자열이 끝나면 다시 돌아와서
첫 번째 사람은 짝수번째, 두 번째 사람은 홀수번째를 외쳐야 한다.

주요 알고리즘 : 수학?

출처 : 국민대 2016 G번
*/

char s[32];

int main(void) {
    int t, l;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%s", s);
        l = strlen(s);
        if (l & 1) {
            for (int i = 0; i < l; i += 2) printf("%c", s[i]);
            for (int i = 1; i < l; i += 2) printf("%c", s[i]);
            printf("\n");
            for (int i = 1; i < l; i += 2) printf("%c", s[i]);
            for (int i = 0; i < l; i += 2) printf("%c", s[i]);
            printf("\n");
        }
        else {
            for (int i = 0; i < l; i += 2) printf("%c", s[i]);
            printf("\n");
            for (int i = 1; i < l; i += 2) printf("%c", s[i]);
            printf("\n");
        }
    }
    return 0;
}