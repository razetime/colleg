#include <iostream>
#include <set>
#include <unordered_map>

// std::set1.insert( std::set1.end(), std::set2.begin(), std::set2.end() );

/*int vec_contains(std::set<T> vec, T value) {
    
}
*/
std::set<std::set<std::set<int>>> nfa2dfa(std::set<std::set<std::set<int>>> trans) {
    int pos = 0; 
    std::set<std::set<int>> visited {{0}};
    std::unordered_map<std::set<int>,std::set<int>> dfa;
    std::set<std::set<int>> curr {{0}};
    while(1) {
        std:set<std::set<int>> new;
        for(auto state:curr) {
            for()
        }
        int hasNew
        if()
    }
}

int main() {
    
}
