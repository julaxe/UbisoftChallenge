#pragma once
#include "../../../Engine/Button.h"
#include "../../../Engine/Text.h"

class InstructionsButton : public Button
{
public:
    InstructionsButton(std::string name, const char* text, const char* fileNameActive, const char* fileNameInactive);
    void OnClick() override;
private:
    Text* m_text;
};
