#include <stdio.h>
#include <string.h>

/*
문제 : N(N <= 10)명이 K(K <= 30)번의 가위바위보에 낼 것이 주어진다. 앞 라운드에서 지게 되면 다음 라운드에
참가할 수 없다. 여러 명이 가위바위보를 하는 경우 2개로 패가 갈리는 경우에만 승부가 갈린다.
이때, 우승하는 사람이 몇 번째 사람인지 구한다. 끝까지 2명 이상이 남는다면 0을 출력한다.

해결 방법 : 탈락자의 목록과 낸 패들을 확인해 나가며 승부를 확인한다. 매 승부마다 낸 패들을 초기화하고
각 사람의 패들을 확인하되 탈락자의 패는 무시하고 집계한다. 집계가 끝나면 패가 2가지로 갈린 경우
탈락자를 추가한다. 이를 K번 반복한 다음, 최종적으로 몇 명이 남았는지 확인한다. 2명 이상 남은 경우 0을 출력하고,
1명만 남았다면 탈락하지 않은 사람을 찾아 그 사람을 출력하면 된다. 구조상 0명만 남는 것은 불가능하다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : Daejeon 2012 I번
*/

char rps[16][32];
int cnt[3], lost[16];

int main(void) {
    int t, n, k, s;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%s", rps[i]);
        }
        k = strlen(rps[0]);
        for (int i = 0; i < k; i++) {
            cnt[0] = 0, cnt[1] = 0, cnt[2] = 0; //초기화
            for (int j = 0; j < n; j++) {
                if (lost[j]) continue; //탈락자의 패는 무시한다.
                if (rps[j][i] == 'R') cnt[0]++; //낸 패 확인
                else if (rps[j][i] == 'P') cnt[1]++;
                else if (rps[j][i] == 'S') cnt[2]++;
                else return 1;
            }
            if ((!!cnt[0]) + (!!cnt[1]) + (!!cnt[2]) != 2) continue; //패가 2개로 갈리지 않았을 때
            for (int j = 0; j < n; j++) {
                if (cnt[2] == 0 && rps[j][i] == 'R') lost[j] = 1; //탈락자 추가
                else if (cnt[1] == 0 && rps[j][i] == 'S') lost[j] = 1;
                else if (cnt[0] == 0 && rps[j][i] == 'P') lost[j] = 1;
            }
        }

        s = 0;
        for (int i = 0; i < n; i++) s += (!!lost[i]); //최종적으로 탈락자의 수를 센다.
        if (s < n - 1) printf("0\n"); //2명 이상이 남은 경우
        else if (s >= n) return 2;
        else {
            for (int i = 0; i < n; i++) {
                if (!lost[i]) {
                    printf("%d\n", i + 1); //유일하게 1명이 남았다면 그 사람을 출력한다.
                    break;
                }
            }
        }
        for (int i = 0; i < n; i++) lost[i] = 0; //탈락자의 목록을 초기화한다.
    }
    return 0;
}