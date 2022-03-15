#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INF (1LL << 63)

/*
문제 : 주어진 길이 200 이하의 수식에서 연산자의 우선순위를 바꿀 수 있다면
식의 결과로 가능한 최댓값을 구한다. 수식 중간에 어떤 연산을 하더라도
long long 범위 안에 들어가도록 주어진다. 수식의 연산자는 '+', '-', '*' 3가지로 제한된다.

해결 방법 : 우선순위에 대한 모든 경우를 시도해보면서 수식의 답을 계산하여 가장 작은 값을 찾으면 된다.
수식의 답은 괄호 단위로 재귀적으로 각 항을 확인하고, 괄호 안의 값들은 연산자가 없다면
strtoll()로 파싱하고, 있는 경우에는 우선순위가 높은 것부터 차례로 계산해나간다.
구현이 상당히 복잡하므로 주의한다.

주요 알고리즘 : 수학, 파싱, 브루트 포스

출처 : JAG 2013S3 G번
*/

char s[256];
int prio[3]; //+, -, *, higher first

long long big(long long a, long long b) {
    return a > b ? a : b;
}

long long solve(int st, int ed) {
    long long num[128], nnm[128];
    int inst[128], nnst[128];
    int ncnt = 0, icnt = 0, nnct = 0, nict = 0, lst = st, par = 0, noop = 1;
    long long tmp;
    for (int i = st; i <= ed; i++) {
        if (s[i] == '(') par++;
        else if (s[i] == ')') par--;
        else if (par == 0 && (s[i] == '+' || s[i] == '-' || s[i] == '*')) noop = 0;
    }
    if (noop && s[st] == '(') {
        lst++, st++, ed--, par = 0;
    }
    for (int i = st; i <= ed; i++) {
        if (par == 0 && (s[i] == '+' || s[i] == '-' || s[i] == '*')) {
            if (s[i] == '+') inst[icnt++] = 0;
            else if (s[i] == '-') inst[icnt++] = 1;
            else if (s[i] == '*') inst[icnt++] = 2;
            num[ncnt++] = solve(lst, i - 1);
            lst = i + 1;
        }
        else if (s[i] == '(') par++;
        else if (s[i] == ')') par--;
    }
    if (icnt == 0) return strtoll(&s[st], NULL, 10);
    else num[ncnt++] = solve(lst, ed);

    for (int i = 2; i >= 0; i--) {
        nnct = 0, nict = 0;
        tmp = num[0];
        for (int j = 0; j < icnt; j++) {
            if (prio[inst[j]] == i) {
                if (inst[j] == 0) tmp += num[j + 1];
                else if (inst[j] == 1) tmp -= num[j + 1];
                else tmp *= num[j + 1];
            }
            else {
                nnst[nict++] = inst[j];
                nnm[nnct++] = tmp;
                tmp = num[j + 1];
            }
        }
        nnm[nnct++] = tmp;
        for (int j = 0; j < nnct; j++) num[j] = nnm[j];
        for (int j = 0; j < nict; j++) inst[j] = nnst[j];
        icnt = nict, ncnt = nnct;
    }
    return num[0];
}

int main(void) {
    long long best = INF;
    scanf("%s", s);
    for (int i = 0; i < 3; i++) {
        prio[0] = i;
        for (int j = 0; j < 3; j++) {
            prio[1] = j;
            for (int k = 0; k < 3; k++) {
                prio[2] = k;
                best = big(best, solve(0, strlen(s) - 1));
            }
        }
    }
    printf("%lld\n", best);
    return 0;
}