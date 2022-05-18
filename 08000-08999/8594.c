#include <stdio.h>
#include <string.h>

/*
문제 : 길이 L(L <= 10^6)의 괄호로 이루어진 문자열이 주어지면 이 문자열이 제대로 되었는 지 확인하고,
제대로 된 경우 최고 괄호 깊이를 구한다.

해결 방법 ; 스택을 이용해 괄호를 검사하면서 최고 top 높이를 찾는다.
괄호가 제대로 되었다면 최고 높이를, 아니라면 NIE를 출력하면 된다.

주요 알고리즘 : 자료 구조, 스택

출처 : JPOI 2010 1-2번
*/

char p[1048576], stack[1048576];
int top = 0;

int main(void) {
    int l, r1 = 1, r2 = 0;
    scanf("%d", &l);
    scanf("%s", p);
    top = 0;
    for (int j = 0; j < l; j++) {
        if (p[j] == '(' || p[j] == '[' || p[j] == '{') {
            stack[top] = p[j];
            top++;
            if (top > r2) r2 = top;
        }
        else if (p[j] == ')' || p[j] == ']' || p[j] == '}') {
            if (top <= 0) {
                r1 = 0;
                break;
            }
            if ((p[j] == ')' && stack[top - 1] != '(') || (p[j] == ']' && stack[top - 1] != '[')
                || (p[j] == '}' && stack[top - 1] != '{')) {
                r1 = 0;
                break;
            }
            else top--;
        }
    }
    if (top) r1 = 0;
    if (!r1) printf("NIE");
    else printf("%d", r2);
    return 0;
}