#pragma once
#include "../glut/include/GL/freeglut.h"
#include <map>
#include <vector>

#include "SceneNode.h"

class Entity : SceneNode
{
public:
    void Draw() override;

    void SetFrame(unsigned int f);
    void SetAnimation(int id);
    float GetWidth()  const { return m_width;  }
    float GetHeight() const { return m_height; }
    
    unsigned int GetFrame()  const { return m_frame; }
    void SetColor(float r, float g, float b);
    void CreateAnimation( unsigned int id, float speed, const std::vector<int> &frames);

protected:
    Vector3 m_color;
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
    bool LoadTexture(const char*);
    static std::map<const char *, sTextureDef > m_textures;
    
};
