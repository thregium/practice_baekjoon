#include <stdio.h>
#include <string>
#include <unordered_map>
using namespace std;

/*
���� : N(N <= 100000)���� ���ڿ� ���� �־�����. �׸��� M(M <= 100000)���� ���ڿ��� �־����µ�, �� ���ڿ����� �ش� ���ڿ��� �����ϴ� ���ڿ��� ���Ѵ�.
M���� ��� ���ڿ��� N���� �ֿ��� ù ��°�� �־��� ���ڿ� �߿� �ִ�.

�ذ� ��� : �ؽøʿ� N���� ���ڿ� ���� ������Ų��. ���ķ� M���� ���ڿ��� �־�����, �� ���ڿ����� �ؽøʿ��� �����ϴ� ���� ã�� ����ϸ� �ȴ�.

�ֿ� �˰��� : �ڷᱸ��, �ؽø�, ���ڿ�

��ó : �Ѿ��E 2019HM F��
*/

unordered_map<string, string> um;
char buff1[32], buff2[32];

int main(void) {
    int n, m;
    string s1, s2;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s %s", buff1, buff2);
        s1.assign(buff1);
        s2.assign(buff2);
        um.insert(pair<string, string>(s1, s2));
    }
    for (int i = 0; i < m; i++) {
        scanf("%s", buff1);
        s1.assign(buff1);
        printf("%s\n", um.find(buff1)->second.data());
    }
    return 0;
}