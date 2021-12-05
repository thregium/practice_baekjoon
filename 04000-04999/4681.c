#include <stdio.h>
#include <string.h>

/*
문제 : 1024 * 1024 크기의 화면에서 창들을 띄우고 마우스의 움직임에 따라 창들의 움직임을 추적하는 프로그램을 만든다.

각 창은 26 * 51 픽셀 이상의 크기이고, 왼쪽 위 25 * 25 픽셀은 종료 버튼, 오른쪽 위 25 * 25 픽셀은 최대화 버튼,
그 외 위쪽 25 픽셀은 이동 바이다. 나머지 칸들은 일반 영역이다.

창의 일부분을 클릭하면 그 창이 맨 위로 올라온다. 마우스를 누를 때와 뗄 때 같은 버튼에 있었다면 그 버튼의 기능을 실행한다.
이동 바를 누른 채로 움직이면 그 창이 같이 움직인다. 단, 최대화 상태에서는 이동하지 않는다.
새로운 창을 만들면 그 창이 맨 위에 생성된다. RE 기능을 사용하면 밑에서부터 하나씩 창들의 정보를 보여준다.
각 기능을 수행할 때 마다 각 기능에 대한 정보를 보여줘야 한다. 창 번호는 생성한 순서대로 들어간다.

해결 방법 : 각 창의 정보를 배열에 담아둔 다음, 배열의 정보를 이용해 해결해 나간다.
위로 갈 수록 새로운 창을 담는 것이 좋다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : MidC 1997 F번
*/

typedef struct window {
    int xl, yl, xh, yh;
    int oxl, oyl, oxh, oyh;
    int isfull;
    int num;
} window;

window wd[1024]; //창의 정보를 저장한다. 위로 갈 수록 새로운 창이다.
char buff[8]; //명령어를 저장하는 임시 버퍼

void makescreen(int ws, int wc, int xl, int yl, int xh, int yh) {
    //새 창을 만든다.
    wd[ws].xl = xl;
    wd[ws].yl = yl;
    wd[ws].xh = xh;
    wd[ws].yh = yh;
    wd[ws].num = wc;
    wd[ws].isfull = 0;
    printf("Created window %d at %d, %d, %d, %d\n", wc, xl, yl, xh, yh);
}

int inwindow(int w, int x, int y) {
    //해당 점이 해당 창에 속하는지, 속한다면 어느 영역에 속하는지 확인한다.
    if (x > wd[w].xh || x < wd[w].xl || y > wd[w].yh || y < wd[w].yl) return 0;
    if (y > wd[w].yl + 24) return 1;
    if (x <= wd[w].xl + 24) return 3;
    if (x >= wd[w].xh - 24) return 4;
    return 2;
}

