#pragma once

#include "Core/ImGui/ImLayer.h"

namespace BeastCode {

	class BEASTCODE_API MainMenuBar : public Layer
	{
	public:
		MainMenuBar();
		~MainMenuBar() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void NewWorkspace();
		void OpenWorkspace();
		void CloseWorkspace();
		
		void Close();

		void Begin();
		void End();

	private:
		 bool newSL;
		 bool showFile;
		 bool showCodeFile ;
		 bool showSparky ;
		 bool showDirectoryChooser ;
		 bool isSlnOpen;
	};
}



