#include <stdio.h>

/*
문제 : N(N <= 100000)개의 칸으로 이루어진 기차에 A_i(A_i <= 9)명의 죄수들이 각각 있다.
i번째 칸에서 출발하여 뒤 칸으로 이동하며 연속한 칸들의 죄수들을 탈출시키려 한다.
이때, 풀어준 죄수들을 정확히 10개의 트럭에 같은 수만큼 태우기 위해 i번 칸에서 출발했을 때
열어야 하는 칸의 최소 개수를 각각 구한다. 불가능한 경우 -1을 출력한다.

해결 방법 : 각 칸의 누적 합을 구한 다음, 10으로 나눈 나머지에 따라 최근 위치와의 차이를
그 위치의 결괏값으로 한다. 결괏값이 없던 경우 -1을 출력하면 된다.

주요 알고리즘 : 수학, 정수론, 누적 합

출처 : CERC 2020 M번
*/

int crim[103000], res[103000], last[10];

int main(void) {
    int n, x;
    scanf("%d", &n);
    for (int i = 1; i < 10; i++) last[i] = -1;
    for (int i = 1; i <= n; i++) res[i] = -1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &crim[i]);
        crim[i] += crim[i - 1];
        x = crim[i] % 10;
        if (last[x] >= 0) res[last[x] + 1] = i - last[x];
        last[x] = i;
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", res[i]);
    }
    return 0;
}