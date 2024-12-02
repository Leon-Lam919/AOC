#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
    return(*(int *)a - *(int *)b);
}

int main() {
    FILE *file;
    char filename[] = "day1.txt";
    int number, total = 0;
    int num1[1000], num2[1000];

    // Open the file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    printf("Numbers in the file:\n");

    // Read numbers from the file and print them
    /*
    while (fscanf(file, "%d %d", &num1, &num2) != EOF) {
        printf("%d\t%d\n", number);
    }
    */
    for (int i = 0; i < 1000; i++){
        fscanf(file, "%d %d", &num1[i], &num2[i]);
    }
    int size1 = sizeof(num1) / sizeof(num1[0]);
    int size2 = sizeof(num2) / sizeof(num2[0]);

    qsort(num1, size1, sizeof(int), compare);
    qsort(num2, size2, sizeof(int), compare);

    for (int j =0; j < 1000; j++){
        total += abs(num1[j] - num2[j]);
    }

    printf("Total = %d", total);

    // Close the file
    fclose(file);

    return EXIT_SUCCESS;
}

