#include "mkpch.h"
#include "Application.h"

#include "Mika/Events/ApplicationEvent.h"
#include "Mika/Log.h"

namespace Mika {

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			MIKA_TRACE(e.ToString());
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			MIKA_TRACE(e.ToString());
		}
		while (true);
	}

}