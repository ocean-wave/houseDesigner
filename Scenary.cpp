#include "Scenary.h"
#include "Util.h"
#include "ModelManager.h"

CScenary* CScenary::m_Scenary = 0;

CScenary::CScenary(void)
{
    m_Models = vector<ModelInfo>();
}


CScenary::~CScenary(void)
{
}

CScenary* CScenary::getInstance()
{
    if(m_Scenary == NULL)
        m_Scenary = new CScenary();
    return m_Scenary;
}

bool CScenary::addModel(ModelInfo m_Info)
{
    m_Models.push_back(m_Info);
    return true;
}

bool CScenary::Draw()
{
    CModelManager *modelManager = CModelManager::GetInstance();

    for(int i = 0; i < m_Models.size(); ++i)
    {
        ModelInfo model = m_Models[i];
        glPushMatrix();
            glTranslatef(model.position.x, model.position.y, model.position.z);
            glRotatef(model.rotation.x, 1, 0 ,0);
            glRotatef(model.rotation.y, 0, 1 ,0);
            glRotatef(model.rotation.z, 0, 0 ,1);
            glScalef(model.scale.x, model.scale.y, model.scale.z);
            modelManager->Draw(model.modelName);
        glPopMatrix();
    }
    return true;
}

bool CScenary::SaveMap(string fileName)
{
    // Implementation of the save funtion, need to write all the ModelInfo in the m_Info
    return false;
}

bool CScenary::LoadMap(string fileName)
{
    // Implementation of the read file function, need to read all the ModelInfo to the m_Info
    return false;
}

void CScenary::DrawAxis()
{
    // Eix X (vermell)
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(300.0,0.0,0.0);
    glEnd();

    // Eix Y (verd)
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_LINES);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(0.0,300.0,0.0);
    glEnd();

    // Eix Z (blau)
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_LINES);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(0.0,0.0,300.0);
    glEnd();

}

void CScenary::DrawGrid()
{
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex3f(0, 0, -0.01);
    glVertex3f(25, 0, -0.01);
    glVertex3f(25, 25, -0.01);
    glVertex3f(0, 25, -0.01);
    glEnd();
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    for(int i = 0; i < 25; i += 1)
    {
        glVertex3f(i, 0, 0);
        glVertex3f(i, 25, 0);
        glVertex3f(0, i, 0);
        glVertex3f(25, i, 0);
    }
    glEnd();
    glEnable (GL_LINE_STIPPLE);
    glColor3f(0.0, 1.0, 0.0);
    glLineStipple(1, 0x1111);
    glBegin(GL_LINES);
    for(int i = 0; i < 25; i += 1)
    {
        glVertex3f((float)i + 0.5, 0, 0);
        glVertex3f((float)i + 0.5, 25, 0);
        glVertex3f(0, (float)i + 0.5, 0);
        glVertex3f(25, (float)i + 0.5, 0);
    }
    glEnd();
    glDisable(GL_LINE_STIPPLE);
}
