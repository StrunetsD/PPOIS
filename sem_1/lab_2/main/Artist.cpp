#include "includes.h"


string Artist::getBiography() const  {
  return biography_;
}
void Artist::showInfo() const  {
  cout<<getName()<<", "<< getBiography()<<"\n";
}
