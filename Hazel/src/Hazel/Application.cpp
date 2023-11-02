// #include "hzpch.h"
// #include "Application.h"

// #include "Hazel/Events/ApplicationEvent.h"
// #include "Hazel/log.h"

// #include <GLFW/glfw3.h>

// #define BIND_EVENT_FN(x) std::bind(&Hazel::Application::x, this, std::placeholders::_1)

// Hazel::Application::Application()
// {
//     m_Window = std::unique_ptr<Hazel::Window>(Hazel::Window::Create());
//     m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
// }

// Hazel::Application::~Application() {}

// void Hazel::Application::OnEvent(Event& e) 
// {
//     // EventDispatcher dispatcher(e);
// 	// dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
//     HZ_CORE_INFO("{0}", e);
// }


// void Hazel::Application::Run()
// {
//     // WindowResizeEvent e(1280, 720);
//     // if (e.IsInCategory(EventCategoryApplication))
//     // {
//     //     HZ_TRACE(e);
//     // }

//     // if (e.IsInCategory(EventCategoryInput))
//     // {
//     //     HZ_TRACE(e);
//     // }

//     while (m_Running)
//     {
//         glClearColor(0.2, 0.2, 0.2, 1);
//         glClear(GL_COLOR_BUFFER_BIT);
//         m_Window->OnUpdate();
//     }
// }

#include "hzpch.h"
#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Hazel/Log.h"

#include <GLFW/glfw3.h>

namespace Hazel {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	

	Application::Application() 
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application()
	{
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		HZ_CORE_INFO("{0}", e);
	}

	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(0.2, 0.2, 0.2, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

}