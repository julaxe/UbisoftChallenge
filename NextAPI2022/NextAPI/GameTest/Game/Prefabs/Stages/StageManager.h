#pragma once
#include "StageBase.h"
#include "../../../Engine/SceneNode.h"

class StageManager : public SceneNode
{
public:
    StageManager();

private:
    StageBase* GetANewStage(StageBase* newStage);
    void SetupAvailableStages();
    void AddBossStageToTheGrid();
    void ShuffleStages();
    void InitializeStages();
    void SetupConnectionBetweenStages();
    std::vector<StageBase*> m_available_stages;
    StageBase* m_boss_stage;
    StageBase* m_stages[3][3];
};
