#ifndef PAINTING_H
#define PAINTING_H

#include "libraries.h"
#include "Artist.h"
#include "Entity.h"
#include "Category.h"


#include <string>

class Painting final : public Entity {
public:
    Painting(const std::string title, Artist* artist, const std::string style, const double price, Category* category)
        : category_(category), title_(title), artist_(artist), style_(style), price_(price) {} // Правильный порядок инициализации

    std::string getTitle() const;
    Artist* getArtist() const;
    std::string getStyle() const;
    double getPrice() const;
    void showInfo() const override;
    std::string getCategory() const;

private:
    Category* category_;
    std::string title_;
    Artist* artist_;
    std::string style_;
    double price_;
};
#endif //PAINTING_H
