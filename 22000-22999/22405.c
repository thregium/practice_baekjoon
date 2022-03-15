#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
���� : ���� 1000 ������ ���ڿ��� �� Ʈ���� �־�����. (���� ����)[����](������ ����)�� ���·� �־�����,
�� ������ ��� 0 �̻� 1000 ���Ϸ� �־�����. �̶�, �� Ʈ���� ��ģ ������� �־��� ������ ���ڿ���
���� ������� ����Ѵ�. Ʈ���� ��ĥ ������ ���� ��� ������ ������ �� ������ ���� ������ ������
�ش� ������ �����, �ϳ��� ���ٸ� ������ �ʴ´�. �θ� ������ ���ٸ� �ڽ� ������ ����.

�ذ� ��� : ��ȣ ���̰� 0�� ���� ������ ã�Ƽ� strtoll() �Լ��� ������ Ȯ���� ���� �� ������ ������ ��������
�� Ʈ���� ����� ������. �� ���� Ʈ���� ���� ��ȸ�ϸ鼭 Ʈ���� ��ġ�� ����� ������ �ȴ�.

�ֿ� �˰��� : ���ڿ�, �Ľ�, Ʈ��, ����

��ó : JAG 2016DA C��
*/

typedef struct node {
    int n;
    struct node* l, *r;
} node;

char buff[1024];
node* ta, *tb;

void mktree(node* nd, int st, int ed) {
    int par = 0;
    for (int i = st; i <= ed; i++) {
        if (buff[i] == '(') par++;
        else if (buff[i] == ')') par--;
        else if (buff[i] == '[' && par == 0) {
            nd->n = strtoll(&buff[i + 1], NULL, 10);
            if (i - 2 > st) {
                nd->l = calloc(1, sizeof(node));
                mktree(nd->l, st + 1, i - 2);
            }
        }
        else if (buff[i] == ']' && par == 0) {
            if (i + 2 < ed) {
                nd->r = calloc(1, sizeof(node));
                mktree(nd->r, i + 2, ed - 1);
            }
        }
    }
}

void mergetree(node* na, node* nb) {
    if (na->l && nb->l) {
        printf("(");
        mergetree(na->l, nb->l);
        printf(")");
    }
    else printf("()");
    sprintf(buff, "[%d]", na->n + nb->n);
    printf("%s", buff);
    if (na->r && nb->r) {
        printf("(");
        mergetree(na->r, nb->r);
        printf(")");
    }
    else printf("()");
}

int main(void) {
    ta = calloc(1, sizeof(node));
    tb = calloc(1, sizeof(node));
    scanf("%s", buff);
    mktree(ta, 0, strlen(buff) - 1);
    scanf("%s", buff);
    mktree(tb, 0, strlen(buff) - 1);
    mergetree(ta, tb);
    printf("\n");
    return 0;
}