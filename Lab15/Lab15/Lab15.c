#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct student
{
    char Painter[50];
    char Work[50];
    int Year;
};

void accept(struct student list[], int s);
void display(struct student list[], int s);
void sort(struct student list[], int s);
void threeOfThem(struct student list[], int s);

int main()
{
    struct student data[20];
    int n;

    printf("Number of records you want to enter: ");
    scanf("%d", &n);

    accept(data, n);
    printf("\nBefore sorting");
    display(data, n);
    sort(data, n);
    printf("\nAfter sorting");
    display(data, n);
    threeOfThem(data, n);
    return 0;
}

void accept(struct student list[80], int s)
{
    for (int i = 0; i < s; i++)
    {
        printf("\n\nEnter data for Record #%d", i + 1);

        if (gets(list[i].Painter) == '\0')
            break;

        printf("\nEnter painter name: ");
        gets(list[i].Painter);

        printf("Enter title of the work: ");
        gets((list+i)->Work);

        printf("Enter year of creation : ");
        scanf("%d", &list[i].Year);
    }
}

void display(struct student list[80], int s)
{
    printf("\n\nPainter\t\t\t\tTitle\t\t\t\tYear\n\n");
    for (int i = 0; i < s; i++)
    {
        printf("%-26.24s\t%-20s\t%10ld\n", list[i].Painter, list[i].Work, list[i].Year);
    }
}

void sort(struct student list[80], int s)
{
    struct student temp;

    for (int i = 0; i < s - 1; i++)
    {
        for (int j = 0; j < (s - 1 - i); j++)
        {
            if (list[j].Year < list[j + 1].Year)
            {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}
void threeOfThem(struct student list[80], int s)
{
    printf("\n\n3 random painters:\n");
    int i, j;
    srand(time(NULL));
    printf("\nPainter\t\t\t\tTitle\t\t\t\tYear\n");
    for (i = 0; i < 3; i++)
    {
        j = rand() % s;
        printf("%-26.24s\t%-20s\t%10ld\n", list[j].Painter, list[j].Work, list[j].Year);
    }
}