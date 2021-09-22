#include <stdio.h>
#include <string.h>

/*
문제 : N(N <= 20)개의 1부터 S(S <= 8)까지 적혀있는 주사위를 던진다. 이 던진 주사위들이 E(E <= 20)가지의 조건 중 하나라도
만족하는 경우의 가짓수를 구한다. 주사위를 던지는 가짓수는 1512768가지 이하다.
각 조건은 주사위의 특정 눈이 특정 횟수 이상 나오는 조건이 모두 충족되었을 때 충족된다.

해결 방법 : 파싱을 통해 각 눈이 나올 조건들을 구해놓는다. 각 조건에서 홀수번째 나오는 수는 주사위의 개수이고,
짝수번째 나오는 수는 주사위의 눈임을 알 수 있으므로 간단히 이를 옮겨놓으면 된다.
그 다음으로는 브루트 포스를 통해 S^N가지 모든 경우에 대해 각각이 조건을 충족시켰는지 확인한 다음 충족된 경우를 세면 된다.

주요 알고리즘 : 브루트 포스, 파싱

출처 : USACO 2007F B1번
*/

int bn[32], expl[32][32], cnt[32];
char buff[256];

int main(void) {
    int n, s, e, r = 0, t1, t2;
    char* c;
    scanf("%d %d %d", &n, &s, &e);
    bn[0] = 1;
    for (int i = 1; i <= n; i++) {
        bn[i] = bn[i - 1] * s; //미리 S의 제곱들을 계산해둔다.
    }
    for (int i = 0; i < e; i++) {
        //파싱
        scanf("%s", buff);
        c = strtok(buff, "+x");
        sscanf(c, "%d", &expl[i][++expl[i][0]]);
        while (c != NULL) {
            c = strtok(NULL, "+x");
            if (c == NULL) break;
            sscanf(c, "%d", &expl[i][++expl[i][0]]);
        }
        if (expl[i][0] & 1) return 1; //전체가 홀수인 경우는 나올 수 없다
    }

    for (int i = 0; i < bn[n]; i++) {
        for (int j = 1; j <= s; j++) cnt[j] = 0;
        for (int j = 0; j < n; j++) {
            cnt[i / bn[j] % s + 1]++;
        }
        t1 = 0;
        for (int j = 0; j < e; j++) {
            t2 = 1;
            for (int k = 1; k <= expl[j][0]; k += 2) {
                if (cnt[expl[j][k + 1]] < expl[j][k]) {
                    t2 = 0;
                    break;
                }
            }
            if (t2) {
                t1 = 1;
                break;
            }
        }
        r += t1;
    }
    printf("%d", r);
    return 0;
}