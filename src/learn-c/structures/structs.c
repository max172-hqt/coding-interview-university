#include <stdio.h>

typedef struct card {
    char *face;
    char *suit;
} Card;

struct employee {
    char firstName[20];
    char lastName[20];
    int age;
    char gender;
    double hourlySalary;
};

int main(void)
{
    /* struct card aCard, deck[52], *cardPtr; */
    Card aCard = { "Three", "Hearts" };
    Card *cardPtr;
    cardPtr = &aCard;
    // Structure member operator
    printf("%s\n", aCard.face);

    // Structure pointer operator
    printf("%s same with %s\n", cardPtr->suit, (*cardPtr).suit);

    Card deck[52];

    return 0;
}
