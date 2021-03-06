#pragma once

#include "Base/Base.h"
#include "Core/Window/Window.h"

#include "Core/Events/ApplicationEvent.h"

#include "Core/Window/Layer/Layer.h"
#include "Core/Window/Layer/LayerStack.h"

#include "ImGui/ImLayer.h"

#include "ImGui/Widgets/MainMenuBar.h"

#include "ImGui/Widgets/SolutionExplorer.h"

namespace BeastCode {

	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }


		std::string SaveFile(const char* filter) const;
		std::string OpenFile(const char* filter) const;
	private:
		bool OnWindowClose(WindowCloseEvent& e);
	private:
		Ref<Window> m_Window;
		bool m_Running = true;
		static Application* s_Instance;
		LayerStack m_layerStack;

		ImGuiLayer* m_layer;

		SouExplorer* m_SloExp;

		MainMenuBar* m_MainMenuBar;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}
