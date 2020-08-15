#include "IMFD_OpenSlnFile.h"

#include <ImGuiFileDialog.h>
#include <ImGuiFileDialog.cpp>

#include <imgui/imgui.h>

namespace BeastCode {

    std::string BeastCode::IMFD_OpenFile::LookForSlnFile(static bool p_open)
    {

        BEASTCODE_IMGUI_FILE_DIALOG_SLN

        BEASTCODE_IMGUI_FILE_DIALOG_SLN_COLOUR_AND_NAME

       if (p_open)
       {
           // display
           if (igfd::ImGuiFileDialog::Instance()->FileDialog("ChooseFileDlgKey"))
           {
               // action if OK
               bool isOk = igfd::ImGuiFileDialog::Instance()->IsOk;
               if (isOk)
               {
                   std::string filePathName = igfd::ImGuiFileDialog::Instance()->GetFilePathName();
                   std::string filePath = igfd::ImGuiFileDialog::Instance()->GetCurrentPath();

                   BC_CORE_FATAL(filePathName);

                   BC_CORE_FATAL(filePath);

                   // action
                   igfd::ImGuiFileDialog::Instance()->CloseDialog("ChooseFileDlgKey");
                   

               }
               else if (!isOk) {
                   // close
                   return std::string();
                   igfd::ImGuiFileDialog::Instance()->CloseDialog("ChooseFileDlgKey");
               }

           }
           return std::string();
       }
       else
       {

       }
    }


    std::string BeastCode::IMFD_OpenFile::LookForCFile()
    {
        BEASTCODE_IMGUI_FILE_DIALOG_C_FILE

        BEASTCODE_IMGUI_FILE_DIALOG_SLN_COLOUR_AND_NAME

            // display
            if (igfd::ImGuiFileDialog::Instance()->FileDialog("ChooseFileDlgKey"))
            {
                // action if OK
                if (igfd::ImGuiFileDialog::Instance()->IsOk == true)
                {
                    std::string filePathName = igfd::ImGuiFileDialog::Instance()->GetFilePathName();
                    std::string filePath = igfd::ImGuiFileDialog::Instance()->GetCurrentPath();
                    // action

                    if (filePath != "")
                    {
                        return filePath;
                    }

                }
                // close
                return std::string();
                igfd::ImGuiFileDialog::Instance()->CloseDialog("ChooseFileDlgKey");
            }
        return std::string();
    
    }

    std::string BeastCode::IMFD_OpenFile::LookForCppFile()
    {

        BEASTCODE_IMGUI_FILE_DIALOG_CPP_FILE

        BEASTCODE_IMGUI_FILE_DIALOG_CPP_FILE_COLOUR_AND_NAME

            // display
            if (igfd::ImGuiFileDialog::Instance()->FileDialog("ChooseFileDlgKey"))
            {
                // action if OK
                if (igfd::ImGuiFileDialog::Instance()->IsOk == true)
                {
                    std::string filePathName = igfd::ImGuiFileDialog::Instance()->GetFilePathName();
                    std::string filePath = igfd::ImGuiFileDialog::Instance()->GetCurrentPath();
                    // action

                    if (filePath != "")
                    {
                        return filePath;
                    }

                }
                // close
                return std::string();
                igfd::ImGuiFileDialog::Instance()->CloseDialog("ChooseFileDlgKey");
            }
        return std::string();
    }

  
    std::string BeastCode::IMFD_OpenFile::LookForHFile()
    {

        BEASTCODE_IMGUI_FILE_DIALOG_H_FILE

        BEASTCODE_IMGUI_FILE_DIALOG_H_FILE_COLOUR_AND_NAME

            // display
            if (igfd::ImGuiFileDialog::Instance()->FileDialog("ChooseFileDlgKey"))
            {
                // action if OK
                if (igfd::ImGuiFileDialog::Instance()->IsOk == true)
                {
                    std::string filePathName = igfd::ImGuiFileDialog::Instance()->GetFilePathName();
                    std::string filePath = igfd::ImGuiFileDialog::Instance()->GetCurrentPath();
                    // action

                    if (filePath != "")
                    {
                        return filePath;
                    }

                }
                // close
                return std::string();
                igfd::ImGuiFileDialog::Instance()->CloseDialog("ChooseFileDlgKey");
            }
        return std::string();
    }

    std::string BeastCode::IMFD_OpenFile::LookForAnyFile()
    {
        BEASTCODE_IMGUI_FILE_DIALOG_ANY_FILE

            // display
            if (igfd::ImGuiFileDialog::Instance()->FileDialog("ChooseFileDlgKey"))
            {
                // action if OK
                if (igfd::ImGuiFileDialog::Instance()->IsOk == true)
                {
                    std::string filePathName = igfd::ImGuiFileDialog::Instance()->GetFilePathName();
                    std::string filePath = igfd::ImGuiFileDialog::Instance()->GetCurrentPath();
                    // action

                    if (filePath != "")
                    {
                        return filePath;
                    }

                }
                // close
                return std::string();
                igfd::ImGuiFileDialog::Instance()->CloseDialog("ChooseFileDlgKey");
            }
        return std::string();
    }

    std::string BeastCode::IMFD_OpenFile::LookForTextFile()
    {
        BEASTCODE_IMGUI_FILE_DIALOG_TEXT_FILE

        BEASTCODE_IMGUI_FILE_DIALOG_TEXT_FILE_COLOUR_AND_NAME

            // display
            if (igfd::ImGuiFileDialog::Instance()->FileDialog("ChooseFileDlgKey"))
            {
                // action if OK
                if (igfd::ImGuiFileDialog::Instance()->IsOk == true)
                {
                    std::string filePathName = igfd::ImGuiFileDialog::Instance()->GetFilePathName();
                    std::string filePath = igfd::ImGuiFileDialog::Instance()->GetCurrentPath();
                    // action

                    if (filePath != "")
                    {
                        return filePath;
                    }

                }
                // close
                return std::string();
                igfd::ImGuiFileDialog::Instance()->CloseDialog("ChooseFileDlgKey");
            }
        return std::string();
    }

    std::string BeastCode::IMFD_OpenFile::LookForEditorFile()
    {
        BEASTCODE_IMGUI_FILE_DIALOG_ED_FILE

        BEASTCODE_IMGUI_FILE_DIALOG_ED_FILE_COLOUR_AND_NAME

            // display
            if (igfd::ImGuiFileDialog::Instance()->FileDialog("ChooseFileDlgKey"))
            {
                // action if OK
                if (igfd::ImGuiFileDialog::Instance()->IsOk == true)
                {
                    std::string filePathName = igfd::ImGuiFileDialog::Instance()->GetFilePathName();
                    std::string filePath = igfd::ImGuiFileDialog::Instance()->GetCurrentPath();
                    // action

                    if (filePath != "")
                    {
                        return filePath;
                    }

                }
                // close
                return std::string();
                igfd::ImGuiFileDialog::Instance()->CloseDialog("ChooseFileDlgKey");
            }
        return std::string();
    }

}