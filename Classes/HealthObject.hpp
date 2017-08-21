#ifndef HealthObject_hpp
#define HealthObject_hpp

#include "cocos2d.h"

class HealthObject : public cocos2d::Sprite {
public:
    HealthObject(float maxObjectHealth);
    ~HealthObject();

    void update(float delta, cocos2d::Node *bullet);

    virtual void updateItem(float delta) = 0;
    virtual void onDestroyItem() = 0;

    float getHealth() const;
    void setHealth(float newHealth);

    bool isActive() const;
    void setIsActive(bool state);

private:
    float health;
    const float maxHealth;

    bool active;
};

#endif
