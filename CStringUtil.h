#pragma once
class cCStringUtil
{
public:
	int GetLength(CStringA &strString);
	int GetLength(CStringW& strString);
	CStringA Mid(CStringA& strString, int nStart, int nEnd =0);
	CStringW Mid(CStringW& strString, int nStart, int nEnd =0);
};
