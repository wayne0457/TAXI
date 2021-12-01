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

void print_card(cards_t card[]){
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
        swap(card, position , 4);
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

int which_type(cards_t card[]){
    if (straight_flush(card)) {
        return 1;
    } else if (four_of_a_kind(card)) {
        return 2;
    } else if (full_house(card)) {
        return 3;
    } else if (flush(card)) {
        return 4;
    } else if (straight(card)) {
        return 5;
    } else if (three_of_a_kind(card)) {
        return 6;
    } else if (two_pairs(card)) {
        return 7;
    } else if (pair(card, 0, 4) != 0) {
        return 8;
    } else {
        sort_by_face(card, 0, 4);
        return 9;
    }
}

int main(void){
    int a_type = 0, b_type = 0;
    cards_t *card_a = (cards_t*) malloc(5*sizeof(cards_t));
    cards_t *card_b = (cards_t*) malloc(5*sizeof(cards_t));

    for (int i = 0; i < 5; ++i) {
        scanf("\n%c%c", &card_a[i].suit, &card_a[i].face);
    }
    for (int i = 0; i < 5; ++i) {
        scanf("\n%c%c", &card_b[i].suit, &card_b[i].face);
    }

    a_type = which_type(card_a);
    b_type = which_type(card_b);
    print_card(card_a);

    if (a_type == b_type) {
        if (card_a[4].face == card_b[4].face) {
            printf(" == ");
        } else if (card_a[4].face > card_b[4].face) {
            printf(" < ");
        } else {
            printf(" > ");
        }
    } else if (a_type > b_type) {
        printf(" < ");
    } else {
        printf(" > ");
    }
    
    print_card(card_b);
    printf("\n");
}
