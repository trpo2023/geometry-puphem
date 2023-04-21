#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define _USE_MATH_DEFINES
#include <libgeometry/geometryFuncs.c>
//#include <libgeometry/figures.wkt>
int main(int argc, char* argv[])
{
    if (argc != 2) {
        printf("You have not entered FILE\n");
        return 1;
    }
    FILE* file;
    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Couldn't open the FILE\n");
        return 2;
    }
    int size = 200;                              // constant
    char* file_in = malloc(size * sizeof(char)); // information from file
    struct figure* arr_of_fig
            = malloc(1 * sizeof(struct figure)); // make array of structs

    int index_of_struct = 0;
    int num = 1;
    int points;

    while ((file_in = fgets(file_in, size, file)) != NULL) {
        arr_of_fig = realloc(
                arr_of_fig, (index_of_struct + 2) * sizeof(struct figure));
        arr_of_fig[index_of_struct].number = num;
        file_in[strlen(file_in)] = '\0';
        // head into struct
        arr_of_fig[index_of_struct].head
                = malloc(strlen(file_in) * sizeof(char));
        strcpy(arr_of_fig[index_of_struct].head, file_in);
        //
        // getting
        char* token_del = strtok(file_in, "( ,)");
        int k = 0;
        int index_struct_arr = 0;
        while (token_del != NULL) {
            if (k == 0) {
                strcpy(arr_of_fig[index_of_struct].figure_type, token_del);
            } else {
                points = is_it(arr_of_fig[index_of_struct].figure_type);
                if (points == 0) {
                    printf("Figure type doesn't exit\n");
                    return 3;
                }
                arr_of_fig[index_of_struct].point[index_struct_arr]
                        = atof(token_del);
                index_struct_arr++;
            }
            token_del = strtok(NULL, "( ,)");
            k++;
        }
        //
        if (points == 3) {
            arr_of_fig[index_of_struct].perimetr
                    = circle_per(arr_of_fig[index_of_struct].point[2]);
            arr_of_fig[index_of_struct].area
                    = circle_square(arr_of_fig[index_of_struct].point[2]);
            circle_zone(
                    arr_of_fig[index_of_struct].point[0],
                    arr_of_fig[index_of_struct].point[1],
                    arr_of_fig[index_of_struct].zone,
                    arr_of_fig[index_of_struct].point[2]);
        }
        arr_of_fig = realloc(
                arr_of_fig, (index_of_struct + 1) * sizeof(struct figure));
        index_of_struct++;
        num++;
    }
    // Print
    for (int i = 0; i < index_of_struct; i++) {
        printf("[%i] %s\n", arr_of_fig[i].number, arr_of_fig[i].head);

        for (unsigned int j = 0; j < strlen(arr_of_fig[i].head) + 4; j++) {
            printf("_");
        }

        printf("\nFigure type: %s \nPerimetr: %f; \nSquare: %f\n",
               arr_of_fig[i].figure_type,
               arr_of_fig[i].perimetr,
               arr_of_fig[i].area);

        printf("\n");
    }
    printf("Complited!\n");

    free(arr_of_fig);
    free(file_in);
    fclose(file);
    return 0;
}
