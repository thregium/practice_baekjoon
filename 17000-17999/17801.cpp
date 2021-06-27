#include <stdio.h>
#include <stdlib.h>
#include <map>
using namespace std;

/*
���� : ���ڸ� C(C <= 100000)�� ���� �ְ�, ���� ���̴� C - 1�� ���� �ִ�. i��° ���ڰ��̴� �պ��ϴµ� im�� �ɸ���. 
�̶� ���ڸ� N(N <= 100000)�� ���ƽ�� �� ��, �־��� ������ ���ڸ� ���ƾ��� ���� �ʿ��� �ּ� ������ Ƚ����
�׶��� �ʱ� ������ ���ڰ��̸� ���Ѵ�. ��, ù ��°�� �־����� ���ڴ� �̹� ���� �ִٰ� �����Ѵ�.

�ذ� ��� : �� ���ڰ��̿� ���ڸ� ���Ƴ������ ���ڸ� ���ƾ��µ� �ʿ��� ���ڰ��̴� ó�� ������ ���ڰ��̿���
�ɷ��ִ� ���ڿ� 1��1 ������ �����ϴ�. ����, ó�� ���ڿ� �����ϴ� ���ڰ��̸� ���� �� ȸ ����ϴ��� �� ��
���� ����ϴ� ������ �����ϸ� �ȴ�. �̶�, ù ���ڴ� �̹� ���� �ֱ� ������ �̸� �����ƾ� �Ѵ�.

�ֿ� �˰��� : �׸��� �˰���, ����

��ó : UKIEPC 2019 H��
*/

int cnt[103000][2];
map<int, int> mp;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int c, n, p, fp = 0, x, q;
    long long r = 0;
    //freopen("E:\\PS\\ICPC\\Europe\\UKIEPC\\2019\\hatstand\\data\\secret\\07.in", "r", stdin);
    scanf("%d %d", &c, &n);
    scanf("%d", &fp);
    for (int i = 1; i <= c; i++) {
        cnt[i][1] = i;
        if (i == fp) continue;
        mp.insert(pair<int, int>(i, i));
    }
    p = fp;
    for (int i = 2; i <= n; i++) {
        scanf("%d", &x);
        q = mp.find(x)->second;
        cnt[q][0]++;
        mp.erase(x);
        mp.insert(pair<int, int>(p, q));
        p = x;
    }
    qsort(cnt + 1, c, sizeof(int) * 2, cmp1);
    q = 0;
    for (long long i = 1; i <= c; i++) {
        r += (i - q) * cnt[i][0];
    }
    printf("%lld\n", r);
    for (int i = 1; i <= c; i++) {
        if (cnt[i][1] == fp) continue;
        printf("%d ", cnt[i][1]);
    }
    return 0;
}