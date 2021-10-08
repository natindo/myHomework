#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

    //проверять указатели на NULL
    //освобождать память полсе выхода из функции
    //зануть указатели после free
    //графы могут иметь петли и двойные рёбра (мб больше
    //Андрей Миронов

int main(void) {
    char **arr;
    int i,j;
    int buffer;
    int * num;
    int n1,str;
    n1 = str = i = j = 0;
    FILE * text = fopen("table.txt", "r"); // открываем файл

    if (!text) 
        return 2; // проверяем открылся ли

    rewind(text); // Ставим указатель внутри файла на первое место
    char c;

    for (c = getc(text); c != EOF; c = getc(text)) // Подсчёт кол-ва символов в файле
        str = str + 1;

    arr = (char **)malloc((str + 1) * sizeof(char *)); // arr - массив со всеми данными
    num = (int*) malloc((str + 1) * sizeof(int));
    rewind(text);

    int col = 0;

    while (!feof(text)) { //подсчёт данных на каждой строчке
        buffer = fgetc(text);
        n1++;
        col = n1;
        if (buffer == '\n') {
            num[i] = n1; // num - хранит данные о том, сколько символов в каждой строчке
            i++;
            n1 = 0;
        }
    }

    int strelen = ++i; // хранит данные о том, сколько строк в файле

    num[str] = n1;
    rewind(text);

    for (i = 0; i <= str; i++) // перевыделяем память для каждой строчки массива
        arr[i] = (char *)malloc(num[i] * (sizeof(char*)));

    i = 0;
    j = 0;

    while (!feof(text)) { //запимываем данные в массив
        buffer = fgetc(text);
        arr[i][j] =(char) buffer;
        j++;
        if (buffer == '\n') {
            i++;
            j = 0;
        }
    }

    fclose (text);

    int number = 0;

    for (i = 1; i < strelen; i++) {
        for (j = 2; j < col; j++) {
            if (j > (i * 2)) 
                arr[i][j] = 0;

        }
    }

    int* final = (int*) malloc((str + 1) * sizeof(int));

    for (i = 1; i < strelen; i++) {
        for (j = 2; j < col; j++) {
            if ((arr[i][j] <= '9') && (arr[i][j] >= '1')){
                for (int k = 1; k <= (arr[i][j] - '0'); k++) {
                    final[number] = i;
                    final[number + 1] = ceil (j / 2);
                    number = number + 2;
                }
            }
        }
    }  

    FILE * graph = fopen("g.gv", "w"); // открываем файл

    fprintf (graph, "%s\n", "graph G { ");
    for (i = 0; i < number; i++) {
        fprintf (graph, "\t%d -- ", final[i]);
        fprintf (graph, "%d", final[++i]);
        fprintf (graph, "%s\n", " ");
    }
    fprintf (graph, "%s", "}");

    system("dot -Tpng g.gv -o '1.png'");
    //system("wslview 1.png");

    fclose (graph);

    int counter[9] = {};

    for (i = 0; i < number; i++) {
        counter[final[i]]++;
    }

    for (i = 0; i <= 9; i++) {

        if (counter[i] == 0 || counter[i] == 2) {
            ;
        } else {
            exit(1);
        }
    }

        printf ("граф - простой цикл\n");

    return 0;
}

