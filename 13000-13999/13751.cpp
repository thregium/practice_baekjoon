#include <stdio.h>
#include <stdlib.h>
#include <unordered_set>
using namespace std;

/*
���� : B���� ���� P(B, P <= 14)���� ���� �ִ�. �̶�, ���� ������ ���ʿ� �־�(���� ���� ���� ����)
������ ���Ը� ���� ���� ��, ��ü �ٺ��� ���� ���� �� �� �ִ� ��� ��츦 ������������ ����Ѵ�.
���� ���� ���Դ� ��� 10^8 ������ �ڿ����̴�.

�ذ� ��� : �� ���� ����/�����ʿ� �ִ� ��� ����� ���� �������� ������ ���԰� ���� ��츦 ���ɴ�.
�� �������� ���԰� ���� ��찡 ���� ���� �� �ֱ� ������ �̶��� �ؽü��� �̿��� ���� ������ ����
�� �����θ� �����Ѵ�. �ٽ� �� ������ �����Ͽ� ����ϸ� ���� �ȴ�.

�ֿ� �˰��� : �ڷ� ����, �ؽü�, ���Ʈ ����

��ó : PacNW 2016 N��
*/

unordered_set<int> hs;
int bar[16], plate[16], tri[16], res[1048576];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int b, p, end, lt, rt, rcnt = 0;
    scanf("%d %d", &b, &p);
    for (int i = 0; i < b; i++) {
        scanf("%d", &bar[i]);
    }
    for (int i = 0; i < p; i++) {
        scanf("%d", &plate[i]);
    }
    end = 0;
    while (!end) {
        lt = 0, rt = 0;
        for (int i = 0; i < p; i++) {
            if (tri[i] == 1) lt += plate[i];
            else if (tri[i] == 2) rt += plate[i];
        }

        if (lt == rt) {
            for (int i = 0; i < b; i++) {
                hs.insert(lt + rt + bar[i]);
            }
        }

        tri[0]++;
        for (int i = 0; tri[i] == 3; i++) {
            if (i == p - 1) end = 1;
            tri[i + 1]++;
            tri[i] = 0;
        }
    }
    for (int i : hs) res[rcnt++] = i;
    qsort(res, rcnt, sizeof(int), cmp1);
    for (int i = 0; i < rcnt; i++) {
        printf("%d\n", res[i]);
    }
    return 0;
}