#include <stdio.h>
#include <string.h>

/*
문제 : 자연수 N(N <= 9999)이 주어질 때, 이 수를 번호판으로 만들었을 때의 너비를 구한다.
숫자 0은 4cm, 1은 2cm, 나머지 숫자들은 3cm의 너비를 갖고, 숫자들 사이와 수의 앞뒤로 1cm씩 간격이 필요하다.

해결 방법 : 숫자를 문자열 형태로 입력받은 다음, 각 숫자에 대응하는 너비의 합과 문자열 길이 + 1(앞뒤와 사이 간격)의
합을 구하면 이것이 너비가 된다.

주요 알고리즘 : 구현, 문자열

출처 : NZPC 2006 C번
*/

char n[8];

int main(void) {
    int r;
    while (1) {
        r = 0;
        scanf("%s", n);
        if (n[0] == '0') break;
        for (int i = 0; n[i]; i++) {
            if (n[i] == '0') r += 4;
            else if (n[i] == '1') r += 2;
            else r += 3;
        }
        r += strlen(n) + 1;
        printf("%d\n", r);
    }
    return 0;
}