#include <stdio.h>
#include <ctype.h>

/*
문제 : 길이 50 이하의 화학식이 주어질 때, 이 화학식이 성립하기 위한 계수들 중 사전순으로 가장 작은 것을 구한다.
계수는 1 이상 10 이하며 항상 가능한 경우만 주어진다. 화학식을 구성하는 화합물들은 'C', 'H', 'O'로만 이루어져 있으며,
각 원소들의 값은 1 이상 9 이하로 주어진다.

해결 방법 : 먼저 화학식을 파싱하여 각 원소가 각 항에 몇 개씩 들어있는지 구한다. 원소기호가 오는 경우
다음 문자가 숫자인지 확인한다. 숫자라면 판단을 보류하고, 아니라면 해당 원소의 값을 1 늘린다.
숫자가 오는 경우에는 이전 문자가 원소기호일 것이다. 해당 원소기호의 값을 숫자의 값만큼 올린다.
+나 =이 오는 경우에는 현재 항의 위치를 다음 항으로 옮기도록 한다.

파싱이 끝나면 브루트 포스로 계수를 1 1 1부터 10 10 10까지 차례로 움직여가며 해당 화학식이 성립할 수 있는지 확인한다.
성립하게 되는 첫 화학식을 출력하고 프로그램을 종료하면 된다.

주요 알고리즘 : 브루트 포스, 파싱

출처 : CHCI 2005RJ 3번
*/

char s[64];
int chem[3][3];

int main(void) {
    int p = 0, t;
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        if (s[i] == 'C' || s[i] == 'H' || s[i] == 'O') {
            if (isdigit(s[i + 1])) continue;
            else chem[p][s[i] == 'C' ? 0 : s[i] == 'H' ? 1 : 2]++;
        }
        else if (isdigit(s[i])) {
            if (i == 0) return -2;
            chem[p][s[i - 1] == 'C' ? 0 : s[i - 1] == 'H' ? 1 : 2] += s[i] - '0';
        }
        else if (s[i] == '+' && p == 0) p++;
        else if (s[i] == '=' && p == 1) p++;
        else return -1;
    }
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            for (int k = 1; k <= 10; k++) {
                t = 1;
                for (int l = 0; l < 3; l++) {
                    if (chem[0][l] * i + chem[1][l] * j != chem[2][l] * k) t = 0;
                }
                if (t) {
                    printf("%d %d %d", i, j, k);
                    return 0;
                }
            }
        }
    }
    return 1;
}