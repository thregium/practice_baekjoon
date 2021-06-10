#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <deque>
using namespace std;

/*
문제 : N(N <= 100000)개의 수로 이루어진 수열이 있고, 이 수열의 원소들은 각각 K(K <= 100000) 이하의 자연수이다.
Q개의 다음 쿼리에 응답한다.
L, R이 주어질 때 L번째에서 R번째 사이 수들 가운데 서로 같은 수면서 가장 멀리 떨어진 두 수의 거리를 구한다.

해결 방법 : K개의 각 수별로 현재 범위의 수들을 덱을 이용해 관리한다. 범위가 추가되면 덱의 해당 방향에 수들을 추가하고
줄어들면 해당 방향에 수들을 삭제하면 된다. 이 덱들을 통해 각 수들별로 가장 멀리 떨어진 두 수의 거리를 빠르게 구할 수 있다.
이들 중 가장 큰 수는 평방 분할을 통해 찾으면 된다. 업데이트는 O(1), 쿼리는 O(sqrt(N))이므로 시간 복잡도에 영향이 없다.

주요 알고리즘 : 자료구조, 평방분할, Mo's, 덱
*/

int a[103000], qr[103000][4], r[103000], stt[103000], real[103000];
deque<int> dq[103000];
int cnt[103000], dqs[512];

int cmp1(const void* a, const void* b) {
    int ab = *((int*)a + 2);
    int bb = *((int*)b + 2);
    if (ab != bb) return ab > bb ? 1 : -1;
    int ae = *((int*)a + 1);
    int be = *((int*)b + 1);
    return ae > be ? 1 : ae == be ? 0 : -1;
}

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int n, k, m;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        //무작위값
        //a[i] = (rand() * 32768 + rand()) % k + 1;
        //srand(a[i] * i + rand());
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &qr[i][0], &qr[i][1]);
        /*
        //무작위값
        qr[i][0] = (rand() * 32768 + rand()) % n + 1;
        srand(qr[i][0] + rand());
        qr[i][1] = (rand() * 32768 + rand()) % n + 1;
        srand(qr[i][1] * 39 + rand());
        if (qr[i][1] < qr[i][0]) {
            int t = qr[i][0];
            qr[i][0] = qr[i][1];
            qr[i][1] = qr[i][0];
        }
        */
        qr[i][2] = qr[i][0] / 316;
        qr[i][3] = i;
    }
    qsort(qr, m, sizeof(int) * 4, cmp1); //Mo's 방식에 맞게 쿼리를 정렬한다.

    //첫 값 업데이트
    int s = qr[0][0], e = qr[0][1], d;
    for (int i = s; i <= e; i++) {
        if (dq[a[i]].size()) {
            d = dq[a[i]].back() - dq[a[i]].front();
            cnt[d]--;
            dqs[d >> 8]--;
        }
        dq[a[i]].push_back(i);
        d = dq[a[i]].back() - dq[a[i]].front();
        cnt[d]++;
        dqs[d >> 8]++;
    }
    for (int i = (n >> 8); i >= 0; i--) {
        //큰 수부터 차례로 살피며 나오는 첫 수를 결괏값으로 한다.
        if (dqs[i]) {
            for (int j = 255; j >= 0; j--) {
                if (cnt[(i << 8) + j]) {
                    r[qr[0][3]] = (i << 8) + j;
                    break;
                }
            }
            break;
        }
    }

    for (int i = 1; i < m; i++) {
        //쿼리의 범위에 맞추며 값들을 맞춰준다.
        while (s > qr[i][0]) {
            s--;
            if (dq[a[s]].size()) {
                d = dq[a[s]].back() - dq[a[s]].front();
                cnt[d]--;
                dqs[d >> 8]--;
            }
            dq[a[s]].push_front(s);
            d = dq[a[s]].back() - dq[a[s]].front();
            cnt[d]++;
            dqs[d >> 8]++;
        }
        while (e < qr[i][1]) {
            e++;
            if (dq[a[e]].size()) {
                d = dq[a[e]].back() - dq[a[e]].front();
                cnt[d]--;
                dqs[d >> 8]--;
            }
            dq[a[e]].push_back(e);
            d = dq[a[e]].back() - dq[a[e]].front();
            cnt[d]++;
            dqs[d >> 8]++;
        }
        while (s < qr[i][0]) {
            if (dq[a[s]].size()) {
                d = dq[a[s]].back() - dq[a[s]].front();
                cnt[d]--;
                dqs[d >> 8]--;
            }
            dq[a[s]].pop_front();
            if (dq[a[s]].size()) {
                d = dq[a[s]].back() - dq[a[s]].front();
                cnt[d]++;
                dqs[d >> 8]++;
            }
            s++;
        }
        while (e > qr[i][1]) {
            if (dq[a[e]].size()) {
                d = dq[a[e]].back() - dq[a[e]].front();
                cnt[d]--;
                dqs[d >> 8]--;
            }
            dq[a[e]].pop_back();
            if (dq[a[e]].size()) {
                d = dq[a[e]].back() - dq[a[e]].front();
                cnt[d]++;
                dqs[d >> 8]++;
            }
            e--;
        }
        
        for (int j = (n >> 8); j >= 0; j--) {
            //큰 수부터 차례로 살피며 나오는 첫 수를 결괏값으로 한다.
            if (dqs[j]) {
                for (int l = 255; l >= 0; l--) {
                    if (cnt[(j << 8) + l]) {
                        r[qr[i][3]] = (j << 8) + l;
                        break;
                    }
                }
                break;
            }
        }
    }
    /*
    //나이브 코드
    for (int i = 0; i < m; i++) {
        for (int j = 0; j <= k; j++) {
            stt[j] = 0;
        }
        for (int j = qr[i][0]; j <= qr[i][1]; j++) {
            if (stt[a[j]] == 0) stt[a[j]] = j;
            else real[qr[i][3]] = big(real[qr[i][3]], j - stt[a[j]]);
        }
    }
    */
    for (int i = 0; i < m; i++) {
        if (r[i] != real[i]) printf("%d : %d\n", r[i], real[i]);
        //printf("%d : %d\n", r[i], real[i]);
        //printf("%d\n", r[i]);
    }
    return 0;
}