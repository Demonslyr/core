#pragma once
#include "../CustomShape.h"

// 20
namespace NSCustomShapesConvert
{
class CLineType : public CCustomShape
{
public:
	CLineType()

    {
        m_bConcentricFill = true;
		m_eJoin = NSOfficeDrawing::lineJoinRound;
        m_strPath = _T("m0,0l21600,21600nfe");

		LoadConnectorsList(_T("0,0;21600,21600;10800,10800"));
    }
};
}