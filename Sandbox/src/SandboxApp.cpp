#include <Mika.h>

class ExampleLayer : public Mika::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		MIKA_INFO("ExampleLayer::Update");
	}

	void OnEvent(Mika::Event& event) override
	{
		MIKA_TRACE("{0}", event);
	}
};

class Sandbox : public Mika::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Mika::ImGuiLayer());
	}
	~Sandbox()
	{

	}
};

Mika::Application* Mika::CreateApplication()
{
	return new Sandbox();
}