#include "mkpch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Mika {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;

}