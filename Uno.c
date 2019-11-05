//Authors: Abraham Muasher and Jack Kerr
//Date Created: 4/11/18
//Description: This program is for the game of UNO, a popular card game among many people of all ages
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef struct card_s {
	char suit[7];
	int value;
	char action[15];
	struct card_s *pt;
} card;

card *new_card(card *hl, int i, int j) {
	card *p;

	p = (card *)malloc(sizeof(card));

	if (i == 1) {
		strcpy(p->suit, "Red");
		if (j == 10) {
			strcpy(p->action, "Skip");
		}
		else if (j == 11) {
			strcpy(p->action, "Reverse");
		}
		else if (j == 12) {
			strcpy(p->action, "Draw Two");
		}
		else {
			p->value = j;
		}
	}
	if (i == 2) {
		strcpy(p->suit, "Yellow");
		if (j == 10) {
			strcpy(p->action, "Skip");
		}
		else if (j == 11) {
			strcpy(p->action, "Reverse");
		}
		else if (j == 12) {
			strcpy(p->action, "Draw Two");
		}
		else {
			p->value = j;
		}
	}
	if (i == 3) {
		strcpy(p->suit, "Green");
		if (j == 10) {
			strcpy(p->action, "Skip");
		}
		else if (j == 11) {
			strcpy(p->action, "Reverse");
		}
		else if (j == 12) {
			strcpy(p->action, "Draw Two");
		}
		else {
			p->value = j;
		}
	}
	if (i == 4) {
		strcpy(p->suit, "Blue");
		if (j == 10) {
			strcpy(p->action, "Skip");
		}
		else if (j == 11) {
			strcpy(p->action, "Reverse");
		}
		else if (j == 12) {
			strcpy(p->action, "Draw Two");
		}
		else {
			p->value = j;
		}
	}
	if (i == 5) {
		strcpy(p->action, "Wild");
	}
	if (i == 6) {
		strcpy(p->action, "Wild Draw Four");
	}


	p->pt = hl;
	hl = p;

	return hl;
}

card *create_deck(card *hl) {
	card *p = NULL;

	int k = 0, j, i;

	for (k = 0; k < 2; k++) {
		for (i = 1; i <= 4; i++) {
			for (j = k; j <= 12; j++) {
				hl = new_card(hl, i, j);
			}
		}
	}
	for (i = 5; i < 7; i++) {
		for (k = 1; k < 5; k++) {
			hl = new_card(hl, i, j);
		}
	}

	p = hl;

	while (p != NULL) {
		if (p->pt != NULL) {
			p = p->pt;
		}
		else {
			break;
		}
	}
	if (p->pt == NULL) {
		p->pt = hl;
	}

	return hl;
}

