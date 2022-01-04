#include <stdio.h>
#include <string.h>
#include <set>
#include <string>
using namespace std;

/*
���� : N���� �ܾ�� �̷���� �ܾ���� M���� �̸��� ������� �־��� ��, �ܾ��忡 �ִ� �ܾ�鸸���� �̸����� ��� �� Ȯ���ϰ�,
�ƴ϶�� �ܾ��忡 ���� ������� ���� ����Ѵ�.

�ذ� ��� : ���� �̿��� �ܾ����� ������� ������ ��, �̸����� �ܾ�鸶�� �ܾ��忡 �ִ� �� ���ɴ�.
���� �ܾ���� ���� ����� ������ �ȴ�.

�ֿ� �˰��� : ���ڿ�, �ڷ� ����, ��

��ó : MidAtl 2002 C��
*/

set<string> dict;
char buff[103000];

int main(void) {
    int n, r;
    string s;
    //freopen("E:\\PS\\ICPC\\North America\\Mid Atlantic\\2002\\MidAtlantic2002-Solutions+Data\\problem-C\\pC1.dat", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Mid Atlantic\\2002\\MidAtlantic2002-Solutions+Data\\problem-C\\pC1_t.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", buff);
        s.assign(buff);
        dict.insert(s);
    }
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        r = 1;
        while (1) {
            scanf("%s", buff);
            if (!strcmp(buff, "-1")) break;
            s.assign(buff);
            if (dict.find(s) == dict.end()) {
                if (r) {
                    printf("Email %d is not spelled correctly.\n", i);
                    r = 0;
                }
                printf("%s\n", buff);
            }
        }
        if (r) printf("Email %d is spelled correctly.\n", i);
    }
    printf("End of Output");
    return 0;
}