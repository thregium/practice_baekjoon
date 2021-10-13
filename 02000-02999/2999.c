#include <stdio.h>
#include <string.h>

/*
문제 : 100자 이하의 소문자로 이루어진 문자열이 주어질 때, 이 문자열을 직사각형 형태의 행렬에 모든 문자열을 채운 다음,
문자열을 다른 방향에서 읽은 문자열을 구한다. 여러 직사각형을 만들 수 있다면 행과 열의 차이가 가장 작은 것으로 고른다.

해결 방법 : strlen함수를 통해 문자열의 길이를 구하고, 1부터 sqrt(len)까지의 수로 브루트 포스를 하여
행과 열의 크기를 구한 다음, 문자열에서 세로로 문자열을 채우고, 행렬에 있는 문자열을 읽은 것을 출력하면 된다.

주요 알고리즘 : 구현, 문자열

출처 : COCI 07/08#3 3번
*/

char s[128], mat[128][128];

int main(void) {
    int l, r = 0, c = 0;
    scanf("%s", s);
    l = strlen(s);
    for (int i = 1; i * i <= l; i++) {
        if (l % i == 0) r = i;
    }
    c = l / r;
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            mat[j][i] = s[i * r + j];
        }
    }
    for (int i = 0; i < r; i++) {
        printf("%s", mat[i]);
    }
    return 0;
}