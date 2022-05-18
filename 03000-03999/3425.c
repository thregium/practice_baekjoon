#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
문제 : 문제에 주어진 자료 구조의 연산을 시뮬레이션하고 결과를 출력한다. 중간에 오류가 발생한 경우
"ERROR"를 출력한다.

해결 방법 : 각 연산자에 따라 경우를 나누어 시뮬레이션하면 된다. 실수하기 쉬우므로 주의한다.

주요 알고리즘 : 구현, 시뮬레이션, 스택, 케이스 워크

출처 : CERC 2011 J번
*/

char buff[1024];
int prog[103000], stack[1024];
const char* func[10] = { "NUM", "POP", "INV", "DUP", "SWP", "ADD", "SUB", "MUL", "DIV", "MOD" };

int excut(int plen, long long x) {
    int top = 1;
    stack[0] = x;
    for (int i = 0; i < plen; i++) {
        if (prog[i] >= 0) stack[top++] = prog[i];
        else if (prog[i] == -1) {
            if (top == 0) return -1000000011;
            top--;
        }
        else if (prog[i] == -2) {
            if (top == 0) return -1000000021;
            stack[top - 1] *= -1;
        }
        else if (prog[i] == -3) {
            if (top == 0) return -1000000031;
            stack[top] = stack[top - 1];
            top++;
        }
        else if (prog[i] == -4) {
            if (top <= 1) return -1000000041;
            x = stack[top - 1];
            stack[top - 1] = stack[top - 2];
            stack[top - 2] = x;
        }
        else if (prog[i] == -5) {
            if (top <= 1) return -1000000051;
            x = stack[top - 1] + stack[top - 2];
            if (abs(x) > 1000000000) return -1000000052;
            top--;
            stack[top - 1] = x;
        }
        else if (prog[i] == -6) {
            if (top <= 1) return -1000000061;
            x = stack[top - 2] - stack[top - 1];
            if (abs(x) > 1000000000) return -1000000062;
            top--;
            stack[top - 1] = x;
        }
        else if (prog[i] == -7) {
            if (top <= 1) return -1000000071;
            x = (long long)stack[top - 1] * stack[top - 2];
            if (llabs(x) > 1000000000) return -1000000072;
            top--;
            stack[top - 1] = x;
        }
        else if (prog[i] == -8) {
            if (top <= 1) return -1000000081;
            if(stack[top - 1] == 0) return -1000000083;
            x = abs(stack[top - 2]) / abs(stack[top - 1]);
            if (llabs(x) > 1000000000) return -1000000082;
            if (stack[top - 2] < 0) x *= -1;
            if (stack[top - 1] < 0) x *= -1;
            top--;
            stack[top - 1] = x;
        }
        else if (prog[i] == -9) {
            if (top <= 1) return -1000000091;
            if (stack[top - 1] == 0) return -1000000093;
            x = abs(stack[top - 2]) % abs(stack[top - 1]);
            if (llabs(x) > 1000000000) return -1000000092;
            if (stack[top - 2] < 0) x *= -1;
            top--;
            stack[top - 1] = x;
        }
    }

    if (top == 1) return stack[0];
    else return -1000000100;
}

int main(void) {
    int n, x, plen;
    while (1) {
        plen = 0;
        while (1) {
            scanf("%s", buff);
            if (!strcmp(buff, "QUIT") || !strcmp(buff, "END")) break;
            for (int i = 0; i < 10; i++) {
                if (!strcmp(buff, func[i])) {
                    if (i == 0) {
                        scanf("%d", &x);
                        prog[plen++] = x;
                    }
                    else prog[plen++] = -i;
                    break;
                }
            }
        }
        if (!strcmp(buff, "QUIT")) break;

        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            x = excut(plen, x);
            if (abs(x) <= 1000000000) printf("%d\n", x);
            else printf("ERROR\n");
        }
        printf("\n");
    }
    return 0;
}