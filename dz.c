#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

    //проверять указатели на NULL
    //освобождать память полсе выхода из функции
    //зануть указатели после free
    //графы могут иметь петли и двойные рёбра (мб больше
    //выводить граф илибо на dot, GraphViz и system (можно подключить фреймовки для визуализации)
    //срок сдачи 15 (стоит 8)
    //Андрей Миронов
    //2 семенар

int main()
    {
    char **arr;
    int flag,i,j;
    int buffer;
    int * num;
    int n1, n2,str;
    n1 = n2 = str = i = j = flag = 0;
    FILE * text = fopen("table.txt", "r"); // открываем файл
    if (!text) return -1; // проверяем открылся ли
    rewind(text); // Ставим указатель внутри файла на первое место (проверить)

    char c;
    for (c = getc(text); c != EOF; c = getc(text)) // Подсчёт кол-ва символов в файле
        str = str + 1;

    arr = (char **)malloc((str + 1) * sizeof(char *)); // arr - массив со всеми данными
    num = (int*) malloc((str + 1) * sizeof(int));
    rewind(text);
    while (!feof(text)) { //подсчёт данных на каждой строчке
        buffer = fgetc(text);
        n1++;
        if (buffer == '\n') {
            num[i] = n1;
            i++;
            n1 = 0;
        }
    }
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

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 8; j++) {
            printf ("%c", arr[i][j]);
        }
        printf("\n");
    }
    
    
    return 0;
}
