#include "../include/template_application.h"

TemplateApplication::TemplateApplication() {
    m_demoTexture = nullptr;
}

TemplateApplication::~TemplateApplication() {
    /* void */
}

void TemplateApplication::Initialize(void *instance, ysContextObject::DEVICE_API api) {
    dbasic::Path modulePath = dbasic::GetModulePath();
    dbasic::Path confPath = modulePath.Append("delta.conf");

    std::string enginePath = "../../dependencies/delta/engines/basic";
    std::string assetPath = "../../assets";
    if (confPath.Exists()) {
        std::fstream confFile(confPath.ToString(), std::ios::in);
        
        std::getline(confFile, enginePath);
        std::getline(confFile, assetPath);
        enginePath = modulePath.Append(enginePath).ToString();
        assetPath = modulePath.Append(assetPath).ToString();

        confFile.close();
    }

    m_engine.GetConsole()->SetDefaultFontDirectory(enginePath + "/fonts/");

    m_engine.CreateGameWindow(
        "Delta Template Application",
        instance,
        api,
        (enginePath + "/shaders/").c_str());

    m_engine.SetClearColor(0x34, 0x98, 0xdb);

    m_assetManager.SetEngine(&m_engine);
    m_engine.LoadTexture(&m_demoTexture, (assetPath + "/chicken.png").c_str());
}

void TemplateApplication::Process() {
    /* void */
}

void TemplateApplication::Render() {
    m_engine.SetCameraPosition(0.0f, 0.0f);
    m_engine.SetCameraAltitude(10.0f);

    int color[] = { 0xf1, 0xc4, 0x0f };
    ysMatrix translation = ysMath::TranslationTransform(ysMath::LoadVector(-3.0f, 0.0f, 0.0f));
    m_engine.SetObjectTransform(translation);
    m_engine.DrawBox(color, 2.5f, 2.5f);

    m_engine.SetMultiplyColor(ysVector4(1.0f, 1.0f, 1.0f, 1.0f));
    m_engine.SetObjectTransform(ysMath::LoadIdentity());
    m_engine.DrawImage(m_demoTexture, 0, (float)m_demoTexture->GetWidth() / m_demoTexture->GetHeight());
}

void TemplateApplication::Run() {
    while (m_engine.IsOpen()) {
        m_engine.StartFrame();

        Process();
        Render();

        m_engine.EndFrame();
    }
}
