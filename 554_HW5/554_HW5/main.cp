//HW5 Due: April 15, Sunday, at 11:59pm
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <vector>
using namespace std;

ofstream out("data1.txt");

class card
{
public:
    int number;
    int suit;
    static int uniquenumber;
    card();
    card(const card &a);
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
    void add(const card &a);
};

card::card()
{
    number = uniquenumber % 13;
    suit = uniquenumber / 13;
    uniquenumber++;
    next = nullptr;
}

card::card(const card &a)
{
    number = a.number;
    suit = a.suit;
    uniquenumber = a.uniquenumber;
    next = a.next;
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
    
    switch (suit)
    {
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
    for (int i = 0; i < x; i++)
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
        //out << " Card: ";
        temp->showcard();
        temp = temp->next;
    }
}

void collection::add(const card &a)
{
    /*
     Add a card to the front of the linked list.
     */
    card* new_card = new card(a);
    new_card->next = start;
    start = new_card;
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
    
    //Reorganize cards in array randomly
}

card collection::deal()
{
    //Remove a card from the front of the linked list, and return the card
    //Pop front
    if (start != nullptr)
    {
        card *ptr = start;
        start = start->next;
        numberofcards--;
        return *ptr;
    }
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
    battle(num_players, hand, table);
    getchar();
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
    
    card temp;
    bool gameover = false;
    card current[20];
    vector<int> out;
    vector<int> Players;
    int winner;//update winner
    
    //First step
    for (int i = 0; i < k; i++)
    {
        if (hand[i].numberofcards != 0)
        {
            temp = hand[i].deal();
            table[i].add(temp);
        }
        else
        {
            ;//若没有牌，则。。。
        }
    }
    
    //Compare cards on the table
    for (int i = 0; i < k; i++)
    {
        if (table[i].numberofcards != 0)
        {
            current[i] = table[i].deal();//pop_front
        }
    }
    
    //找出最小牌，并找出所有最小牌号
    
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k - i; j++)
        {
            if (current[j].number > current[j + 1].number)//ascending order, lowest number is the biggest card
            {
                temp = current[j];
                current[j + 10] = current[j + 1];
                current[j + 11] = temp;
                //array[10]to[19] stores the ascending order of card numbers
            }
        }
    }
    
    
    //Who have the lowest cards
    
    for (int i = 0; i < k; i++)
    {
        if (current[10].number == current[i].number)
        {
            Players.push_back(i);//store who will be in the next battle
        }
    }
    
    if (Players.size() == 1)
    {
        gameover = true;
        winner = Players[0];
    }
    
    
    //If there is a tie
    while (!gameover)//winner没有胜出,game not over
    {
        //nextStepPlayer store who can step to the next battle
        
        //最后一关，少于5张牌的player，出局
        for (int i = 0; i < Players.size(); i++)
        {
            if (hand[i].numberofcards < 5)
            {
                //该玩家出局,加入出局列表
                out.push_back(i);
                auto it = out.begin();
                for (int j = 0; j < out.size(); j++)
                {
                    it++;
                    it--;
                    //从nextStepPlayer list中删除
                    Players.erase(it);
                }
            }
        }
        
        //继续出牌
        //没有足够的牌，出局
        for (int i = 0; i < Players.size(); i++)
        {
            if (hand[i].numberofcards != 0)
            {
                temp = hand[i].deal();
                table[i].add(temp);
            }
            else
            {
                out.push_back(i);//add to the out of game list
                auto it = out.begin();
                for (int j = 0; j < out.size(); j++)
                {
                    it++;
                    it--;
                    Players.erase(it);
                }
            }
        }
        
        //继续比牌
        //找出最小牌
        for (int i = 0; i < Players.size(); i++)
        {
            for (int j = 0; j < Players.size() - i; j++)
            {
                if (current[j].number > current[j + 1].number)//ascending order, lowest number is the biggest card
                {
                    temp = current[j];
                    current[j + 10] = current[j + 1];
                    current[j + 11] = temp;
                    //array[10]to[19] stores the ascending order of card numbers
                }
            }
        }
        
        //who have the lowest card?
        for (int i = 0; i < Players.size(); i++)
        {
            if (current[10].number == current[i].number)
            {
                Players.push_back(i);//store who will be in the next battle
            }
        }
        
        
        //who is the winner
        if (Players.size() == 1)
        {
            winner = Players[0];
            gameover = true;
        }
        else
        {
            gameover = false;
        }
        
        cout << "Game is not over!" << endl;
        
        
        
    }
    
    //winner takes all cards on the table
    for (int i = 0; i < Players.size(); i++)
    {
        if (i != winner)
        {
            while (table[i].numberofcards != 0)
            {
                card temp = table[i].deal();
                hand[winner].add(temp);
            }
        }
    }
}

