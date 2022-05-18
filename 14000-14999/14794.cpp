#include <stdio.h>
#include <map>
using namespace std;

/*
���� : ���� N(N <= 10^18)�� ������ �־��� ��, �� �������� �� �� �Ǵ� ���� �� ��� �� ������
���� ����� 2���� ���� ���� �Ÿ��� ���� �� ������ ���� ���� ���� �̴� ���� �ݺ��Ѵ�.
�̶�, K��°�� ���� ������ �� �� ��� �Ÿ��� �� �Ͱ� ����� ���� �Ÿ��� ���� ���Ѵ�.

�ذ� ��� : �ʿ� �� ���� ũ�⺰�� ������ �����ذ��鼭 ���� ū �������� ���� ũ�⸦ Ȯ���س����� �ȴ�.
�׷��ϴ� ���� ũ���� ������ K�� �Ǵ� ������ ���� ũ�⸦ Ȯ���ϰ� �׶� ���������� ������ ã���� ���̴�.

�ֿ� �˰��� : �ڷ� ����, ��, �ùķ��̼�?

��ó : GCJ 2017Q C3��
*/

map<long long, long long> mp;

int main(void) {
    int t;
    long long n, k, x, sz;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%lld %lld", &n, &k);
        mp.insert({ n, 1 });
        x = 0;
        while (k > 0) {
            x = (--mp.end())->first;
            sz = (--mp.end())->second;
            k -= sz;
            if (x > 1) {
                if (mp.find(x >> 1) == mp.end()) mp.insert({ x >> 1, sz });
                else mp[x >> 1] += sz;
            }
            if (x > 2) {
                if (mp.find((x - 1) >> 1) == mp.end()) mp.insert({ (x - 1) >> 1, sz });
                else mp[(x - 1) >> 1] += sz;
            }
            mp.erase(x);
        }
        printf("Case #%d: %lld %lld\n", tt, x >> 1, (x - 1) >> 1);
        mp.clear();
    }
    return 0;
}