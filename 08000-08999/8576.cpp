#include <stdio.h>
#include <map>
using namespace std;

/*
���� : N + 1(N <= 10^6)���� ��ư���� �̷���� ��谡 �ִ�. 1���� N������ ��ư�� �� ��ư�� ī���͸�
1�� ������Ű��, N + 1�� ��ư�� ��� ��ư�� ī���͸� �ִ����� �ʱ�ȭ��Ų��.
�̶�, M(M <= 10^6)ȸ ��ư�� ���� �� �� ��ư�� ī���͸� ���� ����Ѵ�.

�ذ� ��� : �ʿ� �� ��ư�� ���� Ƚ���� ��� ī���͸� �÷� �����ٰ� N + 1�� ��ư�� ���� �� ����
���� ��� ��ư�� Ȯ���ϸ鼭 ���� ���� ���� Ƚ���� ������ �ʱⰪ�� ���Ѵ�.
�׸��� ���� �ʱ�ȭ�صд�. �̸� �ݺ��� ����, �� ��ư�� ���� Ƚ�� + �ʱⰪ�� �� ��ư�� ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : �ڷ� ����, ��

��ó : JPOI 2012 2-1��
*/

map<int, int> mp;
int res[1048576];

int main(void) {
    int n, m, x, hist = 0, biggest;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        if (x > n) {
            if (mp.size() == 0) continue;
            else {
                biggest = 0;
                for (auto& j : mp) {
                    if (j.second > biggest) biggest = j.second;
                }
                hist += biggest;
            }
            mp.clear();
        }
        else {
            if (mp.find(x) == mp.end()) mp.insert({ x, 1 });
            else mp[x]++;
        }
    }
    for (auto& i : mp) res[i.first] = i.second;
    for (int i = 1; i <= n; i++) {
        printf("%d ", res[i] + hist);
    }
    return 0;
}