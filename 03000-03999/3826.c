#include <stdio.h>

/*
���� : P(P <= 10)���� �ٿ� ���� �ùٸ��� �ε�Ʈ�� �ڵ尡 �־�����. �� �ڵ��� ���̴� 80 ���ϸ�,
'.', 3���� ��ȣ, �ҹ��ڷ� �̷���� �ִ�. ������ '.'���� ǥ�õȴ�.
�� ��ȣ���� ������ �ε�Ʈ�� ���� ��ŭ�� �鿩�����Ѵ�. �� ��ȣ���� �ε�Ʈ�� ĭ ���� 1 �̻� 20 ���ϴ�.
�̶�, Q(Q <= 10)���� �ε�Ʈ���� ���� �ڵ尡 �־����� �� �ڵ忡 �鿩�����ؾ� �ϴ� ĭ ���� ���� ���Ѵ�.
�� �� ���ٸ� -1�� ����Ѵ�. �־����� �ڵ嵵 80�� �������� �鿩���� �ؾ� �ϴ� ĭ ���� �� ���� �� �ִ�.

�ذ� ��� : �켱 �Ľ��� ���� �� ���� �ε�Ʈ�� �� �ٸ��� �����ִ� ��ȣ ������ ����Ѵ�.
�׸��� �ش� ��ȣ ���� ��ο� �����ϴ� �ε�Ʈ���� Ȯ���ϸ鼭 ������ ���� �ִٸ� �� ������ �����Ѵ�.
�ٽ� �ε�Ʈ���� ���� �ڵ���� �޾ƿ� ����, �� ���� ��� ������ ��� �״�� ����ϸ� �ǰ�,
�������� ���� ���� �ִٸ� �� ���� ������ ������ Ȯ���� �� �ִ� �� ���Ѵ�.
�̴� ������ ������ ������ ��ϰ����� ���� ��ȣ ���� ������ ���� ��츦 Ȯ���ϴ� ������ �� �� �ִ�.
�׷��� ��찡 �ִٸ� �׷��� ����� �ε�Ʈ�� ���, ���ٸ� -1�� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, �Ľ�, ����, ���Ʈ ����, ���̽� ��ũ ��

��ó : Tokyo 2012 B��
*/

char buff[128];
int idt[16][4]; //�� ��ȣ �� �� �ε�Ʈ

