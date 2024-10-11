#include "Guide.h"

void Guide::work() const {
    cout << "Security " << name << " arrived in " << arriveTime << endl;
}

void Guide::listScheduledTours() const {
    if (tours_.empty()) {
        cout << "No scheduled tours." << endl;
        return;
    }

    cout << "Scheduled Tours:" << endl;
    for (const auto& tour : tours_) {
        cout << " - " << tour->getName() << " at " << tour->getDateTime() << endl;
    }
}

void Guide::greetClients() const {
    cout << "Welcome to the tour! I'm your guide, " << getName() << "." << endl;
}

void Guide::provideFeedback(const string& feedback) {
    feedbacks_.push_back(feedback);
    cout << "Feedback received: " << feedback << endl;
}

void Guide::showGuideInfo() const {
    cout << "Guide Name: " << getName() << endl;
    cout << "Arrival Time: " << getArriveTime() << endl;
}

void Guide::showAvailableTours() const {
    cout << "Available Tours:" << endl;
    cout << " - City Tour" << endl;
    cout << " - Historical Tour" << endl;
    cout << " - Nature Tour" << endl;
}