#include <Mika.h>

#include "imgui/imgui.h"

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

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
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
	}
	~Sandbox()
	{

	}
};

Mika::Application* Mika::CreateApplication()
{
	return new Sandbox();
}