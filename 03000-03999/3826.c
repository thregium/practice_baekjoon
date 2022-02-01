#include <stdio.h>

/*
문제 : P(P <= 10)개의 줄에 대해 올바르게 인덴트된 코드가 주어진다. 각 코드의 길이는 80 이하며,
'.', 3가지 괄호, 소문자로 이루어져 있다. 공백은 '.'으로 표시된다.
각 괄호마다 각각의 인덴트를 더한 만큼을 들여쓰기한다. 각 괄호마다 인덴트된 칸 수는 1 이상 20 이하다.
이때, Q(Q <= 10)개의 인덴트되지 않은 코드가 주어지면 이 코드에 들여쓰기해야 하는 칸 수를 각각 구한다.
알 수 없다면 -1을 출력한다. 주어지는 코드도 80자 이하지만 들여쓰기 해야 하는 칸 수는 더 많을 수 있다.

해결 방법 : 우선 파싱을 통해 각 줄의 인덴트와 각 줄마다 열려있는 괄호 개수를 기록한다.
그리고 해당 괄호 개수 모두에 성립하는 인덴트들을 확인하면서 유일한 값이 있다면 그 값들을 설정한다.
다시 인덴트되지 않은 코드들을 받아온 다음, 세 값이 모두 유일한 경우 그대로 출력하면 되고,
유일하지 않은 값이 있다면 그 값을 제외한 값들을 확인할 수 있는 지 구한다.
이는 유일한 값들을 제거한 기록값에서 남은 괄호 수의 비율이 같은 경우를 확인하는 것으로 알 수 있다.
그러한 경우가 있다면 그러한 경우의 인덴트를 출력, 없다면 -1을 출력하면 된다.

주요 알고리즘 : 구현, 파싱, 수학, 브루트 포스, 케이스 워크 등

출처 : Tokyo 2012 B번
*/

char buff[128];
int idt[16][4]; //각 괄호 수 별 인덴트

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
            //주어진 코드에서 괄호 수와 인덴트를 기록한다.
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
                    //유일한 값들이 있는 지 구한다.
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
            //유일한 값들을 제거한다.
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
            for (int j = 0; j < 4; j++) idt[i][j] /= t; //다른 값들은 최대공약수로 나눈다.
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

            //유일하지 않은 경우
            if (t < 0) {
                t = 0, trc = rc, tcc = cc, tsc = sc;
                //유일한 값은 제거한다.
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
                        //세 값이 모두 나누어 떨어진다면 비율이 맞는 지 확인한다.
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
                if (tx == 0) t = -1; //어떠한 줄에서도 알 수 없다면 -1을 출력한다.
            }
            printf("%d%c", t, i == q - 1 ? '\n' : ' ');
            //괄호의 수를 센다.
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