#ifndef WORKERS_H
#define WORKERS_H

#include "Security.h"
#include "Administrator.h"
#include "Curator.h"
#include "Entity.h"

class Workers final :public  Entity {
public:
  void addAdministrator(Administrator* adm);
  void removeAdministrator(Administrator* adm);
  void addCurator(Curator* cur);
  void removeCurator(Curator* cur);
  void addSecurity(Security* sec);
  void removeSecurity(Security* sec);
  void showAdministrators() const;
  void showCurators() const;
  void showSecurity() const;
  void showInfo() const override;
private:
  vector<Administrator*> admins_;
  vector<Curator*> curators_;
  vector<Security*> security_;
};



#endif //WORKERS_H
