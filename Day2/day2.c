#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int aim = 0;

int main(void)
{
    int horizontal = 0;
    int depth = 0;
    int result = 0;

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
        if ((strcmp(direction, "forward")) == 0)
        {
           horizontal += num; 
           depth += (aim * num);
        }
        else if ((strcmp(direction, "up")) == 0)
        {
            // depth -= num; // PART 1
            aim -= num;
        }
        else if ((strcmp(direction, "down")) == 0)
        {
            // depth += num; // PART 1
            aim += num;
        }
    }

    result = horizontal * depth;

    printf("Answer: %i\n", result);

    fclose(data);
    return 0;
    
}