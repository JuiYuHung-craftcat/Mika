#pragma once

#include "Core.h"

namespace Mika {

	class MIKA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};


	// To be defined in CLIENT
	Application* CreateApplication();

}
