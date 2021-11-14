#include <stdio.h>
#include <string.h>
#include <string>
#include <map>
using namespace std;

/*
���� : N(N <= 1000)���� ���ڿ��� �� �� ������ �־��� ��, ù ��° ����� �� ��° ������ ���� �ٸ� �ܾ�θ� �̷���� �ְ�,
������ ����. �� ��° ���忡 �����ϴ� �� ��° ���忡�� ���� ��ġ�� �ֵ� ù ��° ������ �ܾ��� �Ű��� ����
�������� ����Ѵ�.

�ذ� ��� : �ʿ� ù ��° ������ �ܾ�鸶�� ��ġ�� ������ ����, �� ��° ������� �Է¹ް�, �� ��ġ�� �ʿ��� ã�Ƽ�
�־�� �� ��ġ�� �ִ´�. �׸��� ����ϸ� �ȴ�.

�ֿ� �˰��� : �ڷ� ����, ��, ���ڿ�

��ó : BAPC 2013P E��
*/

char buff[16], scnd[1024][16], res[1024][16];
map<string, int> mp;

int main(void) {
    int t, n;
    string s;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%s", buff);
            s.assign(buff);
            mp.insert(pair<string, int>(s, i));
        }
        for (int i = 0; i < n; i++) {
            scanf("%s", scnd[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%s", buff);
            s.assign(scnd[i]);
            strcpy(res[mp.find(s)->second], buff);
        }

        for (int i = 0; i < n; i++) {
            printf("%s ", res[i]);
        }
        printf("\n");
        mp.clear();
    }
    return 0;
}