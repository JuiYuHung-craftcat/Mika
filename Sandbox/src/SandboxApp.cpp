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
		if (Mika::Input::IsKeyPressed(MK_KEY_TAB))
			MIKA_TRACE("Tab key is pressed (poll)!");
	}

	void OnEvent(Mika::Event& event) override
	{
		if (event.GetEventType() == Mika::EventType::KeyPressed)
		{
			Mika::KeyPressedEvent& e = (Mika::KeyPressedEvent&)event;
			if (e.GetKeyCode() == MK_KEY_TAB)
				MIKA_TRACE("Tab key is pressed (event)!");
			MIKA_TRACE("{0}", (char)e.GetKeyCode());
		}
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