#include <stdio.h>
#include <malloc.h>

/*
���� : N(N <= 100000)���� �ڿ����� ���� ��, �� ���� �ڽź��� ū ���� �ִ� ���� �����س����� ������ ����Ѵ�.

�ذ� ��� : �ܼ��� �ùķ��̼����� �ذ� ������ �� ������ O(N^2) �ð��� �ɸ��� ������ �ٸ� ����� ����ؾ� �Ѵ�.
�� ������δ� ���� ����Ʈ�� �����ϴ� ���� �ִ�. ���� ����Ʈ�� ���� ���ӵ� ���� ������ �ǳʶٴ� ���̴�.
���� ������ ������, �Ǵ� ���� ���� �Ѿ�� �����͸� �߰��� ���� ���� ����Ʈ�� ��ȸ�ϸ� ���� ������ ã�´�.
ã�ư��� ������ ������ ����� ����, ������ ������ �����ϸ� ���� ĭ���� �ǳʶٴ� ���鵵 ������ ������.

�ֿ� �˰��� : �ڷᱸ��, ���� ����Ʈ

��ó : Rocky 2020 E��
*/

typedef struct llst{
    int n;
    struct llst* next;
    struct llst* prev;
    struct llst* jump;
} llst;

llst* q, *erasetmp[103000], *erase[103000], *elast[103000];
int ep = 0, tp = 0;

llst* makejump(llst* now, int c) {
    if (now->n != now->next->n) {
        now->jump = now->next;
        return now;
    }
    else {
        llst* dest = makejump(now->next, c + 1);
        now->jump = dest;
        return dest;
    }
}

int main(void) {
    int n;
    llst* last, *node;
    //freopen("E:\\PS\\ICPC\\North America\\Rocky Mountain\\2020\\problems\\interviewqueue\\data\\secret\\sparse-234-1.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Rocky Mountain\\2020\\problems\\interviewqueue\\data\\secret\\random-4-check.out", "w", stdout);
    scanf("%d", &n);
    q = malloc(sizeof(llst));
    q->n = -1;
    q->jump = NULL;
    q->prev = NULL;
    last = q;
    for (int i = 1; i <= n + 1; i++) {
        node = malloc(sizeof(llst));
        if (i > n) node->n = -1;
        else scanf("%d", &(node->n));
        last->next = node;
        node->prev = last;
        node->next = NULL;
        node->jump = NULL;
        last = node;
    }
    for (llst* i = q->next; i->next; i = i->next) {
        /*
        if (i->jump == NULL) {
            makejump(i, 1);
        }
        */
        if (i->n != i->next->n) {
            for (llst* j = i->prev; j->prev && !(j->jump); j = j->prev) {
                j->jump = i;
            }
            i->jump = i->next;
        }
    }
    while (1) {
        tp = 0;
        for (llst* i = q->next; i->next; i = (i->jump->n == -2 ? i->next : i->jump)) {
            if (i->n == -2) {
                return 1;
            }
            if (i->n < i->prev->n || i->n < i->next->n) {
                erasetmp[tp++] = i;
                if (tp > 100000) {
                    return 1;
                }
                node = malloc(sizeof(llst));
                node->n = i->n;
                node->next = NULL;
                if (erase[ep] == NULL) {
                    erase[ep] = node;
                    elast[ep] = node;
                }
                else {
                    elast[ep]->next = node;
                    elast[ep] = node;
                }
            }
        }

        if (tp == 0) break;

        for (int i = 0; i < tp; i++) {
            if (erasetmp[i]->prev == NULL) return 1;
            if (erasetmp[i]->next == NULL) return 1;
            //if (erasetmp[i]->next->jump == NULL) return 1;
            erasetmp[i]->prev->next = erasetmp[i]->next;
            erasetmp[i]->prev->jump = erasetmp[i]->next;
            erasetmp[i]->next->prev = erasetmp[i]->prev;
            erasetmp[i]->n = -2;
            if (q->next->jump == erasetmp[i] && erasetmp[i] != q->next) {
                q->next->jump = erasetmp[i]->prev;
            }

            if (erasetmp[i]->next->jump == erasetmp[i]->next->next || erasetmp[i]->next->jump == NULL || erasetmp[i]->jump->next == NULL) continue;
            while (erasetmp[i]->next->jump->n == -2 || erasetmp[i]->next->jump->n < erasetmp[i]->next->jump->next->n) {
                erasetmp[i]->next->jump = erasetmp[i]->next->jump->prev;
                /*
                if (erasetmp[i]->jump->n < erasetmp[i]->jump->next->n) {
                    erasetmp[i]->next->jump = erasetmp[i]->jump->prev;
                }
                else {
                    erasetmp[i]->next->jump = erasetmp[i]->jump;
                    if (erasetmp[i]->next->jump == erasetmp[i]->next) {
                        erasetmp[i]->next->jump = erasetmp[i]->next->next;
                        while (erasetmp[i]->next->jump->n == -2) erasetmp[i]->next->jump = erasetmp[i]->next->jump->next;
                    }
                }
                */
            }
            if (erasetmp[i]->next->jump == erasetmp[i]->next) {
                erasetmp[i]->next->jump = erasetmp[i]->next->next;
                while (erasetmp[i]->next->jump->n == -2 || erasetmp[i]->next->jump->n < erasetmp[i]->next->jump->next->n) {
                    erasetmp[i]->next->jump = erasetmp[i]->next->jump->next;
                }
            }
            
        }
        ep++;
        if (ep > 100000) return 1;
    }
    printf("%d\n", ep);
    for (int i = 0; i < ep; i++) {
        for (llst* j = erase[i]; j; j = j->next) {
            printf("%d ", j->n);
        }
        printf("\n");
    }
    for (llst* i = q->next; i->next; i = i->next) {
        printf("%d ", i->n);
    }
    return 0;
}