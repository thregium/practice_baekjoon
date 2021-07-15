#include <stdio.h>

/*
문제 : K(K <= 1000)개의 법을 발의하고 투표한 기록이 주어질 때, 이 기록이 유효한지 구한다.
법을 발의하는 경우 이전 논의를 일시 중지한 후 해당 법에 대한 논의를 한다. 그 다음 현재 법에 대한 투표를 진행한 뒤
다시 이전 법에 대한 논의를 한다. 모든 기록이 끝난 후 투표하지 않고 남아있는 법이 존재해서는 안 된다.

해결 방법 : 괄호가 유효한지 검사하는 것과 동치임을 알 수 있다. 따라서 이를 스택을 이용해 구하면 된다.

주요 알고리즘 : 자료구조, 스택

출처 : NWRRC 2019Q E번
*/

char buff[8], stack[1024];
int top = 0;

int main(void) {
    int k;
    char c;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%s %c", buff, &c);
        if (buff[0] == 'A') {
            stack[top++] = c;
        }
        else {
            if (top < 1 || stack[top - 1] != c) {
                printf("No");
                return 0;
            }
            top--;
        }
    }
    if (top) printf("No");
    else printf("Yes");
    return 0;
}