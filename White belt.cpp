#include "test.h"
#include <random>
#include <iostream>
#include <array>
#include <string>



using namespace std;

//A-ЧЕРВЫ
//B-БУБНЫ
//C-ПИКИ
//D-КРЕСТИ

/*
вывод в стандартных значениях
for (int i = 0; i < 52; i++) {
		cout << deck[i].suit << " " << deck[i].rank<<endl;
	}

*/

int main()
{
	setlocale(LC_ALL, "Russian");
	card deck[52];
	player player;
	diller diller;
	cout << "Введите количество денег\n";
	cin >> player.money;
	char symb='+';
	while (symb=='+'){
		diller.score = 0;
		player.score = 0;
		for (int i = 0; i < 10; i++) {
			player.cards[i].rank = 0;
			player.cards[i].suit = '0';
			player.cards[i].value = 0;
			diller.cards[i].rank = 0;
			diller.cards[i].suit = '0';
			diller.cards[i].value = 0;
		}


	player.money=playBlackJack(deck, player, diller);
	cout << "Играть? +/-" << endl;
	cin >> symb;
	}
	
	return 0;
}


