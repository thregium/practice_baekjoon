#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

/*
���� : N(N <= 200000)���� ������ �ְ�, �� ������ ���� �Ⱓ �ȿ� Ǯ�� �Ŷ���� ������ ������ŭ ���� �� �ִ�.
�̶�, ���� �� �ִ� �Ŷ���� �ִ� ������ ���Ѵ�. �Ⱓ�� �Ŷ���� 2^31 ������ �ڿ����̰�, �Ϸ翡 �ִ� 1������ Ǯ �� �ִ�.

�ذ� ��� : ������ ������ �������� Ǯ �� �ִ� ���� ��� ���� ���� �Ŷ���� ���� �� �ִ� ���� Ǭ��.
�̴� �������� ��¥�� �������� ������ ����, �켱���� ť�� �ش� �� ������ �������� �ְ� �������� �������
�ϸ� ������ Ǯ �� �ִ�. �̶�, �ð��� ���̱� ���� ������ ���� ���̶�� ������ �ִ� ������ ������ ���� �Űܾ� �Ѵ�.

�ֿ� �˰��� : �׸��� �˰���, �켱���� ť
*/

long long prob[204800][2];
priority_queue<long long> cr;

int cmp1(const void* a, const void* b) {
    long long ai = *(long long*)a;
    long long bi = *(long long*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    long long n, d = 1234567898, p = 0, r = 0;
    scanf("%lld", &n);
    for (long long i = 0; i < n; i++) {
        scanf("%lld %lld", &prob[i][0], &prob[i][1]);
    }
    qsort(prob, n, sizeof(long long) * 2, cmp1);
    while (d > 0) {
        if (cr.empty()) d = prob[p][0];
        while (p < n && d <= prob[p][0]) {
            cr.push(prob[p][1]);
            p++;
        }
        if (cr.size()) {
            r += cr.top();
            cr.pop();
        }
        d--;
    }
    printf("%d", r);
    return 0;
}