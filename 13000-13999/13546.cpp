#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <deque>
using namespace std;

/*
���� : N(N <= 100000)���� ���� �̷���� ������ �ְ�, �� ������ ���ҵ��� ���� K(K <= 100000) ������ �ڿ����̴�.
Q���� ���� ������ �����Ѵ�.
L, R�� �־��� �� L��°���� R��° ���� ���� ��� ���� ���� ���鼭 ���� �ָ� ������ �� ���� �Ÿ��� ���Ѵ�.

�ذ� ��� : K���� �� ������ ���� ������ ������ ���� �̿��� �����Ѵ�. ������ �߰��Ǹ� ���� �ش� ���⿡ ������ �߰��ϰ�
�پ��� �ش� ���⿡ ������ �����ϸ� �ȴ�. �� ������ ���� �� ���麰�� ���� �ָ� ������ �� ���� �Ÿ��� ������ ���� �� �ִ�.
�̵� �� ���� ū ���� ��� ������ ���� ã���� �ȴ�. ������Ʈ�� O(1), ������ O(sqrt(N))�̹Ƿ� �ð� ���⵵�� ������ ����.

�ֿ� �˰��� : �ڷᱸ��, ������, Mo's, ��
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
        //��������
        //a[i] = (rand() * 32768 + rand()) % k + 1;
        //srand(a[i] * i + rand());
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &qr[i][0], &qr[i][1]);
        /*
        //��������
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
    qsort(qr, m, sizeof(int) * 4, cmp1); //Mo's ��Ŀ� �°� ������ �����Ѵ�.

    //ù �� ������Ʈ
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
        //ū ������ ���ʷ� ���Ǹ� ������ ù ���� �ᱣ������ �Ѵ�.
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
        //������ ������ ���߸� ������ �����ش�.
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
            //ū ������ ���ʷ� ���Ǹ� ������ ù ���� �ᱣ������ �Ѵ�.
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
    //���̺� �ڵ�
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