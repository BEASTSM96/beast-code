#pragma once

#include "Core/ImGui/ImLayer.h"

namespace BeastCode {

	class BEASTCODE_API_EXPORT_ALL SouExplorer : public Layer
	{
	public:
		SouExplorer();
		~SouExplorer() = default;

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
		bool show;
	};
}
