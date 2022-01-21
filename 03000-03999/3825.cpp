#include <stdio.h>
#include <stdlib.h>
#include <set>
using namespace std;

/*
���� : ������� ���� (M, N)�� ���̴�. ������� ���� �� ����� (M, N), (A, B)�� ����
(MA - NB, MB + NA)�̴�. �� ������� ���� (A, B) * (P, Q) = (M, N)�� �Ǵ� ����� (A, B)�� �ִ� ���
(A, B)(�Ǵ� (P, Q))�� (M, N)�� ����� ���Ѵ�. A^2 + B^2 > 1�� ��� ����� (A, B)�� ����
(0, 1), (0, -1), (1, 0), (-1, 0), (A, B), (-A, B), (A, -B), (-A, -B)�� �׻� ����̴�.
�̶�, �� ���� ���� �ٸ� ������� ����� ���� �ʴ� ������� �Ҽ� �������� �Ѵٸ�,
1 < A^2 + B^2 < 20000�� ����� (A, B)�� ���� �� ���� �Ҽ� ��������� ���Ѵ�.

�ذ� ��� : ������� ������ �� �� A^2 + B^2�� ���� �� ���� 1 �̻��� ��� �׻� �þ�� �� �� �ִ�.
����, A^2 + B^2�� ���� �� ū ���� ���ϸ� �ݵ�� �� ū A^2 + B^2 ���� ������ �Ǵ� �͵� �� �� �ִ�.
�̸� �̿��� �����佺�׳׽��� ü�� ������ �� �ִ�. �־��� ���ǿ� �´� (A, B)�� �� 62000���̴�.
�� (A, B)���� ���� ���� ���� A^2 + B^2�� ������������ �����Ѵ�. �̷��� �Ǹ� ��ǻ� ũ�� �������
(A, B)���� ���ĵǴ� ���̹Ƿ� �����佺�׳׽��� ü�� ���� 6��°����(���� 0, 1 ����) ���ʷ�
�Ҽ��� ������ ������� �ƴ� ������ ���������� �ȴ�. �������� ������ �¿� �߰��Ѵ�.

�¿� ��� ������ �߰������� �־��� ������� ���� �¿� �ִ� �� ���θ� Ȯ���Ѵ�. �ִٸ� �ռ����̰�,
���ٸ� �Ҽ��̴�.

�ֿ� �˰��� : ����, ������, �����佺�׳׽�, ��, ����

��ó : Tokyo 2012 A��
*/

int gn[65536][2];
set<pair<int, int>> sieve;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    int aj = *((int*)a + 1);
    int bj = *((int*)b + 1);
    return ai * ai + aj * aj > bi * bi + bj * bj ? 1 : ai * ai + aj * aj == bi * bi + bj * bj ? 0 : -1;
}

int main(void) {
    int cnt = 0, t, x, y;
    for (int i = -200; i <= 200; i++) {
        for (int j = -200; j <= 200; j++) {
            if (i * i + j * j < 20000) {
                gn[cnt][0] = i;
                gn[cnt++][1] = j;
            }
        }
    }
    qsort(gn, cnt, sizeof(int) * 2, cmp1);
    for (int i = 5; i < cnt; i++) {
        if (sieve.find(pair<int, int>(gn[i][0], gn[i][1])) != sieve.end()) continue;
        for (int j = 5; j < cnt; j++) {
            x = gn[i][0] * gn[j][0] - gn[i][1] * gn[j][1];
            y = gn[i][0] * gn[j][1] + gn[i][1] * gn[j][0];
            if (x * x + y * y > 20000) break;
            sieve.insert(pair<int, int>(x, y));
        }
    }
    //freopen("E:\\PS\\ICPC\\Asia Pacific\\Japan Regional\\2012\\InputsAndOutputs12\\A.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Asia Pacific\\Japan Regional\\2012\\InputsAndOutputs12\\A_t.out", "w", stdout);
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &x, &y);
        if (sieve.find(pair<int, int>(x, y)) != sieve.end()) printf("C\n");
        else printf("P\n");
    }
    return 0;
}