#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <queue>
using namespace std;

/*
���� : ���ڿ��� �־��� ��, �� ���ڿ��� �ƽ�Ű �ڵ�� ǥ���� ���� �ּ��� ��ȣȭ�� ������ ���� ��Ʈ ���� ���ϰ� �� ���� ����� ���Ѵ�.

�ذ� ��� : ������ ��ȣȭ�� �ϸ� ��Ʈ ���� �ּ������� ���� �� �ִ�. ���� ���� �󵵰� ���� ������ ���ʷ� ���ĳ�����,
��ģ ������ �������� �� ���ڸ� ��ȣȭ�� ��Ʈ���� ��� ����̴�.

�ֿ� �˰��� : �׸��� �˰���, �켱���� ť, ������ ��ȣȭ

��ó : GNY 2000 F��
*/

priority_queue<int, vector<int>, greater<int>> pq;

char buff[1024];
int cnt[27];

int main(void) {
    int r, a, b;
    while (1) {
        scanf("%s", buff);
        if (!strcmp(buff, "END")) break;
        for (int i = 0; buff[i]; i++) {
            if (isupper(buff[i])) cnt[buff[i] - 'A']++;
            else cnt[26]++;
        }
        for (int i = 0; i < 27; i++) {
            if (cnt[i] == 0) continue;
            pq.push(cnt[i]);
        }

        r = 0;
        while (pq.size() >= 2) {
            a = pq.top();
            pq.pop();
            b = pq.top();
            pq.pop();
            r += a + b;
            pq.push(a + b);
        }
        if (r == 0) r += strlen(buff);

        printf("%d %d %.1f\n", strlen(buff) * 8, r, strlen(buff) * 8 / (double)r);

        while (pq.size()) pq.pop();
        for (int i = 0; i < 27; i++) cnt[i] = 0;
    }
    return 0;
}