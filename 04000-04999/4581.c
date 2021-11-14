#include <stdio.h>
#include <string.h>

char s[128];

int main(void) {
    int ys, ns, as, l;
    while (1) {
        scanf("%s", s);
        if (s[0] == '#') break;
        l = strlen(s);
        ys = 0, ns = 0, as = 0;
        for (int i = 0; s[i]; i++) {
            if (s[i] == 'Y') ys++;
            else if (s[i] == 'N') ns++;
            else if (s[i] == 'A') as++;
        }
        if (as * 2 >= l) printf("need quorum\n");
        else if (ys > ns) printf("yes\n");
        else if (ys == ns) printf("tie\n");
        else printf("no\n");
    }
    return 0;
}