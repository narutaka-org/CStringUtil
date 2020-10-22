#include "CStringUtil.h"

int CStringUtil::GetLength(CStringA& strString)
{
	USES_CONVERSION;
	CStringW strW = CA2W(strString);
	return strW.GetLength();
}

int CStringUtil::GetLength(CStringW& strString)
{
	int nLen = strString.GetLength();
	int nSurrogeteLen = 0;
	for (const wchar_t* p = (LPCWSTR)strString; *p; ++p)
	{
		if (IS_SURROGATE_PAIR(p[0], p[1]))
		{
			++nSurrogeteLen;
			++p;
		}
	}
	nLen -= nSurrogeteLen;
	return nLen;
}

CStringA nmCStringUtil::Mid(CStringA& strString, int nStart, int nEnd)
{
	USES_CONVERSION;
	CStringW strW = CA2W(strString);
	CStringW StrR;
	if (nEnd == 0)
	{
		StrR = strW.Mid(nStart);
	} else {
		StrR = strW.Mid(nStart, nEnd);
	}
	CStringA strRet = CW2A(StrR);
	return strRet;
}

CStringW nmCStringUtil::Mid(CStringW& strString, int nStart, int nEnd)
{
	CStringW strRet;
	int nLoop = 0;
	int nLen = 0;
	BOOL bRLen = FALSE;
	BOOL bREnd = FALSE;
	for (const wchar_t* p = (LPCWSTR)strString; *p; ++p)
	{
		if (!bREnd)
		{
			if (nLoop >= nStart) { bRLen = TRUE; }
		}
		if (IS_SURROGATE_PAIR(p[0], p[1]))
		{
			if (bRLen) { strRet += CStringW(p[0]) + CStringW(p[1]); ++nLen; }
			++p;
		} else {
			if (bRLen) { strRet += CStringW(p[0]); ++nLen; }
		}
		if (nEnd != 0) 
		{
			if (nEnd == nLen) { bRLen = FALSE; bREnd = TRUE; }
		}
		++nLoop;		
	}
	return strRet;
}
