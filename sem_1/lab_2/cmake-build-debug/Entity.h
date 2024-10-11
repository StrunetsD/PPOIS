#ifndef ENTITY_H
#define ENTITY_H
class Entity{
public:
  virtual ~Entity() = default;
  virtual void showInfo() const = 0;
};
#endif //ENTITY_H
