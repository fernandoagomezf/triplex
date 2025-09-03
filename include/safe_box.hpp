#pragma once

#include <set>
#include <string>

namespace triplex{
    using std::string;
    using std::multiset;

    class safe_box{
        public:
            explicit safe_box(int level);
            safe_box(const safe_box& other);
            ~safe_box();

            bool matches(int x1, int x2, int x3) const;
            string get_first_hint() const;
            string get_second_hint() const;
            int get_level() const;
            int get_loot_score() const;

        private:
            multiset<int> _codes;
            int _level;

            int generate() const;
    };
}

