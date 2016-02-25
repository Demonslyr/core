#pragma once
#include "../CustomShape.h"

// 199
namespace NSCustomShapesConvert
{
class CActionButtonSoundType : public CCustomShape
{
public:
	CActionButtonSoundType()

    {
        m_bConcentricFill = true;
		m_eJoin = NSOfficeDrawing::lineJoinMiter;
        
		m_strPath = _T("m,l,21600r21600,l21600,xem@0@0nfl@0@2@1@2@1@0xem,nfl@0@0em,21600nfl@0@2em21600,21600nfl@1@2em21600,nfl@1@0em@11@21nfl@11@22@24@22@25@10@25@9@24@21xem@26@21nfl@12@20em@26@4nfl@12@4em@26@22nfl@12@23e");

		AddGuide(_T("val #0"));  
		AddGuide(_T("sum width 0 #0"));  
		AddGuide(_T("sum height 0 #0"));  
		AddGuide(_T("prod width 1 2"));  
		AddGuide(_T("prod height 1 2"));  
		AddGuide(_T("prod #0 1 2"));  
		AddGuide(_T("prod #0 3 2"));  
		AddGuide(_T("sum @1 @5 0"));  
		AddGuide(_T("sum @2 @5 0"));  
		AddGuide(_T("sum @0 @4 8100"));  
		AddGuide(_T("sum @2 8100 @4"));  
		AddGuide(_T("sum @0 @3 8100"));  
		AddGuide(_T("sum @1 8100 @3"));  
		AddGuide(_T("sum @10 0 @9"));  
		AddGuide(_T("prod @13 1 8"));  
		AddGuide(_T("prod @13 5 16"));  
		AddGuide(_T("prod @13 5 8"));  
		AddGuide(_T("prod @13 11 16"));  
		AddGuide(_T("prod @13 3 4"));  
		AddGuide(_T("prod @13 7 8"));  
		AddGuide(_T("sum @9 @14 0"));  
		AddGuide(_T("sum @9 @15 0"));  
		AddGuide(_T("sum @9 @17 0"));  
		AddGuide(_T("sum @9 @19 0"));  
		AddGuide(_T("sum @11 @15 0"));  
		AddGuide(_T("sum @11 @16 0"));  
		AddGuide(_T("sum @11 @18 0"));  
		AddGuide(_T("sum @4 @5 0"));  
		AddGuide(_T("sum @9 @5 0"));  
		AddGuide(_T("sum @10 @5 0"));  
		AddGuide(_T("sum @11 @5 0"));  
		AddGuide(_T("sum @12 @5 0"));  
		AddGuide(_T("sum @20 @5 0"));  
		AddGuide(_T("sum @21 @5 0"));  
		AddGuide(_T("sum @22 @5 0"));  
		AddGuide(_T("sum @23 @5 0"));  
		AddGuide(_T("sum @24 @5 0"));  
		AddGuide(_T("sum @25 @5 0"));  
		AddGuide(_T("sum @26 @5 0"));
		
		m_arAdjustments.push_back(1350);
		LoadConnectorsList(_T("0,@4;@0,@4;@3,21600;@3,@2;21600,@4;@1,@4;@3,0;@3,@0"));
		LoadTextRect(_T("@0,@0,@1,@2"));

		CHandle_ oHandle1;
		oHandle1.position = _T("#0,topLeft");
		oHandle1.switchHandle = _T("true");
		oHandle1.xrange = _T("0,5400");
		m_arHandles.push_back(oHandle1);

		m_lLimoX = 10800;
		m_lLimoY = 10800;
    }
};
}