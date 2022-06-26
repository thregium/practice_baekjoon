#include <stdio.h>
#include <unordered_set>
using namespace std;

/*
���� : N(N <= 20000)���� ���� �ٸ� �ڿ���(<= 10^9)�� �־��� ��, ���� M(M <= 10^9)�� �Ǵ�
�� ���� ������ ���Ѵ�.

�ذ� ��� : �ؽü¿� ������ �־�鼭 M - ���� ���� �ؽü¿� �ִٸ� �ᱣ���� 1�� �÷�������.
�� �� �ؽü¿� ���� ���� ����ִ´�. �̸� �ݺ��Ͽ� ���� �ᱣ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : �ڷ� ����, �ؽü�

��ó : Khwarizmi 2010 F��
*/

unordered_set<int> st;

int main(void) {
    int t, n, m, x, r;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %d", &n, &m);
        st.clear();
        r = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            if (st.find(m - x) != st.end()) r++;
            st.insert(x);
        }
        printf("Case #%d: %d\n", tt, r);
    }
    return 0;
}