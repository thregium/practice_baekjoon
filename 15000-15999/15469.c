#include <stdio.h>
#include <malloc.h>

/*
���� : N(N <= 100000)���� ���� ����� ���� - ������ ������ ���·� �־�����. �տ������� ���ʷ� ������
���� 3���� ������ ������ �����ϰ� ����� �� �ڿ� �� ���� 1���� �߰��� ���� ��,
���������� ���� ������ ������ ���Ѵ�.

�ذ� ��� : ���� ����Ʈ�� �̿��� �տ������� �������� Ȯ���� �����鼭 �� �ڿ� �������� �߰��� �����⸦
�ݺ��Ѵ�. �յ� ������ �������� ��쿡 �����Ѵ�.

�ֿ� �˰��� : �ڷ� ����, ���� ����Ʈ

��ó : TOPC 2017 D��
*/

typedef struct coin {
    char type;
    long long len;
    struct coin* prev, *next;
} coin;

coin* clist;

void removenode(coin* node, coin** front, coin** back) {
    if (node->prev && node->next) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        if (node->prev->type == node->next->type) {
            node->prev->next = node->next->next;
            if (node->next->next) node->next->next->prev = node->prev;
            node->prev->len += node->next->len;
            free(node->next);
        }
    }
    else if (node->prev) {
        *back = node->prev;
        node->prev->next = NULL;
    }
    else if (node->next) {
        *front = node->next;
        node->next->prev = NULL;
    }
    else {
        *front = NULL;
        *back = NULL;
    }
    free(node);
}

int main(void) {
    int t, n;
    long long res;
    coin* front, *back;
    //freopen("E:\\PS\\ICPC\\Asia Pacific\\Taiwan\\2017\\problems\\testdata\\final\\PD.in", "r", stdin);
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        front = calloc(1, sizeof(coin));
        back = front;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf(" %c %lld", &(back->type), &(back->len));
            if (i < n - 1) {
                back->next = calloc(1, sizeof(coin));
                back->next->prev = back;
                back = back->next;
            }
        }
        res = 0;
        for (coin* seeing = front; seeing;) {
            if (seeing->len >= 3) {
                res += seeing->len / 3;
                if (seeing->type == back->type) back->len += seeing->len / 3;
                else {
                    back->next = calloc(1, sizeof(coin));
                    back->next->prev = back;
                    back = back->next;
                    back->len = seeing->len / 3;
                    back->type = seeing->type;
                }
                seeing->len %= 3;
                if (seeing->len == 0) {
                    if (seeing->prev) {
                        seeing = seeing->prev;
                        removenode(seeing->next, &front, &back);
                    }
                    else if (seeing->next) {
                        seeing = seeing->next;
                        removenode(seeing->prev, &front, &back);
                    }
                    else break;
                }
                else seeing = seeing->next;
            }
            else seeing = seeing->next;
        }

        res = 0;
        for (coin* seeing = front; seeing; seeing = seeing->next) {
            res += seeing->len;
            if (seeing->prev) free(seeing->prev);
        }
        free(back);
        printf("%lld\n", res);
    }
    return 0;
}