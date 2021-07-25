#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 100)���� ��ϵ��� �ִ�. �� ��ϵ��� �� ����� �����ϸ鼭 �Ʒ� ����� �������� �ʴ� �ظ��� ������ �Ϸ��� �� ��,
�׷��� �ϴ� ����� �ִ��� Ȯ���ϰ� �ִٸ� �׷��� ����� �� ��Ϻ��� ���ʷ� ����Ѵ�.
�� ��ϵ��� �� ���� �� ���� ���̰� A�� ���簢������ �� ������ü �Ǵ� �������� A�� ������̰�, A�� 1000 ������ �ڿ����̴�.

�ذ� ��� : ����, �� ��ϵ��� �ظ��� ���� �Ǵ� �� ���� ���� ������ �����Ѵ�. �׷��� �ϸ� ���� ��ϳ��� �Ǵ�
������ü ���� ������� �ִ� ��쿡 ���ؼ��� �ذ�ȴ�. �׸��� ���� ����� ���� ������ü�� ����� �ִ��� Ȯ���ϸ� �ȴ�.
�̴� ��Ÿ��� ������ ���� �밢���� ���̰� �Ʒ� ���� ���� ���� �̻��� ��찡 ������ Ȯ���ϸ� �ȴ�.
�׷��� ��찡 �ִٸ� �Ұ����� ���̰� ���ٸ� �����ϹǷ� �ش� ������ ����ϸ� �ȴ�.

�ֿ� �˰��� : ������, �׸��� �˰���, ����

��ó : GCPC 2020 A��
*/

int shapes[128][2];
char buff[16];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    if (ai != bi) return ai > bi ? 1 : -1;
    int as = *((int*)a + 1);
    int bs = *((int*)b + 1);
    return as > bs ? 1 : as == bs ? 0 : -1;
}

int main(void) {
    int n, r = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %d", buff, &shapes[i][0]);
        if (buff[1] == 'u') shapes[i][1] = 2;
        else {
            shapes[i][1] = 1;
            shapes[i][0] *= 2;
        }
    }
    qsort(shapes, n, sizeof(int) * 2, cmp1);
    for (int i = 0; i < n - 1; i++) {
        if (shapes[i][1] == 2 && shapes[i + 1][1] == 1) {
            if (shapes[i][0] * shapes[i][0] * 2 > shapes[i + 1][0] * shapes[i + 1][0]) r = 0;
        }
    }
    if (!r) printf("impossible");
    else {
        for (int i = 0; i < n; i++) {
            if (shapes[i][1] == 1) printf("cylinder %d\n", shapes[i][0] / 2);
            else printf("cube %d\n", shapes[i][0]);
        }
    }
    return 0;
}