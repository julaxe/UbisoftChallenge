#pragma once
#include "../../../Engine/Button.h"
#include "../../../Engine/Text.h"

class MainMenuButton : public Button
{
public:
    MainMenuButton(std::string name, const char* fileNameActive, const char* fileNameInactive);
    void OnClick() override;
private:
    Text* m_text;
};
