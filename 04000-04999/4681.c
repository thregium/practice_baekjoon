#include <stdio.h>
#include <string.h>

/*
���� : 1024 * 1024 ũ���� ȭ�鿡�� â���� ���� ���콺�� �����ӿ� ���� â���� �������� �����ϴ� ���α׷��� �����.

�� â�� 26 * 51 �ȼ� �̻��� ũ���̰�, ���� �� 25 * 25 �ȼ��� ���� ��ư, ������ �� 25 * 25 �ȼ��� �ִ�ȭ ��ư,
�� �� ���� 25 �ȼ��� �̵� ���̴�. ������ ĭ���� �Ϲ� �����̴�.

â�� �Ϻκ��� Ŭ���ϸ� �� â�� �� ���� �ö�´�. ���콺�� ���� ���� �� �� ���� ��ư�� �־��ٸ� �� ��ư�� ����� �����Ѵ�.
�̵� �ٸ� ���� ä�� �����̸� �� â�� ���� �����δ�. ��, �ִ�ȭ ���¿����� �̵����� �ʴ´�.
���ο� â�� ����� �� â�� �� ���� �����ȴ�. RE ����� ����ϸ� �ؿ������� �ϳ��� â���� ������ �����ش�.
�� ����� ������ �� ���� �� ��ɿ� ���� ������ ������� �Ѵ�. â ��ȣ�� ������ ������� ����.

�ذ� ��� : �� â�� ������ �迭�� ��Ƶ� ����, �迭�� ������ �̿��� �ذ��� ������.
���� �� ���� ���ο� â�� ��� ���� ����.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : MidC 1997 F��
*/

typedef struct window {
    int xl, yl, xh, yh;
    int oxl, oyl, oxh, oyh;
    int isfull;
    int num;
} window;

window wd[1024]; //â�� ������ �����Ѵ�. ���� �� ���� ���ο� â�̴�.
char buff[8]; //��ɾ �����ϴ� �ӽ� ����

void makescreen(int ws, int wc, int xl, int yl, int xh, int yh) {
    //�� â�� �����.
    wd[ws].xl = xl;
    wd[ws].yl = yl;
    wd[ws].xh = xh;
    wd[ws].yh = yh;
    wd[ws].num = wc;
    wd[ws].isfull = 0;
    printf("Created window %d at %d, %d, %d, %d\n", wc, xl, yl, xh, yh);
}

int inwindow(int w, int x, int y) {
    //�ش� ���� �ش� â�� ���ϴ���, ���Ѵٸ� ��� ������ ���ϴ��� Ȯ���Ѵ�.
    if (x > wd[w].xh || x < wd[w].xl || y > wd[w].yh || y < wd[w].yl) return 0;
    if (y > wd[w].yl + 24) return 1;
    if (x <= wd[w].xl + 24) return 3;
    if (x >= wd[w].xh - 24) return 4;
    return 2;
}

void resize(int w) {
    //â�� ũ�⸦ �ִ�ȭ�ϰų� �ִ�ȭ�� â�� ���󺹱ͽ�Ų��.
    if (wd[w].isfull) {
        wd[w].isfull = 0;
        wd[w].xl = wd[w].oxl, wd[w].yl = wd[w].oyl, wd[w].xh = wd[w].oxh, wd[w].yh = wd[w].oyh;
    }
    else {
        wd[w].isfull = 1;
        wd[w].oxl = wd[w].xl, wd[w].oyl = wd[w].yl, wd[w].oxh = wd[w].xh, wd[w].oyh = wd[w].yh;
        wd[w].xl = 0, wd[w].yl = 0, wd[w].xh = 1023, wd[w].yh = 1023;
    }
}