card *scan_file(FILE *in, card *hr) {
	card *p = NULL;
	p = (card *)malloc(sizeof(card));

	char line[30];

	while (!feof(in)) {
		fgets(line, 30, in);
		line[strlen(line) - 1] = '\0';
		if (strncmp(line, "Red", 3) == 0) {
			strcpy(p->suit, "Red");
			if (strstr(line, "0") != NULL) {
				p->value = 0;
			}
			else if (strstr(line, "1") != NULL) {
				p->value = 1;
			}
			else if (strstr(line, "2") != NULL) {
				p->value = 2;
			}
			else if (strstr(line, "3") != NULL) {
				p->value = 3;
			}
			else if (strstr(line, "4") != NULL) {
				p->value = 4;
			}
			else if (strstr(line, "5") != NULL) {
				p->value = 5;
			}
			else if (strstr(line, "6") != NULL) {
				p->value = 6;
			}
			else if (strstr(line, "7") != NULL) {
				p->value = 7;
			}
			else if (strstr(line, "8") != NULL) {
				p->value = 8;
			}
			else if (strstr(line, "9") != NULL) {
				p->value = 9;
			}
			else {
				if (strstr(line, "Draw Two") != NULL) {
					strcpy(p->action, "Draw Two");
				}
				else if (strstr(line, "Reverse") != NULL) {
					strcpy(p->action, "Reverse");
				}
				else {
					strcpy(p->action, "Skip");
				}
			}
		}
		else if (strncmp(line, "Blue", 4) == 0) {
			strcpy(p->suit, "Blue");
			if (strstr(line, "0") != NULL) {
				p->value = 0;
			}
			else if (strstr(line, "1") != NULL) {
				p->value = 1;
			}
			else if (strstr(line, "2") != NULL) {
				p->value = 2;
			}
			else if (strstr(line, "3") != NULL) {
				p->value = 3;
			}
			else if (strstr(line, "4") != NULL) {
				p->value = 4;
			}
			else if (strstr(line, "5") != NULL) {
				p->value = 5;
			}
			else if (strstr(line, "6") != NULL) {
				p->value = 6;
			}
			else if (strstr(line, "7") != NULL) {
				p->value = 7;
			}
			else if (strstr(line, "8") != NULL) {
				p->value = 8;
			}
			else if (strstr(line, "9") != NULL) {
				p->value = 9;
			}
			else {
				if (strstr(line, "Draw Two") != NULL) {
					strcpy(p->action, "Draw Two");
				}
				else if (strstr(line, "Reverse") != NULL) {
					strcpy(p->action, "Reverse");
				}
				else {
					strcpy(p->action, "Skip");
				}
			}
		}
		else if (strncmp(line, "Green", 5) == 0) {
			strcpy(p->suit, "Green");
			if (strstr(line, "0") != NULL) {
				p->value = 0;
			}
			else if (strstr(line, "1") != NULL) {
				p->value = 1;
			}
			else if (strstr(line, "2") != NULL) {
				p->value = 2;
			}
			else if (strstr(line, "3") != NULL) {
				p->value = 3;
			}
			else if (strstr(line, "4") != NULL) {
				p->value = 4;
			}
			else if (strstr(line, "5") != NULL) {
				p->value = 5;
			}
			else if (strstr(line, "6") != NULL) {
				p->value = 6;
			}
			else if (strstr(line, "7") != NULL) {
				p->value = 7;
			}
			else if (strstr(line, "8") != NULL) {
				p->value = 8;
			}
			else if (strstr(line, "9") != NULL) {
				p->value = 9;
			}
			else {
				if (strstr(line, "Draw Two") != NULL) {
					strcpy(p->action, "Draw Two");
				}
				else if (strstr(line, "Reverse") != NULL) {
					strcpy(p->action, "Reverse");
				}
				else {
					strcpy(p->action, "Skip");
				}
			}
		}
		else if (strncmp(line, "Yellow", 6) == 0) {
			strcpy(p->suit, "Yellow");
			if (strstr(line, "0") != NULL) {
				p->value = 0;
			}
			else if (strstr(line, "1") != NULL) {
				p->value = 1;
			}
			else if (strstr(line, "2") != NULL) {
				p->value = 2;
			}
			else if (strstr(line, "3") != NULL) {
				p->value = 3;
			}
			else if (strstr(line, "4") != NULL) {
				p->value = 4;
			}
			else if (strstr(line, "5") != NULL) {
				p->value = 5;
			}
			else if (strstr(line, "6") != NULL) {
				p->value = 6;
			}
			else if (strstr(line, "7") != NULL) {
				p->value = 7;
			}
			else if (strstr(line, "8") != NULL) {
				p->value = 8;
			}
			else if (strstr(line, "9") != NULL) {
				p->value = 9;
			}
			else {
				if (strstr(line, "Draw Two") != NULL) {
					strcpy(p->action, "Draw Two");
				}
				else if (strstr(line, "Reverse") != NULL) {
					strcpy(p->action, "Reverse");
				}
				else {
					strcpy(p->action, "Skip");
				}
			}
		}
		else if (strncmp(line, "Wild Draw Four", 14) == 0) {
			strcpy(p->action, "Wild Draw Four");
		}
		else {
			strcpy(p->action, "Wild");
		}

		p->pt = hr;
		hr = p;
		p = (card *)malloc(sizeof(card));
	}

	card *h = NULL;
	h = hr;

	for (int i = 1; i < 109; i++) {
		if (h->pt == NULL) {
			h->pt = hr;
		}
		else {
			h = h->pt;
		}
	}

	return hr;
}

