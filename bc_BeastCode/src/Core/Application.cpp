#include "bcpch.h"
#include "Application.h"

#include <GLFW/glfw3.h>

#include "Core/Events/ApplicationEvent.h"

#include <glad/glad.h>

#include "ImGui/ImLayer.h"

#include <imgui.h>

#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3native.h>
#include <Windows.h>

namespace BeastCode {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)
	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		BC_CORE_ASSERT(!s_Instance, "Application already exists!");

		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
		m_Window->SetVSync(false);


		m_layer = new ImGuiLayer();
		m_MainMenuBar = new MainMenuBar();
		m_SloExp = new SouExplorer();

		PushOverlay(m_layer);
		PushOverlay(m_MainMenuBar);
		PushOverlay(m_SloExp);
	}

	Application::~Application()
	{
	}

	
	void Application::PushLayer(Layer* layer)
	{
		m_layerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_layerStack.PushOverlay(layer);
		layer->OnAttach();
	}
	
	void Application::Run()
	{
		
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);


			for (Layer* layer : m_layerStack)
				layer->OnUpdate();

			m_layer->Begin();
			for (Layer* layer : m_layerStack)
				layer->OnImGuiRender();
			m_layer->End();

			m_Window->OnUpdate();
		}
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		for (auto it = m_layerStack.end(); it != m_layerStack.begin(); )
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
				break;
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}


	std::string Application::OpenFile(const char* filter) const
	{

#ifdef  BC_PLATFORM_WINDOWS
		OPENFILENAMEA ofn;
		CHAR szFile[260] = { 0 };
		ZeroMemory(&ofn, sizeof(OPENFILENAME));

		ofn.lStructSize = sizeof(OPENFILENAME);
		ofn.lpstrFilter = filter;
		ofn.hwndOwner = glfwGetWin32Window((GLFWwindow*)m_Window->GetNativeWindow());
		ofn.lpstrFile = szFile;
		ofn.nMaxFile = sizeof(szFile);
		ofn.lpstrTitle = filter;
		ofn.nFilterIndex = 1;
		ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_NOCHANGEDIR;

		if (GetOpenFileNameA(&ofn) == TRUE)
		{
			return ofn.lpstrFile;
		}
		return std::string();
#endif

#ifdef  BC_PLATFORM_LINUX
		m_Running = false;
		m_Crashed = false;

		return std::string();
#endif

		return std::string();
	}

	std::string Application::SaveFile(const char* filter) const
	{

#ifdef  BC_PLATFORM_WINDOWS
		OPENFILENAME ofn;

		WCHAR szFileName[MAX_PATH] = L"";
		
		ofn.lpstrFile = szFileName;  // no cast needed
		ofn.nMaxFile = MAX_PATH;

		ZeroMemory(&ofn, sizeof(ofn));

		ofn.lStructSize = sizeof(ofn);
		ofn.hwndOwner = NULL;
		ofn.lpstrFilter = (LPCWSTR)L"Text Files (*.txt)\0*.txt\0All Files (*.*)\0*.*\0";
		ofn.lpstrFile = (LPWSTR)szFileName;
		ofn.nMaxFile = MAX_PATH;
		ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
		ofn.lpstrDefExt = (LPCWSTR)L"txt";

		GetSaveFileName(&ofn);

		std::string* path = reinterpret_cast<std::string *>(ofn.lpstrFile);
		return std::string();
		getchar();
#endif

#ifdef  BC_PLATFORM_LINUX
		m_Running = false;
		m_Crashed = false;

		return std::string();
#endif

		return std::string();
	}
}
