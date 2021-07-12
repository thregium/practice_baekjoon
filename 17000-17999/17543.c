#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000007

/*
문제 : 덧셈과 곱셈만으로 이루어진, 부호를 생략한 식이 주어진다. 이때 이 식의 결과를 구한다. 식은 최대 300000개의
수나 괄호로 이루어져 있고, 괄호의 바깥은 덧셈 연산이다.

해결 방법 : 홀수번째 괄호 안쪽은 곱셈 연산이고, 짝수번째(0 포함) 괄호 안쪽은 덧셈 연산이다. 따라서 각 괄호 단계의 연산 결과를
스택에 저장한 후 괄호가 끝나면 윗 단계의 결과를 꺼내서 연산하면 된다. 이때 홀수 번째는 스택을 1로 초기화하고 짝수 번째는
스택을 0으로 초기화해 두어야 이후 다시 괄호가 나올 때 연산이 제대로 된다.

주요 알고리즘 : 자료구조, 스택, 구현, 파싱

출처 : BAPC 2019P B번
*/

int tokens[327680], stack[327680];
char buff[16];

int main(void) {
    int n, lv = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", buff);
        if (buff[0] == '(') tokens[i] = -1;
        else if (buff[0] == ')') tokens[i] = -2;
        else tokens[i] = strtoll(buff, NULL, 10);
        if (i & 1) stack[i] = 1;
    }
    for (int i = 0; i < n; i++) {
        if (tokens[i] == -1) lv++;
        else if (tokens[i] == -2) {
            lv--;
            if (lv & 1) stack[lv] = ((long long)stack[lv] * stack[lv + 1]) % MOD;
            else stack[lv] = (stack[lv] + stack[lv + 1]) % MOD;

            if (lv & 1) stack[lv + 1] = 0;
            else stack[lv + 1] = 1;
        }
        else {
            if (lv & 1) stack[lv] = ((long long)stack[lv] * tokens[i]) % MOD;
            else stack[lv] = (stack[lv] + tokens[i]) % MOD;
        }
    }
    printf("%d", stack[0]);
    return 0;
}