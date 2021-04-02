#include <stdio.h>

int a[1024], s[1024], st[1024], ed[1024];

int main(void) {
    int n, l, h, t, r = 0;
    int stt[1024], edt[1024];
    scanf("%d", &n);
    for (int nn = 0; nn < n; nn++) {
        scanf("%d", &l);
        for (int i = 1; i <= l; i++) {
            scanf("%d", &a[i]);
            stt[i] = 0;
            edt[i] = 0;
        }
        t = 0;
        h = -10000;
        for (int i = 1; i <= l; i++) {
            t += a[i];
            if (a[i] >= t) {
                t = a[i];
                stt[i] = 1;
            }
            if (t >= h) {
                h = t;
                //edt[i] = 1;
            }
            s[i] = t;
        }
        for (int i = 1; i <= l; i++) {
            if (s[i] == h) edt[i] = 1;
        }
        int lst = 0, ld = 1024;
        for (int i = 1; i <= l; i++) {
            if (stt[i]) lst = i;
            if (edt[i]) {
                if (i - lst < ld) {
                    st[nn] = lst;
                    ed[nn] = i;
                    ld = i - lst;
                }
            }
        }
        r += h;
    }
    printf("%d\n", r);
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", st[i], ed[i]);
    }
    return 0;
}