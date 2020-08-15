#pragma once

#include "Core/Application.h"

#define BEASTCODE_IMGUI_FILE_DIALOG_SLN ::igfd::ImGuiFileDialog::Instance()->OpenDialog("ChooseFileDlgKey", "Choose File", ".sln", ".");
#define BEASTCODE_IMGUI_FILE_DIALOG_SLN_COLOUR_AND_NAME ::igfd::ImGuiFileDialog::Instance()->SetExtentionInfos(".sln", ImVec4(0, 1, 0.5, 0.9), "[VSSOLUTIONFILE]");

#define BEASTCODE_IMGUI_FILE_DIALOG_RETRUN_STRING_FILEPATH BEASTCODE_API static std::string

#define BEASTCODE_IMGUI_FILE_DIALOG_C_FILE ::igfd::ImGuiFileDialog::Instance()->OpenDialog("ChooseFileDlgKey", "Choose File", ".c", ".");
#define BEASTCODE_IMGUI_FILE_DIALOG_C_FILE_COLOUR_AND_NAME ::igfd::ImGuiFileDialog::Instance()->SetExtentionInfos(".sln", ImVec4(0, 1, 0.5, 0.9), "[C FILE]");


#define BEASTCODE_IMGUI_FILE_DIALOG_CPP_FILE ::igfd::ImGuiFileDialog::Instance()->OpenDialog("ChooseFileDlgKey", "Choose File", ".cpp", ".");
#define BEASTCODE_IMGUI_FILE_DIALOG_CPP_FILE_COLOUR_AND_NAME ::igfd::ImGuiFileDialog::Instance()->SetExtentionInfos(".sln", ImVec4(0, 1, 0.5, 0.9), "[C++ FILE]");

#define BEASTCODE_IMGUI_FILE_DIALOG_H_FILE ::igfd::ImGuiFileDialog::Instance()->OpenDialog("ChooseFileDlgKey", "Choose File", ".h", ".");
#define BEASTCODE_IMGUI_FILE_DIALOG_H_FILE_COLOUR_AND_NAME ::igfd::ImGuiFileDialog::Instance()->SetExtentionInfos(".sln", ImVec4(0, 1, 0.5, 0.9), "[HEADER FILE]");

#define BEASTCODE_IMGUI_FILE_DIALOG_ANY_FILE ::igfd::ImGuiFileDialog::Instance()->OpenDialog("ChooseFileDlgKey", "Choose File", " * . *", ".");

#define BEASTCODE_IMGUI_FILE_DIALOG_TEXT_FILE ::igfd::ImGuiFileDialog::Instance()->OpenDialog("ChooseFileDlgKey", "Choose File", ".txt", ".");
#define BEASTCODE_IMGUI_FILE_DIALOG_TEXT_FILE_COLOUR_AND_NAME ::igfd::ImGuiFileDialog::Instance()->SetExtentionInfos(".sln", ImVec4(0, 1, 0.5, 0.9), "[TEXT FILE]");

#define BEASTCODE_IMGUI_FILE_DIALOG_ED_FILE ::igfd::ImGuiFileDialog::Instance()->OpenDialog("ChooseFileDlgKey", "Choose File", ".BEASTCODE", ".");
#define BEASTCODE_IMGUI_FILE_DIALOG_ED_FILE_COLOUR_AND_NAME ::igfd::ImGuiFileDialog::Instance()->SetExtentionInfos(".sln", ImVec4(0, 1, 0.5, 0.9), "[BEASTCODE FILE]");

#define BEASTCODE_PRV_FUNC_NO_EXPORT private: BEASTCODE_IMGUI_FILE_DIALOG_RETRUN_STRING_FILEPATH 
#define BEASTCODE_PRV_FUNC_NO_EXPORT_CPP BEASTCODE_IMGUI_FILE_DIALOG_RETRUN_STRING_FILEPATH

namespace BeastCode {

	class IMFD_OpenFile
	{
	public:
		static std::string LookForSlnFile(static bool p_open = true);

		static std::string LookForCFile();

		static std::string LookForCppFile();
		
		static std::string LookForHFile();

		static std::string LookForAnyFile();

		static std::string LookForTextFile();

		static std::string LookForEditorFile();

	};
}