int gcd(int a, int b) {
    if (a == 0 && b == 0) return 1;
    else if (a == 0) return b;
    else if (b == 0) return a;
    else return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int main(void) {
    int p, q, rc, cc, sc, ri, ci, si, t, tx, trc, tcc, tsc;
    //freopen("E:\\PS\\ICPC\\Asia Pacific\\Japan Regional\\2012\\InputsAndOutputs12\\B.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Asia Pacific\\Japan Regional\\2012\\InputsAndOutputs12\\B_t.out", "w", stdout);
    while (1) {
        scanf("%d %d", &p, &q);
        if (p == 0) break;
        rc = 0, cc = 0, sc = 0, ri = -1, ci = -1, si = -1;
        for (int i = 0; i < p; i++) {
            //�־��� �ڵ忡�� ��ȣ ���� �ε�Ʈ�� ����Ѵ�.
            scanf("%s", buff);
            for (int j = 0; buff[j]; j++) {
                idt[i][3] = j;
                if (buff[j] != '.') break;
            }
            idt[i][0] = rc;
            idt[i][1] = cc;
            idt[i][2] = sc;
            for (int j = 0; buff[j]; j++) {
                if (buff[j] == '(') rc++;
                else if (buff[j] == '{') cc++;
                else if (buff[j] == '[') sc++;
                else if (buff[j] == ')') rc--;
                else if (buff[j] == '}') cc--;
                else if (buff[j] == ']') sc--;
            }
        }

        for (int i = 1; i <= 20; i++) {
            for (int j = 1; j <= 20; j++) {
                for (int k = 1; k <= 20; k++) {
                    //������ ������ �ִ� �� ���Ѵ�.
                    t = 1;
                    for (int l = 0; l < p; l++) {
                        if (idt[l][0] * i + idt[l][1] * j + idt[l][2] * k != idt[l][3]) t = 0;
                    }
                    if (!t) continue;
                    if (ri < 0) ri = i;
                    else if (ri != i) ri = 0;
                    if (ci < 0) ci = j;
                    else if (ci != j) ci = 0;
                    if (si < 0) si = k;
                    else if (si != k) si = 0;
                }
            }
        }
        for (int i = 0; i < p; i++) {
            //������ ������ �����Ѵ�.
            if (ri > 0) {
                idt[i][3] -= ri * idt[i][0];
                idt[i][0] = 0;
            }
            if (ci > 0) {
                idt[i][3] -= ci * idt[i][1];
                idt[i][1] = 0;
            }
            if (si > 0) {
                idt[i][3] -= si * idt[i][2];
                idt[i][2] = 0;
            }
            t = gcd(gcd(idt[i][0], idt[i][1]), idt[i][2]);
            for (int j = 0; j < 4; j++) idt[i][j] /= t; //�ٸ� ������ �ִ������� ������.
        }

        rc = 0, cc = 0, sc = 0;
        for (int i = 0; i < q; i++) {
            scanf("%s", buff);
            t = 0;
            if (t >= 0 && rc > 0 && ri > 0) t += ri * rc;
            else if (t >= 0 && rc > 0) t = -1;
            if (t >= 0 && cc > 0 && ci > 0) t += ci * cc;
            else if (t >= 0 && cc > 0) t = -1;
            if (t >= 0 && sc > 0 && si > 0) t += si * sc;
            else if (t >= 0 && sc > 0) t = -1;

            //�������� ���� ���
            if (t < 0) {
                t = 0, trc = rc, tcc = cc, tsc = sc;
                //������ ���� �����Ѵ�.
                if (ri > 0) {
                    t += trc * ri;
                    trc = 0;
                }
                if (ci > 0) {
                    t += tcc * ci;
                    tcc = 0;
                }
                if (si > 0) {
                    t += tsc * si;
                    tsc = 0;
                }
                tx = 0;
                for (int j = 0; j < p; j++) {
                    if ((trc <= 0 || (idt[j][0] > 0 && trc % idt[j][0] == 0)) &&
                        (tcc <= 0 || (idt[j][1] > 0 && tcc % idt[j][1] == 0)) &&
                        (tsc <= 0 || (idt[j][2] > 0 && tsc % idt[j][2] == 0))) {
                        //�� ���� ��� ������ �������ٸ� ������ �´� �� Ȯ���Ѵ�.
                        if (trc > 0 && tcc > 0 && tsc > 0) {
                            if (!(trc / idt[j][0] == tcc / idt[j][1] &&
                                tcc / idt[j][1] == tsc / idt[j][2])) continue;
                            else t += idt[j][3] * (trc / idt[j][0]);
                        }
                        else if (trc > 0 && tcc > 0) {
                            if (trc / idt[j][0] != tcc / idt[j][1]) continue;
                            else t += idt[j][3] * (trc / idt[j][0]);
                        }
                        else if (trc > 0 && tsc > 0) {
                            if (trc / idt[j][0] != tsc / idt[j][2]) continue;
                            else t += idt[j][3] * (trc / idt[j][0]);
                        }
                        else if (tcc > 0 && tsc > 0) {
                            if (tcc / idt[j][1] != tsc / idt[j][2]) continue;
                            else t += idt[j][3] * (tcc / idt[j][1]);
                        }
                        else continue;
                        tx = 1;
                        break;
                    }
                }
                if (tx == 0) t = -1; //��� �ٿ����� �� �� ���ٸ� -1�� ����Ѵ�.
            }
            printf("%d%c", t, i == q - 1 ? '\n' : ' ');
            //��ȣ�� ���� ����.
            for (int j = 0; buff[j]; j++) {
                if (buff[j] == '(') rc++;
                else if (buff[j] == '{') cc++;
                else if (buff[j] == '[') sc++;
                else if (buff[j] == ')') rc--;
                else if (buff[j] == '}') cc--;
                else if (buff[j] == ']') sc--;
            }
        }
    }
    return 0;
}