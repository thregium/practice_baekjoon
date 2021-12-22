#include <stdio.h>
#include <stdlib.h>
#define INF 1012345678

/*
문제 : 자연수 N(N <= 10^6)이 주어지고, N에서 시작하여 N의 진 부분 문자열 가운데 0보다 큰 수를 빼 나간다.
더이상 진 부분 문자열을 뽑을 수 없는 사람이 진다면 N이 주어졌을 때 선공이 이기는 방법이 있는 지 구하고 있다면
선택해야 하는 진 부분 문자열 가운데 가장 작은 수를 출력하고, 없다면 -1을 출력한다.

해결 방법 : 우선 1자리 수만 남은 경우 진 부분 문자열이 없기 때문에 지게 된다. 그 외의 수들은 진 부분 문자열을
빼서 만들 수 있는 수 가운데 지는 수가 있다면 이기고, 없다면 지게 된다.
이러한 경우들은 다이나믹 프로그래밍을 통해 구해 나가면 된다. 결과를 확인할 때에는 지는 수라면 -1을 출력하면 되고,
이기는 수라면 진 부분 문자열을 뺀 수 가운데 지는 수가 나오는 가장 작은 진 부분 문자열을 찾아 출력하면 된다.

주요 알고리즘 : DP, 게임 이론, 문자열

출처 : SRM 360 D2C번
*/

int mem[1048576];
char buff[16];

int main(void) {
    int n, win, sub, best = INF;
    for (int i = 10; i <= 1000000; i++) {
        sprintf(buff, "%d", i);
        win = 0;
        while (1) {
            if (buff[0] == '\0') break;
            for (int j = 0; buff[j]; j++) {
                sub = strtoll(buff + j, NULL, 10);
                if (buff[j + 1] == '\0') buff[j] = '\0';
                if (sub >= i || sub == 0) continue;
                if (mem[i - sub] == 0) win = 1;
            }
        }
        mem[i] = win;
    }
    scanf("%s", buff);
    n = strtoll(buff, NULL, 10);
    while (1) {
        if (buff[0] == '\0') break;
        for (int j = 0; buff[j]; j++) {
            sub = strtoll(buff + j, NULL, 10);
            if (buff[j + 1] == '\0') buff[j] = '\0';
            if (sub >= n || sub >= best || sub == 0) continue;
            if (mem[n - sub] == 0) best = sub;
        }
    }
    printf("%d", best == INF ? -1 : best);
    return 0;
}