#include <stdio.h>

/*
문제 : 1에서 10^6 사이의 자연수 구간이 주어질 때, 이 구간 사이의 진약수 사이클을 전부 출력한다.
진약수 사이클은 진약수의 합 연산을 반복하여 원래 수로 돌아오는 수열이다.
사이클을 출력할 때에는 사이클에서 가장 작은 수를 기준으로 구간 내에 있는지 구하고, 그 수부터 출력한다.
사이클은 50회 이상 반복하지 않고 중간에 200만 이상의 수가 나오지 않는다.

해결 방법 : 에라토스테네스의 체를 응용하여 각 수의 진약수 합을 미리 처리해준다.
그 다음으로는 주어지는 구간의 모든 수에 대해 50회씩 반복해보면서 원래 수로 돌아오는지 확인한다.
확인하는 동시에 가장 작은 수도 같이 구한다. 만약 가장 작은 수가 구간의 시작 이전이라면 그냥 넘어가야 한다.
원래수로 돌아오지 않거나 중간에 200만 이상으로 넘어가는 경우도 그냥 넘어간다.
사이클이 생긴 것을 확인하면 가장 작은 수부터 시작하는 사이클을 출력하고 방문처리한다.
한번 방문처리한 사이클은 다시 방문하지 않는다.

주요 알고리즘 : 수학, 에라토스테네스, 그래프 이론

출처 : USACO 2006O B4번
*/

char vis[2097152];
int bess[2097152];

int main(void) {
    for (int i = 1; i <= 2000000; i++) {
        for (int j = i * 2; j <= 2000000; j += i) bess[j] += i; //각 수의 진약수 합 전처리
    }
    int s, e, cnt, tn, lt;
    scanf("%d %d", &s, &e);
    for (int i = s; i <= e; i++) {
        if (vis[i]) continue;
        cnt = 1;
        tn = i;
        lt = i;
        while (bess[tn] != i && cnt < 64) {
            //진약수 수열 확인
            tn = bess[tn];
            if (tn < lt) lt = tn;
            if (tn > 2000000) {
                cnt = 64;
                break;
            }
            cnt++;
        }
        if (cnt > 50 && cnt < 64) {
            printf("ERROR50\n");
            return 1;
        }
        else if (cnt < 64) {
            //반복이 가능한 경우
            if (lt < s) continue;
            printf("%d ", lt);
            tn = lt;
            vis[tn] = 1;
            while (bess[tn] != lt) {
                tn = bess[tn];
                printf("%d ", tn);
                vis[tn] = 1;
                if (bess[tn] == lt) break;
            }
            printf("\n");
        }
    }
    return 0;
}