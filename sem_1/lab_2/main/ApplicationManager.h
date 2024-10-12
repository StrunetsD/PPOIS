#ifndef APPLICATIONMANAGER_H
#define APPLICATIONMANAGER_H

#include "includes.h"
#include "libraries.h"
class ApplicationManager final : public Entity {
public:
  void run()const;
private:
  Client* client_ = new Client("Maksim","@example.com","1111");
  ArtGallery* gallery_ = new ArtGallery("gallery");
  Artist* artist_ = new Artist("Van Gog","try killed hi,self");
  Category* category_ = new Category("post-impressionism");
  Painting* painting_ = new Painting("Starry Night",artist_,"post-impressionism",10000,category_);
  Security* security_ = new Security("Dima","04:00");
  Curator* curator_ = new Curator("Masha","08:00");
  Administrator* administrator_ = new Administrator("Kirill","10:00");
  Workers* workers_ = new Workers;
  Transaction* transaction_ = new Transaction(client_,painting_,10000);
  Bank* bank_ = new Bank;
  Review* review_ = new Review(client_,"i love art",5);
  Event* event_ = new Event("event","12.10.2025");
  void showInfo() const override;
  void addWorkersToGallery()const;
  void addReviewsToGallery()const;
  void addClientsToGallery()const;
  void addPaintingsToGallery()const;
  void addArtistsToGallery()const;
  void addEventToGallery()const;
  void addTransaction()const;
};
#endif //APPLICATIONMANAGER_H
