#include <stdio.h>

/*
문제 : 각 알파벳을 1부터 26까지의 자연수에 대응시켰을 때, 길이 L(L <= 26)에 전체 합이 W(W <= 1000)인
소문자로 이루어진 문자열이 있는 지 구하고, 있다면 그 중 하나를 출력한다.

해결 방법 : W가 L보다 작거나 L * 26보다 크다면 만들 수 없다. 그 외의 경우에는 나눗셈과 나머지를 이용하여
간단히 문자열을 출력할 수 있다.

주요 알고리즘 : 수학, 구성적

출처 : VTH 2017 F번
*/

int main(void) {
    int l, w;
    scanf("%d %d", &l, &w);
    if (w < l || w > l * 26) {
        printf("impossible");
        return 0;
    }
    for (int i = 0; i < l; i++) {
        printf("%c", w / l + 'a' - (i >= w % l));
    }
    return 0;
}