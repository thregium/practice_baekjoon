#include <stdio.h>

/*
문제 : 1부터 N(N <= 10^8)까지의 자연수들을 나열한 문자열의 K(K <= 10^9)번째 문자를 구한다.
그러한 문자가 없다면 -1을 출력한다. (제한시간 2초)

해결 방법 : 제한시간이 길기 때문에 각 자연수의 길이를 확인해 나가면서 K번째가 될 때의 문자를 찾으면 된다.

주요 알고리즘 : 구현, 시뮬레이션, 수학
*/

char buff[16];

int getdigit(int x) {
    if (x >= 100000) {
        if (x < 1000000) return 6;
        else if (x < 10000000) return 7;
        else if (x < 100000000) return 8;
        else return 9;
    }
    else if (x >= 10000) return 5;
    else if (x >= 1000) return 4;
    else if (x >= 100) return 3;
    else if (x >= 10) return 2;
    else return 1;
}

int main(void) {
    int n, k, d = 0;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        if (d + getdigit(i) >= k) {
            sprintf(buff, "%d", i);
            printf("%d", buff[k - d - 1] - '0');
            return 0;
        }
        else d += getdigit(i);
    }
    printf("-1");
    return 0;
}