#pragma once
#include <string>

#include "../../../../Engine/Button.h"

class Text;

class GameSceneButton : public Button
{
public:
    GameSceneButton(std::string name, const char* text , const char* fileNameActive, const char* fileNameInactive);
    void OnClick() override;
private:
    Text* m_text;
};
