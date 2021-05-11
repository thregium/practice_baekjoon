#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
���� : ���ڵ�� ���ڵ��� ���� ��ϵ�(N <= 100)�� �־��� ��, �� ��ϸ��� ���ڴ� ���ڳ���, ���ڴ� ���ڳ��� ������ �� ����Ѵ�.
��, ���ڸ� ������ �� ��ҹ��ڴ� �����ؾ� �Ѵ�.

�ذ� ��� : �켱, ����� �� ���ҵ��� ���ڿ� ���ڷ� �з��Ѵ�. ����� ������ ������ ������ ���� �з��� �� �ִ�.
�� ���� �з��� �� ����� ���� ������ �ش�. ������ ��� atoi�� �̿��ϸ� �ǰ�, ���ڶ�� ���ο� �迭�� �� �� �ҹ��ڷ� �����
strcmp�� �̿��ϸ� �ȴ�. ������ ������ �ٽ� ���� ������� ���ƿͼ� ���ڿ� ���ڸ� ���� ����� ���ҵ��� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ����, �Ľ�

��ó : GNY 2000 4��
*/

char orig[256][64], words[256][64], nums[256][64];
int types[256];

int cmp1(const void* a, const void* b) {
    //�� ��
    int ai = atoi((char*)a);
    int bi = atoi((char*)b);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int cmp2(const void* a, const void* b) {
    //���ڿ� ��
    char al[64] = { 0, };
    char bl[64] = { 0, };
    for (int i = 0; ((char*)a)[i]; i++) {
        al[i] = tolower(((char*)a)[i]);
    }
    for (int i = 0; ((char*)b)[i]; i++) {
        bl[i] = tolower(((char*)b)[i]);
    }
    return strcmp(al, bl);
}

int main(void) {
    int sz, wd, nm;
    while (1) {
        for (sz = 0;; sz++) {
            //��Ͽ��� �� ���� ����
            scanf("%s", orig[sz]);
            if (orig[sz][strlen(orig[sz]) - 1] == '.') {
                orig[sz][strlen(orig[sz]) - 1] = '\0';
                sz++;
                break;
            }
            orig[sz][strlen(orig[sz]) - 1] = '\0';
        }
        if (sz == 1 && strlen(orig[0]) == 0) break;

        wd = 0;
        nm = 0;
        for (int i = 0; i < sz; i++) {
            //���� �з�
            if (isdigit(orig[i][strlen(orig[i]) - 1])) {
                strcpy(nums[nm], orig[i]);
                nm++;
                types[i] = 1;
            }
            else {
                strcpy(words[wd], orig[i]);
                wd++;
                types[i] = 2;
            }
        }

        qsort(nums, nm, sizeof(char) * 64, cmp1);
        qsort(words, wd, sizeof(char) * 64, cmp2);

        nm = 0;
        wd = 0;
        for (int i = 0; i < sz; i++) {
            if (types[i] == 1) printf("%s", nums[nm++]);
            else printf("%s", words[wd++]);
            if (i == sz - 1) printf(".\n");
            else printf(", ");
        }
    }
    return 0;
}