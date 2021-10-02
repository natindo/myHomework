#include <stdio.h>
#include <math.h>
#include <ctype.h>

int main(void) {
    FILE *table;
    table = fopen("table.txt", "r");

    if (table == NULL) {
        exit(1);
    }
    
    

    fclose (table);
    return 0;
}
