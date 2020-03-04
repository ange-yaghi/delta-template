#ifndef DELTA_TEMPLATE_TEMPLATE_APPLICATION_H
#define DELTA_TEMPLATE_TEMPLATE_APPLICATION_H

#include "delta.h"

class TemplateApplication {
public:
    TemplateApplication();
    ~TemplateApplication();

    void Initialize(void *instance, ysContextObject::DEVICE_API api);
    void Run();

protected:
    void Process();
    void Render();

    dbasic::DeltaEngine m_engine;
    dbasic::AssetManager m_assetManager;

    ysTexture *m_demoTexture;
};

#endif /* DELTA_TEMPLATE_TEMPLATE_APPLICATION_H */
