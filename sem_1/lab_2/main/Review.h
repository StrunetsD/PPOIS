#ifndef REVIEW_H
#define REVIEW_H
#include "libraries.h"
#include "Client.h"
#include "Entity.h"

class Review final : public Entity{
public:
    Review(Client* clientName, const string& content, const int& rating)
        : clientName_(clientName), content_(content), rating_(rating), date_(getCurrentDate()) {
        if (rating < 1 || rating > 5) {
            throw invalid_argument("Rating must be between 1 and 5.");
        }
    }
    void showInfo() const override;
    string getClientName() const;
    string getContent() const;
    int getRating() const;
    string getDate() const;
private:
    Client* clientName_;
    string content_;
    int rating_;
    string date_;
protected:
    static string getCurrentDate();
};
#endif //REVIEW_H
