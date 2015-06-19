/*
 * Ex_8_1.h
 *
 */

/*
 * black jack
 */


#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <ctime>
#include <cstdlib>
 
using namespace std;

vector<string> SUITS = {"Club", "Diamond", "Heart", "Spade"};
vector<string> RANKS = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
unordered_map<string, int> VALUES = {{"A",1}, {"2",2}, {"3",3}, {"4",4}, {"5",5}, {"6",6}, 
    {"7",7}, {"8",8}, {"9",9}, {"10",10}, {"J",10}, {"Q",10}, {"K",10}}; 
 
struct Card {
    string suit;
    string rank;
    Card(string s, string r) : suit(s), rank(r) {}
};
 
class Deck {
private:
    vector<Card> cards;
public:
    Deck() {
        for (auto suit : SUITS)
            for (auto rank : RANKS)
                cards.push_back(Card(suit, rank));
    }
    void shuffle() {
        random_shuffle(cards.begin(), cards.end());
    }
    Card deal_card() {
        Card result = cards.back();
        cards.pop_back();
        return result;
    }
};
 
class Hand {
private:
    vector<Card> cards;
public:
    Hand() {}
    void add_card(Card c) {
        cards.push_back(c);
    }
    int get_value() {
        int value = 0, has_ace = 0;
        for (auto card : cards) {
            value += VALUES[card.rank];
            if (card.rank == "A") has_ace = 1;
        }
        if (has_ace && value < 12) value += 10;
        return value;
    }
    string printCards() {
        string result = "";
        for (auto card : cards)
            result += card.suit + " " + card.rank + "  ";
        return result;
    }
};
 
int main() {
    srand (unsigned (time(0)));
    cout << endl << "----------Black Jack----------" << endl;
    cout << "  Game starts! " << endl;
    bool newgame = true, inplay = true;
    char input;
    while (newgame) {
        Deck deck;
        Hand dealer, player;
        deck.shuffle();
        dealer.add_card(deck.deal_card());
        player.add_card(deck.deal_card());
        dealer.add_card(deck.deal_card());
        player.add_card(deck.deal_card());
        cout << "  You have: " << player.printCards() << endl;
        while (inplay) {
            cout << "  Hit (h) or Stand (s)? ";
            cin >> input;
            if (input == 'h') {
                player.add_card(deck.deal_card());
                cout << "  You have: " << player.printCards() << endl;
                if (player.get_value() > 21) {
                    cout << "  You have busted! Dealer wins!" << endl;
                    inplay = false;
                }
            } else if (input == 's') {
                while (dealer.get_value() < 17) dealer.add_card(deck.deal_card());
                cout << "  Dealer has: " << dealer.printCards() << endl;
                if (dealer.get_value() > 21) 
                    cout << "  Dealer has busted! You win!" << endl;
                else if (dealer.get_value() < player.get_value())
                    cout << "  You win!" << endl;
                else cout << "  Dealer wins!" << endl;
                inplay = false;
            } else cout << endl << "  Invalid input! Hit (h) or Stand (s)? ";
        }
        while (!inplay) {
            cout << "  New game? (y or n) ";
            cin >> input;
            if (input == 'y') inplay = true;
            else if (input == 'n') {
                inplay = true; newgame = false;
            } else cout << endl << "  Invalid input! New game? (y or n) ";
        }
    }

    return 0;
}

