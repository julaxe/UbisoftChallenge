#pragma once
#include "../glut/include/GL/freeglut.h"
#include <map>
#include <vector>

#include "SceneNode.h"

class Entity : public SceneNode
{
public:
    //constructors
    Entity(const char *fileName, unsigned int nColumns = 1, unsigned int nRows = 1);
    Entity(std::string name, const char *fileName, unsigned int nColumns = 1, unsigned int nRows = 1);

    //GameObject
    void Update(float dt) override;
    void Draw() override;

    //Texture
    float GetWidth()  const { return m_width;  }
    float GetHeight() const { return m_height; }
    void SetColor(float r, float g, float b);

    //Animation
    void SetFrame(unsigned int f);
    void SetAnimation(int id);
    unsigned int GetFrame()  const { return m_frame; }
    void CreateAnimation( unsigned int id, float speed, const std::vector<int> &frames);

protected:
    //Texture
    Vector3 m_color = {1.0f,1.0f,1.0f};
    float m_width = 0.0F;
    float m_height = 0.0F;
    unsigned int   m_texWidth = 0;
    unsigned int   m_texHeight = 0;
    
    //animation
    unsigned int   m_frame;
    unsigned int   m_nColumns;
    unsigned int   m_nRows;
    int     m_currentAnim = -1;
    float   m_animTime = 0.0F;
    struct sAnimation
        {
            unsigned int m_id;
            float m_speed;
            std::vector<int> m_frames;
        };
    std::vector<sAnimation> m_animations;

    // Texture management.
    struct sTextureDef
    {
        unsigned int m_width;
        unsigned int m_height;
        GLuint m_textureID;
    };
    void CalculateUVs();
    GLuint m_texture;
    float m_points[8];    
    float m_uvcoords[8];
    bool LoadTexture(const char* fileName);
    static std::map<const char *, sTextureDef > m_textures;

private:
    void InitEntity(const char *fileName, unsigned int nColumns = 1, unsigned int nRows = 1);
    
};