int main(void) {
    int ws = 0, wc = 0, a, b, c, d; //���� â�� ��, ���ݱ��� ���� â�� ��, �Ķ���� 4��
    int m_orig_x = -1, m_orig_y = -1, m_now_x = -1, m_now_y = -1, m_last_x = -1, m_last_y = -1;
    //���콺�� ���� ������, ������, ���������� �������� ���� ��ǥ
    int m_down = 0, m_wd = -1, m_ar = -1; //���콺�� ���� ��������, ���콺�� ������ �ִ� â�� ��ȣ, ���� ������ ��ȣ
    window temp_wd; //�ӽ� â(â�� �ű� �� ���)
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\acm97\\wimp\\wimp.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\acm97\\wimp\\wimp_t.out", "w", stdout);
    while (1) {
        scanf("%s", buff);
        if (!strcmp(buff, "ZZ")) break; //���α׷��� �����Ѵ�.
        else if (!strcmp(buff, "CR")) {
            //�� â�� �����.
            scanf("%d %d %d %d", &a, &b, &c, &d);
            if (wc > 1000) return 1;
            makescreen(ws, wc, a, b, c, d);
            ws++;
            wc++;
        }
        else if (!strcmp(buff, "DN")) {
            //�ش� ��ǥ���� ���콺�� ������.
            //if (m_down) return 2; ���콺�� ���� ���¿��� �ٽ� ������ �͵� �����ϴ�.
            scanf("%d %d", &a, &b);
            for (int i = ws - 1; i >= 0; i--) {
                if (inwindow(i, a, b)) {
                    //�ش� ��ǥ�� �ִ� ���� ���� â
                    m_wd = wd[i].num;
                    m_ar = inwindow(i, a, b);
                    temp_wd = wd[i];
                    for (int j = i; j < ws - 1; j++) {
                        wd[j] = wd[j + 1];
                    }
                    wd[ws - 1] = temp_wd; //�ش� â�� �� ���� �ø���.
                    printf("Selected window %d\n", m_wd);
                    break;
                }
            }
            m_down = 1;
            m_orig_x = a, m_orig_y = b;
            m_now_x = a, m_now_y = b;
        }
        else if (!strcmp(buff, "AT")) {
            //���콺�� �̵��Ѵ�. �̵��ϴ� ��쿡�� ���ǹ��ϴ�.
            scanf("%d %d", &a, &b);
            m_last_x = m_now_x, m_last_y = m_now_y;
            m_now_x = a, m_now_y = b;
            if (m_ar == 2) {
                if (ws < 1) return 4;
                if (wd[ws - 1].isfull) continue; //�ִ�ȭ�� ���
                //�̵���Ų��.
                wd[ws - 1].xl += (m_now_x - m_last_x), wd[ws - 1].yl += (m_now_y - m_last_y);
                wd[ws - 1].xh += (m_now_x - m_last_x), wd[ws - 1].yh += (m_now_y - m_last_y);
                printf("Moved window %d to %d, %d, %d, %d\n", wd[ws - 1].num,
                    wd[ws - 1].xl, wd[ws - 1].yl, wd[ws - 1].xh, wd[ws - 1].yh);
            }
        }
        else if (!strcmp(buff, "UP")) {
            //������ ���콺�� ����.
            if (!m_down) return 3;
            scanf("%d %d", &a, &b);
            m_last_x = m_now_x, m_last_y = m_now_y;
            m_now_x = a, m_now_y = b;
            if (m_ar == 2) {
                if (ws < 1) return 4;
                if (wd[ws - 1].isfull) continue;
                //�̵���Ų��.
                wd[ws - 1].xl += (m_now_x - m_last_x), wd[ws - 1].yl += (m_now_y - m_last_y);
                wd[ws - 1].xh += (m_now_x - m_last_x), wd[ws - 1].yh += (m_now_y - m_last_y);
                printf("Moved window %d to %d, %d, %d, %d\n", wd[ws - 1].num,
                    wd[ws - 1].xl, wd[ws - 1].yl, wd[ws - 1].xh, wd[ws - 1].yh);
            }
            else if (m_ar == 3) {
                if (ws < 1) return 4;
                //â�� �ݴ´�.
                if (inwindow(ws - 1, a, b) == 3) printf("Closed window %d\n", wd[--ws].num);
            }
            else if (m_ar == 4) {
                if (ws < 1) return 4;
                //�ִ�ȭ ��ư�� ������.
                if (inwindow(ws - 1, a, b) == 4) {
                    resize(ws - 1);
                    printf("Resized window %d to %d, %d, %d, %d\n", wd[ws - 1].num,
                        wd[ws - 1].xl, wd[ws - 1].yl, wd[ws - 1].xh, wd[ws - 1].yh);
                }
            }
            m_down = 0; //���콺�� ���¸� ������� �ǵ�����.
            m_ar = -1, m_wd = -1;
        }
        else if (!strcmp(buff, "RE")) {
            //â���� ������ ����Ѵ�.
            for (int i = 0; i < ws; i++) {
                printf("Window %d at %d, %d, %d, %d\n", wd[i].num, wd[i].xl, wd[i].yl, wd[i].xh, wd[i].yh);
            }
        }
        else return -1; //�ٸ� ���� ����.
    }
    return 0;
}