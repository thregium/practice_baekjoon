#include <stdio.h>
#include <stdlib.h>
#include <unordered_map>
using namespace std;

/*
���� : N(N <= 10^6)���� ���� ����� �־�����. �ߺ��� ���ǵ��� ��ģ ����, �� ���ǵ��� ��ȣ�� ������
���� ������� ����Ѵ�.

�ذ� ��� : �ؽø��� ����Ͽ� �� ������ ���� ������ ������ ��ȣ�� ������Ų ����,
�ؽø��� ��� ������ ������ ���� ���� ������ ������ �� ����ϸ� �ȴ�.

�ֿ� �˰��� : �ڷ� ����, �ؽø�, ����

��ó : JPOI 2007 3-3��
*/

long long res[1048576][3];
unordered_map<int, pair<int, long long>> stor;

int cmp1(const void* a, const void* b) {
    long long ai = *(long long*)a;
    long long bi = *(long long*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, a, k, rp = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a, &k);
        if (stor.find(a) == stor.end()) {
            stor.insert({ a, {i, k} });
        }
        else stor[a].second += k;
    }
    for (auto& i : stor) {
        res[rp][0] = i.second.first;
        res[rp][1] = i.first;
        res[rp++][2] = i.second.second;
    }
    qsort(res, rp, sizeof(long long) * 3, cmp1);
    printf("%d\n", rp);
    for (int i = 0; i < rp; i++) {
        printf("%lld %lld\n", res[i][1], res[i][2]);
    }
    return 0;
}