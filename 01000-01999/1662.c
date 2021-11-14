#include <stdio.h>
#include <string.h>

/*
문제 : 50자 이하의 숫자와 괄호로 이루어진 문자열이 주어질 때, 해당 문자열의 압축을 풀면 어느 정도 길이인지 구한다.
잘못 압축된 것이 들어오는 경우는 주어지지 않는다.

해결 방법 : 재귀적으로 답을 구한다. 만약 다음 문자가 '('인 경우 해당 괄호가 닫히는 구간까지를 찾아낸 다음,
해당 구간에 해당 숫자의 값을 곱한 값을 답에 더한다. 그 외의 문자(숫자)가 나오면 결괏값에 1을 더한다.

주요 알고리즘 : 수학, 재귀
*/

char s[64];

int getres(int st, int ed) {
    int r = 0, p = 0, schk, num;
    for (int i = st; i <= ed; i++) {
        if (s[i + 1] == '(') {
            p = 1;
            num = s[i] - '0';
            i++;
            schk = i + 1;
            while (p) {
                i++;
                if (s[i] == '(') p++;
                else if (s[i] == ')') p--;
            }
            r += num * getres(schk, i - 1);
        }
        else r++;
    }
    return r;
}

int main(void) {
    int l;
    scanf("%s", s);
    l = strlen(s);
    printf("%d", getres(0, l - 1));
    return 0;
}