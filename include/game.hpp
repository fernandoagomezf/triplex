#pragma once

#include <vector>
#include "safe_box.hpp"

namespace triplex {
    using std::vector;

    class game {
        public:
            const int min_difficulty = 1;
            const int max_difficulty = 5;
            typedef vector<safe_box> safe_box_vector;

            game();
            ~game();

            void initialize();
            bool has_next_level() const;
            const safe_box& current_level() const;
            safe_box& current_level();
            void next_level();
            void loot(int coins);
            int get_coins_looted() const;

        private:
            int _coins_looted;
            int _current_difficulty;
            safe_box_vector _safe_boxes;

            void ensure_valid_level() const;
    };
}