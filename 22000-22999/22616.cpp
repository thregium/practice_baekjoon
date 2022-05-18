#include <stdio.h>
#include <string>
#include <unordered_map>
using namespace std;

/*
���� : 10�� ������ ���ڷ� �̷���� ���̾� �����ġ�� �ִ�. �� ��ġ���� ������ ���ڵ��� ���� ������ ����
�����ϴٸ�, ���̾� �����ġ�� ���߱� ���� ������ �ϴ� �ּ� Ƚ���� ���Ѵ�.

�ذ� ��� : �Ź� ���� �� ���� ���� ���� �Ǵ� ������ ĭ�� ����� ��ġ�� ���ߴ� �ִ� Ƚ���� �ȴ�.
����, �׷��� �� ������� ��Ʈ��ŷ�� ���� �ϳ��� �� ������ �ȴ�. ��, �� �������� �̹� ���Դ� ����
�޸������̼��� ���� ������ �ذ��ؾ� �ð� ���� ���ư��� ���� �����ϴ�.

�ֿ� �˰��� : DP, ��Ʈ��ŷ

��ó : JAG 2009S2 C��
*/

char locka[16], lockb[16];
unordered_map<string, int> mem;

int track(string a, string b, int st, int ed) {
    if (a == b) return 0;
    if (mem.find(a) != mem.end()) return mem[a];
    while (a[st] == b[st]) st++;
    while (a[ed] == b[ed]) ed--;
    int res = 103000, inner, diff;
    string orig = a;
    diff = (b[st] - orig[st] + 10) % 10;
    for (int i = st; i <= ed; i++) {
        a[i] = (a[i] - '0' + diff) % 10 + '0';
        inner = track(a, b, st + 1, ed);
        if (inner + 1 < res) res = inner + 1;
        if (res == 1) {
            mem.insert({ orig, res });
            return res;
        }
    }
    a = orig;
    diff = (b[ed] - orig[ed] + 10) % 10;
    for (int i = ed; i >= st; i--) {
        a[i] = (a[i] - '0' + diff) % 10 + '0';
        inner = track(a, b, st, ed - 1);
        if (inner + 1 < res) res = inner + 1;
        if (res == 1) {
            mem.insert({ orig, res });
            return res;
        }
    }
    mem.insert({ orig, res });
    return res;
}

int main(void) {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        scanf("%s %s", locka, lockb);
        printf("%d\n", track(locka, lockb, 0, n - 1));
        mem.clear();
    }
    return 0;
}