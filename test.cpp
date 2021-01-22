#include <random>
#include <iostream>
#include <array>
#include <string>
#include "test.h"




using namespace std;


card deckCreate(card deck[]) {
	int a;
	for (int i = 0; i < 52; i++) {
		if (i < 13) {
			a = i;
			deck[i].suit = 'A';
			deck[i].rank = a + 2;
			if(a<9){
				deck[i].value = a + 2;
			}
			if ((a>=9)&&(a<12)) {
				deck[i].value = 10;
			}
			if (a == 12) {
				deck[i].value = 1;
			}
		}

		if ((i >= 13) && (i < 26)) {
			a = i - 13;
			deck[i].suit = 'B';
			deck[i].rank = a+2;
			if (a < 9) {
				deck[i].value = a + 2;
			}
			if ((a >= 9) && (a < 12)) {
				deck[i].value = 10;
			}
			if (a == 12) {
				deck[i].value = 1;
			}
		}


		

		if ((i >= 26) && (i < 39)) {
			a = i - 26;
			deck[i].suit = 'C';
			deck[i].rank = a + 2;
			if (a < 9) {
				deck[i].value = a + 2;
			}
			if ((a >= 9) && (a < 12)) {
				deck[i].value = 10;
			}
			if (a == 12) {
				deck[i].value = 1;
			}
		}

		

		if ((i >= 39) && (i < 52)) {
			a = i - 39;
			deck[i].suit = 'D';
			deck[i].rank = a + 2;
			if (a < 9) {
				deck[i].value = a + 2;
			}
			if ((a >= 9) && (a < 12)) {
				deck[i].value = 10;
			}
			if (a == 12) {
				deck[i].value = 1;
			}
		}

		
	
	}
	for (int i = 0; i < 52; i++) {
		return deck[i];
	}
}

void deckPrint(card deck[]) {

	for (int i = 0; i < 52; i++) {
		switch (deck[i].rank)
		{
		case 2:cout << "2 ";
			break;
		case 3:cout << "3 ";
			break;
		case 4:cout << "4 ";
			break;
		case 5:cout << "5 ";
			break;
		case 6:cout << "6 ";
			break;
		case 7:cout << "7 ";
			break;
		case 8:cout << "8 ";
			break;
		case 9:cout << "9 ";
			break;
		case 10:cout << "10 ";
			break;
		case 11:cout << "Валет ";
			break;
		case 12:cout << "Дама ";
			break;
		case 13:cout << "Король ";
			break;
		case 14:cout << "Туз ";
			break;
		}



			switch (deck[i].suit)
			{
			case 'A':cout << "Червей";
				break;
			case 'B':cout << "Буби";
				break;
			case 'C':cout << "Пик";
				break;
			case 'D':cout << "Крести";

			}
		
			cout << "(" << deck[i].value << ")\n";

	}
}


card deckShuffle(card deck[]) {
	card temp;
	int first, second;
	std::random_device rd;
	std::uniform_int_distribution<int> uid(0, 51);
	for (int i = 0; i < 200; i++) {
		first = uid(rd);
		second = uid(rd);
		temp = deck[first];
		deck[first] = deck[second];
		deck[second] = temp;

	}
	for (int i = 0; i < 51; i++)
		return deck[i];


}


player playerInit(player player) {
	player.score = 0;
	for (int i = 0; i < 10; i++) {
		player.cards[i].rank = 0;
		player.cards[i].suit = '0';
		player.cards[i].value = 0;
	}
	return player;
}
diller dillerInit(diller diller) {
	diller.score = 0;
	for (int i = 0; i < 10; i++) {
		diller.cards[i].rank = 0;
		diller.cards[i].suit = '0';
		diller.cards[i].value = 0;
	}
	return diller;
}

