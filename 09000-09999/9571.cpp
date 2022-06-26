#include <stdio.h>
#include <stdlib.h>
#include <set>
using namespace std;

/*
문제 : N(N <= 50000)마리의 소가 각 좌표(|| <= 10^9)에 있다. 각 소의 키(<= 10^9)가 주어질 때,
거리 D(D <= 10^9) 이하의 양 옆에 자신의 키 * 2 이상인 소가 있는 소의 마릿수를 구한다.

해결 방법 : 각 소의 왼쪽과 오른쪽 영향을 받는 범위에 대해 각 소들의 키를 멀티셋에 저장한 후,
두 멀티셋의 최댓값이 그 소의 키 * 2 이상인 소의 마릿수를 구하면 된다.

주요 알고리즘 : 자료 구조, 멀티셋, 투 포인터

출처 : USACO 2013N S2번
*/

int cow[51200][2];
multiset<int> lt, rt;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, d, ls = 0, le = -1, rs = 0, re = -1, res = 0;
    //freopen("crowded.in", "r", stdin);
    //freopen("crowded.out", "w", stdout);
    scanf("%d %d", &n, &d);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &cow[i][0], &cow[i][1]);
    }
    qsort(cow, n, sizeof(int) * 2, cmp1);

    for (int i = 0; i < n; i++) {
        while (re < n - 1 && cow[re + 1][0] <= cow[i][0] + d) {
            re++;
            rt.insert(cow[re][1]);
        }
        while (rs <= re && cow[rs][0] <= cow[i][0]) {
            rt.erase(rt.find(cow[rs][1]));
            rs++;
        }
        while (le < i - 1 && cow[le + 1][0] < cow[i][0]) {
            le++;
            lt.insert(cow[le][1]);
        }
        while (ls <= le && cow[ls][0] < cow[i][0] - d) {
            lt.erase(lt.find(cow[ls][1]));
            ls++;
        }

        if (lt.size() >= 1 && rt.size() >= 1 &&
            *lt.rbegin() >= cow[i][1] * 2 && *rt.rbegin() >= cow[i][1] * 2) {
            res++;
        }
    }
    printf("%d", res);
    return 0;
}