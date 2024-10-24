
#ifndef SOUNDDESIGNER_H
#define SOUNDDESIGNER_H


#include "Employee.h"
class SoundDesigner final : public Employee {
public:
    SoundDesigner(const string& name, const int age, const double salary)
        : Employee(name, age, salary) {}

    void createSoundEffects() const;
    void composeMusic() const;
    void adjustAudioLevels() const;
};



#endif //SOUNDDESIGNER_H
