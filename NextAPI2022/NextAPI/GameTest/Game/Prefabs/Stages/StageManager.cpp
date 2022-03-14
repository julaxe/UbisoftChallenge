#include "stdafx.h"
#include "StageManager.h"
#include <algorithm>
#include <ctime>
#include <random>

#include "Stage1.h"
#include "Stage2.h"
#include "Stage3.h"

StageManager::StageManager()
{
    SetupAvailableStages();
    AddBossStageToTheGrid();
    InitializeStages();
    SetupConnectionBetweenStages();
}

StageBase* StageManager::GetANewStage(StageBase* newStage)
{
    AddChild(newStage);
    newStage->SetActive(false);
    return newStage;
}

void StageManager::SetupAvailableStages()
{
    //8
    m_available_stages.push_back(GetANewStage(new Stage3()));
    m_available_stages.push_back(GetANewStage(new Stage3()));
    m_available_stages.push_back(GetANewStage(new Stage3()));
    m_available_stages.push_back(GetANewStage(new Stage3()));
    m_available_stages.push_back(GetANewStage(new Stage3()));
    m_available_stages.push_back(GetANewStage(new Stage3()));
    m_available_stages.push_back(GetANewStage(new Stage3()));
    m_available_stages.push_back(GetANewStage(new Stage3()));

    ShuffleStages();
    m_boss_stage = GetANewStage(new StageBase());
}

void StageManager::AddBossStageToTheGrid()
{
    std::vector<int> possible_boss_location = {2,5,6,7,8};
    std::random_shuffle(possible_boss_location.begin(), possible_boss_location.end());
    switch (possible_boss_location[0])
    {
    case 2:
        m_stages[0][2] = m_boss_stage;
        break;
    case 5:
        m_stages[1][2] = m_boss_stage;
        break;
    case 6:
        m_stages[2][0] = m_boss_stage;
        break;
    case 7:
        m_stages[2][1] = m_boss_stage;
        break;
    case 8:
        m_stages[2][2] = m_boss_stage;
        break;
    default:
        break;
    }
}

void StageManager::ShuffleStages()
{
    std::random_shuffle(m_available_stages.begin(), m_available_stages.end());
}

void StageManager::InitializeStages()
{
    constexpr int grid_size = 3;
    int stage_counter = 0;
    
    for(int i = 0; i < grid_size;i++)
    {
        for(int j = 0; j < grid_size;j++)
        {
            if(m_stages[i][j] == m_boss_stage) continue;
            m_stages[i][j] = m_available_stages[stage_counter];
            stage_counter++;
        }
    }
    m_stages[0][0]->InitializeStage();
}

void StageManager::SetupConnectionBetweenStages()
{
    constexpr int grid_size = 3;
    for(int i = 0; i < grid_size;i++)
    {
        for(int j = 0; j < grid_size;j++)
        {
            //top
            if(i-1 >= 0)
            {
                m_stages[i][j]->SetTopWormHoleConnection(m_stages[i-1][j]);
            }
            //right
            if(j+1 < grid_size)
            {
                m_stages[i][j]->SetRightWormHoleConnection(m_stages[i][j+1]);
            }
            //left
            if(j-1 >= 0)
            {
                m_stages[i][j]->SetLeftWormHoleConnection(m_stages[i][j-1]);
            }
            //bottom
            if(i+1 < grid_size)
            {
                m_stages[i][j]->SetBottomWormHoleConnection(m_stages[i+1][j]);
            }
        }
    }
}
