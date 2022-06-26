#include <stdio.h>
#include <string>
#include <unordered_set>
using namespace std;

/*
���� : N(N <= 10^6)���� �ҹ���(���ڼ� �� <= 10^6)�� �̷���� ����� �̸����� �־�����.
���� �̸��� ROT13 ������ �̸��� ����⵵ �־�߸� ��ȿ�� �̸��̶� �� ��, ���� �ٸ� ��ȿ�� �̸���
������ ���Ѵ�.

�ذ� ��� : �� ������� �̸��� �Է¹��� �� ���� �Է¹��� �̸��� ROT13�� ���ڿ��� �ؽü¿� �ִٸ�
�� ���� ��ȿ�� �̸��� �ǹǷ� �ᱣ���� 2�� �߰��Ѵ�. ��, �̹� �� �̸��� �ؽü¿� �ִٸ�
�ߺ��Ǵ� �̸��̹Ƿ� �߰����� �ʴ´�. �� �� �� ���ڿ��� �ؽü¿� ���س�����.
���������� ������ �ᱣ���� ����Ѵ�.

�ֿ� �˰��� : ���ڿ�, �ڷ� ����, �ؽü�

��ó : PA 2007 7-0��
*/

char buff[1048576];
unordered_set<string> u;

string rot13(string s) {
    for (int i = 0; i < s.size(); i++) {
        s[i] = (s[i] - 'a' + 13) % 26 + 'a';
    }
    return s;
}

int main(void) {
    int n, res = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", buff);
        if (u.find(rot13(buff)) != u.end()) {
            if (u.find(buff) != u.end()) continue;
            else res += 2;
        }
        u.insert(buff);
    }
    printf("%d", res);
    return 0;
}