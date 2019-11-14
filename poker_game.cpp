// You are given the following problem statement:
// Develop the design of the cards, deck, shuffle, and deal of the game of Battle Cards.
// Battle Cards has the following rules:
// 1. There are K (at least 2) players who alternate being dealer.
// 2. The deck has 52 cards with 4 suits and 13 cards per suit.
// 3. Before each game the deck is shuffled by the dealer.
// 4. The deal starts with the non-dealer and alternates between dealer and non-dealer. All cards are dealt from the deck.
// 5. The players may not look at their cards.
// 6. The game is made up of a series of battles.
// 7. Each battle is played to its conclusion. At the end of a battle if a player has less than 5 cards they are out of the game.
// 8. Every player participates in a battle by putting 1 card on the table face up.
// The player with the lowest card wins the battle. The Ace is the lowest card in a suit and the king is the highest. If there is a tie for lowest card, 
// both the players play one more cards on to the table face down and another face up. The last card of the two played are then compared.
// The lowest wins. This step can be repeated until the battle is won.
// 9. The player winning the battle gets all the cards on the table.
// 10. If during a battle, a player does not have enough cards to continue, they are
// out of the game and the game is over.
// 11. The game is over when there is only one player left.

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <unordered_set>
using namespace std;


#define CONSOLE 0
#define FILESTREAM 1

ofstream out("data1.txt");

class card
{
public:
	int number;
	int suit;
	static int uniquenumber;
	card();
	void showcard(int where);
	card * next;
};

class collection
{
public:
	card * start;
	int numberofcards;
	collection(int x);
	collection() { start = nullptr; numberofcards = 0; }
	void showcollection(int where);
	void shuffle();
	card deal();
	void add(card a);
};

card::card()
{
	number = uniquenumber % 13;
	suit = (uniquenumber / 13);
	uniquenumber++;
	next = nullptr;
}

//Print card
void card::showcard(int where)
{
    if(where==FILESTREAM)
    {
        switch (number)
        {
            case 0: out << "A"; break;  // Ace is low
            case 10: out << "J"; break; // Jack
            case 11: out << "Q"; break; // Queen
            case 12: out << "K"; break; // King
            default: out << (number + 1); break;
        }

        //4 suits
        switch (suit) 
        {
            case 0: out << "S "; break;//Spades
            case 1: out << "H "; break;//Hearts
            case 2: out << "D "; break;//Diamonds
            case 3: out << "C "; break;//Clubs
        }
    }

    if(where==CONSOLE)
    {
        switch (number)
        {
            case 0: out << "A"; break;  // Ace is low
            case 10: out << "J"; break; // Jack
            case 11: out << "Q"; break; // Queen
            case 12: out << "K"; break; // King
            default: out << (number + 1); break;
        }

        //4 suits
        switch (suit) 
        {
            case 0: out << "S "; break;//Spades
            case 1: out << "H "; break;//Hearts
            case 2: out << "D "; break;//Diamonds
            case 3: out << "C "; break;//Clubs
        }
    }
    
}

collection::collection(int x)
{
	start = nullptr;

	numberofcards = 0;
	for (int i = 0; i<x; i++)
	{
		card temp;
		add(temp);
	}
}

void collection::showcollection(int where)
{
    int i;
    card * temp;
    temp = start;
    for (i = 0; i<numberofcards; i++)
    {
        temp->showcard(where);
        temp = temp->next;
    }
}

void collection::add(card a)
{
	/*Add a card to the front of the linked list.*/
    card* new_card=new card(a);// shallow copy
    new_card->next=start;
    start=new_card;

    numberofcards++;
}


void collection::shuffle()
{
	/*Randomize the sequence of cards in the deck.*/
	card *temp2, *temp3;
	temp2 = start;
	temp3 = temp2;
	int i, j, k;
	char c1;
	int num;
	for (i = numberofcards; i>1; i--) {
		j = rand() % i;
		for (k = 0; k <= j - 1; k++)
			temp3 = temp3->next;
		c1 = temp2->suit;
		num = temp2->number;
		temp2->suit = temp3->suit;
		temp2->number = temp3->number;
		temp3->suit = c1;
		temp3->number = num;
		temp2 = temp2->next;
		temp3 = temp2;
	}
	// Reorganize cards in array randomly
}

// Remove a card from the front of the linked list, and return the card
card collection::deal()
{
    card* front=start;
    if(start!=nullptr)  start=start->next;
    numberofcards--;

    return *front;
}



int card::uniquenumber = 0;//这是干嘛用的？

void deal_cards(int k, int d, collection &deck, collection *hand);
void battle(int k, collection *hand, collection *table);
void Enter_Num_players_Dealer(int &k_players, int &dealer);
void Show_Initial_Deck_Hands(int &k_players, int &dealer, collection &deck, collection * hand, collection * table);


