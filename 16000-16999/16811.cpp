#include <stdio.h>
#include <tuple>
#include <set>
using namespace std;

/*
���� : A * B * C(A, B, C <= 10^8) ũ���� ������ü���� N(N <= 1000)���� ���� �ٸ� 1 * 1 * 1 ũ��
��ϵ��� ���´�. �� ��ü�� �ѳ��̸� ���Ѵ�. � ���·� ��ü�� ��������� ����� �ִ� ����
���� ���� ���� ������ ���� ���� �ѳ��̿� ���Եȴ�.

�ذ� ��� : ����� ������ �ѳ��̿� ������ �޴� ���� ���� 6ĭ���̴�.
����, ó�� ������ �ѳ���((a * b + a * c + b * c) * 2)���� �����Ͽ� �ѳ����� ��ȭ�� ������ ������.
����� ���� �� ���� �ٲ�� �ѳ��̴� (���� ��� �� * 2) - 6��ŭ�̴�.
������ �ִ� ��ϵ��� ���� ������� ���θ� �¿� �����ϸ� ����� �ִ� ĭ���� �� ĭ������ ������ �� �� �ִ�.
N���� ��Ͽ� ���� �̸� �ݺ��� �� ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : �ڷ� ����, ��, ������

��ó : JAG 2015S4 G��
*/

set<tuple<int, int, int>> st;
int dxyz[6][3] = { {0, 0, 1}, {0, 1, 0}, {1, 0, 0}, {0, 0, -1}, {0, -1, 0}, {-1, 0, 0} };

int main(void) {
    int n, x, y, z, xt, yt, zt, cnt;
    long long a, b, c, r;
    scanf("%lld %lld %lld %d", &a, &b, &c, &n);
    r = (a * b + a * c + b * c) * 2;
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &x, &y, &z);
        cnt = 0;
        for (int j = 0; j < 6; j++) {
            xt = x + dxyz[j][0];
            yt = y + dxyz[j][1];
            zt = z + dxyz[j][2];
            if (xt < 0 || yt < 0 || zt < 0 || xt >= a || yt >= b || zt >= c) continue;
            if (st.find(make_tuple(xt, yt, zt)) != st.end()) continue;
            cnt++;
        }
        r += cnt * 2 - 6;
        st.insert(make_tuple(x, y, z));
    }
    printf("%lld\n", r);
    return 0;
}