#include <stdio.h>

/*
문제 : N(N <= 17)개의 자연수와 연산자로 이루어진 수식이 주어진다. 각 연산자의 범위는 .의 개수로
정해진다고 할 때, 이 수식의 답을 출력한다. 자연수와 연산자는 각각 9개 이하로 주어진다.
또한, 각 자연수는 1 자리 수로만 이루어져 있다.

해결 방법 : 가장 바깥쪽부터 수식을 안쪽으로 들어가며 계산해 나간다. 가장 앞의 연산자를 기준으로
계산하며, 숫자가 나오면 더하거나 곱하고, 연산자가 나오면 .의 개수가 현재 .의 개수보다 많은 칸의 범위를
구한 다음 그 범위는 재귀적으로 계산한 다음 결괏값에 더하거나 곱한다. 중간에 1칸만 남는 칸이 나온다면
그 칸은 숫자일 것이므로 그대로 반환한다. 위 내용대로 계산한 다음 답을 출력하면 된다.

주요 알고리즘 : 수학, 재귀

출처 : JDC 2015 C번
*/

char buff[64];
int level[64], num[64];

int getres(int st, int ed, int lv) {
    if (st == ed) {
        return num[st];
    }
    int op = -num[st];
    int r = op - 1, et;
    for (int i = st + 1; i <= ed; i++) {
        if (num[i] >= 0) {
            if (op == 1) r += getres(i, i, lv + 1);
            else r *= getres(i, i, lv + 1);
        }
        else {
            et = i + 1;
            while (level[et] > lv + 1) et++;
            if (op == 1) r += getres(i, et - 1, lv + 1);
            else r *= getres(i, et - 1, lv + 1);
            i = et - 1;
        }
    }
    return r;
}

int main(void) {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%s", buff);
            level[i] = 0;
            for (int j = 0; buff[j]; j++) {
                if (buff[j] == '.') level[i]++;
                else if (buff[j] == '+') num[i] = -1;
                else if (buff[j] == '*') num[i] = -2;
                else num[i] = buff[j] - '0';
            }
        }
        printf("%d\n", getres(0, n - 1, 0));
        for (int i = 0; i < n; i++) {
            level[i] = 0, num[i] = 0;
        }
    }
    return 0;
}