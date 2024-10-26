#pragma once

#include "Mika/Layer.h"

#include "Mika/Events/ApplicationEvent.h"
#include "Mika/Events/KeyEvent.h"
#include "Mika/Events/MouseEvent.h"

namespace Mika {

	class MIKA_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};
}