#include "mkpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <GL/GL.h>

Mika::OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
	: m_WindowHandle(windowHandle)
{
	MIKA_CORE_ASSERT(windowHandle, "Window handle is null!");
}

void Mika::OpenGLContext::Init()
{
	glfwMakeContextCurrent(m_WindowHandle);
	int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	MIKA_CORE_ASSERT(status, "Failed to initialize Glad!");
}

void Mika::OpenGLContext::SwapBuffers()
{
	glfwSwapBuffers(m_WindowHandle);
}
