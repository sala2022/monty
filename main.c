#include "monty.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    unsigned int lin_cnt = 0;
    char buffer[321];

    while (fgets(buffer, sizeof(buffer), file))
    {
        lin_cnt++;
    }

    fclose(file);

    printf("Nombre de lignes dans le fichier : %u\n", lin_cnt);

    return EXIT_SUCCESS;
}
