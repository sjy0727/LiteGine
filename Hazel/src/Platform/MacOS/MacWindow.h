#pragma once

#include "GLFW/glfw3.h"
#include "Hazel/Window.h"

namespace Hazel
{
    class MacWindow : public Window
    {
    private:
        virtual void Init(const WindowProps& props);
        virtual void Shutdown();

    private:
        GLFWwindow* m_Window;

        struct WindowData
        {
            std::string  Title;
            unsigned int Width;
            unsigned int Height;
            bool         Vsync;

            EventCallbackFn EventCallback;
        };

        WindowData m_Data;

    public:
        MacWindow(const WindowProps& props);
        // FIXME:析构函数不继承virtual
        ~MacWindow() override;

        void OnUpdate() override;

        inline unsigned int GetWidth() const override { return m_Data.Width; };
        inline unsigned int GetHeight() const override { return m_Data.Height; };

        // Window attributes
        inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; };
        void        SetVSync(bool enabled) override;
        bool        isVSync() const override;
    };
} // namespace Hazel