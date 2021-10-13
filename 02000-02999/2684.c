#include <stdio.h>

/*
문제 : 길이 40의 'H'와 'T'로 이루어진 문자열이 주어질 때, 연속한 3 글자가
"TTT", "TTH", "THT", "THH", "HTT", "HTH", "HHT", "HHH" 인 부분 문자열의 개수를 각각 구한다.

해결 방법 : 연속한 3개의 문자에 대해 T를 0, H를 1로 두고 3자리 이진수로 보며 각 수에 대한 개수를 센다.
그 다음, 0부터 7까지의 등장 횟수를 차례로 출력하면 위의 순서와 같게 된다.

주요 알고리즘 : 구현, 비트마스킹?

출처 : GNY 2010 A번
*/

char s[64];
int cnt[8];

int main(void) {
    int p;
    scanf("%d", &p);
    for (int i = 0; i < p; i++) {
        scanf("%s", s);
        for (int j = 0; j < 38; j++) {
            cnt[(s[j] == 'H') * 4 + (s[j + 1] == 'H') * 2 + (s[j + 2] == 'H')]++;
        }
        for (int j = 0; j < 8; j++) {
            printf("%d ", cnt[j]);
            cnt[j] = 0;
        }
        printf("\n");
    }
    return 0;
}