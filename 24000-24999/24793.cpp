#include <stdio.h>
#include <string>
#include <unordered_set>
using namespace std;

/*
���� : N(N <= 100000)���� �����ձ⿡�� ���� �ܾ �־��� ��, ���� �̰�� �� �Ǵ� ��� �������� �� ���Ѵ�.
�� �ܾ�� 120�� ������ �ҹ��ڷ� �̷���� �ְ�, �̹� ����� �ܾ ����ϸ� ����.

�ذ� ��� : �ؽü��� �̿��� �̹� ����� �ܾ �����ϰ�, ������ ���ڿ� �Բ� Ȯ���ϸ�
���� �ܾ �� �� �ִ� �ܾ��� �� Ȯ���Ѵ�. �� �� ���� �ܾ ����ϴ� ����� �ִٸ� �� �����
���� ������ ó���ϸ� �ǰ�, ���ٸ� ��� �����ϰ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, �ؽü�, ����

��ó : VTH 2017 A��
*/

char buff[128];
unordered_set<string> wd;

int main(void) {
    int n;
    char last;
    string s;
    scanf("%d", &n);
    scanf("%s", buff);
    s.assign(buff);
    wd.insert(buff);
    last = s[s.length() - 1];
    for (int i = 1; i < n; i++) {
        scanf("%s", buff);
        s.assign(buff);
        if (wd.find(s) != wd.end() || buff[0] != last) {
            if (i & 1) printf("Player 2 lost");
            else printf("Player 1 lost");
            return 0;
        }
        else wd.insert(s);
        last = s[s.length() - 1];
    }
    printf("Fair Game");
    return 0;
}