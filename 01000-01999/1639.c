#include <stdio.h>
#include <string.h>

/*
문제 : 길이 50 이하의 숫자로 이루어진 문자열이 주어질 때, 이 문자열의 부분 문자열 가운데, 길이가 짝수이고,
왼쪽 부분과 오른쪽 부분의 합이 같은 문자열 중 가장 긴 것의 길이를 구한다. 없으면 0을 출력한다.

해결 방법 : 길이를 내려가며 그러한 것이 나올 때 까지 그러한 문자열을 찾는다.
나오면 그 문자열의 길이를 출력하고 프로그램을 종료하고, 나오지 않으면 0을 출력한다.

주요 알고리즘 : 브루트 포스
*/

char s[64];

int main(void) {
    int l, sl, sr;
    scanf("%s", s);
    l = strlen(s);
    for (int i = l; i > 0; i--) {
        if (i & 1) continue;
        for (int j = 0; j + i <= l; j++) {
            sl = 0, sr = 0;
            for (int k = 0; k < (i >> 1); k++) {
                sl += s[j + k];
                sr += s[j + (i >> 1) + k];
            }
            if (sl == sr) {
                printf("%d", i);
                return 0;
            }
        }
    }
    printf("0");
    return 0;
}