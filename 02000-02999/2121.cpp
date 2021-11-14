#include <stdio.h>
#include <set>
using namespace std;

/*
���� : N(N <= 500000)���� ���� ��ǥ���� �־��� ��, ���� �̾� ���� �� �ִ� ���ΰ� A, ���ΰ� B��
��ǥ�࿡ ������ ���簢���� ������ ���Ѵ�.

�ذ� ��� : �¿� �� ���� ��ǥ�� �ְ�, �� ���� ���� �� ���������� �ϴ� ���簢���� ���� �� �ִ��� ���캻��.
���� �ٸ� �� ���� ��� �¿� �ִٸ� �׷��� ���簢���� ���� �� �ִ�.

�ֿ� �˰��� : �ڷ� ����, ��, ����
*/

set<pair<int, int>> st;

int main(void) {
    int n, a, b, x, y, r = 0;
    scanf("%d%d %d", &n, &a, &b);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        st.insert(pair<int, int>(x, y));
    }
    for (auto i : st) {
        if (st.find(pair<int, int>(i.first, i.second + b)) != st.end()) {
            if (st.find(pair<int, int>(i.first + a, i.second)) != st.end()) {
                if (st.find(pair<int, int>(i.first + a, i.second + b)) != st.end()) r++;
            }
        }
    }
    printf("%d", r);
    return 0;
}