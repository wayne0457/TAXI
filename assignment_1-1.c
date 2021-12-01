#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char suit;
    char face;
} cards_t;

void sort_by_face(cards_t card[], int a, int b){
    cards_t t_1;
    int t_2;
    char face[13] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
    int *array = (int*) malloc((b - a ) * sizeof(int));

    for (int i = a; i <= b; ++i) {
        for (int j = 0; j < 13; ++j) {
            if (card[i].face == face[j]) {
                array[i] = j;
            }
        }
    }
    for (int i = a; i <= b; ++i) {
        for (int j = a; j < i; ++j) {
            if (array[j] > array[i]) {
                t_1 = card[j];
                card[j] = card[i];
                card[i] = t_1;
                t_2 = array[j];
                array[j] = array[i];
                array[i] = t_2;
            }
        }
    }
}
void sort_by_suit(cards_t card[], int a, int b){
    cards_t t_1;
    char t_2;
    char suit[4] = {'C', 'D', 'H', 'S'};
    char *array = (char*) malloc((b - a ) * sizeof(char));

    for (int i = a; i <= b; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (card[i].suit == suit[j]) {
                array[i] = j;
            }
        }
    }
    for (int i = a; i <= b; ++i) {
        for (int j = a; j < i; ++j) {
            if (array[j] > array[i]) {
                t_1 = card[j];
                card[j] = card[i];
                card[i] = t_1;
                t_2 = array[j];
                array[j] = array[i];
                array[i] = t_2;
            }
        }
    }
}

void swap(cards_t card[], int a, int b){
    cards_t t = card[a];
    card[a] = card[b];
    card[b] = t;
}

int pair(cards_t card[], int a, int b){
    int ans = 0, position;

    for (int i = a; i < b; ++i) {
        if (card[i].face == card[i+1].face) {
            ++ans;
            position = i;
        }
    }
    if (ans == 1) {
        swap(card, position, 4);
        swap(card, position + 1, 3);
        sort_by_face(card, 0, 2);
        sort_by_face(card, 3, 4);
    }
    return ans;
}

int straight(cards_t card[]){
    char face[13] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
    int *array = (int*) malloc(5 * sizeof(int));

    sort_by_face(card, 0, 4);
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 13; ++j) {
            if (card[i].face == face[j]) {
                array[i] = j;
            }
        }
    }
    for (int i = 0; i < 4 ; ++i) {
        if (array[i] + 1 != array[i + 1]) {
            return 0;
        }
    }
    return 1;
}

int flush(cards_t card[]){
    for (int i = 0; i < 4; ++i) {
        if (card[i].suit != card[i+1].suit) {
            return 0;
        }
    }
    sort_by_suit(card, 0, 4);
    return 1;
}

int straight_flush(cards_t card[]){
    if (!flush(card)) {
        return 0;
    }
    if (!straight(card)) {
        return 0;
    }
    return 1;
}

int four_of_a_kind(cards_t card[]){
    int ans;
    sort_by_face(card, 0, 4);

    if (card[0].face == card[1].face) {
        swap(card, 0, 4);
        ans = pair(card, 1, 4);
    } else {
        ans = pair(card, 1, 4);
    }
    if (ans != 3) {
        return 0;
    }
    sort_by_suit(card, 1, 4);
    return 1;
}

int full_house(cards_t card[]){
    int num = 0;
    sort_by_face(card, 0, 4);

    num = pair(card, 0, 2);
    if(num == 2) {
        swap(card, 1, 4);
        swap(card, 0, 3);
    } else if (num == 2) {
    } else {
        return 0;
    }
    sort_by_suit(card, 0, 1);
    sort_by_suit(card, 2, 4);
    return 1;
}

int three_of_a_kind(cards_t card[]){
    sort_by_face(card, 0, 4);
    if (card[1].face == card[2].face) {
        if (card[0].face == card[1].face) {
            swap(card, 1, 4);
            swap(card, 0, 3);
        } else {
            swap(card, 1, 4);
        }
    }
    if (pair(card, 2, 4) == 2) {
        sort_by_suit(card, 2, 4);
        sort_by_face(card, 0, 1);
        return 1;
    }
    return 0;
}

int two_pairs(cards_t card[]){
    sort_by_face(card, 0, 4);
    if (card[2].face != card[3].face) {
        swap(card, 0, 2);
    } else if (card[3].face != card[4].face) {
        swap(card, 2, 4);
        swap(card, 0, 2);
    }
    if (pair(card, 0, 4) == 2) {
        sort_by_suit(card, 1, 2);
        sort_by_suit(card, 3, 4);
        return 1;
    }
    return 0;
}

int main(void){
    /*看不懂的話可以問我，啊記得跟林庭伃說講話不要打那麼多笑哭臉表情符號*/
    cards_t *card = (cards_t*) malloc(5*sizeof(cards_t));

    for (int i = 0; i < 5; ++i) {
        scanf("\n%c%c", &card[i].suit, &card[i].face);
    }
    if (straight_flush(card)) {
        if (card[4].suit == 'T') {
            printf("%c10-straight flush\n", card[4].suit);
        } else {
            printf("%c%c-straight flush\n", card[4].suit, card[4].face);
        }
    } else if (four_of_a_kind(card)) {
        if (card[4].suit == 'T') {
            printf("10-four of a kind\n");
        } else {
            printf("%c-four of a kind\n", card[4].face);
        }
    } else if (full_house(card)) {
        if (card[4].suit == 'T') {
            printf("10-full house\n");
        } else {
            printf("%c-full house\n", card[4].face);
        }
    } else if (flush(card)) {
        printf("%c-flush\n", card[4].suit);
    } else if (straight(card)) {
        if (card[4].suit == 'T') {
            printf("10-straight\n");
        } else {
            printf("%c-straight\n", card[4].face);
        }
    } else if (three_of_a_kind(card)) {
        if (card[4].suit == 'T') {
            printf("10-three of a kind\n");
        } else {
            printf("%c-three of a kind\n", card[4].face);
        }
    } else if (two_pairs(card)) {
        if (card[4].suit == 'T') {
             printf("%c10-two pairs\n", card[4].suit);
        } else {
            printf("%c%c-two pairs\n", card[4].suit, card[4].face);
        }
    } else if (pair(card, 0, 4) != 0) {
        if (card[4].suit == 'T') {
             printf("%c10-pair\n", card[4].suit);
        } else {
            printf("%c%c-pair\n", card[4].suit, card[4].face);
        }
    } else {
        sort_by_face(card, 0, 4);
        if (card[4].suit == 'T') {
             printf("%c10-high card\n", card[4].suit);
        } else {
            printf("%c%c-high card\n", card[4].suit, card[4].face);
        }
    }
    for (int i = 0; i < 5; ++i) {
        if (card[i].face == 'T') {
            printf("%c10", card[i].suit);
        } else {
            printf("%c%c", card[i].suit, card[i].face);
        }
        if (i != 4) {
            printf(" ");
        }
    }
    printf("\n");
}
