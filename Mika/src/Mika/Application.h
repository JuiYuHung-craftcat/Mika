#pragma once

#include "Core.h"

#include "Window.h"
#include "Mika/LayerStack.h"
#include "Mika/Events/Event.h"
#include "Mika/Events/ApplicationEvent.h"

#include "Mika/ImGui/ImGuiLayer.h"

#include "Mika/Renderer/Shader.h"
#include "Mika/Renderer/Buffer.h"
#include "Mika/Renderer/VertexArray.h"

namespace Mika {

	class MIKA_API Application
	{
	public:
		Application();
		virtual ~Application() = default;

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		std::shared_ptr<Shader> m_Shader;
		std::shared_ptr<VertexArray> m_VertexArray;

		std::shared_ptr<Shader> m_BlueShader;
		std::shared_ptr<VertexArray> m_SquareVA;
	private:
		static Application* s_Instance;
	};


	// To be defined in CLIENT
	Application* CreateApplication();

}
