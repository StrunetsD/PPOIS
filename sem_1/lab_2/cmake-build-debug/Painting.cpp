#include "Painting.h"


string Painting::getTitle()const{
  return title_;
}
Artist* Painting::getArtist()const{
  return artist_;
}
string Painting::getStyle()const{
  return style_;
}
double Painting::getPrice()const{
  return price_;
}
string Painting::getCategory() const {
  return category_->getCategoryName();
}
void Painting::showInfo() const {
  cout<<"Category: "<< category_->getCategoryName()<<"\n";
  cout << "Title: " << getTitle() << "\n";
  cout << "Artist: " <<artist_->getName() << "\n";
  cout << "Style: " << getStyle() << "\n";
  cout << "Price: " << getPrice() <<"$"<< "\n";
}