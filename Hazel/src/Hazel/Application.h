#pragma once

#include "Core.h"

#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Window.h"

namespace Hazel
{
    class HAZEL_API Application
    {
    private:
        std::unique_ptr<Window> m_Window;
        bool                    m_Running = true;
        bool OnWindowClose(WindowCloseEvent & e);
    public:
        Application();
        ~Application();

        void Run();

        void OnEvent(Event& e);
    };

    // 在客户端(Sandbox)中定义
    Application* CreateApplication();

} // namespace Hazel
