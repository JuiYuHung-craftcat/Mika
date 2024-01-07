#include <Mika.h>

class Sandbox : public Mika::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}
};

Mika::Application* Mika::CreateApplication()
{
	return new Sandbox();
}