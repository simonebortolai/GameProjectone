#include "./entities/bullet.hpp"
#include "./entities/livingentity.hpp"


struct bulletList {
    Bullet *value;
    bulletList *next;
};


struct monsterList {
    LivingEntity *value;
    monsterList *next;
};


struct allEntityList {
    LivingEntity *player;
    monsterList *headMonster;
    bulletList *headBullet;
};

