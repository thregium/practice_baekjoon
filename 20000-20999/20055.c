#include <stdio.h>

/*
문제 : 다음 규칙에 맞게 길이 N(N <= 100)의 컨베이어 벨트에서 로봇들이 움직일 때, 내구도 0인 구간이 K(K <= 2 * N)개가 되는 시점을 구한다.
N번 칸에 있는 로봇을 내린다. 컨베이어 벨트가 +방향으로 1칸 움직인 다음 다시 N번 칸에 있는 로봇을 내린다.
수가 큰 칸에 있는 로봇부터 i + 1번 칸의 내구도가 1 이상이고 그 칸에 로봇이 없다면 그 칸으로 움직인다. 움직이며 해당 칸의 내구도는 1 감소한다.
1번 칸의 내구도가 1 이상이라면 1번 칸에 로봇을 놓는다. 놓으며 1번 칸의 내구도는 1 감소한다. 위 내용을 계속 반복한다.

해결 방법 : 

주요 알고리즘 : 구현, 시뮬레이션
*/

int a[256], ar[256];

int main(void) {
    int n, k, r = 0, cnt = 0, tmp;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n * 2; i++) {
        scanf("%d", &a[i]);
    }
    while (cnt < k) {
        r++;
        tmp = a[n * 2 - 1];
        for (int i = n * 2 - 1; i > 0; i--) {
            a[i] = a[i - 1];
            ar[i] = ar[i - 1];
        }
        a[0] = tmp;
        ar[0] = 0;
        ar[n] = 0;
        ar[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            if (!ar[i]) continue;
            if (!ar[i + 1] && a[i + 1] > 0) {
                ar[i]--;
                ar[i + 1]++;
                a[i + 1]--;
                if (a[i + 1] == 0) cnt++;
            }
        }
        if (a[0]) {
            ar[0]++;
            a[0]--;
            if (a[0] == 0) cnt++;
        }
    }
    printf("%d", r);
    return 0;
}