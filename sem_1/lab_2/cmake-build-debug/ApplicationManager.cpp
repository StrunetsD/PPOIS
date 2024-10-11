#include "ApplicationManager.h"

void ApplicationManager::showInfo()const{
      addWorkersToGallery();
      addArtistsToGallery();
      addReviewsToGallery();
      addPaintingsToGallery();
      addClientsToGallery();
      addEventToGallery();
      addTransaction();
      gallery_->showWorkers(workers_);
      gallery_->showInfo();
 }
 void ApplicationManager::run() const {
      showInfo();
}
void ApplicationManager::addTransaction() const {
    bank_->processTransaction(transaction_);
    bank_->showTransactions();
    cout<<"totalRevenue: "<<"\n";
    cout<<bank_->getTotalRevenue()<<"\n";
}
void ApplicationManager::addEventToGallery() const {
    gallery_->addEvent(event_);
}
void ApplicationManager::addArtistsToGallery() const  {
    gallery_->addArtist(artist_);
}
void ApplicationManager::addPaintingsToGallery() const {
    gallery_->addPainting(painting_);
}
void ApplicationManager::addClientsToGallery() const {
    gallery_->addClient(client_);
}
void ApplicationManager::addReviewsToGallery() const {
    gallery_->addReview(review_);
}

void ApplicationManager::addWorkersToGallery() const {
      workers_->addAdministrator(administrator_);
      workers_->addCurator(curator_);
      workers_->addSecurity(security_);
}