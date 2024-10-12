#include "ArtGallery.h"

string ArtGallery::getName() const {
    return name_;
}

void ArtGallery::addArtist(Artist* artist) {
    artists_.push_back(artist);
}

void ArtGallery::addPainting(Painting* painting) {
    paintings_.push_back(painting);
}

void ArtGallery::addClient(Client* client) {
    clients_.push_back(client);
}

void ArtGallery::addReview(Review* review) {
    reviews_.push_back(review);
}

void ArtGallery::addEvent(Event* event) {
    events_.push_back(event);
}

void ArtGallery::showInfo() const {
    cout << "Artists: " << endl;
    if (artists_.empty()) {
        cout << "None." << endl;
    } else {
        for (const auto& artist : artists_) {
            artist->showInfo();
        }
    }

    cout << "Paintings: " << endl;
    if (paintings_.empty()) {
        cout << "None." << endl;
    } else {
        for (const auto& painting : paintings_) {
            painting->showInfo();
        }
    }

    cout << "Clients: " << endl;
    if (clients_.empty()) {
        cout << "None." << endl;
    } else {
        for (const auto& client : clients_) {
            client->showInfo();
        }
    }

    cout << "Events: " << endl;
    if (events_.empty()) {
        cout << "None." << endl;
    } else {
        for (const auto& event : events_) {
            event->showInfo();
        }
    }

    cout << "Reviews: " << endl;
    if (reviews_.empty()) {
        cout << "None." << endl;
    } else {
        for (const auto& review : reviews_) {
            review->showInfo();
        }
    }
}

void ArtGallery::showWorkers(Workers* workers) const {
    cout << "Workers: " << endl;
    if (workers) {
        workers->showAdministrators();
        workers->showCurators();
        workers->showSecurity();
    } else {
        cout << "None." << endl;
    }
}