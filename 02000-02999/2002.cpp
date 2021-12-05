#include <stdio.h>
#include <string>
#include <map>
using namespace std;

/*
���� : N(N <= 1000)���� ���� �ٸ� �ڵ����� ������� �������� ���� ������ �־�����. �̶�, �߿��� �ڵ����� ���� ���Ѵ�.
�ڵ��� �̸��� 6���� �̻� 8���� ������ ���ڿ� �빮�ڷ� �־�����.

�ذ� ��� : �� �ڵ����� �̸��� ����������� ���� ������ ���� ���� ¦�����ش�. �׸��� �������� ���� �������
���� �ڵ��� ��� ��������� �տ� �ִ� �ڵ����� �ִ��� Ȯ���Ѵ�. �׷��� �ڵ����� ������ ���� ���� �ȴ�.

�ֿ� �˰��� : �ڷ� ����, ��

��ó : CHCI 2002N1S 1��
*/

char buff[16];
int a[1024], mem[1024];
map<string, int> mp;

int main(void) {
    int n, r = 0;
    string s;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", buff);
        s.assign(buff);
        mp.insert(pair<string, int>(s, i + 1));
    }
    for (int i = 0; i < n; i++) {
        scanf("%s", buff);
        s.assign(buff);
        if (mp.find(s) == mp.end()) return 1;
        a[i] = mp[s];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[i]) {
                r++;
                break;
            }
        }
    }
    printf("%d", r);
    return 0;
}