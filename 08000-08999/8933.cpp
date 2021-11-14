#include <stdio.h>
#include <map>
#include <tuple>
using namespace std;

/*
���� : ���� 60000 ������ DNA ���ڿ��� �ڿ��� K(K <= 600)�� �־��� ��, ������ K���� ���ڿ��� ����
������ ���� ���� ������ �� ���� ū ������ ũ�⸦ ���Ѵ�.

�ذ� ��� : �ʿ� 4���� ������ ������ Ű������ �ϰ� ������ ������ �Ͽ� �� ���� ������ ���� ������ ���س�����.
ó������ K�� ���ڿ� ���� ���� ���ϰ�, �� �ڷδ� ���ڸ� �߰��ϰ� K�� ���� ���ڸ� 1���� �����鼭
�� ������ ������ ����. ������ ������ �� �� ���� �ʿ� ���� �ְų� ���� ������Ʈ�Ѵ�.
��� ���ڸ� Ȯ�������� �� ������ ã�Ƽ� ũ�Ⱑ ���� ū ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : �ڷ� ����, ��, �����̵� ������

��ó : Seoul 2008 B��
*/

char w[65536];
int cnt[4];
map<tuple<int, int, int, int>, int> mp;

int main(void) {
    int t, k, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %s", &k, w);
        for (int i = 0; i < k; i++) {
            if (w[i] == 'A') cnt[0]++;
            else if (w[i] == 'C') cnt[1]++;
            else if (w[i] == 'G') cnt[2]++;
            else cnt[3]++;
        }
        mp.insert(pair<tuple<int, int, int, int>, int>(make_tuple(cnt[0], cnt[1], cnt[2], cnt[3]), 1));
        for (int i = k; w[i]; i++) {
            if (w[i] == 'A') cnt[0]++;
            else if (w[i] == 'C') cnt[1]++;
            else if (w[i] == 'G') cnt[2]++;
            else cnt[3]++;
            if (w[i - k] == 'A') cnt[0]--;
            else if (w[i - k] == 'C') cnt[1]--;
            else if (w[i - k] == 'G') cnt[2]--;
            else cnt[3]--;
            if (mp.find(make_tuple(cnt[0], cnt[1], cnt[2], cnt[3])) != mp.end()) {
                (mp.find(make_tuple(cnt[0], cnt[1], cnt[2], cnt[3]))->second)++;
            }
            else {
                mp.insert(pair<tuple<int, int, int, int>, int>(make_tuple(cnt[0], cnt[1], cnt[2], cnt[3]), 1));
            }
        }
        r = -1;
        for (auto i : mp) {
            if (i.second > r) r = i.second;
        }
        printf("%d\n", r);

        for (int i = 0; i < 4; i++) cnt[i] = 0;
        mp.clear();
    }
    return 0;
}