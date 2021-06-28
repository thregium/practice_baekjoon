#include <stdio.h>

/*
문제 : MBTI 유형이 주어질 때, 그와 반대되는 유형을 찾는다.

해결 방법 : 4자리의 결과를 하드코딩한다.

주요 알고리즘 : 구현, 문자열

출처 : 인하대 2020 A번
*/

char m[8];

int main(void) {
    scanf("%s", &m);
    if (m[0] == 'I') printf("E");
    else printf("I");
    if (m[1] == 'N') printf("S");
    else printf("N");
    if (m[2] == 'F') printf("T");
    else printf("F");
    if (m[3] == 'P') printf("J");
    else printf("P");
    return 0;
}