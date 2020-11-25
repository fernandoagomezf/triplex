#include <string>
#include <ctime>
#include "game.hpp"
#include "safe_box.hpp"
#include "invalid_level.hpp"

using std::srand;
using std::time;
using triplex::game;
using triplex::safe_box;
using triplex::invalid_level;

game::game(){
    _current_difficulty = game::min_difficulty;
    _coins_looted = 0;
}

game::~game(){
}

void game::initialize() {
    srand(time(nullptr));
    _safe_boxes.push_back(safe_box(1));
    _safe_boxes.push_back(safe_box(2));
    _safe_boxes.push_back(safe_box(3));
    _safe_boxes.push_back(safe_box(4));
    _safe_boxes.push_back(safe_box(5));
}

bool game::has_next_level() const {
    return _current_difficulty <= game::max_difficulty;
}

void game::ensure_valid_level() const{
if (_current_difficulty < game::min_difficulty || 
        _current_difficulty > game::max_difficulty ||
        _current_difficulty > _safe_boxes.size()){
        throw invalid_level();
    }
}

const safe_box& game::current_level() const {
    ensure_valid_level();
    return _safe_boxes.at(_current_difficulty - 1);
}

safe_box& game::current_level() {
    ensure_valid_level();
    return _safe_boxes.at(_current_difficulty - 1);
}

void game::next_level(){
    if (_current_difficulty > game::max_difficulty){
        throw invalid_level();
    }

    _current_difficulty++;
}

void game::loot(int coins){
    _coins_looted += coins;
}

int game::get_coins_looted() const {
    return _coins_looted;
}