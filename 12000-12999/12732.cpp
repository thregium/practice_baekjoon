#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

/*
���� : A���� B�� ���̸� ������ �ð�ǥ�� ���� �̵��Ѵ�. ȸ�� �ð��� T(T <= 60)���̰�,
A������ ����ϴ� ������ NA(NA <= 100)��, B������ ����ϴ� ������ NB(NB <= 100)���� ��,
�ð�ǥ�� ���߱� ���� �� ������ ��� ���� ����ؾ� �ϴ� ������ ���� ���� ���Ѵ�.
�� ������ �����ð��� ��߽ð����� ������, 1�� ���� ��� ������ ����.

�ذ� ��� : �� �������� ��� �ð� ������ ������ ����, �� ������ ����ϰ� �ִ� ������ �����
�ּ� ������ ���� ���� ���� ���� �־�д�. �� �������� ���� ����ų� ���� ���� ������
���� ��߽ð����� �ʰ� ��� ������ ��쿡�� �� ������ ����ؾ� �ϴ� ���� ���� 1 ���δ�.
�ð� �� ��� �����ϴٸ� �� ������ ������ �����Ѵ�. �� ����, �ݴ� ���� �����ð� + T�� �ð�����
���� ������ �켱���� ť�� �־�д�. �̸� �ݺ��� ����, ������ ����ϴ� ���� ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, ����, �켱���� ť

��ó : GCJ 2008Q B2��
*/

int train[256][3];
priority_queue<int, vector<int>, greater<>> pqa, pqb;

int cmp1(const void* a, const void* b) {
    int ai = *((int*)a + 1);
    int bi = *((int*)b + 1);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int t, tn, na, nb, hs, ms, he, me, ra, rb;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d", &tn);
        scanf("%d %d", &na, &nb);
        for (int i = 0; i < na + nb; i++) {
            scanf("%d:%d %d:%d", &hs, &ms, &he, &me);
            train[i][0] = (i >= na);
            train[i][1] = hs * 60 + ms;
            train[i][2] = he * 60 + me;
        }
        qsort(train, na + nb, sizeof(int) * 3, cmp1);

        ra = 0, rb = 0;
        for (int i = 0; i < na + nb; i++) {
            if (train[i][0] == 0) {
                if (pqa.size() > 0 && pqa.top() <= train[i][1]) pqa.pop();
                else ra++;
                pqb.push(train[i][2] + tn);
            }
            else {
                if (pqb.size() > 0 && pqb.top() <= train[i][1]) pqb.pop();
                else rb++;
                pqa.push(train[i][2] + tn);
            }
        }

        printf("Case #%d: %d %d\n", tt, ra, rb);
        while (pqa.size()) pqa.pop();
        while (pqb.size()) pqb.pop();
    }
    return 0;
}