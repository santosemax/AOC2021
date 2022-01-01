#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define ARRAY_SIZE 13
#define TOTAL 1000

struct node
{
    char* string;
    struct node* next;
};
typedef struct node NODE;

int main(void)
{

    char gamma_rate[ARRAY_SIZE];
    char epsilon_rate[ARRAY_SIZE];

    // Linked list variables
    NODE *current, *head;
    head = current = NULL;

    FILE *data;
    data = fopen("data.txt", "r");
    if (data == NULL)
    {
        printf("Error opening data file");
        return 1;
    }

    // getline args
    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    int total = 0;
    int temp[ARRAY_SIZE] = {0};
    while ((read = getline(&line, &len, data) != -1))
    {
        //printf("%s", line);

        // Find total number of 1s for each index of array
        for (int i = 0; i < ARRAY_SIZE; i++)
        {
            if (line[i] == '0')
            {
               //printf("Equal to 1\n");
               temp[i] += 1;
            }

        }

        // Create linked list for part 2
        NODE *list = malloc(sizeof(NODE));
        list->string = strdup(line);
        list->next = NULL;

        if (head == NULL)
        {
            current = head = list;
        }
        else
        {
            current = current->next = list;
        }
        
        total += 1;

    }

    // Debug
    for (int i = 0; i < ARRAY_SIZE-1; i++)
    {
        printf("temp: %i\n", temp[i]);
    }

    // Calculate Gamma Rate
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if ((total - temp[i]) < (total/2))
        {
            gamma_rate[i] = '0';
        }
        else {
            gamma_rate[i] = '1';
        }
    }

    // Print Gamma Rate
    printf("Gamme Rate: ");
    for (int i = 0; i < ARRAY_SIZE-1; i++)
    {
        printf("%c", gamma_rate[i]); }
    printf("\n");

    // Find Epsilon Rate
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (gamma_rate[i] == '0')
        {
            epsilon_rate[i] = '1';
        }
        else
        {
            epsilon_rate[i] = '0';
        }
    }

    // Print Epsilon Rate
    printf("Epsilon Rate: ");
    for (int i = 0; i < ARRAY_SIZE-1; i++)
    {
        printf("%c", epsilon_rate[i]);
    }
    printf("\n");

    // Convert to Binary
    epsilon_rate[12] = '\0';
    gamma_rate[12] = '\0';
    int gamma_binary = strtol(gamma_rate, NULL, 2);
    int epsilon_binary = strtol(epsilon_rate, NULL, 2);
    printf("Gamma Binary: %d\n", gamma_binary);
    printf("Epsilon Binary: %d\n", epsilon_binary);

    // TODO: PART 2

    // Oxygen Generator Rating
    for (current = head; current; current=current->next)
    {
        // TODO: Calculate most common bit


        for (int i = 0; i < ARRAY_SIZE-1; i++)
        {

            if (current->string[i] == ?CURRENT_LINKED_LIST_CRITERIA?)
            {
                // TODO: Remove Node
            }

        }
                
        printf("%s", current->string); // DEBUG
    }

    fclose(data);
    if (line)
        free(line);
    return 0;
}
