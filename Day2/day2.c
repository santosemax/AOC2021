#include <stdio.h>
#include <string.h>

int main(void)
{
    int horizontal;
    int depth;
    int result;

    FILE *data;
    data = fopen("data.txt", "r");
    if (data == NULL)
    {
        printf("This file doesn't exist.\n");
        return 1;
    }

    char* direction;
    int num;
    while(!feof(data))
    {
        fscanf(data, "%s %d", direction, &num);

        // printf("%s ", direction);
        // printf("%d\n", num);

        // Take variables and do arithmetic
        if (strcmp(direction, "forward"))
        {
           horizontal += num; 
        }
        else if (strcmp(direction, "up"))
        {
            depth -= num;
        }
        else if (strcmp(direction, "down"))
        {
            depth += num;
        }
    }

    result = horizontal * depth;
    printf("%d\n", num);
    printf("Part 1: %d", result);

    fclose(data);
    return 0;
    
}
