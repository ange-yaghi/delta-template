#ifndef DELTA_TEMPLATE_TEMPLATE_APPLICATION_H
#define DELTA_TEMPLATE_TEMPLATE_APPLICATION_H

#include "delta.h"

class TemplateApplication {
public:
    TemplateApplication();
    ~TemplateApplication();

    void Initialize(void *instance, ysContextObject::DEVICE_API api);
    void Run();
    void Destroy();

protected:
    void Process();
    void Render();

    dbasic::DeltaEngine m_engine;
    dbasic::AssetManager m_assetManager;

    ysTexture *m_demoTexture;
    float m_currentRotation;
    float m_temperature;
};

#endif /* DELTA_TEMPLATE_TEMPLATE_APPLICATION_H */