int playBlackJack(card deck[], player player, diller diller) {
	string playerChoise;
	int cardInitial =0;
	int playerBet;
	player=playerInit(player);
	diller=dillerInit(diller);
	cout << "Введите ставку игрока\n";
	cin >> playerBet;
	deckCreate(deck);
	deckPrint(deck);
	deckShuffle(deck);
	deckPrint(deck);
	diller=dillerStartPlay(diller, deck, cardInitial);
	cardInitial++;
	dillerInfo(diller);
	player = playerStartPlay(player, deck, cardInitial);
	cardInitial += 2;
	playerInfo(player);
	cout << "Взять ещё карту(hit) или оставить(stand) \n";
	cin >> playerChoise;
	if (playerChoise == "stand") {//не проверяется <=21
		//диллер не набирает
		//Диллер берёт
		//не выводится победа
		diller = dillerTakeCards(diller, deck, cardInitial);
		for (int i = 1; i < 10; i++) {
			if (diller.cards[i].rank != 0) {
				cardInitial++;
			}
		}
		dillerInfo(diller);
		gameResult(player, diller);
		player = playerMoney(player, diller, playerBet);
	}

	if (playerChoise == "hit") {
		while ((playerChoise != "stand")&&(player.score<22)) {
			
			cardInitial++;
			int init;
			for (int i = 0; i < 10; i++) {
				if (player.cards[i].rank == 0) {
					init = i;
					break;
				}
			}
			player.cards[init].rank = deck[cardInitial].rank;
			player.cards[init].suit = deck[cardInitial].suit;
			player.score = player.score + deck[cardInitial].value;
			playerInfo(player);//нет проверки на проигрыш игрока 
			                   //и не прибавляются/отнимаются деньги
			cout << "Взять ещё карту(hit) или оставить(stand) \n";
			cin >> playerChoise;
		}
		diller = dillerTakeCards(diller, deck, cardInitial);
		for (int i = 1; i < 10; i++) {
			if (diller.cards[i].rank != 0) {
				cardInitial++;
			}
		}
		dillerInfo(diller);
		gameResult(player, diller);
		player = playerMoney(player, diller, playerBet);

	}



	return player.money;
}






void playerInfo(player player) {
	cout << "Деньги игрока " << player.money<<endl;
	cout << "Очки игрока " << player.score<<endl;
	for (int i = 0; i < 10; i++) {
		cout << "Карта №" << i+1 << " " << player.cards[i].rank << " " << player.cards[i].suit<<endl;
	}
}

void dillerInfo(diller diller) {
	
		cout << "Очки Диллера " << diller.score<<endl;
	for (int i = 0; i < 10; i++) {
		cout << "Карта №" << i+1 << " " << diller.cards[i].rank << " " << diller.cards[i].suit << endl;
	}


}

diller dillerStartPlay(diller diller,card deck[],int cardInitial) {
	diller.cards[0].rank = deck[cardInitial].rank;
	diller.cards[0].suit = deck[cardInitial].suit;
	diller.score = diller.score + deck[cardInitial].value;

	return diller;
}
player playerStartPlay(player player, card deck[],int cardInitial) {
	for (int i = 0; i < 2; i++) {
		player.cards[i].rank = deck[cardInitial+i].rank;
		player.cards[i].suit = deck[cardInitial + i].suit;
		player.score = player.score + deck[cardInitial + i].value;
	}

	return player;
}


player playerMoney(player player, diller diller,int playerBet) {

	if ((player.score > diller.score) && (player.score < 22) && (diller.score < 22)) {
		player.money += playerBet;
		cout << "Деньги игрока " << player.money << endl;
	}
	if ((player.score < 22) && (diller.score >= 22)) {
		player.money += playerBet;
		cout << "Деньги игрока " << player.money << endl;
	}
	if ((player.score < diller.score) && (player.score < 22) && (diller.score < 22)) {
		player.money -= playerBet;
		cout << "Деньги игрока " << player.money << endl;
	}
	if ((player.score >= 22) && (diller.score < 22)) {
		player.money -= playerBet;
		cout << "Деньги игрока " << player.money << endl;
	}
	
	return player;
	
}
diller dillerTakeCards(diller diller,card deck[], int cardInitial) {
	while (diller.score <= 17) {
		cardInitial++;

		int init;
		for (int i = 0; i < 10; i++) {
			if (diller.cards[i].rank == 0) {
				init = i;
				break;
			}
		}

		diller.cards[init].rank = deck[cardInitial].rank;
		diller.cards[init].suit = deck[cardInitial].suit;
		diller.score = diller.score + deck[cardInitial].value;

	}

	return diller;
	
}
void gameResult(player player, diller diller) {
	if ((player.score > diller.score) && (player.score < 22) && (diller.score < 22)) {
		cout << "Игрок победил\n";
	}
	if ((player.score < 22) && (diller.score >= 22)) {
		cout << "Игрок победил\n";
	}
	if ((player.score < diller.score) && (player.score < 22) && (diller.score < 22)) {
		cout << "Игрок проиграл\n";
	}
	if ((player.score >= 22) && (diller.score < 22)) {
		cout << "Игрок проиграл\n";
	}
	if ((player.score == diller.score) && (player.score < 22) && (diller.score < 22)) {
		cout << "Ничья\n";
	}
	if ((player.score >= 22) && (diller.score >= 22)) {
		cout << "Ничья\n";
	}

}
