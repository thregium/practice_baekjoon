#include <stdio.h>
#include <unordered_set>
using namespace std;

/*
���� : N(N <= 10000)���� ���ڿ��� ���� �־�����, ���ķ� M(M <= 10000)���� ���ڿ��� �־�����. M���� ���ڿ� ���
N���� ���ڿ����� ���Դ� ���� ������ ���Ѵ�. ��� ���ڿ��� ���̴� 500 �����̴�.

�ذ� ��� : N���� ���ڿ��� �ؽü¿� ������ �� M���� ���ڿ� ��� �ؽü¿��� �����ϴ� ���ڿ��� ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, �ڷᱸ��, �ؽü�
*/

char buff[512];
unordered_set<string> us;

int main(void) {
    int n, m, r = 0;
    string s;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", buff);
        s.assign(buff);
        us.insert(s);
    }
    for (int i = 0; i < m; i++) {
        scanf("%s", buff);
        s.assign(buff);
        if (us.find(s) != us.end()) r++;
    }
    printf("%d", r);
    return 0;
}