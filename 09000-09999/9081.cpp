#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

/*
���� : 100�� ������ ���ĺ� �빮�ڷ� �̷���� ���ڿ��� �־��� ��, �� ���ڵ�� ���� �� �ִ� ���� ������ ���� ���ڿ��� ã�´�.
��, ������ ���ڿ��� ��� �״�� ����Ѵ�.

�ذ� ��� : �̴� ���� ������ ���� �ǹ��̹Ƿ� next_permutation �Լ��� �̿��� Ǯ�� �ȴ�. �̶�, 0�� ��ȯ�� ��쿡��
������ �����̾��ٴ� �ǹ��̹Ƿ� �ٽ� prev_permutation�� ���� ���� ���·� �ǵ�����.

�ֿ� �˰��� : ����, ���շ�, ���ڿ�

��ó : Seoul 2003 C��
*/

char s[128];

int main(void) {
    int t, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%s", s);
        r = next_permutation(s, s + strlen(s));
        if (!r) prev_permutation(s, s + strlen(s));
        printf("%s\n", s);
    }
    return 0;
}