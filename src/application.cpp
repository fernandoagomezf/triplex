#include <iostream>
#include <string>
#include <exception>
#include "application.hpp"
#include "game.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::exception;
using triplex::application;
using triplex::game;

application::application(){
    _name = "Triple X";
    _version = "0.1.0";
    _developer = "Tollan";
}

application::~application(){

}

string application::get_name() const {
    return _name;
}

string application::get_version() const {
    return _version;
}

string application::get_developer() const {
    return _developer;
}

void application::run(){    
    print_hello();

    try {
        game g;
        g.initialize();
        while (g.has_next_level()){
            print_level_quest(g);
            print_level_input();
            
            int guess1, guess2, guess3;
            input_guesses(guess1, guess2, guess3);

            const auto level = g.current_level();
            auto success = level.matches(guess1, guess2, guess3);
            if (success) {
                g.loot(level.get_loot_score());
                print_level_success();
            } else {
                print_level_failure();
            }
            print_end_level(g);
            g.next_level();
        }
        print_end_game(g);
    } catch (const exception& ex){
        cout << "Error detected in the game: " << ex.what() << endl;
        cout << endl;
    }

    print_bye();
}

void application::print_hello() const {
    cout << _name << " v" << _version << endl;
    cout << _developer << " (C) 2020" << endl;
    cout << endl;
}

void application::print_bye() const {
    cout << endl;
    cout << "Exiting game, bye!" << endl;
}

void application::print_level_input() const{
    cout << "Please enter the code for the safe box: " << endl;
}

void application::input_guesses(int& guess1, int& guess2, int& guess3){
    cin >> guess1;
    cin >> guess2;
    cin >> guess3;
}

void application::print_level_quest(const game& g) const {
    const auto level = g.current_level();

    cout << endl;
    cout << "You are attempting to break a safe box of level " 
         << level.get_level()
         << " which is protected by three numbers. " 
         << "As you use your skills to detect how the pins are arranged, you've gathered a few "
         << "hints about the safe box, which apparently is holding "
         << level.get_loot_score()
         << " coins in loot." << endl;
    cout << "\t1. " << level.get_first_hint() << endl;
    cout << "\t2. " << level.get_second_hint() << endl;
    cout << endl;
}

void application::print_level_success() const{
    cout << "As you enter the codes, you hear the click of the pins as they fall into the correct places. "
         << "the safe box opens as a smile appears on your face, basking in the thought of how are you "
         << "going to spend your well-earned coins." << endl;
    cout << endl;
}

void application::print_level_failure() const{
    cout << "Even as you finish entering the codes, a sense of frustration fills your being, as you understand "
         << "that the codes entered are not valid and the safe box simply won't budge. Moreover, it seems "
         << "the pins broke, so you are deprived of its loot for good." << endl;
    cout << endl;
}

void application::print_end_level(const game& g) const{
    cout << "So far, you have looted " 
         << g.get_coins_looted()
         <<  " coins. Press enter to continue."
         << endl;
    cin.get();
    cin.get();
}

void application::print_end_game(const game& g) const{
    cout << "There are no more safe boxes to loot. You have collected " 
         << g.get_coins_looted()
         <<  " coins. Press enter to finish the game."
         << endl;
    cin.get();
}