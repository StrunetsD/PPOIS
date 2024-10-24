#ifndef GAME_H
#define GAME_H


#include "libraries.h"
#include "Category.h"
#include "Developer.h"
#include "QA.h"

class Game {
public:
    Game(const string& title, const string& genre,
         Category* category)
        : title_(title), genre_(genre), category_(category) {}

    void addDeveloper(Developer* developer) {developers_.push_back(developer);}
    void addTester(QA* tester) {testers_.push_back(tester);}
    void displayInfo() const {
        cout << "Game title: " << title_ << '\n';
        cout << "Genre: " << genre_ << '\n';
        cout << "Category: " << (category_ ? category_->getName() : "N/A") << '\n';
        if (!developers_.empty()){
            cout << "Developers: " << developers_.size() << '\n';
        }
        else {
            throw string("No Developers found.");
        }
        if (!testers_.empty()){
            cout << "Testers: " << testers_.size() << '\n';
        }
        else {
            throw string("No Testers found.");
        }

    }

   
    const string& getTitle_() const { return title_; }
    const string& getGenre() const { return genre_; }
    Category* getCategory() const { return category_; }
private:
    string title_;
    string genre_;
    Category* category_;
    vector<Developer*> developers_;
    vector<QA*> testers_;    
};


#endif //GAME_H
