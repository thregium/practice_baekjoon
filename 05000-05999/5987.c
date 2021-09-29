#include <stdio.h>
#include <string.h>

/*
문제 : Z(Z <= 100)개의 길이 100 이하의 문자열과 N_i, C_i(C_i <= 12)가 주어질 때, (N_i + 1)번째 이후의 부분 문자열을
현재 문자열에 붙이는 것을 C_i회 반복한 결과를 각각 출력한다.

해결 방법 : 문자열에서 strcpy 함수에 n번 인덱스의 포인터를 입력하면 해당 (N_i + 1)번 이후의 부분 문자열이 추가된다.
여기에 이전 문자열을 strcat하면 다음 문자열이 나오고, 이를 C_i회 반복하면 된다.

주요 알고리즘 : 문자열, 구현

출처 : USACO 2011O B4번
*/

char str[16][524288];

int main(void) {
    int z, n, c;
    scanf("%d", &z);
    for (int zz = 0; zz < z; zz++) {
        scanf("%d %d %s", &n, &c, str[0]);
        for (int i = 1; i <= c; i++) {
            strcpy(str[i], &str[i - 1][n]);
            strcat(str[i], str[i - 1]);
        }
        printf("%s\n", str[c]);
    }
    return 0;
}