#ifndef GUIDE_H
#define GUIDE_H
#include "libraries.h"
#include "Employee.h"
#include "Human.h"
#include "Tour.h"


class Guide final : public Employee, public Human {
public:
    Guide(const string& name, const string& arriveTime)
        : Human(name), Employee(arriveTime) {}
    void work() const;
    void listScheduledTours() const;
    void greetClients() const;
    void provideFeedback(const string& feedback);
    void showGuideInfo() const;
    void showAvailableTours() const;
private:
    vector<Tour*> tours_;
    vector<string> feedbacks_;
};

#endif //GUIDE_H
