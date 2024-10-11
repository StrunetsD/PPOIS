#include "Review.h"

void Review::showInfo() const {
    cout << "Review by: " << getClientName() << "\n";
    cout << "Rating: " << getRating() << "/5" << "\n";
    cout << "Date: " << getDate() << "\n";
    cout << "Comment: " << getContent()<< "\n";
}
string Review::getClientName() const {
  return clientName_->getName();
}
string Review::getContent() const {
    return content_;
}
int Review::getRating() const {
  return rating_;
}
string Review::getDate() const {
  return date_;
}
string Review::getCurrentDate() {
    const time_t now = time(nullptr);
    struct tm timeinfo{};


    if (localtime_r(&now, &timeinfo) == nullptr) {
        return "";
    }


    std::array<char, 80> buffer{};
    if (strftime(buffer.data(), buffer.size(), "%Y-%m-%d", &timeinfo) == 0) {
        return "";
    }

    return string(buffer.data());
}