void print_func(card *h) {
	card *p = NULL;
	int count = 1;
	p = h;

	while (p->pt != h) { // traversing the list
		if (p->value >= 0 && p->value <= 9) {
			printf("\t%d) %s %d\n", count, p->suit, p->value);
		}
		else if (strcmp(p->suit, "Red") == 0 || strcmp(p->suit, "Yellow") == 0 || strcmp(p->suit, "Blue") == 0 || strcmp(p->suit, "Green") == 0) {
			printf("\t%d) %s %s\n", count, p->suit, p->action);
		}
		else {
			printf("\t%d) %s\n", count, p->action);
		}
		p = p->pt;
		count++;
	}
	if (p->value >= 0 && p->value <= 9) {
		printf("\t%d) %s %d\n", count, p->suit, p->value);
	}
	else if (strcmp(p->suit, "Red") == 0 || strcmp(p->suit, "Yellow") == 0 || strcmp(p->suit, "Blue") == 0 || strcmp(p->suit, "Green") == 0) {
		printf("\t%d) %s %s\n", count, p->suit, p->action);
	}
	else {
		printf("\t%d) %s\n", count, p->action);
	}
	printf("\n");
}

int rand_gen(int max) {
	double frac;
	int a;
	frac = (double)rand() / ((double)RAND_MAX + 1);
	a = (floor(max * frac)); //random number in [0, max]
	if (a == 0) {
		return 1;
	}
	else {
		return a;
	}
}

int HandLength(card *player);

card *getNode(card **h, int i) {
	card *p = NULL, *m = NULL;
	m = *h;

	if (HandLength(*h) == 1) {
		p = *h;
	}
	else if (i == 1) {
		p = *h;
		while ((*h)->pt != m) {
			*h = (*h)->pt;
		}
		(*h)->pt = (*h)->pt->pt;
		*h = (*h)->pt;
	}
	else {
		for (int j = 1; j < i; j++) {

			if (j == i - 1) {
				p = (*h)->pt;
				(*h)->pt = (*h)->pt->pt;
			}
			else if ((*h)->pt != NULL) {
				*h = (*h)->pt;
			}
		}
		while (*h != m) {
			*h = (*h)->pt;
		}
	}

	return p;
}

card *swap(card **ptr, card *new, int i) {
	card *s = NULL, *z = NULL;

	s = (card *)malloc(sizeof(card));

	z = getNode(ptr, i);

	strcpy(s->suit, z->suit);
	s->value = z->value;
	strcpy(s->action, z->action);

	if (new == NULL) {
		s->pt = NULL;
	}
	s->pt = new;
	new = s;

	return new;
}

card *shuffle(card *head, int length) {
	card *newlist = NULL, *ptr = NULL, *hd = NULL;
	int count = 0, lengthTemp = length;

	newlist = (card *)malloc(sizeof(card));
	int i;
	for (int z = 0; z < lengthTemp; z++) {
		i = rand_gen(length);
		newlist = swap(&head, newlist, i);
		length--;
	}
	hd = newlist;
	for (int i = 1; i < lengthTemp; i++) {
		ptr = newlist->pt;
		newlist = newlist->pt;
		count++;
	}
	newlist->pt = hd;

	return newlist;
}

void deal_deck(card **hp, card **player1, card **player2) { // takes pointers to start of deck, player 1 hand, and player 2 hand. Deals 7 cards to each player.

	card *temp = NULL;


	for (int i = 1; i <= 7; i++) {
		temp = getNode(hp, 1);
		temp->pt = *player1;
		*player1 = temp;
		temp = getNode(hp, 1);
		temp->pt = *player2;
		*player2 = temp;
	}
	temp = *player1;
	while (temp->pt != NULL) {
		temp = temp->pt;
	}
	temp->pt = *player1;
	temp = *player2;
	while (temp->pt != NULL) {
		temp = temp->pt;
	}
	temp->pt = *player2;
}

int HandLength(card *player) {
	card *Temp;
	int count = 1;
	Temp = player;
	while ((Temp->pt != player) && (Temp->pt != NULL)) {
		count++;
		Temp = Temp->pt;
	}
	return count;
}

