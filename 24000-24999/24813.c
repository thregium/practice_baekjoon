#include <stdio.h>

/*
문제 : 길이 100 이하의 문자열이 주어질 때, 이 문자열의 왼쪽 끝에서 오른쪽 끝으로 이동 가능한 지 구한다.
'$', '|', '*'를 만나면 각각을 가방에 저장한다. 'b', 't', 'j'를 만나면 각각 '$', '|', '*'가
가방의 맨 위에 있는 경우 가방에서 그것을 제거한다. 없다면 이동이 불가능하고 그곳에서 멈춘다.
마지막 칸의 행동을 끝낸 다음 가방에 아무것도 없지 않다면 이동이 불가능하다.

해결 방법 : 스택을 사용하면 된다. '$', '|', '*'가 나오면 스택에 해당하는 것들을 저장한다.
'b', 't', 'j'가 나오면 스택의 맨 위에 원하는 것이 있다면 맨 위의 값을 제거한다.
없다면 실패이다. 마지막으로 스택이 비어있지 않다면 실패이고, 비어있다면 성공이다.

주요 알고리즘 : 자료 구조, 스택

출처 : VTH 2018 I번
*/

char s[128];
int stack[128];
int top = 0;

int main(void) {
    int n, r;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        top = 0, r = 1;
        for (int j = 0; s[j]; j++) {
            if (s[j] == '$') stack[top++] = 1;
            else if (s[j] == '|') stack[top++] = 2;
            else if (s[j] == '*') stack[top++] = 3;
            else if (s[j] == 'b') {
                if (top <= 0 || stack[top - 1] != 1) {
                    r = 0;
                    break;
                }
                else top--;
            }
            else if (s[j] == 't') {
                if (top <= 0 || stack[top - 1] != 2) {
                    r = 0;
                    break;
                }
                else top--;
            }
            else if (s[j] == 'j') {
                if (top <= 0 || stack[top - 1] != 3) {
                    r = 0;
                    break;
                }
                else top--;
            }
        }
        if (top > 0) r = 0;
        printf("%s\n", r ? "YES" : "NO");
    }
    return 0;
}