void Show_Initial_Deck_Hands(int &k_players, int &dealer, collection &deck, collection * hand, collection * table) {
	out << "\n\n************** initial deck of cards before shuffle ****\n\n";
	deck.showcollection(FILESTREAM);
	deck.shuffle(); // Shuffle cards in deck
	out << "\n\n****************** after shuffle **************\n\n";
	deck.showcollection(FILESTREAM);
	out << "\n\n****************** after cards are dealt **************\n\n";
	deal_cards(k_players, dealer, deck, hand);
	for (int i = 0; i< k_players; i++)
	{
		out << "\ncards for player " << i + 1 << "\n";
		hand[i].showcollection(FILESTREAM);
	}

}

void Enter_Num_players_Dealer(int &num_players, int &dealer) 
{
	do {
		cout << "Enter the number (2-10) of players ";
		cin >> num_players;
		if (num_players > 10 || num_players < 2)
			out << "Illegal player number. Enter again\n\n";
	} while (num_players >10 || num_players < 2);

	do {
		cout << "Enter initial dealer (1-k)";
		cin >> dealer;
		if (dealer < 1 || dealer > num_players)
			out << "Illegal dealer ID. Enter again\n\n";
	} while (dealer < 1 || dealer > num_players);
}


void battle(int k, collection *hand, collection *table) 
{ 
    bool gameover=false;
    unordered_set<int> insiders;
    unordered_set<int> tiers;
    unordered_set<int> outters;
    int winner=0;
    int players=k;
    bool tie=false;

    //游戏逻辑(有些乱):
    //如果该玩家手中的牌数小于5，则该玩家出局
    //只要有玩家手中没有足够的牌以供出牌，那么他们将出局
    //所有剩下的玩家中，所出的牌最小的玩家获胜，
    //若平局，则平局者继续各出两张牌，比较后来face-up的那两张张牌,直到游戏结束。
    //如果只剩下一个玩家, 那么游戏自动结束，该玩家自动成为赢家
    //每个玩家都有各自的桌子
    //赢家收走桌上所有的牌

    int round=1;
    while(players>1)
    {
        //Show table
        // out << "\n\ntable " << endl;
        // table->showcollection(FILESTREAM);
        // cout<< "\n\ntable " << endl;
        // table->showcollection(CONSOLE);

        cout << "Show Round: " << round <<endl;
        round++;
        insiders.clear();
        tiers.clear();
        //

        //每局都要重新计算insider和outter
        //这里用来干嘛?
        for(int i=0;i<k;i++)
        {
            cout << "\n\nHand " << i << endl;
            hand[i].showcollection(CONSOLE);
            out << "\n\nHand " << i << endl;
            hand[i].showcollection(FILESTREAM);
        }


        //每个玩家出一张牌
        //若未平局
        if(tie==false)
        {
            for(int i=0;i<k;i++)
            {
                if(hand[i].numberofcards!=0)
                {
                    insiders.insert(i);
                    //将新牌放入每个player的桌子
                    table[i].add(hand[i].deal());//
                }
            }

            //Show table
            for(int i=0;i<k;i++)
            {
                out<<"\n\ntable"<<i<<endl;
                table[i].showcollection(FILESTREAM);
                cout << "\n\ntable " << i + 1 << endl;
                table[i].showcollection(CONSOLE);
            }

            //print insiders
            cout << "\n curr_player: ";
            for (auto p: insiders)  cout << p << endl;


            //Find smallest porker
            //Selection sort
            //怎样从set中选出
            int min=table[insiders[]]

        }

        //如果平局,每个玩家各出两张牌
        if(tie==true)
        {
            for(int p: tiers)
            {
                //每个玩家一个桌子???
                //这里怎么理解?
                table[p].add(hand[p].deal());
                table[p].add(hand[p].deal());
            }

        }



    }


    string res="Game Over, the winner is "+ std::to_string(winner);
    cout<<res<<endl;
    out<<res<<endl;

    return;
}


void deal_cards(int k, int d, collection &deck, collection *hand) 
{
	//deal cards to each player
    //k is the total number of players
    //The deal starts with the non-dealer and alternates between
    //dealer and non-dealer. All cards are dealt from the deck.
    
    cout<<"Dealing cards..."<<endl;
    if(k<2) return;

    while(deck.numberofcards>0)
    {
        //Deal to dealder
        hand[d].add(deck.deal());
        //Deal to non-dealers
        for(int i=0;i<k;i++)
        {
            if(i==d) continue;
            else    hand[i].add(deck.deal());   
        }
    }

    return;
}

int main() 
{
	collection *hand, *table;
	int num_players, dealer, i, winner = 0;
	srand(time(0));
	Enter_Num_players_Dealer(num_players, dealer);
	collection deck(52);
	hand = new collection[num_players];
	table = new collection[num_players];
	Show_Initial_Deck_Hands(num_players, dealer, deck, hand, table);
	battle(num_players, hand, table);

	return 0;
}