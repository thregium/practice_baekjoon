#include <stdio.h>

/*
문제 : N(2 <= N <= 1000)개의 수로 이루어진 배열에서 모든 서로 다른 두 수의 합이 주어질 때, 원래의 수들을 출력한다.
답이 유일한 경우만 주어진다.

해결 방법 : N이 3 이상인 경우는 첫 3개의 수 간의 합에서 첫 번째 수를 알아낼 수 있고, 이를 이용해 수들을 출력하면 된다.
N이 2인 경우에는 유일한 경우가 0 2 2 0인 경우밖에 없고, 이 때의 답은 1 1이다.

주요 알고리즘 : 수학

출처 : COCI 12/13#6 2번
*/

int arr[1024][1024], res[1024];

int main(void) {
    int n;
    scanf("%d", &n);
    if (n == 2) {
        printf("1 1");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    res[0] = (arr[0][1] + arr[0][2] + arr[1][2]) / 2 - arr[1][2];
    for (int i = 1; i < n; i++) {
        res[i] = arr[0][i] - res[0];
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", res[i]);
    }
    return 0;
}