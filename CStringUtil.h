#pragma once
class CStringUtil
{
public:
	int GetLength(CStringA& strString);
	int GetLength(CStringW& strString);
	CStringA Mid(CStringA& strString, int nStart, int nEnd =0);
	CStringW Mid(CStringW& strString, int nStart, int nEnd =0);

	CStringA escape5c(CStringW& strString);
};
