#pragma once

#include <string>
#include "game.hpp"

namespace triplex {
    using std::string;
    using triplex::game;

    class application {
        public:
            application();
            ~application();

            string get_name() const;
            string get_version() const;
            string get_developer() const;
            void run();

        private:
            void print_hello() const;
            void print_bye() const;
            void print_level_quest(const game& g) const;
            void print_level_input() const;
            void print_level_success() const;
            void print_level_failure() const;
            void print_end_level(const game& g) const;
            void print_end_game(const game& g) const;
            void input_guesses(int& guess1, int& guess2, int& guess3);

            string _developer;
            string _name;
            string _version;
    };
}
