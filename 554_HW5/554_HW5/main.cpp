//HW5 Due: April 15, Sunday, at 11:59pm
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
using namespace std;

ofstream out("data1.txt");

class card
{
public:
    int number;
    int suit;
    static int uniquenumber;
    card();
    void showcard();
    card * next;
};

class collection
{
public:
    card * start;
    int numberofcards;
    collection(int x);
    collection() { start = nullptr; numberofcards = 0; }
    void showcollection();
    void shuffle();
    card deal();
    void add(card a);
};

card::card()
{
    number = uniquenumber % 13;//得到牌代号
    suit = (uniquenumber / 13);//得到花色
    uniquenumber++;
    next = nullptr;
}

void card::showcard()
{
    
    switch (number)
    {
        case 0: out << "A"; break;  // Ace is low
        case 10: out << "J"; break;
        case 11: out << "Q"; break;
        case 12: out << "K"; break;
        default: out << (number + 1); break;
    }
    
    switch (suit) {
        case 0: out << "S "; break;
        case 1: out << "H "; break;
        case 2: out << "D "; break;
        case 3: out << "C "; break;
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

void collection::showcollection()
{
    int i;
    card * temp;
    temp = start;
    for (i = 0; i<numberofcards; i++)
    {
        temp->showcard();
        temp = temp->next;
    }
}

void collection::add(card a)
{
    /*
     Add a card to the front of the linked list.
     */
    a.next = start;
    start = &a;
    numberofcards++;
}

void collection::shuffle()
{
    /*
     Randomize the sequence of cards in the deck.
     You can use my shuffle
     */
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

card collection::deal()
{
    // Remove a card from the front of the linked list, and return the card
    //Pop front
    if( start == nullptr )
    {
        numberofcards = 0;
        return *start;
    }

    card *ptr = start;
    start = start->next;
    numberofcards--;
    return *ptr;
}



int card::uniquenumber = 0;
void deal_cards(int k, int d, collection &deck, collection *hand);
void battle(int k, collection *hand, collection *table);
void Enter_Num_players_Dealer(int &k_players, int &dealer);
void Show_Initial_Deck_Hands(int &k_players, int &dealer, collection &deck, collection * hand, collection * table);

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
//    battle(num_players, hand, table);
    return 0;
}

void Show_Initial_Deck_Hands(int &k_players, int &dealer, collection &deck, collection * hand, collection * table)
{
    out << "\n\n************** initial deck of cards before shuffle ****\n\n";
    deck.showcollection();
    deck.shuffle(); // Shuffle cards in deck
    out << "\n\n****************** after shuffle **************\n\n";
    deck.showcollection();
    out << "\n\n****************** after cards are dealt **************\n\n";
    deal_cards(k_players, dealer, deck, hand);
    for (int i = 0; i< k_players; i++)
    {
        out << "\ncards for player " << i + 1 << "\n";
        hand[i].showcollection();
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
{ //k is num_players
    /*function battle is the heart of the program.  It implements the card battle operaitons and decides outcomes of card battel according to rules.*/
    //table指每个人放在桌上的牌
    //最后，少于5张牌，就出局
    card temp;
    //step 1
    for(int i = 0; i < k; i++)
    {
        temp = hand[i].deal();
        table[i].add(temp);
    }
    
    //table[]要比头
    //比较table->start的大小
    card array[k];
    for(int i = 0; i < k; i++)
    {
        array[i] = table[i].deal();
    }
    
    
    for(int i = 0; i < k; i++)
    {
        for( int j = 0; j < k; j++ )
        {
            if( array[k].number > array[k+1].number  )//lowest first
            {
                //swap card
                temp = array[k];
                array[k] = array[k+1];
                array[k+1] = temp;
            }
        }
    }
    
    //winner takes all
    //
    
}

void deal_cards(int k, int d, collection &deck, collection *hand) {
    //deal cards to each player
    //non-dealer first, then alternate between dealer and non-dealers
    if( k < 2 )
        return;
    
    card temp;
    if( d == 0 )
    {
        for(int i = 1; i < k;i++)
        {
            //deal to dealer
            if(deck.numberofcards != 0)
            {
                temp = deck.deal();
                hand[d].add(temp);
            }
            //deal to non dealer
            if(deck.numberofcards != 0)
            {
                temp = deck.deal();
                hand[i].add(temp);
            }
        }
    }

    if( d == k-1 )
    {
        for(int i = 0;i < k-1;i++)
        {
            //deal to dealer
            if(deck.numberofcards != 0)
            {
                temp = deck.deal();
                hand[i].add(temp);
            }
            //deal to non dealer
            if(deck.numberofcards != 0)
            {
                temp = deck.deal();
                hand[d].add(temp);
            }
        }
    }
    
    else
    {
        for(int i = 0; i < k; i++)//for cards between 0 to d
        {
            if( i != d )
            {
                //deal to non-dealer
                temp = deck.deal();
                hand[i].add(temp);
                //deal to dealer
                temp = deck.deal();
                hand[d].add(temp);
            }

        }
    }
    
}
