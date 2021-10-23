#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 3000)개의 수로 이루어진 수열이 주어질 때, 이 수열이 Jolly jumper인지 구한다. Jolly jumper인 경우는
인접한 두 수의 차이로 1부터 N - 1까지 모든 수가 나오는 경우이다.

해결 방법 : 각 수열의 값을 보면서 인접한 두 수의 차이를 살핀다. 만약 0이거나 N 이상인 경우에는 범위를 벗어났으므로
모든 수를 나오게 할 수 없고, Jolly jumper가 아니다. 또한, 이미 나온 두 수의 차이가 나온 경우에도 Jolly jumper가 아니다.
나오지 않은 범위 내 값이 나왔다면 나왔음을 표시해둔다. 끝까지 위 두 경우가 나오지 않았다면 Jolly jumper이다.

주요 알고리즘 : 구현?

출처 : Waterloo 000930 C번
*/

int num[3200], chk[3200];

int main(void) {
    int n, r;
    //freopen("E:\\PS\\Contest\\waterloo\\20000930\\data\\C.1.dat", "r", stdin);
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &num[i]);
        }
        r = 1;
        for (int i = 1; i < n; i++) {
            if (abs(num[i] - num[i - 1]) >= n || num[i] == num[i - 1]) {
                r = 0;
                break;
            }
            else if (chk[abs(num[i] - num[i - 1])]) {
                r = 0;
                break;
            }
            else chk[abs(num[i] - num[i - 1])] = 1;
        }
        for (int i = 1; i < n; i++) chk[i] = 0;
        printf("%s\n", r ? "Jolly" : "Not jolly");
    }
    return 0;
}