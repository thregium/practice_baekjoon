#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*
���� : N(N <= 5000)���� ���� �ٸ� ���� �ƴ� ����(<= 10^9)�� �־��� ��, �� ������ ��� ���
���� �� ���������� ���̸� ���Ѵ�.

�ذ� ��� : �켱 ��� ���� ������ ����, ���� ������ ���ʷ� Ȯ���� ������.
�� ������ ���� ���� ���� �����ϸ鼭 ���� �� �ִ� ���� �� ���������� Ȯ���Ѵ�.
�� ������ Ȯ���� ������ �ؽü��� �̿��� ����ϰ�, �̹� Ȯ���� ���� ������ ���� ������ ã�´�.
�̸� �ݺ��Ͽ� �߰��� ������ ���� �� ���������� ���̸� ���ϸ� �ȴ�.
�ð��� ���̱� ���� reserve()�� �̸� �� �ִ� ���� ����.

�ֿ� �˰��� : �ڷ� ����, �ؽü�, �ؽø�, ����

��ó : Yokohama 2018 B��
*/

int v[5120];
unordered_set<int> vis[5120];
unordered_map<int, int> rv;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    long long n, c, r = 1, x, y, p;
    //freopen("E:\\PS\\ICPC\\Asia Pacific\\Japan Regional\\2018\\icpc2018data\\B\\59.in", "r", stdin);
    scanf("%lld", &n);
    for (long long i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    qsort(v, n, sizeof(int), cmp1);
    for (long long i = 0; i < n; i++) {
        rv.insert(pair<int, int>(v[i], i));
        vis[i].reserve(5120);
    }
    for (long long i = 0; i < n; i++) {
        for (long long j = i + 1; j < n; j++) {
            p = v[j] - v[i];
            if (vis[i].find(p) != vis[i].end()) continue;
            c = 1;
            y = i;
            while (1) {
                x = y;
                if (rv.find(v[i] + p * c) == rv.end() || vis[x].find(p) != vis[x].end()) break;
                else {
                    y = rv[v[i] + p * c++];
                    vis[x].insert(p);
                }
            }
            if (c > r) r = c;
        }
        vis[i].clear();
    }
    printf("%lld\n", r);
    return 0;
}