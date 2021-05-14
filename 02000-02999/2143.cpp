#include <stdio.h>
#include <map>
using namespace std;

/*
���� : ���� ���� N�� M(N, M <= 1000)�� ���� A, B�� ���� �� �� ������ �������� ���� ���ؼ� T(|T| <= 10^9)�� ������ �ϴ� ����� �������� ���Ѵ�.

�ذ� ��� : A�� ���������� ���� �� �ִ� ��� ���� �� ����� ����� �������� ���ؼ� �ʿ� �����Ѵ�.
�� ���� B�� ���������� ���� �� �ִ� ��� ����� ���� �ش� �հ� ���ؼ� T�� ������ �ϴ� A�� ����� �������� �ᱣ���� ���Ѵ�.
�̸� ��� ����� ���� �����ϸ� ���� ���� �� �ִ�.

�ֿ� �˰��� : �ڷᱸ��, map

��ó : ���� 2001 ��1��
*/

int a[1024], b[1024];
map<int, int> mp;

int main(void) {
    int t, n, m, p, s;
    long long r = 0;
    scanf("%d%d", &t, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        s = 0;
        for (int j = i; j < n; j++) {
            s += a[j];
            if (mp.find(s) == mp.end()) {
                mp.insert(pair<int, int>(s, 1));
            }
            else {
                p = mp.find(s)->second;
                mp.erase(s);
                mp.insert(pair<int, int>(s, p + 1));
            }
        }
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < m; i++) {
        s = 0;
        for (int j = i; j < m; j++) {
            s += b[j];
            if (mp.find(t - s) != mp.end()) {
                r += mp.find(t - s)->second;
            }
        }
    }
    printf("%d", r);
    return 0;
}