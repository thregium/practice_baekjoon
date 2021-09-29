#include <stdio.h>

/*
���� : M(M <= 20)������ ���ҿ� F(F <= 20)������ �ϼҿ� ���� ������ DNA �Ϻΰ� 25�ھ� �־�����. ���� ��� ���� DNA��
��� ���⿡ ���� �θ� �� ��� �� ������ ����� ���ٸ� �� �Ҵ� �θ��� �ڽ��� ���ɼ��� �ִٰ� �Ѵٸ�,
��� �θ��� �ֿ� ���� �θ��� �ڽ��� ���ɼ��� �ִ� �Ұ� �� �������� ���Ѵ�.
���� �θ� �� ��ü�� �ڽ� �Ұ� �� �� ����.

�ذ� ��� : �� �θ� ���� �ָ��� ��� �ҵ鿡 ���� �ڽ� �Ұ� �� �� �ִ��� Ȯ���Ѵ�.
�ڽ� �Ұ� �� �� �ִ� ������ �θ� �� �ڽ��� �ƴϸ� ��� DNA�� ���Ⱑ �θ� ���� �ش� ���� �� �ϳ��� ���̴�.

�ֿ� �˰��� : ����, ���ڿ�

��ó : USACO 2010J B1��
*/

char bull[32][32], cow[32][32];

int main(void) {
    int m, f, c, t;
    scanf("%d %d", &m, &f);
    for (int i = 0; i < m; i++) {
        scanf("%s", bull[i]);
    }
    for (int i = 0; i < f; i++) {
        scanf("%s", cow[i]);
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < f; j++) {
            c = 0;
            for (int k = 0; k < m; k++) {
                //�� ���ƿ� ����
                if (k == i) continue;
                t = 1;
                for (int l = 0; bull[k][l]; l++) {
                    if (bull[k][l] != bull[i][l] && bull[k][l] != cow[j][l]) {
                        t = 0;
                        break;
                    }
                }
                c += t;
            }
            for (int k = 0; k < f; k++) {
                //�� ���ƿ� ����
                if (k == j) continue;
                t = 1;
                for (int l = 0; cow[k][l]; l++) {
                    if (cow[k][l] != bull[i][l] && cow[k][l] != cow[j][l]) {
                        t = 0;
                        break;
                    }
                }
                c += t;
            }
            printf("%d ", c);
        }
        printf("\n");
    }
    return 0;
}