void resize(int w) {
    //창의 크기를 최대화하거나 최대화된 창을 원상복귀시킨다.
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
    int ws = 0, wc = 0, a, b, c, d; //현재 창의 수, 지금까지 만든 창의 수, 파라미터 4개
    int m_orig_x = -1, m_orig_y = -1, m_now_x = -1, m_now_y = -1, m_last_x = -1, m_last_y = -1;
    //마우스를 누른 지점의, 현재의, 마지막으로 움직였던 곳의 좌표
    int m_down = 0, m_wd = -1, m_ar = -1; //마우스가 눌린 상태인지, 마우스로 누르고 있는 창의 번호, 눌린 영역의 번호
    window temp_wd; //임시 창(창을 옮길 때 사용)
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\acm97\\wimp\\wimp.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\acm97\\wimp\\wimp_t.out", "w", stdout);
    while (1) {
        scanf("%s", buff);
        if (!strcmp(buff, "ZZ")) break; //프로그램을 종료한다.
        else if (!strcmp(buff, "CR")) {
            //새 창을 만든다.
            scanf("%d %d %d %d", &a, &b, &c, &d);
            if (wc > 1000) return 1;
            makescreen(ws, wc, a, b, c, d);
            ws++;
            wc++;
        }
        else if (!strcmp(buff, "DN")) {
            //해당 좌표에서 마우스를 누른다.
            //if (m_down) return 2; 마우스가 눌린 상태에서 다시 누르는 것도 가능하다.
            scanf("%d %d", &a, &b);
            for (int i = ws - 1; i >= 0; i--) {
                if (inwindow(i, a, b)) {
                    //해당 좌표에 있는 가장 위의 창
                    m_wd = wd[i].num;
                    m_ar = inwindow(i, a, b);
                    temp_wd = wd[i];
                    for (int j = i; j < ws - 1; j++) {
                        wd[j] = wd[j + 1];
                    }
                    wd[ws - 1] = temp_wd; //해당 창을 맨 위로 올린다.
                    printf("Selected window %d\n", m_wd);
                    break;
                }
            }
            m_down = 1;
            m_orig_x = a, m_orig_y = b;
            m_now_x = a, m_now_y = b;
        }
        else if (!strcmp(buff, "AT")) {
            //마우스를 이동한다. 이동하는 경우에만 유의미하다.
            scanf("%d %d", &a, &b);
            m_last_x = m_now_x, m_last_y = m_now_y;
            m_now_x = a, m_now_y = b;
            if (m_ar == 2) {
                if (ws < 1) return 4;
                if (wd[ws - 1].isfull) continue; //최대화된 경우
                //이동시킨다.
                wd[ws - 1].xl += (m_now_x - m_last_x), wd[ws - 1].yl += (m_now_y - m_last_y);
                wd[ws - 1].xh += (m_now_x - m_last_x), wd[ws - 1].yh += (m_now_y - m_last_y);
                printf("Moved window %d to %d, %d, %d, %d\n", wd[ws - 1].num,
                    wd[ws - 1].xl, wd[ws - 1].yl, wd[ws - 1].xh, wd[ws - 1].yh);
            }
        }
        else if (!strcmp(buff, "UP")) {
            //눌렀던 마우스를 뗀다.
            if (!m_down) return 3;
            scanf("%d %d", &a, &b);
            m_last_x = m_now_x, m_last_y = m_now_y;
            m_now_x = a, m_now_y = b;
            if (m_ar == 2) {
                if (ws < 1) return 4;
                if (wd[ws - 1].isfull) continue;
                //이동시킨다.
                wd[ws - 1].xl += (m_now_x - m_last_x), wd[ws - 1].yl += (m_now_y - m_last_y);
                wd[ws - 1].xh += (m_now_x - m_last_x), wd[ws - 1].yh += (m_now_y - m_last_y);
                printf("Moved window %d to %d, %d, %d, %d\n", wd[ws - 1].num,
                    wd[ws - 1].xl, wd[ws - 1].yl, wd[ws - 1].xh, wd[ws - 1].yh);
            }
            else if (m_ar == 3) {
                if (ws < 1) return 4;
                //창을 닫는다.
                if (inwindow(ws - 1, a, b) == 3) printf("Closed window %d\n", wd[--ws].num);
            }
            else if (m_ar == 4) {
                if (ws < 1) return 4;
                //최대화 버튼을 누른다.
                if (inwindow(ws - 1, a, b) == 4) {
                    resize(ws - 1);
                    printf("Resized window %d to %d, %d, %d, %d\n", wd[ws - 1].num,
                        wd[ws - 1].xl, wd[ws - 1].yl, wd[ws - 1].xh, wd[ws - 1].yh);
                }
            }
            m_down = 0; //마우스의 상태를 원래대로 되돌린다.
            m_ar = -1, m_wd = -1;
        }
        else if (!strcmp(buff, "RE")) {
            //창들의 정보를 출력한다.
            for (int i = 0; i < ws; i++) {
                printf("Window %d at %d, %d, %d, %d\n", wd[i].num, wd[i].xl, wd[i].yl, wd[i].xh, wd[i].yh);
            }
        }
        else return -1; //다른 경우는 없다.
    }
    return 0;
}