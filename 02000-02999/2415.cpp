#include <stdio.h>
#include <stdlib.h>
#include <unordered_set>
using namespace std;

/*
���� : N(N <= 1500)���� ���� ��ǥ���� �ִ�. ���簢���� �̷�� 4���� ���� �ٸ� �� ���
���̰� ���� ���� ���� ���̸� ���Ѵ�. �� ���� ��ǥ�� ���� 10^8 ���� �����̴�.

�ذ� ��� : 3008���� ���������� �� ���� ���� �� ������ ������� ��ǥ�� �����ϰ�,
�� ������ ���� ������� ������ �����鼭 ���� 90���� �ֵ��� �� ������ �˰������� ã�Ƴ�����.
�׷��� �ֵ鿡 ���� �ݴ��� 4��° ���� �ִ� �� ã��, �׷��ϴٸ� ������ �ִ��� ������ ������.
���������� ���� ������ �ִ��� ���� �ȴ�.

�ֿ� �˰��� : ������, ����, �� ������, �ؽü�

��ó : BtOI 2009 4��
*/

long long pos[1536][2], npos[1536][2];
unordered_set<long long> h;

int cmp1(const void* a, const void* b) {
    long long ax = *(long long*)a;
    long long bx = *(long long*)b;
    long long ay = *((long long*)a + 1);
    long long by = *((long long*)b + 1);
    if ((ay < 0 || (ay == 0 && ax > 0)) && (by > 0 || (by == 0 && bx < 0))) return 1;
    else if ((ay > 0 || (ay == 0 && ax < 0)) && (by < 0 || (by == 0 && bx > 0))) return -1;
    else if (ay != 0 && by == 0) return 1;
    else if (ay == 0 && by != 0) return -1;
    else return (ax * by > bx * ay) ? 1 : (ax * by == bx * ay) ? 0 : -1;
}

long long sqr(long long x) {
    return x * x;
}

long long ccwz(long long bx, long long by, long long cx, long long cy) {
    return llabs((bx * cy) - (by * cx));
}

int main(void) {
    int n, e2 = -1;
    long long r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &pos[i][0], &pos[i][1]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            npos[j - (j > i)][0] = pos[j][0] - pos[i][0];
            npos[j - (j > i)][1] = pos[j][1] - pos[i][1];
            if (pos[j][0] == pos[i][0] && pos[j][1] == pos[i][1]) {
                return 1;
            }
            h.insert(npos[j - (j > i)][0] * (1LL << 32) + npos[j - (j > i)][1]);
        }
        qsort(npos, n - 1, sizeof(long long) * 2, cmp1);
        e2 = -1;
        for (int s = 0, e = 0; s < n - 1; s++) {
            while (npos[e][0] * npos[s][0] + npos[e][1] * npos[s][1] >= 0 && npos[e][0] * npos[s][1] - npos[e][1] * npos[s][0] >= 0) {
                if (npos[e][0] * npos[s][0] + npos[e][1] * npos[s][1] == 0) {
                    if (e2 >= 0) {
                        for (int i = e; i <= e2; i++) {
                            if (npos[i][0] * npos[s][0] + npos[i][1] * npos[s][1] != 0) continue;
                            if (h.find((npos[s][0] + npos[i][0]) * (1LL << 32) + npos[s][1] + npos[i][1]) != h.end()) {
                                if (ccwz(npos[s][0], npos[s][1], npos[i][0], npos[i][1]) > r) {
                                    r = ccwz(npos[s][0], npos[s][1], npos[i][0], npos[i][1]);
                                }
                            }
                        }
                        //r += e2 - e;
                    }
                    else {
                        e2 = e;
                        while (e2 < n - 1 && npos[e2][0] * npos[s][0] + npos[e2][1] * npos[s][1] == 0 && npos[e2][0] * npos[s][1] - npos[e2][1] * npos[s][0] >= 0) {
                            if (h.find((npos[s][0] + npos[e2][0]) * (1LL << 32) + npos[s][1] + npos[e2][1]) != h.end()) {
                                if (ccwz(npos[s][0], npos[s][1], npos[e2][0], npos[e2][1]) > r) {
                                    r = ccwz(npos[s][0], npos[s][1], npos[e2][0], npos[e2][1]);
                                }
                            }
                            e2++;
                        }
                    }
                    break;
                }
                else e2 = -1;
                e = (e + 1) % (n - 1);
                if (e == s) break;
            }
        }

        while (h.size()) h.erase(h.begin());
    }

    printf("%lld", r);
    return 0;
}