#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
���� : 10�� ������ Ű ���� 100�� ������ ��ȣ���� �־��� ��, �� ��ȣ�� ��ȣȭ�� ����� ���Ѵ�.
��ȣ���� ���̴� Ű ���� �ڿ������̴�. ��ȣ�� Ű�� ���� ���� �� ������ ������ ����,
Ű�� �������� �������� �������� ������ �� ����� �������� �д� ������� ���Ѵ�.

�ذ� ��� : ����ü ������ ���� ������ �� ���� ���� �ٿ��� �� ��° ������ ���ϰ�,
������ ������ ������ ���� ��ȣ���� ��ġ���� ���� ��ġ�� �ű� ������ ã�Ƽ� �ű� ����, ��ȣȭ�� ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ���ڿ�, ����

��ó : ECRC 2003 A��
*/

typedef struct ki {
    char c;
    int pos;
} ki;

char key[16], crypt[128], uncry[128];
ki ka[16];

int cmp1(const void* a, const void* b) {
    ki ak = *(ki*)a;
    ki bk = *(ki*)b;
    if (ak.c != bk.c) return ak.c > bk.c ? 1 : -1;
    else return ak.pos > bk.pos ? 1 : ak.pos == bk.pos ? 0 : -1;
}

int main(void) {
    int kl, h;
    scanf("%s", key);
    kl = strlen(key);
    for (int i = 0; i < kl; i++) {
        ka[i].c = key[i];
        ka[i].pos = i;
    }
    qsort(ka, kl, sizeof(ki), cmp1);
    scanf("%s", crypt);
    if (strlen(crypt) % kl) return 1;
    h = strlen(crypt) / kl;
    for (int i = 0; crypt[i]; i++) {
        uncry[(i % h) * kl + ka[i / h].pos] = crypt[i];
    }
    printf("%s", uncry);
    return 0;
}