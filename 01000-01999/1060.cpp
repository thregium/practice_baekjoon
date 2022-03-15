#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <queue>
#define INF 1234567890987654321
using namespace std;

/*
���� : L(L <= 50)���� �ڿ���(<= 10^9)�� �־�����. ��� �ڿ������� �� ���� �־��� �ڿ��� ������
���� �ٸ� �� �� �ȿ� ���ԵǴ� ������ ������ �������� ������������ �����ϰ�,
�� ������ ���� ��� �ڿ����� ������������ �����Ͽ��� ��, �տ������� N(N <= 100)���� ���� ���Ѵ�.

�ذ� ��� : �־��� �ڿ�������� �ڿ������� pair�� ���� ������ �Բ� ���� �켱���� ť�� �ְ�
�ϳ��� ����������. ���� �ڿ����� �յ� �ڿ������� ���� ���� �ʾҴٸ� �켱���� ť�� �ٽ� �ְ�
������ Ȯ���� ������. ��, ó���� ���� ��, �� �� ���� ���̰� 2�� ��� ���̿� �ִ� ����
���� ������ 0�̹Ƿ� �̸� �켱���� ť�� �־�־� �Ѵ�.

�ֿ� �˰��� : �׸��� �˰���, �ڷ� ����, �켱���� ť, ��

��ó : SRM 438D1 1��
*/

int s[64];
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
set<int> vis;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int l, n, x, t;
    scanf("%d", &l);
    for (int i = 1; i <= l; i++) {
        scanf("%d", &s[i]);
        pq.push(make_pair(0, s[i]));
        vis.insert(s[i]);
    }
    qsort(s, l + 1, sizeof(int), cmp1);
    if (s[1] != 1) {
        pq.push(make_pair(s[1] - 2, 1));
        vis.insert(1);
    }
    for (int i = 1; i < l; i++) {
        if (s[i] + 2 == s[i + 1]) {
            pq.push(make_pair(0, s[i] + 1));
            vis.insert(s[i] + 1);
        }
    }
    scanf("%d", &n);
    while (n--) {
        x = pq.top().second;
        printf("%d ", x);
        pq.pop();
        if (x - 1 > 0 && vis.find(x - 1) == vis.end()) {
            for (int i = 0; i < l; i++) {
                if (s[i] < x - 1 && x - 1 < s[i + 1]) {
                    pq.push(make_pair((long long)(s[i + 1] - (x - 1)) * ((x - 1) - s[i]) - 1, x - 1));
                    vis.insert(x - 1);
                    break;
                }
            }
        }
        if (vis.find(x + 1) == vis.end()) {
            t = 0;
            for (int i = 0; i < l; i++) {
                if (s[i] < x + 1 && x + 1 < s[i + 1]) {
                    pq.push(make_pair((long long)(s[i + 1] - (x + 1)) * ((x + 1) - s[i]) - 1, x + 1));
                    vis.insert(x + 1);
                    t = 1;
                    break;
                }
            }
            if (s[l] < x + 1) {
                vis.insert(x + 1);
                pq.push(make_pair(INF, x + 1));
            }
        }
    }
    return 0;
}