#include "RenderManager.h"
#include "Render.h"
#include "Render2D.h"


RenderManager *RenderManager::m_RenderManager = 0;

RenderManager::RenderManager()
{
    m_Renders = RenderMap();
    m_Renders.insert(std::pair<Modes, Render*>(EDITOR_2D, new Render2D()));
    // TODO:
    // Afegir els inserts per els renders que falten un cop creats.

    // Resize all the render modes camera.
    RenderMapIterator it = m_Renders.begin();
    for(; it != m_Renders.end(); ++it)
    {
        it->second->SetCameraProjection(INIT_WIDTH, INIT_HEIGHT);
    }
}

RenderManager::~RenderManager()
{
}

RenderManager* RenderManager::getInstance()
{
    if(m_RenderManager == NULL)
        m_RenderManager = new RenderManager();
    return m_RenderManager;
}

Render* RenderManager::getRenderMode(Modes m)
{
    RenderMapIterator it;
    it = m_Renders.find(m);
    return it->second;
}

void RenderManager::setProjection(int w, int h)
{
    RenderMapIterator it = m_Renders.begin();
    for(; it != m_Renders.end(); ++it)
    {
        it->second->SetCameraProjection(w, h);
    }
}

