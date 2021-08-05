#include <stdio.h>
#include <stdlib.h>

/*
���� : ���� N(N <= 200000)�� ������ �־��� ��, ��� �κ� ���ڿ��� ������ ���Ұ� �ִ� ����(non-boring sequence)���� ���Ѵ�.

�ذ� ��� : ���� � �κ� ���ڿ� ������ ������ ���Ұ� �ִٸ�, �� �κ� ���ڿ� ���� �ش� ���Ҹ� �����ϴ� ��� �κ� ���ڿ���
non-boring�̴�. �׷��Ƿ� �� �ֺ��� ������ ������ ���캸�� ���� ������ ���� ��� �κ� ���ڿ��� �׷����� ���캸�� �ȴ�.

�̸� ���ؼ��� �� ������ ���� ����� ����/������ ��ġ�� ��������� �˾ƾ� �Ѵ�. ��ǥ ������ �Ѵٸ� �� ������ ������ ��ġ��
Ȯ������ ���� ������ �����ϰ� O(N)�� ���� �˾Ƴ� �� �ִ�. �� ������ �ƴ� ���¿��� ���� ����� ���� ��ġ��
������ ���������� ���̰�, �������� ������ �������� �ڶ�� �ش� ���� ������ ���̴�.

�̶�, ���� ������ �ϴ� �������� ������ ��� ���ʿ��� ������ �ð� ���⵵�� O(N^2)�� �Ǿ������.
�̴� ������ �յڷ� Ȯ���� �Ͽ� �ð� ���⵵�� ���� �� �ִ�. ���� ��� �뿡�� ������ ��쿡�� ������ ũ�� �ٱ� ������
�������� ���캸���� ������ O(N^2)�� ����Ǵ� ���̴�.

�ֿ� �˰��� : ���� ����

��ó : CERC 2012 D��
*/

int a[204800][3], same[204800][2], last[204800]; //a[][0] : ���� ��, a[][1] : ����� ��, a[][2] : ���� ����
//same[][0] : ���ʿ��� ���� ����� ���� ���� ��ġ. ������ 0, same[][1] : �����ʿ��� ''. ������ 203900
//last : ���������� Ȯ���� �ش� ��

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int cmp2(const void* a, const void* b) {
    int ai = *((int*)a + 2);
    int bi = *((int*)b + 2);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int isboring(int s, int e) {
    //���� ������ ���� Ȯ��, �յڷ� �̵��ϸ� Ȯ�ν� �ð� ���⵵ ���� ����
    if (s >= e) return 1;
    for (int i = s, j = e; i <= j; i++, j--) {
        if (same[i][0] < s && same[i][1] > e) return (isboring(s, i - 1) & isboring(i + 1, e));
        if (same[j][0] < s && same[j][1] > e) return (isboring(s, j - 1) & isboring(j + 1, e));
    }
    return 0;
}

int main(void) {
    int t, n, r;
    //freopen("E:\\PS\\ICPC\\Europe\\CERC\\2012\\d\\7.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Europe\\CERC\\2012\\d\\7_t.out", "w", stdout);
    scanf("%d", &t);
    a[0][0] = -1;
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i][0]);
            a[i][2] = i;
        }
        //��ǥ ����
        qsort(a + 1, n, sizeof(int) * 3, cmp1);
        for (int i = 1; i <= n; i++) {
            if (a[i][0] == a[i - 1][0]) a[i][1] = a[i - 1][1];
            else a[i][1] = a[i - 1][1] + 1;
        }
        qsort(a + 1, n, sizeof(int) * 3, cmp2);
        //��/���� ���� ����� �� ��ó��
        for (int i = 1; i <= n; i++) last[i] = 0;
        for (int i = 1; i <= n; i++) {
            same[i][0] = last[a[i][1]];
            last[a[i][1]] = i;
        }
        for (int i = 1; i <= n; i++) last[i] = 203900;
        for (int i = n; i > 0; i--) {
            same[i][1] = last[a[i][1]];
            last[a[i][1]] = i;
        }
        r = isboring(1, n);
        if (r) printf("non-boring\n");
        else printf("boring\n");
    }
    return 0;
}