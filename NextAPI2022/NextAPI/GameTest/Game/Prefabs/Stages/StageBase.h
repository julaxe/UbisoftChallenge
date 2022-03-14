#pragma once
#include "../../../Engine/SceneNode.h"
#include "../Player/Player.h"
#include "../UI/ZoomInEffect.h"
#include "../Enemies/Turret.h"
#include "../Resources/FuelTank.h"

class WormHole;

class StageBase : public SceneNode
{
public:
    StageBase();

    void Update(float dt) override;
    
    virtual bool MissionComplete() { return true; }

    void SetTopWormHoleConnection(StageBase* stage);
    void SetLeftWormHoleConnection(StageBase* stage);
    void SetRightWormHoleConnection(StageBase* stage);
    void SetBottomWormHoleConnection(StageBase* stage);

    WormHole* GetTopWormHole() const {return m_top_wormhole;}
    WormHole* GetLeftWormHole() const {return m_left_wormhole;}
    WormHole* GetRightWormHole() const {return m_right_wormhole;}
    WormHole* GetBottomWormHole() const {return m_bottom_wormhole;}
    
    void SetWormHolesState(bool unlocked) const;
    void SetPlayer(Player* player);
    void SetPlayerBulletPool(BulletPool* bullet_pool);
    void SetTurretsBulletsPool(BulletPool* bullet_pool);
    void SetBossBulletPool(BulletPool* bullet_pool);

    virtual void InitializeStage();
    void InitializeStaticData();
    void RestartZoomAnimation() const;
    void SetPlayerInitialPosition(Vector2 initialPos);
    
protected:
    void RandomGravity();
    void AddATurret(Vector2 position, float angle);
    void AddAFuelTank(Vector2 position, float angle);
    
    ZoomInEffect* m_root;
    
    WormHole* m_top_wormhole;
    WormHole* m_left_wormhole;
    WormHole* m_right_wormhole;
    WormHole* m_bottom_wormhole;

    Player* m_player;
    BulletPool* m_player_bullet_pool;
    BulletPool* m_turrets_bullet_pool;
    BulletPool* m_boss_bullet_pool;

    std::vector<Turret*> m_list_turrets;
    std::vector<FuelTank*> m_list_fuelTanks;

    Vector2 m_player_initial_position;
};