int cardValidity(int cardNumber, card *player, card *discardPile, char *color) { // takes pointer to the card played and to the discard pile. Returns 1 if the card is able to be played.
	card *Temp = player;
	int length = HandLength(player);
	if (cardNumber > length) {
		return 0;
	}
	if (cardNumber != 1) {
		for (int i = 1; i < cardNumber; i++) {
			Temp = Temp->pt;
		}
	}

	if (strcmp(discardPile->action, "Wild Draw Four") != 0 && strcmp(discardPile->action, "Wild") != 0) {
		if (Temp->value >= 0 && Temp->value <= 9) {
			if (Temp->value == discardPile->value || strcmp(Temp->suit, discardPile->suit) == 0) {
				return 1;
			}
		}
		else if (strcmp(Temp->suit, "Red") == 0 || strcmp(Temp->suit, "Yellow") == 0 || strcmp(Temp->suit, "Blue") == 0 || strcmp(Temp->suit, "Green") == 0) {
			if (strcmp(Temp->suit, discardPile->suit) == 0 || strcmp(Temp->action, discardPile->action) == 0) {
				return 1;
			}
		}
		else {
			if (strcmp(Temp->action, "Wild") == 0 || strcmp(Temp->action, "Wild Draw Four") == 0) {
				return 1;
			}
		}
	}
	else if (strcmp(Temp->suit, color) == 0 || strcmp(Temp->action, "Wild") == 0 || strcmp(Temp->action, "Wild Draw Four") == 0) {
		return 1;
	}
	return 0;
}

int handValidity(card *player, card *discardPile, char *color) {
	card *p = NULL;
	int j = 0, t = 0;

	p = player;

	for (int i = 1; i <= HandLength(player); i++) {
		if (strcmp(p->action, "Wild Draw Four") != 0) {
			if (cardValidity(i, player, discardPile, color) == 1) {
				t = 1;
			}
		}
		else {
			j = 1;
		}
		p = p->pt;
	}
	if (j == 1 && t == 1) {
		return 2;
	}
	else if (j == 0 && t == 1) {
		return 1;
	}
	else if (j == 1 && t == 0) {
		return 1;
	}

	return 0;
}

void card_Action(card **head, int cardNumber, card **discardPile, card **playerTurn, card **player2, int *playerNumber, char *color) { // try color as numbers or change pointers
	card *Temp = getNode(playerTurn, cardNumber);
	card *Draw = NULL, *TempCard = NULL;
	int count = 1;
	card *discardHead = NULL;
	Temp->pt = *discardPile;
	while (count < HandLength(*discardPile)) {
		*discardPile = (*discardPile)->pt;
		count++;
	}
	(*discardPile)->pt = Temp;
	*discardPile = Temp;
	discardHead = *discardPile;
	count = 1;
	while (count < HandLength(*discardPile)) {
		*discardPile = (*discardPile)->pt;
		count++;
	}
	(*discardPile)->pt = discardHead;
	*discardPile = (*discardPile)->pt;
	if ((strcmp(Temp->action, "Reverse") == 0) || (strcmp(Temp->action, "Skip") == 0)) {
		*playerNumber = *playerNumber * -1;
	}
	else if (strcmp(Temp->action, "Draw Two") == 0) {
		for (int i = 1; i <= 2; i++) {
			if (HandLength(*head) == 1) {
				Draw = getNode(head, 1);
				Draw->pt = *player2;
				count = 1;
				while (count < HandLength(*player2)) {
					*player2 = (*player2)->pt;
					count++;
				}
				(*player2)->pt = Draw;
				*player2 = Draw;
				printf("Shuffling\n\n");
				TempCard = getNode(discardPile, 1);
				TempCard->pt = TempCard;
				*discardPile = shuffle(*discardPile, (107 - CardsinHands(*playerTurn, *player2)));
				*head = *discardPile;
				*discardPile = TempCard;
				TempCard = NULL;
			}
			else {
				Draw = getNode(head, 1);
				Draw->pt = *player2;
				count = 1;
				while (count < HandLength(*player2)) {
					*player2 = (*player2)->pt;
					count++;
				}
				(*player2)->pt = Draw;
				*player2 = Draw;
			}
		}
		*playerNumber = *playerNumber * -1;
	}
	else if (strcmp(Temp->action, "Wild") == 0) {
		printf("What color would you like? ");
		scanf("%s", color);
		while (strcmp(color, "Red") != 0 && strcmp(color, "Yellow") != 0 && strcmp(color, "Green") != 0 && strcmp(color, "Blue") != 0) {
			printf("Not an UNO color!\n");
			printf("What color would you like (Red, Yellow, Green, Blue): ");
			scanf("%s", color);
		}
	}
	else if (strcmp(Temp->action, "Wild Draw Four") == 0) {
		for (int j = 1; j <= 4; j++) {
			if (HandLength(*head) == 1) {
				Draw = getNode(head, 1);
				Draw->pt = *player2;
				count = 1;
				while (count < HandLength(*player2)) {
					*player2 = (*player2)->pt;
					count++;
				}
				(*player2)->pt = Draw;
				*player2 = Draw;
				printf("Shuffling\n\n");
				TempCard = getNode(discardPile, 1);
				TempCard->pt = TempCard;
				*discardPile = shuffle(*discardPile, (107 - CardsinHands(*playerTurn, *player2)));
				*head = *discardPile;
				*discardPile = TempCard;
				TempCard = NULL;
			}
			else {
				Draw = getNode(head, 1);
				Draw->pt = *player2;
				count = 1;
				while (count < HandLength(*player2)) {
					*player2 = (*player2)->pt;
					count++;
				}
				(*player2)->pt = Draw;
				*player2 = Draw;
			}
		}
		*playerNumber = *playerNumber * -1;
		printf("What color would you like? ");
		scanf("%s", color);
		while (strcmp(color, "Red") != 0 && strcmp(color, "Yellow") != 0 && strcmp(color, "Green") != 0 && strcmp(color, "Blue") != 0) {
			printf("Not an UNO color!\n");
			printf("What color would you like (Red, Yellow, Green, Blue): ");
			scanf("%s", color);
		}
	}

}

