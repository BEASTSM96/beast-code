#include "bcpch.h"
#include "MainMenuBar.h"

#include "imgui.h"
#include "examples/imgui_impl_glfw.h"
#include "examples/imgui_impl_opengl3.h"

#include "Core/Application.h"

#include <functional>
#include <iostream>
#include <numeric>

#include <fstream>

#include <vector>

#include <string>

#include <IMFD_OpenSlnFile.h>

// TEMPORARY
#include <GLFW/glfw3.h>

namespace BeastCode {

	BeastCode::MainMenuBar::MainMenuBar() : Layer("MainBar")
	{
		newSL = false;
		showFile = false;
		showCodeFile = false;
		showSparky = false;
		showDirectoryChooser = false;

	}

	void BeastCode::MainMenuBar::OnAttach()
	{
		// Setup Dear ImGui context
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();

		ImGuiIO& io = ImGui::GetIO(); (void)io;

		// Setup Platform/Renderer bindings
		ImGui_ImplOpenGL3_Init("#version 410");
	}

	void BeastCode::MainMenuBar::OnDetach()
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
	}

	void BeastCode::MainMenuBar::Begin()
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}

	void BeastCode::MainMenuBar::End()
	{
		ImGuiIO& io = ImGui::GetIO();
		Application& app = Application::Get();
		io.DisplaySize = ImVec2((float)app.GetWindow().GetWidth(), (float)app.GetWindow().GetHeight());

		// Rendering
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			GLFWwindow* backup_current_context = glfwGetCurrentContext();
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
			glfwMakeContextCurrent(backup_current_context);
		}
	}


	void BeastCode::MainMenuBar::OnImGuiRender()
	{
	   
		if (newSL)           NewWorkspace();
		//if (showCodeFile)           ShowCodeFiles(&showCodeFile);
		//if (showDirectoryChooser)           ShowDirectoryChooser(&showDirectoryChooser);
		//if (showFile)           ShowExampleAppDocuments(&show_app_documents); 
		//if (showSparky)       ShowExampleAppMainMenuBar();

	// Note: Switch this to true to enable dockspace
		static bool dockspaceOpen = true;
		static bool opt_fullscreen_persistant = true;
		bool opt_fullscreen = opt_fullscreen_persistant;
		static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

		// We are using the ImGuiWindowFlags_NoDocking flag to make the parent window not dockable into,
		// because it would be confusing to have two docking targets within each others.
		ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
		if (opt_fullscreen)
		{
			ImGuiViewport* viewport = ImGui::GetMainViewport();
			ImGui::SetNextWindowPos(viewport->Pos);
			ImGui::SetNextWindowSize(viewport->Size);
			ImGui::SetNextWindowViewport(viewport->ID);
			ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
			ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
			window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
			window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
		}


		// When using ImGuiDockNodeFlags_PassthruCentralNode, DockSpace() will render our background and handle the pass - thru hole, so we ask Begin() to not render a background.
		if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
			window_flags |= ImGuiWindowFlags_NoBackground;


		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
		ImGui::Begin("DockSpace Demo", &dockspaceOpen, window_flags);
		ImGui::PopStyleVar();

		if (opt_fullscreen)
			ImGui::PopStyleVar(2);

		// DockSpace
		ImGuiIO& io = ImGui::GetIO();

		if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
		{
			ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
			ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
		}

		if (ImGui::BeginMenuBar()) {

			if (ImGui::BeginMenu("File"))
			{

				
				if (ImGui::Button("New Solution")) {
					newSL = true;

				}
				if (ImGui::Button("Open Solution"))  OpenWorkspace();
				if (ImGui::Button("Close Solution")) CloseWorkspace();
				
				if (ImGui::MenuItem("Close", "Alt+F4")) Close();
				
				ImGui::EndMenu();
			}

			ImGui::EndMenuBar();
		}

		ImGui::End();
	}

	void MainMenuBar::NewWorkspace()
	{
		IMFD_OpenFile::LookForSlnFile();
	}

	void MainMenuBar::OpenWorkspace()
	{
		std::string filepath =  IMFD_OpenFile::LookForSlnFile();
		
		BC_CORE_INFO(filepath);
	}

	void MainMenuBar::CloseWorkspace()
	{

	}

	/*THIS IS WHAT CLOSES THE APP NOT THE FILE OR ANY WINDOW*/
	void MainMenuBar::Close()
	{
		exit( 0 );
	}
}