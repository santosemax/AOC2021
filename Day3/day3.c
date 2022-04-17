#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define ARRAY_SIZE 13
#define TOTAL 1000

char *lines[TOTAL];
int total = 0;

typedef struct node {
    char data[12];
    struct node* next;
}node;

// two headNodes, one for finding oxygen rating and the other for co2
node* headNode = NULL;
node* headNode2 = NULL;

// Adding Nodes
void add_last(node** head, char* line)
{
    node* new_node = malloc(sizeof(node));

    strncpy(new_node->data, line, 12);
    new_node->next = NULL;

    // if head is null, it is empty
    if (*head == NULL)
        *head = new_node;
    else
    {
        node *lastNode = *head;

        while(lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }

        lastNode->next = new_node;
    }
}

// Deleting nodes
void delete_node(node **head, char key, int pos)
{
    node *temp;

    if ((*head)->data[pos] == key)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    else
    {
        node *current = *head;
        
        while (current->next != NULL)
        {
            // delete if we detect key
            if (current->next->data[pos] == key)
            {
                temp = current->next;

                // disconnect node
                current->next = current->next->next;
                free(temp);
                break;
            }
            // otherwise, move the current node and proceed
            else
                current = current->next;
        }
    }
}

// Debug function to print linked list
void print()
{
    node *new_node;
    for(new_node=headNode; new_node != NULL; new_node=new_node->next)
    {
        printf("%s\n", new_node->data);
    }
    //printf("\n");
}

void part2();
void oxygen_rating();
void co2_rating();

int main()
{

    char gamma_rate[ARRAY_SIZE];
    char epsilon_rate[ARRAY_SIZE];

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

        // Linked List for part 2
        if (total == 0)
        {
            //headNode = add_head(headNode, line);
            add_last(&headNode, line);
            //printf("%s", headNode->data);
            //tempNode = headNode;
        }
        else
        {
            //tempNode = add_to_list(tempNode, line);
            add_last(&headNode, line);
            //printf("%s", tempNode->data);
        }


        total += 1;

    }

    // Debug
    //for (int i = 0; i < ARRAY_SIZE-1; i++)
    //{
    //    printf("temp: %i\n", temp[i]);
    //}
    //print();

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
    //printf("Gamme Rate: ");
    //for (int i = 0; i < ARRAY_SIZE-1; i++)
    //{
    //    printf("%c", gamma_rate[i]); }
    //printf("\n");


    // Find Epsilon Rate (Just invert gamma rate)
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
    //printf("Epsilon Rate: ");
    //for (int i = 0; i < ARRAY_SIZE-1; i++)
    //{
    //    printf("%c", epsilon_rate[i]);
    //}
    //printf("\n");

    // Convert to Binary
    epsilon_rate[12] = '\0';
    gamma_rate[12] = '\0';
    int gamma_binary = strtol(gamma_rate, NULL, 2);
    int epsilon_binary = strtol(epsilon_rate, NULL, 2);
    printf("Gamma Binary: %d\n", gamma_binary);
    printf("Epsilon Binary: %d\n", epsilon_binary);

    printf("Part 1: %d\n", (epsilon_binary * gamma_binary));

    // TODO: PART 2
    part2();

    fclose(data);
    if (line)
        free(line);
    return 0;
}

void part2()
{
    oxygen_rating();

    printf("CO2 Srubber Rating: ");

}

void oxygen_rating()
{
    int tmp = TOTAL;
    printf("\n");
    // iterate through linked list by character (11 total w/o NULL char)
    for (int i = 0; i < 12; i++)
    {
        int zeros_counter = 0;
        int ones_counter = 0;

        // find most common value
        for (node* current = headNode; current != NULL; current = current->next)
        {
            if (current->data[i] == '0') 
            {
                zeros_counter += 1;
            }
            else if (current->data[i] == '1')
            {
                ones_counter += 1;
            }
        }

        // Debug
        //printf("\n");
        //printf("Place: %d\n", i);
        //printf("Ones Counter: %d\n", ones_counter);
        //printf("Zeros Counter: %d\n", zeros_counter);
        //if (zeros_counter > ones_counter)
        //{
        //    printf("more zeroes\n");
        //}
        //else if (zeros_counter < ones_counter)
        //{

        //    printf("more ones\n");
        //}
        //else
        //    printf("equal\n");
       
        // Remove nodes based on most common value
        for (node* current = headNode; current != NULL; current = current->next)
        {
            if (zeros_counter > ones_counter)
            {
                delete_node(&headNode, '1', i);
            }
            else if (zeros_counter == ones_counter)
            {
                delete_node(&headNode, '0', i);
            }
            else
            {
                delete_node(&headNode, '0', i);
            }

        }
               
    }
    printf("Oxygen Generator Rating: ");
    print();
}