int CardsinHands(card *player1, card *player2) { // returns the amount of cards being held in players hands
	card *Temp1, *Temp2;
	int count = 2;
	Temp1 = player1;
	Temp2 = player2;
	while (Temp1->pt != player1) {
		count++;
		Temp1 = Temp1->pt;
	}
	while (Temp2->pt != player2) {
		count++;
		Temp2 = Temp2->pt;
	}
	return count;
}

void printDiscardPile(card *discardPile) {
	int count = 0;
	card *p = discardPile;
	if (HandLength(discardPile) > 5) {
		while (count < 5) { // traversing the list
			if (p->value >= 0 && p->value <= 9) {
				printf("\t%s %d\n", p->suit, p->value);
			}
			else if (strcmp(p->suit, "Red") == 0 || strcmp(p->suit, "Yellow") == 0 || strcmp(p->suit, "Blue") == 0 || strcmp(p->suit, "Green") == 0) {
				printf("\t%s %s\n", p->suit, p->action);
			}
			else {
				printf("\t%s\n", p->action);
			}
			p = p->pt;
			count++;
		}
	}
	else {
		while (count < HandLength(discardPile)) {
			if (p->value >= 0 && p->value <= 9) {
				printf("\t%s %d\n", p->suit, p->value);
			}
			else if (strcmp(p->suit, "Red") == 0 || strcmp(p->suit, "Yellow") == 0 || strcmp(p->suit, "Blue") == 0 || strcmp(p->suit, "Green") == 0) {
				printf("\t%s %s\n", p->suit, p->action);
			}
			else {
				printf("\t%s\n", p->action);
			}
			p = p->pt;
			count++;
		}
	}


	printf("\n");
}

int Scoring(card *player) {
	int score = 0;
	card *Temp;

	Temp = player;

	while (Temp->pt != player) {
		for (int i = 0; i < 10; i++) {
			if (Temp->value == i) {
				score = score + i;
			}
		}
		if (strcmp(Temp->action, "Skip") == 0 || strcmp(Temp->action, "Reverse") == 0 || strcmp(Temp->action, "Draw Two") == 0) {
			score = score + 20;
		}
		else if (strcmp(Temp->action, "Wild Draw Four") == 0 || strcmp(Temp->action, "Wild") == 0) {
			score = score + 50;
		}
		Temp = Temp->pt;
	}
	for (int i = 0; i < 10; i++) {
		if (Temp->value == i) {
			score = score + i;
		}
	}
	if (strcmp(Temp->action, "Skip") == 0 || strcmp(Temp->action, "Reverse") == 0 || strcmp(Temp->action, "Draw Two") == 0) {
		score = score + 20;
	}
	else if (strcmp(Temp->action, "Wild Draw Four") == 0 || strcmp(Temp->action, "Wild") == 0) {
		score = score + 50;
	}

	return score;
}

