#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int num;
    int linenum = 1;
    int increased = 0;

    const int TOTAL = 2000;
    int lines[TOTAL];


    FILE *data;
    data = fopen("data.txt", "r");
    if (data == NULL)
    {
       printf("This file doesn't exist.\n");
       return 1;
    }

    int tempnum = 0;
    int total, sum;
    while(!feof(data))
    {
        fscanf(data, "%d", &num);
        //printf("%d: ", linenum);
        //printf("%d\n", num);

        // PART 1 - Check everytime the number increases
        if (linenum != 1)
        {
            if (num > tempnum)
            {
                increased += 1;
            }
        }

        // Append to array for part 2
        lines[linenum-1] = num;

        tempnum = num;
        linenum += 1;
                
    }

    // PART 2 - Add up three numbers and see if it increased
    sum = 0;
    int temp = 0;
    int increased2 = 0;
    for (int i = 0; i < TOTAL; i++)
    {
        // Get sum of current line and next two numbers
        if (i < 1998)
        {
            sum = lines[i] + lines[i+1] + lines[i+2];
        }

        if (i != 0)
        {
            if (sum > temp)
            {
                increased2 += 1;
            }
        }

        temp = sum;
        printf("%d\n", temp);

        //printf("%d ", lines[i]);
    }

    printf("Part 1: %d\n", increased);
    printf("Part 2: %d", increased2);

    fclose(data);
    return 0;

}
