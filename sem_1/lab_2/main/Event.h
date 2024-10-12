#ifndef EVENT_H
#define EVENT_H
#include "libraries.h"
#include "Entity.h"

#include <string>

class Event final : public Entity {
public:

    Event(const string& name, const string& date)
        : id_(generateId()), name_(name), date_(date) {}

    int getId() const;
    string getName() const;
    string getDate() const;
    void showInfo() const override;

private:
    int id_;
    string name_;
    string date_;
    static int lastId_;
    static int generateId() {
        return ++lastId_;
    }
};






#endif //EVENT_H
