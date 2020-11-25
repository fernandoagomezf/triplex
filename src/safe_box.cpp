#include <string>
#include <cstdlib>
#include "safe_box.hpp"

using std::string;
using std::to_string;
using std::rand;
using triplex::safe_box;

safe_box::safe_box(int level) {
    _level = level;
    _codes.insert(generate());
    _codes.insert(generate());
    _codes.insert(generate());
}

safe_box::safe_box(const safe_box& other)
    : _codes(other._codes), _level(other._level) {
}

safe_box::~safe_box(){

}

int safe_box::get_loot_score() const{
    return (100 * _level) / 2;
}

int safe_box::get_level() const {
    return _level;
}

int safe_box::generate() const{
    return (rand() % _level) + _level;
}

bool safe_box::matches(int x1, int x2, int x3) const {
    multiset<int> guess;
    guess.insert(x1);
    guess.insert(x2);
    guess.insert(x3);

    return _codes == guess;
}

string safe_box::get_first_hint() const {
    auto sum = 0;
    for (int i : _codes){
        sum += i;
    }
    string hint("The codes add-up to ");
    hint += to_string(sum);
    return hint;
}

string safe_box::get_second_hint() const{
    auto product = 1;
    for (int i : _codes){
        product *= i;
    }
    string hint("The codes multiply to give ");
    hint += to_string(product);
    return hint;
}

