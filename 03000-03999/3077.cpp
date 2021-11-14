#include <stdio.h>
#include <string>
#include <unordered_map>
using namespace std;

/*
���� : �� N(N <= 2500)���� ���ڿ� ������ ���� ��� ���ڿ� �� ������ ������ �� ������ ������ ��ġ�ϴ��� Ȯ���ϰ�,
�׷��� ���� ������ ����Ѵ�.

�ذ� ��� : �ؽøʿ� ù ��° ������ ���ڿ����� ������ �����Ѵ�. �� ����, �� ��° ���ڿ� ������ �����ϰ�,
�� ���ڿ� �ָ��� ������ �ؽøʿ��� ������ ���� ������ ��ġ�ϴ� ���� ������ ���� �ȴ�.

�ֿ� �˰��� : �ڷ� ����, �ؽø�

��ó : COCI 12/13#3 2��
*/

char buff[32], ans[2560][32];
unordered_map<string, int> um;

int main(void) {
    int n, r = 0, a, b;
    string s;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", buff);
        s.assign(buff);
        um.insert(pair<string, int>(s, i));
    }
    for (int i = 0; i < n; i++) {
        scanf("%s", ans[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            s.assign(ans[i]);
            a = um.find(s)->second;
            s.assign(ans[j]);
            b = um.find(s)->second;
            if (a < b) r++;
        }
    }
    printf("%d/%d", r, (n - 1) * n / 2);
    return 0;
}