#include <stdio.h>
#include <string.h>

/*
���� : ���ڿ��� �� ���ڿ��� ���̺��� ���� �ڿ��� N�� �־��� ��, Nĭ��ŭ �������� ����Ʈ��Ų ���ڿ��� ���Ѵ�.

�ذ� ��� : �� ���ڿ� ���� (i + l - n) mod l��° ���ڸ� ����ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ����

��ó : MHSPC 2013 P2��
*/

char w[103000];

int main(void) {
    int t, l, n;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%s %d", w, &n);
        l = strlen(w);
        //if (n == 1) return 1;
        printf("Shifting %s by %d positions gives us: ", w, n);
        for (int i = 0; i < l; i++) {
            printf("%c", w[(i + l - n) % l]);
        }
        printf("\n");
    }
    return 0;
}