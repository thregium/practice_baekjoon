/* ACM Mid-Central Regional Programming Contest */
/* Solution to Problem F, "Instruens Fabulam" */
/* by Dr. Eric Shade, Computer Science Dept. */
/* Southwest Missouri State University */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEFT   '<'
#define RIGHT  '>'
#define CENTER '='
#define in stdin
#define out stdout

enum { MAX_ROWS = 21, MAX_COLS = 19 };
enum { HEADER, ROW, END };

int rows;                           /* number of rows in the table */
int columns;                        /* number of columns in the table */

char align[MAX_COLS + 1];           /* alignment of each column */
int  max_width[MAX_COLS];           /* maximum width of column */

char* entry[MAX_ROWS][MAX_COLS];    /* text of each entry */
int width[MAX_ROWS][MAX_COLS];      /* width of each entry */

char line[80 + 1];                  /* the last line read from the file */
int line_type;                      /* HEADER, ROW, or END */



int read_line(void)
{
    fgets(line, sizeof(line), in);
    line[strlen(line) - 1] = '\0';

    if (line[0] == '*')
        line_type = END;
    else if (line[0] == LEFT || line[0] == RIGHT || line[0] == CENTER)
        line_type = HEADER;
    else
        line_type = ROW;

    return line_type;
}



void process_header(void)
{
    int c;

    columns = strlen(line);
    strcpy(align, line);

    for (c = 0; c < columns; ++c)
        max_width[c] = 0;
}



void read_rows(void)
{
    rows = 0;

    while (read_line() == ROW) {
        char* s;
        int c = 0;

        for (s = strtok(line, "&"); s != NULL; s = strtok(NULL, "&")) {
            int n = strlen(s);

            entry[rows][c] = strdup(s);
            width[rows][c] = n;

            if (n > max_width[c]) max_width[c] = n;

            ++c;
        }

        ++rows;
    }
}



void print_char(int ch, int n)
{
    int i;

    for (i = 0; i < n; ++i) fputc(ch, out);
}



void print_row(int r)
{
    int c;

    for (c = 0; c < columns; ++c) {
        int n = width[r][c];
        int pad = max_width[c] - n;

        fprintf(out, "| ");
        switch (align[c]) {
        case LEFT:
            fprintf(out, "%s", entry[r][c]);
            print_char(' ', pad);
            break;
        case RIGHT:
            print_char(' ', pad);
            fprintf(out, "%s", entry[r][c]);
            break;
        case CENTER:
            print_char(' ', pad / 2);
            fprintf(out, "%s", entry[r][c]);
            print_char(' ', pad - (pad / 2));
        }
        fprintf(out, " ");
    }

    fprintf(out, "|\n");
}



void print_separator(int outer_char, int inner_char)
{
    int c;

    print_char(outer_char, 1);
    print_char('-', max_width[0] + 2);

    for (c = 1; c < columns; ++c) {
        print_char(inner_char, 1);
        print_char('-', max_width[c] + 2);
    }

    print_char(outer_char, 1);
    fputc('\n', out);
}



int main(void)
{

    read_line();
    while (line_type != END) {
        int r;

        process_header();
        read_rows();

        print_separator('@', '-');
        print_row(0);
        print_separator('|', '+');

        for (r = 1; r < rows; ++r) print_row(r);

        print_separator('@', '-');
    }

    return 0;
}
