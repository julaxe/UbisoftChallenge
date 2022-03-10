#pragma once
#include "../../../../Engine/Button.h"
#include "../../../../Engine/SceneNode.h"

class NavigationButtons : public SceneNode
{
public:
    NavigationButtons();

    void HandleInput();
    void Update(float dt) override;
    void Draw() override;

    void AddButton(Button* button);
    Button* GetCurrentButton();

    void SetHorizontalLayout(float offset);
    void SetVerticalLayout(float offset);

private:
    void NavigateToNextButton();
    void NavigateToPreviousButton();
private:
    std::vector<Button*> m_buttonList;

    int m_current_focused_button = 0;
    bool m_vertical_navigation = true;
    
    float m_vertical_offset = 0.0f;
    float m_horizontal_offset = 0.0f;
};
