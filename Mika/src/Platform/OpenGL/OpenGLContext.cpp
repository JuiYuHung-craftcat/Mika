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

	MK_CORE_INFO("OpenGL Infor:");
	MK_CORE_INFO("  Vendor: {0}", (const char*)glGetString(GL_VENDOR));
	MK_CORE_INFO("  Renderer: {0}", (const char*)glGetString(GL_RENDERER));
	MK_CORE_INFO("  Version: {0}", (const char*)glGetString(GL_VERSION));
}

void Mika::OpenGLContext::SwapBuffers()
{
	glfwSwapBuffers(m_WindowHandle);
}
