#include "bcpch.h"
#include "SolutionExplorer.h"

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

// TEMPORARY
#include <GLFW/glfw3.h>

namespace BeastCode {

	BeastCode::SouExplorer::SouExplorer() : Layer("SolutionExplorer")
	{
		show = true;
	}

	void BeastCode::SouExplorer::OnAttach()
	{
		// Setup Dear ImGui context
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();

		ImGuiIO& io = ImGui::GetIO(); (void)io;

		// Setup Platform/Renderer bindings
		ImGui_ImplOpenGL3_Init("#version 410");
	}

	void BeastCode::SouExplorer::OnDetach()
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
	}

	void BeastCode::SouExplorer::Begin()
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}

	void BeastCode::SouExplorer::End()
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

	void BeastCode::SouExplorer::OnImGuiRender()
	{
		if (show)
		{
			ImGui::Begin("SolutionExplorer");

			

			ImGui::End();
		}
		else {
			
		}
	}

	//Closes the win
	void BeastCode::SouExplorer::Close()
	{
		show = false;
	}
}