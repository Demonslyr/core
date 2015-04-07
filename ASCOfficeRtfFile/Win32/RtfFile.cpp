// RtfFile.cpp : Implementation of CRtfFile

#include "stdafx.h"

#include "RtfFile.h"
#include "../../Common/OfficeFileErrorDescription.h"

#include "../RtfFormatLib/source/ConvertationManager.h"
#include "../RtfFormatLib/source/Basic.h"

// CRtfFile
STDMETHODIMP CRtfFile::LoadFromFile(BSTR sSrcFileName, BSTR sDstPath, BSTR sXMLOptions)
{
	CString sFilename( sSrcFileName );
	//проверяем входной файл на rtf
	long nError;
	if( FALSE == IsRtfFile( sFilename, nError ) )
	{
		if( NOERROR == nError )
			return AVS_ERROR_FILEFORMAT;
		else
			return nError;
	}

	//проверяем существует ли папка
	DWORD dwDirectoryAttribute = ::GetFileAttributes( sDstPath );
	if( 0 == ( dwDirectoryAttribute & FILE_ATTRIBUTE_DIRECTORY ) )
		return AVS_ERROR_FILEACCESS;
	
	//конвертация
	ConvertationManager oConvertationManager;
	
	return oConvertationManager.ConvertRtfToOOX( CString( sSrcFileName ), CString( sDstPath ), CString( sXMLOptions ) );
}


STDMETHODIMP CRtfFile::SaveToFile(BSTR sDstFileName, BSTR sSrcPath, BSTR sXMLOptions)
{
	//проверяем доступен ли для записи файл
	HANDLE hFile = CreateFile (sDstFileName, GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL );
	if ( INVALID_HANDLE_VALUE == hFile )
		return AVS_ERROR_FILEACCESS;
	CloseHandle( hFile );

	//проверяем существует ли папка
	DWORD dwDirectoryAttribute = ::GetFileAttributes( sSrcPath );
	if( 0 == ( dwDirectoryAttribute & FILE_ATTRIBUTE_DIRECTORY ) )
		return AVS_ERROR_FILEACCESS;
	
	//конвертация
	ConvertationManager oConvertationManager;

	oConvertationManager.ConvertOOXToRtf( CString( sDstFileName ), CString( sSrcPath ), CString( sXMLOptions ) );
	return S_OK;
}
void CRtfFile::RaiseOnProcess( long nValue, short* nCancel )
{
	if( m_nLastProgress / 10000 < nValue / 10000 ) //если произошло изменение в процентах
	{
		m_nLastProgress = nValue;
		OnProgressEx( 0, nValue, nCancel );
		OnProgress( 0, nValue );
	}
}
BOOL CRtfFile::IsRtfFile(CString sFilename, long& nError )
{
	nError = NOERROR;
    BYTE    pBuffer[ 5 ];
    DWORD    dwBytesRead;
    HANDLE  hFile;


    hFile = ::CreateFile( sFilename , GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (INVALID_HANDLE_VALUE==hFile) 
	{
        nError = AVS_ERROR_FILEACCESS;
        return FALSE;
	}
 
    ::ReadFile( hFile, pBuffer, 5, &dwBytesRead, NULL );
    ::CloseHandle(hFile); 

	if( 5 == dwBytesRead && '{' == pBuffer[0] && '\\' == pBuffer[1] && 'r' == pBuffer[2] && 't' == pBuffer[3] && 'f' == pBuffer[4] )
		return TRUE;

	return FALSE;
}
