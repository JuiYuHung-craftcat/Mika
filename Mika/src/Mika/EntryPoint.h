#pragma once

#ifdef MK_PLATFORM_WINDOWS

extern Mika::Application* Mika::CreateApplication();

int main(int argc, char** argv)
{
	Mika::Log::Init();
	MK_CORE_WARN("Initialized Log!");
	int a = 5;
	MK_INFO("Hello! Var={0}", a);

	auto app = Mika::CreateApplication();
	app->Run();
	delete app;
}

#endif