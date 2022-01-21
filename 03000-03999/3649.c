#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 10^6)���� ������� ������ ���� ũ��(<= 10^7)�� �־�����. �̶�, X(X <= 20, ��Ƽ����) ũ����
������ ��Ȯ�� 2���� �������� ���� �� �ִ� �� ���ϰ� �ִٸ� �׷��� ��� ��� ���� ũ���� ���̰�
���� ū ���� ���Ѵ�.

�ذ� ��� : �� �������� ũ�� ������ ������ ����, �� ���������� ������ �������� ���� �ٸ� �� ������
���� X(* 10^7)�� �Ǵ� ��찡 �ִ� �� ���ϸ� �ȴ�. �׽�Ʈ ���̽��� ������ ���� ���� �� ������ �����Ѵ�.

�ֿ� �˰��� : ����, �� ������

��ó : NWERC 2012 J��
*/

int leg[1048576];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int x, n, s, e, r;
    //freopen("E:\\PS\\ICPC\\Europe\\NWERC\\2012\\J\\joint-venture.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Europe\\NWERC\\2012\\J\\joint-venture_t.out", "w", stdout);
    while (scanf("%d", &x) != EOF) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &leg[i]);
        }
        qsort(leg, n, sizeof(int), cmp1);
        r = 0, s = 0, e = n - 1;
        while (s < e) {
            if (leg[s] + leg[e] < x * 10000000) s++;
            else if (leg[s] + leg[e] > x * 10000000) e--;
            else {
                printf("yes %d %d\n", leg[s], leg[e]);
                r = 1;
                break;
            }
        }
        if (!r) printf("danger\n");
    }
    return 0;
}