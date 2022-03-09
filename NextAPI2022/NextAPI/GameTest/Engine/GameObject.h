#pragma once

class GameObject
{
public:
    virtual ~GameObject() = default;
    virtual void Start();
    virtual void Update(float dt);
    virtual void Draw();
    virtual void Exit();
};

struct Vector2
{
    float x = 0.0f;
    float y = 0.0f;
};
struct Vector3
{
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
};