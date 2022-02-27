#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

/*
���� : N(N <= 20000)���� ������� K(K <= 20000)���� 5�ν� �ڵ����� �̿��� �������� ������ �Ѵ�.
�� ����� �����ؼ� �������� ���� �� T_i(T_i <= 10^6)��ŭ�� �ð��� �ɸ���.
�������� ��� ����� ������ �ֱ� ���� �ʿ��� �ּ� �ð��� ���Ѵ�.
��� ���� ����忡 �� �ʿ�� ����.

�ذ� ��� : �켱 ���� K�� ���̹Ƿ� ���ƾ� ���� ���� ���� ������ K���� ����鸸
�����ϸ� �Ǵ� ���� �� �� �ִ�. ����忡 �����ϴ� ������� �����ڵ��� ������ N���� ���� �����Ͽ��� ��
Ȯ���� ���� ���� �������� �ʾҴٸ� �� �����ڸ� �ٽ� ����������.
�ִ� 5000�� �̸� �ݺ��ϸ� ��� ������� ������ �ְ� �ǰ�, �׶��� �ҿ� �ð��� ã���� ���� �ȴ�.
�̹� ���� ���´� �����ڵ鵵 ���� ������ �ʾҴٸ� ����忡 ���� ���̹Ƿ� �������� �ʾƵ� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, �켱���� ť

��ó : MidC 2019 C��
*/

priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
int cartime[20480], cnt[204800];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, k, p, x;
    long long r = 0;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &cartime[i]);
    }
    qsort(cartime, n, sizeof(int), cmp1);
    for (int i = 0; i < n && i < k; i++) {
        pq.push(make_pair(cartime[i], i));
    }
    p = n;
    while (n > 0) {
        r = pq.top().first;
        x = pq.top().second;
        pq.pop();
        pq.push(make_pair(r + cartime[x] * 2, x));
        if (cnt[x] == 0) n -= 5;
        else n -= 4;
        cnt[x]++;
    }
    printf("%lld", r);
    return 0;
}