int main() {
	srand((int)time(NULL));
	card *headl = NULL, *discardPile = NULL;
	card *player1 = NULL, *player2 = NULL, *TempCard = NULL, *Temp2 = NULL;
	FILE *inFile;
	int playerTurn = 1, WinStatus = 0, num, cardNumber, counter = 1, check, score1 = 0, score2 = 0, score = 0, roundStatus = 1;
	char playStatus = 'y', d, color[7];

	printf("\n\t\tIt's time to play UNO!\n\n");

	printf("Shuffle deck (1) or load deck (2): ");
	scanf("%d", &num);
	if (num == 1) {
		headl = create_deck(headl);
		headl = shuffle(headl, 108);
	}
	else {
		inFile = fopen("deck.txt", "r");
		headl = scan_file(inFile, headl);
		fclose(inFile);
	}

	printf("Press Any Key to Deal Deck...\n");
	getch();
	deal_deck(&headl, &player1, &player2);

	discardPile = getNode(&headl, 1);
	discardPile->pt = discardPile;

	if (strcmp(discardPile->action, "Skip") == 0 || strcmp(discardPile->action, "Reverse") == 0) {
		playerTurn = playerTurn * -1;
	}
	else if (strcmp(discardPile->action, "Draw Two") == 0) {
		card_Action(&headl, 1, &discardPile, &discardPile, &player1, &playerTurn, &color);
	}
	else if (strcmp(discardPile->action, "Wild") == 0) {
		printf("PLAYER 1's HAND: \n\n");
		print_func(player1);
		printf("First card is Wild. Player 1 choose color to start.\n");
		printf("What color would you like? ");
		scanf("%s", color);
		while (strcmp(color, "Red") != 0 && strcmp(color, "Yellow") != 0 && strcmp(color, "Green") != 0 && strcmp(color, "Blue") != 0) {
			printf("Not an UNO color!\n");
			printf("What color would you like (Red, Yellow, Green, Blue): ");
			scanf("%s", color);
		}
	}
	while (strcmp(discardPile->action, "Wild Draw Four") == 0) {
		printf("Wild Draw Four is first card, reshuffling.\n\n");
		TempCard = getNode(&discardPile, 1);
		TempCard->pt = headl;
		Temp2 = headl;
		while (headl->pt != Temp2) {
			headl = headl->pt;
		}
		headl->pt = TempCard;
		headl = TempCard;
		headl = shuffle(headl, 94);
		Temp2 = getNode(&headl, 1);
		Temp2->pt = discardPile;
		Temp2->pt->pt = Temp2;
		discardPile = Temp2;
		TempCard = getNode(&discardPile, 2);
		TempCard = NULL;
		Temp2 = NULL;
	}


	while (score1 < 500 && score2 < 500 && (playStatus == 'y')) {
		if (roundStatus == -1) {
			printf("Shuffle deck (1) or load deck (2): ");
			scanf("%d", &num);
			free(headl);
			free(discardPile);
			free(player1);
			free(player2);
			headl = NULL;
			discardPile = NULL;
			player1 = NULL;
			player2 = NULL;
			if (num == 1) {
				headl = create_deck(headl);
				headl = shuffle(headl, 108);
			}
			else {
				inFile = fopen("deck.txt", "r");
				headl = scan_file(inFile, headl);
				fclose(inFile);
			}

			printf("Press Any Key to Deal Deck...\n");
			getch();
			deal_deck(&headl, &player1, &player2);

			discardPile = getNode(&headl, 1);
			discardPile->pt = discardPile;

			if (strcmp(discardPile->action, "Skip") == 0 || strcmp(discardPile->action, "Reverse") == 0) {
				playerTurn = playerTurn * -1;
			}
			else if (strcmp(discardPile->action, "Draw Two") == 0) {
				card_Action(&headl, 1, &discardPile, &discardPile, &player1, &playerTurn, &color);
			}
			else if (strcmp(discardPile->action, "Wild") == 0) {
				printf("PLAYER 1's HAND: \n\n");
				print_func(player1);
				printf("First card is Wild. Player 1 choose color to start.\n");
				printf("What color would you like? ");
				scanf("%s", color);
				while (strcmp(color, "Red") != 0 && strcmp(color, "Yellow") != 0 && strcmp(color, "Green") != 0 && strcmp(color, "Blue") != 0) {
					printf("Not an UNO color!\n");
					printf("What color would you like (Red, Yellow, Green, Blue): ");
					scanf("%s", color);
				}
			}
			while (strcmp(discardPile->action, "Wild Draw Four") == 0) {
				printf("Wild Draw Four is first card, reshuffling.\n\n");
				TempCard = getNode(&discardPile, 1);
				TempCard->pt = headl;
				Temp2 = headl;
				while (headl->pt != Temp2) {
					headl = headl->pt;
				}
				headl->pt = TempCard;
				headl = TempCard;
				headl = shuffle(headl, 94);
				Temp2 = getNode(&headl, 1);
				Temp2->pt = discardPile;
				Temp2->pt->pt = Temp2;
				discardPile = Temp2;
				TempCard = getNode(&discardPile, 2);
				TempCard = NULL;
				Temp2 = NULL;
			}

			roundStatus = roundStatus * -1;
		}
		cardNumber = 25;

		printf("----------------------------------\n");

		if (playerTurn == 1) {
			printf("PLAYER 1's HAND: \n\n");
			print_func(player1);
		}
		else {
			printf("PLAYER 2's HAND: \n\n");
			print_func(player2);
		}
		printf("Discard Pile: \n\n");
		printDiscardPile(discardPile);

		if (strcmp(discardPile->action, "Wild Draw Four") == 0 || strcmp(discardPile->action, "Wild") == 0) {
			printf("Color is now: %s\n", color);
		}

		if (HandLength(player1) == 1 && playerTurn != 1) {
			printf("Player 1 has...\n");
			printf("(Press Any Button)\n");
			getch();
			printf("____         ____  ______      ____  ___________________\n");
			printf("|  |         |  |  |     \\     |  |  |  ____________   |\n");
			printf("|  |         |  |  |  |\\  \\    |  |  |  |           |  |\n");
			printf("|  |         |  |  |  | \\  \\   |  |  |  |           |  |\n");
			printf("|  |         |  |  |  |  \\  \\  |  |  |  |           |  |\n");
			printf("|  |         |  |  |  |   \\  \\ |  |  |  |           |  |\n");
			printf("|  |_________|  |  |  |    \\  \\|  |  |  |___________|  |\n");
			printf("|_______________|  |__|     \\_____|  |_________________|\n");
			printf("\n\n");
		}
		if (HandLength(player2) == 1 && playerTurn == 1) {
			printf("Player 2 has...\n");
			printf("(Press Any Button)\n");
			getch();
			printf("____         ____  ______      ____  ___________________\n");
			printf("|  |         |  |  |     \\     |  |  |  ____________   |\n");
			printf("|  |         |  |  |  |\\  \\    |  |  |  |           |  |\n");
			printf("|  |         |  |  |  | \\  \\   |  |  |  |           |  |\n");
			printf("|  |         |  |  |  |  \\  \\  |  |  |  |           |  |\n");
			printf("|  |         |  |  |  |   \\  \\ |  |  |  |           |  |\n");
			printf("|  |_________|  |  |  |    \\  \\|  |  |  |___________|  |\n");
			printf("|_______________|  |__|     \\_____|  |_________________|\n");
			printf("\n\n");
		}

		if (playerTurn == 1) {
			if (handValidity(player1, discardPile, color) == 1 || handValidity(player1, discardPile, color) == 2) {
				if (HandLength(player1) == 1) {
					printf("Player 1 wins\n");
					score = Scoring(player2);
					score1 = score + score1;
					printf("Player 1 score: %d\n", score1);
					printf("Player 2 score: %d\n", score2);
					printf("Would you like to play again? (y or n) ");
					scanf(" %c", &playStatus);
					roundStatus = roundStatus * -1;
				}
				else {
					while (cardValidity(cardNumber, player1, discardPile, color) != 1) {

						printf("Which card would you like to play? (1-%d) ", HandLength(player1));
						check = scanf("%*c%d", &cardNumber);
						while (check != 1) {
							printf("Not a number.\nPick another number: ");
							check = scanf("%*c%d", &cardNumber);
						}
						if (handValidity(player1, discardPile, color) == 2) {
							TempCard = player1;
							if (cardNumber != 1) {
								for (int i = 1; i < cardNumber; i++) {
									TempCard = TempCard->pt;
								}
							}
							if (strcmp(TempCard->action, "Wild Draw Four") == 0) {
								printf("Another card is playable before Wild Draw Four. Please choose again.\n");
								cardNumber = 50;
							}
						}
						else if (cardValidity(cardNumber, player1, discardPile, color) != 1) {
							printf("Unable to play that card\n");
						}
					}
					card_Action(&headl, cardNumber, &discardPile, &player1, &player2, &playerTurn, &color);
				}
			}
			else {
				printf("No cards in hand are playable.\nDraw Card.\n");
				if (HandLength(headl) == 1) {
					TempCard = getNode(&headl, 1);
					TempCard->pt = player1;
					counter = 1;
					while (counter < HandLength(player1)) {
						player1 = player1->pt;
						counter++;
					}
					player1->pt = TempCard;
					player1 = TempCard;
					TempCard = getNode(&discardPile, 1);
					TempCard->pt = TempCard;
					shuffle(discardPile, (107 - CardsinHands(player1, player2)));
					headl = discardPile;
					discardPile = TempCard;
					TempCard = NULL;

					printf("DECK RESHUFFLED\n");
				}
				else {
					TempCard = getNode(&headl, 1);
					TempCard->pt = player1;
					counter = 1;
					while (counter < HandLength(player1)) {
						player1 = player1->pt;
						counter++;
					}
					player1->pt = TempCard;
					player1 = TempCard;
				}
				printf("Press Any Key to Continue...\n");
				getch();
			}

		}
		else {
			if (handValidity(player2, discardPile, color) == 1 || handValidity(player2, discardPile, color) == 2) {
				if (HandLength(player2) == 1) {
					printf("Player 2 wins\n");
					score = Scoring(player1);
					score2 = score + score2;
					printf("Player 1 score: %d\n", score1);
					printf("Player 2 score: %d\n", score2);
					printf("Would you like to play again? (y or n) ");
					scanf(" %c", &playStatus);
					roundStatus = roundStatus * -1;
				}
				else {
					while (cardValidity(cardNumber, player2, discardPile, color) != 1) {

						printf("Which card would you like to play? (1-%d) ", HandLength(player2));
						check = scanf("%*c%d", &cardNumber);
						while (check != 1) {
							printf("Not a number.\nPick another number: ");
							check = scanf("%*c%d", &cardNumber);
						}
						if (handValidity(player2, discardPile, color) == 2) {
							TempCard = player2;
							if (cardNumber != 1) {
								for (int i = 1; i < cardNumber; i++) {
									TempCard = TempCard->pt;
								}
							}
							if (strcmp(TempCard->action, "Wild Draw Four") == 0) {
								printf("Another card is playable before Wild Draw Four. Please choose again.\n");
								cardNumber = 50;
							}
						}
						else if (cardValidity(cardNumber, player2, discardPile, color) != 1) {
							printf("Unable to play that card\n");
						}
					}
					card_Action(&headl, cardNumber, &discardPile, &player2, &player1, &playerTurn, &color);
				}
			}
			else {
				printf("No cards in hand are playable.\nDraw Card.\n");
				if (HandLength(headl) == 1) {
					TempCard = getNode(&headl, 1);
					TempCard->pt = player2;
					counter = 1;
					while (counter < HandLength(player1)) {
						player2 = player2->pt;
						counter++;
					}
					player2->pt = TempCard;
					player2 = TempCard;
					TempCard = getNode(&discardPile, 1);
					TempCard->pt = TempCard;
					shuffle(discardPile, (107 - CardsinHands(player1, player2)));
					headl = discardPile;
					discardPile = TempCard;
					TempCard = NULL;

					printf("DECK RESHUFFLED\n");
				}
				else {
					TempCard = getNode(&headl, 1);
					TempCard->pt = player2;
					counter = 1;
					while (counter < HandLength(player2)) {
						player2 = player2->pt;
						counter++;
					}
					player2->pt = TempCard;
					player2 = TempCard;
				}
				printf("Press Any Key to Continue...\n");
				getch();
			}
		}
		playerTurn = playerTurn * -1;
	}

	if (score1 >= 500) {
		printf("\n\nPLAYER 1 WINS UNO!!!!\n\n");
	}
	if (score2 >= 500) {
		printf("\n\nPLAYER 2 WINS UNO!!!!\n\n");
	}

	printf("Goodbye\n");

	free(headl);
	free(discardPile);
	free(player1);
	free(player2);

	return(0);
}