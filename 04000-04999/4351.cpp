#include <stdio.h>
#include <string>
#include <unordered_map>
using namespace std;

/*
���� : M(M <= 1000)���� �ܾ�(<= 16��, �ҹ���)�� �̷���� �ܾ��忡 �� �ܾ ����(<= 10^6, ���� �ƴ� ����)�� �־�����.
�̶�, N(N <= 100)���� ���忡 ���� ������ ���� ���Ѵ�. �� ������ ������ �ܾ��忡 �ִ� �ܾ���� �ܾ ���� �հ� ����.

�ذ� ��� : �ؽøʿ� �ܾ ������ ����� �� �� ������ ������ ����Ѵ�. �̴� �ʿ��� �ܾ �ִ� �� Ȯ���� ��
�� �ܾ�� ����� ������ ���� ������ ������ Ǯ �� �ִ�.

�ֿ� �˰��� : ���ڿ�, �ڷ� ����, �ؽø�

��ó : Waterloo 20020601 A��
*/

char buff[1024];
unordered_map<string, int> u;

int main(void) {
    int m, n, d;
    string s;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++) {
        scanf("%s %d", buff, &d);
        s.assign(buff);
        u.insert(pair<string, int>(buff, d));
    }
    for (int i = 0; i < n; i++) {
        d = 0;
        while (1) {
            scanf("%s", buff);
            s.assign(buff);
            if (s == ".") break;
            if (u.find(s) != u.end()) d += u[s];
        }
        printf("%d\n", d);
    }
    return 0;
}