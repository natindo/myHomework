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

int main() {
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
    int* final = (int*) malloc((str + 1) * sizeof(int));
    rewind(text);

    while (!feof(text)) { //подсчёт данных на каждой строчке
        buffer = fgetc(text);
        n1++;
        if (buffer == '\n') {
            num[i] = n1; // num - хранит данные о том, сколько символов в каждой строчке
            i++;
            n1 = 0;
        }
    }

    int strelen = i; // хранит данные о том, сколько строк в файле

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

    fclose(text);
    text == NULL;

/*    for (i = 0; i < 4; i++) {
        for (j = 1; j < 8; j++) {
            if (arr[i][j] == ' ') {
                arr[i][j] = arr[i][j+1];
                for (int g = j+1; g < 8; g++) {
                    arr[i][g] = arr[i][g+1];           попытка удалить пробелы
                }
            }
        }
    }

    */

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 8; j++) {
            printf ("%c", arr[i][j]);
        }
        printf("\n");
    }

    int line = 0, col = 0, number = 0; // col - столбец

    for (i = 1; i < 4; i++) {
        for (j = 2; j < 8; j++) {

            if (j > (i * 2)) 
                arr[i][j] = 0;

        }
    }

    printf("\n");

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 8; j++) {
            printf ("%c", arr[i][j]);
        }
        printf("\n");
    }

    for (i = 1; i < 4; i++) {
        for (j = 2; j < 8; j++) {
            //printf("%c\n", arr[j][i]);
            if ((arr[i][j] <= '9') && (arr[i][j] >= '1')){
                for (int k = 1; k <= (arr[i][j] - '0'); k++) {
                    final[number] = i;
                    final[number + 1] = ceil (j / 2);
                    number = number + 2;
                }
                //line = i;
                //col = j;
                //final[number] = i;
                //final[number + 1] = ceil (j / 2);
                //number = number + 2;
                //printf("%c\n", arr[i][j]);
                //printf ("%c\n", firstNum);
            
            }
        }
    }

    for (i = 0; i < number; i++) {
        printf("%2d", final[i]);
    }
  

    FILE * graph = fopen("g.gv", "w"); // открываем файл

    //printf ("%d\n", final[0]);

    fprintf (graph, "%s\n", "graph G { ");
    for (i = 0; i < number; i++) {
        fprintf (graph, "\t%d -- ", final[i]);
        fprintf (graph, "%d", final[++i]);
        fprintf (graph, "%s\n", " ");
    }
    fprintf (graph, "%s", "}");

    system ("dot -Tpng g.gv -o file.png");
    system ("wslview file.png");

    
  
    return 0;
}
/* Пишем массив в котором последовательно идут числа которые что-то згачат на графе a и b, мы пишем как сказаны в пред комментрии и всё отлично*/
