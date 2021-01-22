#pragma once

struct card {
	int rank;
	char suit;
	int value;
};
struct player {
	card cards[10];
	int score;
	int money;
};
struct diller {
	card cards[10];
	int score;
};
card deckCreate(card deck[]);
void deckPrint(card deck[]);
card deckShuffle(card deck[]);
player playerInit(player player);
diller dillerInit(diller diller);
int playBlackJack(card deck[], player player, diller diller);
void playerInfo(player player);
void dillerInfo(diller diller);
diller dillerStartPlay(diller diller,card deck[],int cardInitial);
player playerStartPlay(player player, card deck[],int cardInitial);
player playerMoney(player player, diller diller, int playerBet);
diller dillerTakeCards(diller diller, card deck[], int cardInitial);
void gameResult(player player, diller diller);