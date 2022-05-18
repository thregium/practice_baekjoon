#include <stdio.h>

/*
문제 : N(N <= 10)개의 사칙연산 식(<= 5)이 주어질 때, 연산 과정에 음수나 분수가 나오는 수의 개수를 구한다.

해결 방법 : 각 식을 저장한 다음, 음이 아닌 정수가 아닌 수가 나오는 연산때 마다
그러한 시작하는 수의 개수를 세서 출력하면 된다.

주요 알고리즘 : 브루트 포스

출처 : PacNW 2015 M번
*/

char buff[16];
int op[16][2];

int main(void) {
    int n, res = 0, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %d", buff, &op[i][1]);
        if (buff[0] == 'A') op[i][0] = 1;
        else if (buff[0] == 'S') op[i][0] = 2;
        else if (buff[0] == 'M') op[i][0] = 3;
        else if (buff[0] == 'D') op[i][0] = 4;
        else return 1;
    }
    for (int i = 1; i <= 100; i++) {
        x = i;
        for (int i = 0; i < n; i++) {
            if (op[i][0] == 1) x += op[i][1];
            else if (op[i][0] == 2) {
                if (x < op[i][1]) {
                    res++;
                    break;
                }
                else x -= op[i][1];
            }
            else if (op[i][0] == 3) x *= op[i][1];
            else if (op[i][0] == 4) {
                if (x % op[i][1]) {
                    res++;
                    break;
                }
                else x /= op[i][1];
            }
        }
    }
    printf("%d", res);
    return 0;
}