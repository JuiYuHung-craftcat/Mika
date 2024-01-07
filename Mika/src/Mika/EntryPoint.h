#pragma once

#ifdef MK_PLATFORM_WINDOWS

extern Mika::Application* Mika::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Mika::CreateApplication();
	app->Run();
	delete app;
}

#endif