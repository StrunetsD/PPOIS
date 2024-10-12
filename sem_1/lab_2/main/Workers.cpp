#include "includes.h"
#include "libraries.h"




void Workers::addAdministrator(Administrator* adm)  {
    admins_.push_back(adm);
}


void Workers::removeAdministrator(Administrator* adm)  {
    if (const auto it = ranges::find(admins_, adm); it != admins_.end()) {
        admins_.erase(it);
    }
}


void Workers::addCurator(Curator* cur)  {
    curators_.push_back(cur);
}


void Workers::removeCurator(Curator* cur)  {
    if (const auto it = ranges::find(curators_, cur); it != curators_.end()) {
        curators_.erase(it);
    }
}


void Workers::addSecurity(Security* sec) {
    security_.push_back(sec);
}


void Workers::removeSecurity(Security* sec)  {
    if (const auto it = ranges::find(security_, sec); it != security_.end()) {
        security_.erase(it);
    }
}


void Workers::showAdministrators() const {
    cout << "Administrators" << "\n";
    for (const auto& adm : admins_) {
        cout << adm->getName() << "\n";
    }
}


void Workers::showCurators() const {
   cout << "Curators:" << "\n";
    for (const auto& cur : curators_) {
        cout << cur->getName() << "\n";
    }
}


void Workers::showSecurity() const {
    cout << "Security:" << "\n";
    for (const auto& sec : security_) {
        cout << sec->getName() << "\n";
    }
}
void Workers::showInfo() const {
    showAdministrators();
    showCurators();
    showSecurity();
}