#include <iostream>
#include "../htmlfile2.h"
#include "../../DesktopEditor/common/File.h"
#include "../../DesktopEditor/common/Directory.h"
#include "../../Common/3dParty/html/htmltoxhtml.h"
#include "../../ASCOfficeDocxFile2/BinReader/FileWriter.h"
#include "../../Common/DocxFormat/Source/DocxFormat/Docx.h"
#include "../../Common/DocxFormat/Source/DocxFormat/App.h"
#include "../../Common/DocxFormat/Source/DocxFormat/Core.h"
#include "../../DesktopEditor/common/SystemUtils.h"
#include "../../DesktopEditor/common/StringBuilder.h"
#include "../../DesktopEditor/xml/include/xmlutils.h"

int main()
{
    CHtmlFile2 oFile;

    // Файл, который открываем
    std::wstring sFile = NSFile::GetProcessDirectory() + L"/../../../examples/test1.html";

    // Директория, где будем создавать xhtml
    std::wstring sOutputDirectory = NSFile::GetProcessDirectory() + L"/res";
    NSDirectory::DeleteDirectory(sOutputDirectory);
    NSDirectory::CreateDirectory(sOutputDirectory);

    oFile.SetTmpDirectory(sOutputDirectory);

    HRESULT nResConvert = oFile.Open(sFile, sOutputDirectory);
    if(nResConvert == S_OK)
        std::cout << "Success" << std::endl;
    else
        std::cout << "Failure" << std::endl;

    std::cout << "THE END" << std::endl;
    return 0;
}