void deal_cards(int k, int d, collection &deck, collection *hand)
{
    //deal cards to each player
    //non-dealer first, then alternate between dealer and non-dealers
    if (k < 2)
        return;
    
    //starts from dealer.next
    while (deck.numberofcards != 0)
    {
        //deal to non-dealer
        for (int i = d; i < k; i++)
        {
            if (deck.numberofcards != 0)
            {
                card temp;
                temp = deck.deal();
                hand[i].add(temp);
            }
        }
        
        //deal to dealers
        for (int j = 0; j < d; j++)
        {
            if (deck.numberofcards != 0)
            {
                card temp;
                temp = deck.deal();
                hand[j].add(temp);
            }
        }
    }
    
}




////HW5 Due: April 15, Sunday, at 11:59pm
//#include <iostream>
//#include <stdlib.h>
//#include <time.h>
//#include <fstream>
//using namespace std;
//
//ofstream out("data1.txt");
//
//class card
//{
//public:
//    int number;
//    int suit;
//    static int uniquenumber;
//    card();
//    void showcard();
//    card * next;
//};
//
//class collection
//{
//public:
//    card * start;
//    int numberofcards;
//    collection(int x);
//    collection() { start = nullptr; numberofcards = 0; }
//    void showcollection();
//    void shuffle();
//    card deal();
//    void add(card a);
//};
//
//card::card()
//{
//    number = uniquenumber % 13;
//    suit = (uniquenumber / 13);
//    uniquenumber++;
//    next = nullptr;
//}
//
//void card::showcard()
//{
//    switch (number)
//    {
//        case 0: out << "A"; break;  // Ace is low
//        case 10: out << "J"; break;
//        case 11: out << "Q"; break;
//        case 12: out << "K"; break;
//        default: out << (number + 1); break;
//    }
//
//    switch (suit) {
//        case 0: out << "S "; break;
//        case 1: out << "H "; break;
//        case 2: out << "D "; break;
//        case 3: out << "C "; break;
//    }
//
//}
//
//collection::collection(int x)
//{
//    start = nullptr;
//
//    numberofcards = 0;
//    for (int i = 0; i < x; i++)
//    {
//        card temp;
//        add(temp);
//    }
//}
//
//void collection::showcollection()
//{
//    int i;
//    card * temp;
//    temp = start;
//    for (i = 0; i<numberofcards; i++)
//    {
//        temp->showcard();
//        temp = temp->next;
//    }
//}
//
//void collection::add(card a)
//{
//    /*
//     Add a card to the front of the linked list.
//     */
//    //cout << "Address of a: " << &a << endl;
//    card* temp = new card();
//    temp->next = a.next;
//    temp->number = a.number;
//    temp->suit = a.suit;
//    temp->uniquenumber = a.uniquenumber;
//
//    temp->next = start;
//    start = temp;
//
//    numberofcards++;
//}
//
//void collection::shuffle()
//{
//    /*
//     Randomize the sequence of cards in the deck.
//     You can use my shuffle
//     */
//    card *temp2, *temp3;
//    temp2 = start;
//    temp3 = temp2;
//    int i, j, k;
//    char c1;
//    int num;
//    for (i = numberofcards; i>1; i--) {
//        j = rand() % i;
//        for (k = 0; k <= j - 1; k++)
//            temp3 = temp3->next;
//        c1 = temp2->suit;
//        num = temp2->number;
//        temp2->suit = temp3->suit;
//        temp2->number = temp3->number;
//        temp3->suit = c1;
//        temp3->number = num;
//        temp2 = temp2->next;
//        temp3 = temp2;
//    }
//
//    //Reorganize cards in array randomly
//}
//
//card collection::deal()
//{
//    //Remove a card from the front of the linked list, and return the card
//    //Pop front
//    if (start == nullptr)
//    {
//        numberofcards = 0;
//        return *start;
//    }
//
//    card *ptr = start;
//    start = start->next;
//    numberofcards--;
//    return *ptr;
//}
//
//int card::uniquenumber = 0;
//void deal_cards(int k, int d, collection &deck, collection *hand);
//void battle(int k, collection *hand, collection *table);
//void Enter_Num_players_Dealer(int &k_players, int &dealer);
//void Show_Initial_Deck_Hands(int &k_players, int &dealer, collection &deck, collection * hand, collection * table);
//
//int main()
//{
//    collection *hand, *table;
//    int num_players, dealer, i, winner = 0;
//    srand(time(0));
//    Enter_Num_players_Dealer(num_players, dealer);
//    collection deck(52);
//    hand = new collection[num_players];
//    table = new collection[num_players];
//    Show_Initial_Deck_Hands(num_players, dealer, deck, hand, table);
//    //battle(num_players, hand, table);
//    getchar();
//    return 0;
//}
//
//void Show_Initial_Deck_Hands(int &k_players, int &dealer, collection &deck, collection * hand, collection * table)
//{
//    out << "\n\n************** initial deck of cards before shuffle ****\n\n";
//    deck.showcollection();
//    deck.shuffle(); // Shuffle cards in deck
//    out << "\n\n****************** after shuffle **************\n\n";
//    deck.showcollection();
//    out << "\n\n****************** after cards are dealt **************\n\n";
//    /*deal_cards(k_players, dealer, deck, hand);
//     for (int i = 0; i< k_players; i++)
//     {
//     out << "\ncards for player " << i + 1 << "\n";
//     hand[i].showcollection();
//     }*/
//}
//
//void Enter_Num_players_Dealer(int &num_players, int &dealer)
//{
//    do {
//        cout << "Enter the number (2-10) of players ";
//        cin >> num_players;
//        if (num_players > 10 || num_players < 2)
//            out << "Illegal player number. Enter again\n\n";
//    } while (num_players >10 || num_players < 2);
//
//    do {
//        cout << "Enter initial dealer (1-k)";
//        cin >> dealer;
//        if (dealer < 1 || dealer > num_players)
//            out << "Illegal dealer ID. Enter again\n\n";
//    } while (dealer < 1 || dealer > num_players);
//}
//
//
//void battle(int k, collection *hand, collection *table)
//{ //k is num_players
//    /*function battle is the heart of the program.  It implements the card battle operaitons and decides outcomes of card battel according to rules.*/
//    //table指每个人放在桌上的牌
//    card temp;
//    //step 1
//    for (int i = 0; i < k; i++)
//    {
//        if (hand[i].numberofcards != 0)
//        {
//            temp = hand[i].deal();
//            table[i].add(temp);
//        }
//
//    }
//    //比较table->start的大小
//    card array[10] ;
//    for (int i = 0; i < k; i++)
//    {
//        if (table[i].numberofcards != 0)
//        {
//            array[i] = table[i].deal();//pop_front
//        }
//    }
//    //Compare cards on the table
//    for (int i = 0; i < k; i++)
//    {
//        for (int j = 0; j < k - i; j++)
//        {
//            if (array[k].number > array[k + 1].number)//ascending order, lowest number is the biggest card
//            {
//                temp = array[k];
//                array[k] = array[k + 1];
//                array[k + 1] = temp;
//            }
//        }
//    }
//
//    int sameCardsPlayers[10];//indicates who have same lowest cards
//    //find same card and its corresponding players
//    for (int i = 0; i < k; i++)
//    {
//        if (array[0].number == array[i].number)
//        {
//            sameCardsPlayers[i] = i;//
//            //The first card
//            if (hand[i].numberofcards != 0 && hand[i].numberofcards >= 5)
//            {
//                temp = hand[i].deal();
//                table[i].add(temp);
//            }
//            else
//            {
//                ;//少于5张则退出游戏
//            }
//            if (hand[i].numberofcards != 0 && hand[i].numberofcards >= 5)
//            {
//                //The second card
//                temp = hand[i].deal();
//                table[i].add(temp);
//            }
//            else
//            {
//                ;//少于5张则退出游戏
//            }
//        }
//    }
//
//    //for those same cards holders, game continues
//
//
//
//
//
//    //怎样repeat运行？
//    //while()
//    //{  }
//
//
//    //winner takes all cards on the table
//    //    if(  )//winner takes all
//    //    {
//    //        ;  //add all cards on table to each hand
//    //    }
//    //
//
//}
//
//
//void deal_cards(int k, int d, collection &deck, collection *hand)
//{
//    //deal cards to each player
//    //non-dealer first, then alternate between dealer and non-dealers
//    //有问题，dealer的牌总是比non-dealer多
//    //if (k < 2)
//    //    return;
//
//    //card temp;
//    //if (d == 0)//if dealer is the first one
//    //{
//    //    while (deck.numberofcards != 0)
//    //    {
//    //        for (int i = 1; i < k; i++)
//    //        {
//    //            //deal to dealer
//    //            if (deck.numberofcards != 0)
//    //            {
//    //                temp = deck.deal();
//    //                hand[d].add(temp);
//    //            }
//    //            //deal to non dealer
//    //            if (deck.numberofcards != 0)
//    //            {
//    //                temp = deck.deal();
//    //                hand[i].add(temp);
//    //            }
//    //        }
//    //    }
//    //}
//
//    //if (d == k-1)//if dealer is the last one
//    //{
//    //    while (deck.numberofcards != 0)
//    //    {
//    //        for (int i = 0; i < k - 1; i++)
//    //        {
//    //            //deal to dealer
//    //            if (deck.numberofcards != 0)
//    //            {
//    //                temp = deck.deal();
//    //                hand[i].add(temp);
//    //            }
//    //            //deal to non dealer
//    //            if (deck.numberofcards != 0)
//    //            {
//    //                temp = deck.deal();
//    //                hand[d].add(temp);
//    //            }
//    //        }
//    //    }
//    //}
//
//    //else
//    //{
//    //    while (deck.numberofcards != 0)
//    //    {
//    //        for (int i = 0; i < k; i++)//for cards between 0 to d
//    //        {
//    //            if (i != d)
//    //            {
//    //                if (deck.numberofcards != 0)
//    //                {
//    //                    //deal to non-dealer
//    //                    temp = deck.deal();
//    //                    hand[i].add(temp);
//    //                }
//    //                if (deck.numberofcards != 0)
//    //                {
//    //                    //deal to dealer
//    //                    temp = deck.deal();
//    //                    hand[d].add(temp);
//    //                }
//    //            }
//    //    }
//    //    }
//    //}
//
//    //应该从已shuffle的deck里分配到人
//    //starts from dealer.next
//    for (int i = 0; i < k; i++)
//    {
//        for (int j = 0; j < 13; j++)
//        {
//            ;
//        }
//    }
//
//
//}
//
//
//
//////HW5 Due: April 15, Sunday, at 11:59pm
////#include <iostream>
////#include <stdlib.h>
////#include <time.h>
////#include <fstream>
////using namespace std;
////
////ofstream out("data1.txt");
////
////class card
////{
////public:
////    int number;
////    int suit;
////    static int uniquenumber;
////    card();
////    void showcard();
////    card * next;
////};
////
////class collection
////{
////public:
////    card * start;
////    int numberofcards;
////    collection(int x);
////    collection() { start = nullptr; numberofcards = 0; }
////    void showcollection();
////    void shuffle();
////    card deal();
////    void add(card a);
////};
////
////card::card()
////{
////    number = uniquenumber % 13;//得到牌代号
////    suit = (uniquenumber / 13);//得到花色
////    uniquenumber++;
////    next = nullptr;
////}
////
////void card::showcard()
////{
////
////    switch (number)
////    {
////        case 0: out << "A"; break;  // Ace is low
////        case 10: out << "J"; break;
////        case 11: out << "Q"; break;
////        case 12: out << "K"; break;
////        default: out << (number + 1); break;
////    }
////
////    switch (suit) {
////        case 0: out << "S "; break;
////        case 1: out << "H "; break;
////        case 2: out << "D "; break;
////        case 3: out << "C "; break;
////    }
////
////}
////
////collection::collection(int x)
////{
////    start = nullptr;
////
////    numberofcards = 0;
////    for (int i = 0; i<x; i++)
////    {
////        card temp;
////        add(temp);
////    }
////}
////
////void collection::showcollection()
////{
////    int i;
////    card * temp;
////    temp = start;
////    for (i = 0; i<numberofcards; i++)
////    {
////        temp->showcard();
////        temp = temp->next;
////    }
////}
////
////void collection::add(card a)
////{
////    /*
////     Add a card to the front of the linked list.
////     */
////    a.next = start;
////    start = &a;//
////    numberofcards++;
////}
////
////void collection::shuffle()
////{
////    /*
////     Randomize the sequence of cards in the deck.
////     You can use my shuffle
////     */
////    card *temp2, *temp3;
////    temp2 = start;
////    temp3 = temp2;
////    int i, j, k;
////    char c1;
////    int num;
////    for (i = numberofcards; i>1; i--) {
////        j = rand() % i;
////        for (k = 0; k <= j - 1; k++)
////            temp3 = temp3->next;
////        c1 = temp2->suit;
////        num = temp2->number;
////        temp2->suit = temp3->suit;
////        temp2->number = temp3->number;
////        temp3->suit = c1;
////        temp3->number = num;
////        temp2 = temp2->next;
////        temp3 = temp2;
////    }
////
////    // Reorganize cards in array randomly
////}
////
////card collection::deal()
////{
////    // Remove a card from the front of the linked list, and return the card
////    //Pop front
////    if (start == nullptr)
////    {
////        numberofcards = 0;
////        return *start;
////    }
////
////    card *ptr = start;
////    start = start->next;
////    numberofcards--;
////    return *ptr;
////}
////
////
////
////int card::uniquenumber = 0;
////void deal_cards(int k, int d, collection &deck, collection *hand);
////void battle(int k, collection *hand, collection *table);
////void Enter_Num_players_Dealer(int &k_players, int &dealer);
////void Show_Initial_Deck_Hands(int &k_players, int &dealer, collection &deck, collection * hand, collection * table);
////
////int main()
////{
////    collection *hand, *table;
////    int num_players, dealer, i, winner = 0;
////    srand(time(0));
////    Enter_Num_players_Dealer(num_players, dealer);
////    collection deck(52);
////    hand = new collection[num_players];
////    table = new collection[num_players];
////    Show_Initial_Deck_Hands(num_players, dealer, deck, hand, table);
////    //    battle(num_players, hand, table);
////    getchar();//my code
////    return 0;
////}
////
////void Show_Initial_Deck_Hands(int &k_players, int &dealer, collection &deck, collection * hand, collection * table)
////{
////    out << "\n\n************** initial deck of cards before shuffle ****\n\n";
////    deck.showcollection();
////    deck.shuffle(); // Shuffle cards in deck
////    out << "\n\n****************** after shuffle **************\n\n";
////    deck.showcollection();
////    out << "\n\n****************** after cards are dealt **************\n\n";
////    deal_cards(k_players, dealer, deck, hand);
////    for (int i = 0; i< k_players; i++)
////    {
////        out << "\ncards for player " << i + 1 << "\n";
////        hand[i].showcollection();
////    }
////}
////
////void Enter_Num_players_Dealer(int &num_players, int &dealer)
////{
////    do {
////        cout << "Enter the number (2-10) of players ";
////        cin >> num_players;
////        if (num_players > 10 || num_players < 2)
////            out << "Illegal player number. Enter again\n\n";
////    } while (num_players >10 || num_players < 2);
////
////    do {
////        cout << "Enter initial dealer (1-k)";
////        cin >> dealer;
////        if (dealer < 1 || dealer > num_players)
////            out << "Illegal dealer ID. Enter again\n\n";
////    } while (dealer < 1 || dealer > num_players);
////}
////
////
////void battle(int k, collection *hand, collection *table)
////{ //k is num_players
////    /*function battle is the heart of the program.  It implements the card battle operaitons and decides outcomes of card battel according to rules.*/
////    //table指每个人放在桌上的牌
////    card temp;
////    //step 1
////    for (int i = 0; i < k; i++)
////    {
////        if (hand[i].numberofcards != 0)
////        {
////            temp = hand[i].deal();
////            table[i].add(temp);
////        }
////
////    }
////    //table[]要比头
////    //比较table->start的大小
////    card array[10] ;
////    for (int i = 0; i < k; i++)
////    {
////        if (table[i].numberofcards != 0)
////        {
////            array[i] = table[i].deal();//pop_front
////        }
////    }
////    //Compare cards on the table
////    for (int i = 0; i < k; i++)
////    {
////        for (int j = 0; j < k; j++)
////        {
////            if (array[k].number > array[k + 1].number)//ascending order, lowest number is the biggest card
////            {
////                temp = array[k];
////                array[k] = array[k + 1];
////                array[k + 1] = temp;
////            }
////        }
////    }
////
////    int sameCardsPlayers[10];//indicates who have same lowest cards
////    //find same card and its corresponding players
////    for (int i = 0; i < k; i++)
////    {
////        if (array[0].number == array[i].number)
////        {
////            sameCardsPlayers[i] = i;//
////            //The first card
////            if (hand[i].numberofcards != 0 && hand[i].numberofcards >= 5)
////            {
////                temp = hand[i].deal();
////                table[i].add(temp);
////            }
////            else
////            {
////                ;//少于5张则退出游戏
////            }
////            if (hand[i].numberofcards != 0 && hand[i].numberofcards >= 5)
////            {
////                //The second card
////                temp = hand[i].deal();
////                table[i].add(temp);
////            }
////            else
////            {
////                ;//少于5张则退出游戏
////            }
////        }
////    }
////
////    //for those same cards holders, game continues
////
////
////
////
////
////    //怎样repeat运行？
////    //while()
////    //{  }
////
////
////    //winner takes all cards on the table
////    //    if(  )//winner takes all
////    //    {
////    //        ;  //add all cards on table to each hand
////    //    }
////    //
////
////}
////
////
////void deal_cards(int k, int d, collection &deck, collection *hand) {
////    //deal cards to each player
////    //non-dealer first, then alternate between dealer and non-dealers
////    if (k < 2)
////        return;
////
////    cout << "Deal cards is working!" << endl;
////
////    card temp;
////    if (d == 0)
////    {
////        for (int i = 1; i < k; i++)
////        {
////            //deal to dealer
////            if (deck.numberofcards != 0)
////            {
////                temp = deck.deal();
////                hand[d].add(temp);//
////            }
////            //deal to non dealer
////            if (deck.numberofcards != 0)
////            {
////                temp = deck.deal();
////                hand[i].add(temp);
////            }
////        }
////    }
////
////    if (d == k - 1)
////    {
////        for (int i = 0; i < k - 1; i++)
////        {
////            //deal to dealer
////            if (deck.numberofcards != 0)
////            {
////                temp = deck.deal();
////                hand[i].add(temp);
////            }
////            //deal to non dealer
////            if (deck.numberofcards != 0)
////            {
////                temp = deck.deal();
////                hand[d].add(temp);
////            }
////        }
////    }
////
////    else
////    {
////        for (int i = 0; i < k; i++)//for cards between 0 to d
////        {
////            if (i != d)
////            {
////                //deal to non-dealer
////                temp = deck.deal();
////                hand[i].add(temp);
////                //deal to dealer
////                temp = deck.deal();
////                hand[d].add(temp);
////            }
////        }
////    }
////}
