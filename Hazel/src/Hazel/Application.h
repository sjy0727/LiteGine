#pragma once

#include "Core.h"

#include "Events/ApplicationEvent.h"
#include "Events/Event.h"
#include "LayerStack.h"
#include "Window.h"

namespace Hazel
{
    class HAZEL_API Application
    {
    private:
        std::unique_ptr<Window> m_Window;
        bool                    m_Running = true;
        LayerStack              m_LayerStack;
        bool                    OnWindowClose(WindowCloseEvent& e);

    public:
        Application();
        ~Application();

        void Run();

        void OnEvent(Event& e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* overlay);
    };

    // 在客户端(Sandbox)中定义
    Application* CreateApplication();

} // namespace Hazel
