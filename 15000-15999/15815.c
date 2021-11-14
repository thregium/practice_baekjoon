#include <stdio.h>
#include <ctype.h>

/*
문제 : 후위 표기식으로 표기된 100자 이하의 식이 주어질 때, 이 식을 계산한 결과를 구한다.
단, 각 수는 모두 숫자 단위로 주어지고, 중간과 최종 결과는 모두 2^31보다 작으며 0으로 나누는 경우는 없다.

해결 방법 : 스택을 이용한다.

주요 알고리즘 : 자료 구조, 스택

출처 : 전북대 2018 G번
*/

char s[128];
int stack[128];
int top = 0;

int main(void) {
    int r = 0;
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        if (isdigit(s[i])) {
            stack[top++] = s[i] - '0';
        }
        else {
            if (top < 2) return 1;
            if (s[i] == '+') stack[top - 2] = stack[top - 2] + stack[top - 1];
            else if (s[i] == '-') stack[top - 2] = stack[top - 2] - stack[top - 1];
            else if (s[i] == '*') stack[top - 2] = stack[top - 2] * stack[top - 1];
            else if (s[i] == '/') stack[top - 2] = stack[top - 2] / stack[top - 1];
            else return 2;
            top--;
        }
    }
    if (top != 1) return 3;
    printf("%d", stack[0]);
    return 0;
}