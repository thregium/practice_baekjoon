#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <unordered_set>
#define INF 0x7A35090F
using namespace std;

/*
문제 : 물건 N(N <= 100)개의 무게(<= 10^9, 자연수)를 추 N(N <= 10)개 중 일부 또는 전부를 사용하여
잴 수 있는 지 구한다. 각 추의 무게는 10^8 이하의 자연수이며, 같은 무게의 추가 있을 수 있다.
그러한 방법이 있다면 0을, 추 1개를 추가해 잴 수 있는 방법이 있다면 가장 가벼운 그 추의 무게를 출력한다.
그러한 방법도 없다면 -1을 출력한다.

해결 방법 : 각 추를 왼쪽과 오른쪽에 올렸을 때 잴 수 있는 모든 무게들을 (음수를 포함해서) 해시셋에 담는다.
그리고 각 잴 물건의 무게마다 해시셋에서 찾을 수 있다면 넘어가고 아니라면 해당 물건의 무게와
해시셋에 있는 각 값의 차를 새로운 해시셋에 담는다. 이를 반복한 다음, 모든 값을 찾을 수 있었는 지 확인한다.
그렇다면 0을 출력하고, 그렇지 않다면 모든 새로운 해시셋에 공통인 값이 있는 지 확인한다.
있다면 그 값 중 가장 작은 것을 출력하면 된다. 그 외 모든 경우에는 -1을 출력한다.

주요 알고리즘 : 브루트 포스, 해시셋

출처 : JDC 2019 C번
*/

int meas[16], weight[128];
const int b3[] = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049};
unordered_set<int> scale, cand, ncand;

int main(void) {
    int n, m, w, r;
    //freopen("E:\\PS\\ICPC\\Asia Pacific\\Japan Domestic\\2019\\judgedata\\C\\C4", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Asia Pacific\\Japan Domestic\\2019\\judgedata\\C\\C4_t.out", "w", stdout);
    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%d", &weight[i]);
        }
        for (int i = 0; i < m; i++) {
            scanf("%d", &meas[i]);
        }
        for (int i = 0; i < b3[m]; i++) {
            w = 0;
            for (int j = i, k = 0; k < m; j /= 3, k++) w += meas[k] * (j % 3 - 1);
            scale.insert(w);
        }
        w = 0;
        for (int i = 0; i < n; i++) {
            if (scale.find(weight[i]) != scale.end()) continue;
            if (w == 0) {
                for (int j : scale) cand.insert(abs(weight[i] - j));
                w = 1;
            }
            else {
                for (int j : scale) {
                    if (cand.find(abs(weight[i] - j)) != cand.end()) ncand.insert(abs(weight[i] - j));
                }
                cand.clear();
                for (int j : ncand) cand.insert(j);
                ncand.clear();
            }
        }
        if (w == 0) printf("0\n");
        else if (cand.empty()) printf("-1\n");
        else {
            r = INF;
            for (int i : cand) {
                if (i < r) r = i;
            }
            printf("%d\n", r);
        }
        cand.clear();
        scale.clear();
    }
    return 0;
}