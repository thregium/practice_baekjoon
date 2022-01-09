#include <stdio.h>
#include <stdlib.h>

/*
���� : N(3 <= N <= 1500)���� ���� ��ǥ��� �� �ִ�. �̶�, ��ǥ��鿡�� ���� �� �ִ� �����ﰢ���� ������ ���Ѵ�.
�� ���� ��ǥ�� (-10^9 <= X, Y <= 10^9) ������ �����̴�. ����� �ﰢ���� X, Y�࿡ �������� �ʾƵ� �ȴ�.
����, ���� ��ġ�� ���� ���� �־������� �ʴ´�.

�ذ� ��� : �� ������ �ش� ���� �߽����� ���� �������� �ϸ� ������ �����Ѵ�.
�� �� �ð�������� ������ ���캸�� ������ ������ ���� �ȴ�. �̶�, ������ ���� ���� �� ����� ��쿡 �����Ѵ�.
����, �迭�� 1���� ���� ��쿡�� �����ؾ� �ϸ�, �Ǽ� ������ ���� �� �����Ƿ� ���������� ���ؾ� �Ѵ�.
�̸� �ݺ��ϸ� ������ ������ ������ ���� ���ϸ� ���� �ȴ�.

�ֿ� �˰��� : ������, ����, �� ������

��ó : COCI 07/08#2 6��
*/

long long pos[1536][2], npos[1536][2];

int cmp1(const void* a, const void* b) {
    //���� �������� �� ����
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

int ccw(int ax, int ay, int bx, int by, int cx, int cy) {
    return (ax * by + bx * cy + cx * ay) - (ay * bx + by * cx + cy * ax);
}

int main(void) {
    int n, r = 0, e2 = -1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &pos[i][0], &pos[i][1]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            //�ٸ� ������ ��ġ�� �����Ѵ�.
            npos[j - (j > i)][0] = pos[j][0] - pos[i][0];
            npos[j - (j > i)][1] = pos[j][1] - pos[i][1];
            if (pos[j][0] == pos[i][0] && pos[j][1] == pos[i][1]) {
                return 1;
            }
        }
        qsort(npos, n - 1, sizeof(long long) * 2, cmp1);
        e2 = -1; //������ ������ �� + 1, ������ �ƴ϶�� ������ �д�.
        for (int s = 0, e = 0; s < n - 1; s++) {
            //�� �����͸� �����Ѵ�.
            while (npos[e][0] * npos[s][0] + npos[e][1] * npos[s][1] >= 0 && npos[e][0] * npos[s][1] - npos[e][1] * npos[s][0] >= 0) {
                //���� �Ǵ� ������ ��� Ȯ��
                if (npos[e][0] * npos[s][0] + npos[e][1] * npos[s][1] == 0) {
                    //������ ���
                    if (e2 >= 0) r += e2 - e; //�̹� ������ ������ Ȯ���� ���
                    else {
                        e2 = e; //�� �ܿ��� ������ ������ �������� Ȯ���Ѵ�.
                        while (e2 < n - 1 && npos[e2][0] * npos[s][0] + npos[e2][1] * npos[s][1] == 0 && npos[e2][0] * npos[s][1] - npos[e2][1] * npos[s][0] >= 0) {
                            e2++;
                            r++;
                        }
                    }
                    break;
                }
                else e2 = -1;
                e = (e + n) % (n - 1);
                if (e == s) break; //���� �� ������ �Ѿ ��쿡�� �� ������������ Ȯ���� �����Ѵ�.
            }
        }
        //printf("%d ", r);
    }
    printf("%d", r);
    return 0;
}