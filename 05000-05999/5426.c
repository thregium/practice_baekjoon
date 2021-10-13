#include <stdio.h>
#include <string.h>

/*
문제 : 10000자 이하의 소문자로만 이루어진 문자열이 주어진다. 문자열의 길이는 제곱수라 할 때, 정사각형 형태의 행렬에
문자열을 가로로 채워넣은 다음, 오른쪽으로 90도 회전시켜 해당 문자열을 만들었다면 원래의 문자열을 구한다.

해결 방법 : 문제에 주어진 대로 해보면 바뀐 문자열은 원래 문자열을 오른쪽부터 세로쓰기로 쓴 것과 같다.
따라서, 먼저 문자열의 길이에서 한 변의 길이를 구한 다음, 오른쪽 위부터 아래로 내려가며 해당하는 문자들을 출력하면 된다.

주요 알고리즘 : 구현, 문자열

출처 : BAPC 2012 E번
*/

char s[10240];

int main(void) {
    int t, l, x;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%s", s);
        l = strlen(s);
        x = -1;
        for (int i = 1; i <= 100; i++) {
            if (i * i == l) x = i;
        }
        if (x < 0) break;
        for (int i = x - 1; i >= 0; i--) {
            for (int j = 0; j < x; j++) {
                printf("%c", s[j * x + i]);
            }
        }
        printf("\n");
    }
    return 0;
}