#ifndef GameScene_hpp
#define GameScene_hpp

#include "cocos2d.h"
#include "Subject.hpp"
#include "GameEventListener.hpp"
#include "HealthBar.hpp"
#include "Circle.hpp"

#include "Bullet.hpp"
#include "HealthObject.hpp"

class GameScore;

class GameScene : public cocos2d::LayerColor {
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    virtual void update(float delta);

    /**
     * Update every game object in the game.
     *
     * @param delta   The game's delta time
     * @param bullet  Current active bullet
     */
    void updateComponents(float delta, Bullet *bullet);

    /**
     * Creates a bullet moving in the specified direction.
     *
     * @param direction  The bullet's direction
     */
    Bullet* createBullet(const cocos2d::Vec2 direction);

    CREATE_FUNC(GameScene);

private:
    Subject subject;
    GameEventListener *eventListener;

    cocos2d::Rect screenBounds;
    Circle playerCircle;
    GameScore *score;

    HealthBar *health;
    cocos2d::Sprite *bulletDirectionIndicator;

    cocos2d::Vector<Bullet*> bullets;
    cocos2d::Vector<HealthObject*> objects;

    Bullet::BulletParams normalBullet;

    /**
     * Create an event listener for handling touch events.
     */
    void setupTouchListener();

    /**
     * Initializes different types of bullets.
     */
    void createBulletParams();
};

class GameScore : public Observer, public cocos2d::Label {
public:
    static constexpr float FONT_SIZE = 32.0f;
    static GameScore* create();

    GameScore();

    void setScore(int newScore);
    int getScore() const;

    virtual void onNotify(ActionEvent action, int data);

private:
    int score;
};

#endif // GameScene_hpp

