#include <stdio.h>
#include <string.h>
#include <vector>
#include <set>
using namespace std;

/*
���� : 10^7 ������ ���� �ƴ� ���� N�� �־��� ��, �� �ڸ��� ������ ������ �߰��ذ��� N�� ����� ����� �������� ���Ѵ�.
�ڸ��� �߰��ϴ� ������ �ٸ����� �߰��ϴ� ���� ���ٸ� ���� ����̴�.

�ذ� ��� : ���Ϳ� ���� �̿��� �߰��ϴ� �������� �����Ѵ�. �ִ� 7�ڸ��̹Ƿ� ������ �߰��ϴ� ����� ���ƾ� 7!������
���̹Ƿ� ���Ʈ ������ �̿��� Ǯ �� �ִ�. �� �ڸ����� �����ؼ� �հ� �� �ڸ��� ��ġ�� ���� ���� �����ϸ� Ǯ�� �ȴ�.
���� ���� ũ�Ⱑ �ȴ�.

�ֿ� �˰��� : ���Ʈ ����, ��

��ó : ���ϴ� 2019 L��
*/

char n[16];
int l;
set<vector<int>> st;
vector<int> v;

void track(int s, int e, int b, int x, int nn) {
    if (x == l) {
        if (st.find(v) == st.end()) st.insert(v);
        return;
    }
    v[x] = nn;
    if (s > 0) {
        track(s - 1, e, b * 10, x + 1, nn + b * 10 * (n[s - 1] - '0'));
    }
    if (e < l - 1) {
        track(s, e + 1, b * 10, x + 1, nn * 10 + (n[e + 1] - '0'));
    }
}

int main(void) {
    int a, b;
    scanf("%s", n);
    l = strlen(n);
    for (int i = 0; i < l; i++) v.push_back(0);
    for (int i = 0; i < l; i++) {
        track(i, i, 1, 1, n[i] - '0');
    }
    printf("%d", st.size());
    return 0;
}