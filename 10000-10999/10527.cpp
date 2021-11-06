#include <stdio.h>
#include <string>
#include <map>
using namespace std;

/*
���� : �� ũ�� 100000 ������ �ܾ�(���� 15 ����, �ҹ���) ������ �־��� ��, �� ���� ���� ��ġ�ϴ� ������ ������ ���Ѵ�.

�ذ� ��� : ����, ù ��° ���տ��� �� �ܾ��� �ܾ���� �Է� Ƚ���� �ʿ� �����Ѵ�. �� ��° ������ ���ҵ��� �Է¹�����
ù ��° ���տ� �ش� ���Ұ� �����ִ��� Ȯ���ϰ� �ִٸ� �ش� ������ ���� �������� 1�� ���̰� �ᱣ���� 1 �ø���.
���� ���� ������ 0�� �Ǹ� �ش� ���Ҹ� ���쵵�� �Ѵ�.

�ֿ� �˰��� : �ڷᱸ��, ��

��ó : NWERC 2014 J��
*/

char buff[32];
map<string, int> mp;

int main(void) {
    int n, r = 0;
    string s;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", buff);
        s.assign(buff);
        if (mp.find(s) != mp.end()) {
            (mp.find(s)->second)++;
        }
        else mp.insert(pair<string, int>(s, 1));
    }
    for (int i = 0; i < n; i++) {
        scanf("%s", buff);
        s.assign(buff);
        if (mp.find(s) != mp.end()) {
            r++;
            if (mp.find(s)->second == 1) {
                mp.erase(mp.find(s));
            }
            else {
                (mp.find(s)->second)--;
            }
        }
    }
    printf("%d", r);
    return 0;
}