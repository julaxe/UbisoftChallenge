#pragma once
#include "../../../../Engine/Button.h"
#include "../../../../Engine/Text.h"

class CreditsButton : public Button
{
public:
    CreditsButton(std::string name, const char* text, const char* fileNameActive, const char* fileNameInactive);
    void Exit() override;
    void OnClick() override;
private:
    Text* m_text;
};
