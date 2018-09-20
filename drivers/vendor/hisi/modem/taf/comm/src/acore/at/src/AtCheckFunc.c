

#include "AtCheckFunc.h"


#ifdef  __cplusplus
  #if  __cplusplus
  extern "C"{
  #endif
#endif


#define    THIS_FILE_ID        PS_FILE_ID_AT_CHECKFUNC_C



VOS_UINT32 atCheckBasicCmdName( VOS_UINT8 Char )
{
    if(    ('e' == Char) || ('E' == Char) || ('v' == Char) || ('V' == Char)
        || ('a' == Char) || ('A' == Char) || ('h' == Char) || ('H' == Char)
        || ('&' == Char) || ('F' == Char) || ('f' == Char)
        || ('i' == Char) || ('I' == Char) || ('t' == Char) || ('T' == Char)
        || ('p' == Char) || ('P' == Char) || ('x' == Char) || ('X' == Char)
        || ('z' == Char) || ('Z' == Char) || ('c' == Char) || ('C' == Char)
        || ('d' == Char) || ('D' == Char) || ('q' == Char) || ('Q' == Char)
        || ('s' == Char) || ('S' == Char) || ('o' == Char) || ('O' == Char)
      )
    {
        return AT_SUCCESS;
    }
    else
    {
        return AT_FAILURE;
    }
}





/******************************************************************************
 ��������: �Ƚϡ�ƥ��ʮ������(0x��0X)

 ����˵��:
   Char [in] ������ַ�

 �� �� ֵ: AT_SUCCESS --- �ɹ�
           AT_FAILURE --- ʧ��
******************************************************************************/
VOS_UINT32 atCheckHex(VOS_UINT8 Char)
{
    if('x' == Char || 'X' == Char)
    {
        return AT_SUCCESS;
    }
    else
    {
        return AT_FAILURE;
    }
}


/******************************************************************************
 ��������: �Ƚϡ�ƥ��ʮ����������

 ����˵��:
   Char [in] ������ַ�

 �� �� ֵ: AT_SUCCESS --- �ɹ�
           AT_FAILURE --- ʧ��
******************************************************************************/
VOS_UINT32 atCheckHexNum(VOS_UINT8 Char)
{
    if(isdigit(Char)
        || ('a' <= Char && 'f' >= Char)
        || ('A' <= Char && 'F' >= Char))
    {
        return AT_SUCCESS;
    }
    else
    {
        return AT_FAILURE;
    }
}



/******************************************************************************
 ��������: �Ƚϡ�ƥ����˫���Ű�����ĸ��ʼ

 ����˵��:
   Char [in] ������ַ�

 �� �� ֵ: AT_SUCCESS --- �ɹ�
           AT_FAILURE --- ʧ��
******************************************************************************/
VOS_UINT32 atNoQuotLetter(VOS_UINT8 Char)
{
    if('@' == Char)
    {
        return AT_SUCCESS;
    }
    else
    {
        return AT_FAILURE;
    }
}



VOS_UINT32 atCheckblank( VOS_UINT8 Char )
{
    /* ����-֧����Ϊ�ַ� */
    if(' ' == Char)
    {
        return AT_SUCCESS;
    }
    else
    {
        return AT_FAILURE;
    }
}



VOS_UINT32 atCheckComma( VOS_UINT8 Char )
{
    if( ',' == Char )
    {
        return AT_SUCCESS;
    }
    else
    {
        return AT_FAILURE;
    }
}


VOS_UINT32 atCheckColon( VOS_UINT8 Char )
{
    if( ':' == Char )
    {
        return AT_SUCCESS;
    }
    else
    {
        return AT_FAILURE;
    }
}



VOS_UINT32 atCheckChar0x2f( VOS_UINT8 Char )
{
    if( '/' == Char)
    {
        return AT_SUCCESS;
    }
    else
    {
        return AT_FAILURE;
    }
}


/******************************************************************************
 ��������: �Ƚ�ƥ��ʮ����������

 ����˵��:
   usLen [in]     ���ֳ���
   pcTmp [in] ���ִ�

 �� �� ֵ:
    AT_SUCCESS : ƥ��
    AT_FAILURE : ��ƥ��
******************************************************************************/
static VOS_UINT32 checkHexNumString(VOS_UINT16 usLen,  VOS_UINT8 *pcData)
{
    VOS_UINT16 usLength = 2;          /* ��0x��ʼ�Ƚ� */
    VOS_UINT8 *pcTmp    = pcData + 2; /* ��0x��ʼ�Ƚ� */

    /* ����ָ���ɵ����߱�֤��ΪNULL, �ô������ж� */

    while(usLength++ < usLen)
    {
        /* �ж��Ƿ������� */
        if(isdigit(*pcTmp)
            || ('A' <= *pcTmp && 'F' >= *pcTmp)
            || ('a' <= *pcTmp && 'f' >= *pcTmp))
        {
            pcTmp++;
        }
        else
        {
            return AT_FAILURE;
        }
    }

    return AT_SUCCESS;
}

#if 0
/******************************************************************************
 ��������: �Ƚ�ƥ��˽�������

 ����˵��:
   usLen [in]     ���ֳ���
   pcTmp [in] ���ִ�

 �� �� ֵ:
    AT_SUCCESS : ƥ��
    AT_FAILURE : ��ƥ��
******************************************************************************/
static VOS_UINT32 checkOctNumString(VOS_UINT16 usLen,  VOS_UINT8 *pcData)
{
    VOS_UINT16 usLength = 1;          /* ��0��ʼ�Ƚ� */
    VOS_UINT8 *pcTmp    = pcData + 1; /* ��0��ʼ�Ƚ� */

    /* ����ָ���ɵ����߱�֤��ΪNULL, �ô������ж� */

    while(usLength++ < usLen)
    {
        /* �ж��Ƿ������� */
        if((*pcTmp >= '0') && (*pcTmp <= '7'))
        {
            pcTmp++;
        }
        else
        {
            return AT_FAILURE;
        }
    }

    return AT_SUCCESS;
}
#endif

/******************************************************************************
 ��������: �Ƚ�ƥ��ʮ��������

 ����˵��:
   usLen [in]     ���ֳ���
   pcTmp [in] ���ִ�

 �� �� ֵ:
    AT_SUCCESS : ƥ��
    AT_FAILURE : ��ƥ��
******************************************************************************/
static VOS_UINT32 checkDecNumString(VOS_UINT16 usLen,  VOS_UINT8 *pcData)
{
    VOS_UINT16 usLength = 0;      /* ��0��ʼ�Ƚ� */
    VOS_UINT8 *pcTmp    = pcData; /* ��0��ʼ�Ƚ� */

    /* ����ָ���ɵ����߱�֤��ΪNULL, �ô������ж� */

    while(usLength++ < usLen)
    {
        /* �ж��Ƿ������� */
        if(isdigit(*pcTmp))
        {
            pcTmp++;
        }
        else
        {
            return AT_FAILURE;
        }
    }

    return AT_SUCCESS;
}


/******************************************************************************
 ��������: �Ƚϡ�ƥ������

 ����˵��:
   pData [in] ������ַ���
   usLen [in] ����ĳ���

 �� �� ֵ: AT_SUCCESS --- �ɹ�
           AT_FAILURE --- ʧ��
******************************************************************************/
VOS_UINT32 atCheckNumString( VOS_UINT8 *pData, VOS_UINT16 usLen)
{
    VOS_UINT8 *pcTmp    = pData;

    if((NULL == pData) || (0 == usLen))
    {
        return AT_FAILURE;
    }

    pcTmp = pData;

    if('0' == *pcTmp)
    {
        if(2 < usLen && (('x' == *(pcTmp + 1)) || ('X' == *(pcTmp + 1))))
        {
            return checkHexNumString(usLen, pcTmp);
        }
#if 0
        else if(1 < usLen)
        {
            return checkOctNumString(usLen, pcTmp);
        }
#endif
        else
        {
        }
    }

    return checkDecNumString(usLen, pcTmp);
}



VOS_UINT32 atCheckRightArrowStr( VOS_UINT8 *pData,VOS_UINT16 usLen )
{
    VOS_UINT16 usLength = 0;
    VOS_UINT8 *pcTmp    = pData;

    while( usLength++ < usLen )
    {
        /* �ж��Ƿ���MMI�ַ� */
        if(*pcTmp == '>')
        {
            return AT_SUCCESS;
        }
        else
        {
            pcTmp++;
        }
    }
    return AT_FAILURE;
}


VOS_UINT32 atCheckMmiString( VOS_UINT8 *pData,VOS_UINT16 usLen )
{
    VOS_UINT16 usLength = 0;
    VOS_UINT8 *pcTmp    = pData;

    while( usLength++ < usLen )
    {
        /* �ж��Ƿ���MMI�ַ� */
        if((*pcTmp == '*') || (*pcTmp == '#') )
        {
            return AT_SUCCESS;
        }
        else
        {
            pcTmp++;
        }
    }
    return AT_FAILURE;
}



VOS_UINT32 At_CheckStringPara( AT_PARSE_PARA_TYPE_STRU *pPara)
{
    VOS_UINT8 *pData = pPara->aucPara;

    /* ����Ƿ����ַ��� */
    if (pPara->usParaLen < 2)
    {
        return AT_FAILURE;
    }

    if ( ('"' != *pData) || ('"' != *((pData + pPara->usParaLen) - 1)))
    {
        return AT_FAILURE;
    }

    /* ȥ����ͷ��˫���� */
    pPara->usParaLen -= 2;       /*�޸Ĳ�������*/
    PS_MEM_CPY(pData, pData+1, pPara->usParaLen);

    pData[pPara->usParaLen] = '\0';

    return AT_SUCCESS;
}


/******************************************************************************
 ��������: �Ƚϡ�ƥ����˫���Ű����ַ�������

 ����˵��:
   pPara [in/out] ������ַ���

 �� �� ֵ: AT_SUCCESS --- �ַ�������β���� "
           AT_FAILURE --- �ַ�������β��ȫ�� "
******************************************************************************/
VOS_UINT32 atCheckNoQuotStringPara( AT_PARSE_PARA_TYPE_STRU *pPara)
{
    VOS_UINT8 *pData = pPara->aucPara;

    /* ����Ƿ��Ǵ����ŵ��ַ��� */
    if ( ('"' == *pData) && ('"' == *((pData + pPara->usParaLen) - 1)))
    {
        if (pPara->usParaLen < 2)
        {
            return AT_FAILURE;
        }

        /* ȥ����ͷ��˫���� */
        pPara->usParaLen -= 2;       /*�޸Ĳ�������*/
        PS_MEM_CPY(pData, pData+1, pPara->usParaLen);

        pData[pPara->usParaLen] = '\0';
    }

    return AT_SUCCESS;
}



VOS_UINT32 atCheckNumPara(AT_PARSE_PARA_TYPE_STRU *pPara)
{
    VOS_UINT32 i  = 0;

    /* ����ַ��� */
    if(AT_SUCCESS == atCheckNumString(pPara->aucPara,pPara->usParaLen))
    {
        if(AT_SUCCESS != atAuc2ul(pPara->aucPara,pPara->usParaLen,&pPara->ulParaValue))
        {
            return AT_FAILURE;
        }

        for(i = 0; i< g_stATParseCmd.ucParaNumRangeIndex; i++)
        {
            /* �������ֵƥ�� */
            if( (g_stATParseCmd.astParaNumRange[i].ulSmall <= pPara->ulParaValue)
                && (pPara->ulParaValue <= g_stATParseCmd.astParaNumRange[i].ulBig) )
            {
                return AT_SUCCESS;
            }
        }
    }

    return AT_FAILURE;
}


VOS_UINT32 atCheckCharPara( AT_PARSE_PARA_TYPE_STRU *pPara)
{
    VOS_UINT8 ucIndex  = 0;
    VOS_UINT8 pBuf[AT_PARA_MAX_LEN + 1] = {0};

    PS_MEM_CPY(pBuf, pPara->aucPara, pPara->usParaLen);

    At_UpString(pBuf, pPara->usParaLen);

    pBuf[pPara->usParaLen] = '\0';

    for(ucIndex = 0; ucIndex < g_stATParseCmd.ucParaStrRangeIndex; ucIndex++)
    {
        if(0 == AT_STRCMP((VOS_CHAR *)g_stATParseCmd.auStrRange[ucIndex],(VOS_CHAR *)pBuf))
        {
            pPara->ulParaValue = ucIndex;

            return AT_SUCCESS;
        }
    }

    return AT_FAILURE;
}


/*****************************************************************************
 Prototype      : At_CheckSemicolon
 Description    : �Ƚϡ�ƥ��ֺ�
 Input          : Char---������ַ�
 Output         : ---
 Return Value   : AT_SUCCESS --- �ɹ�
                  AT_FAILURE --- ʧ��
 Calls          : ---
 Called By      : ---

 History        : ---
  1.Date        : 2005-04-19
    Author      : ---
    Modification: Created function
*****************************************************************************/
TAF_UINT32 At_CheckSemicolon( TAF_UINT8 Char )
{
    if( ';' == Char )
    {
        return AT_SUCCESS;
    }
    else
    {
        return AT_FAILURE;
    }
}

TAF_UINT32 At_CheckDialNum( TAF_UINT8 Char )
{
    if ((Char >= '0') && (Char <= '9'))
    {
        return AT_SUCCESS;
    }
    else if ((Char >= 'a') && (Char <= 'c'))
    {
        return AT_SUCCESS;
    }
    else if ((Char >= 'A') && (Char <= 'C'))
    {
        return AT_SUCCESS;
    }
    else if (('*' == Char) || ('#' == Char) || ('+' == Char))
    {
        return AT_SUCCESS;
    }
    else
    {
        return AT_FAILURE;
    }
}

TAF_UINT32 At_CheckDmChar( TAF_UINT8 Char )
{
    if( ('*' != Char) && ('#' != Char) )
    {
        return AT_SUCCESS;
    }
    else
    {
        return AT_FAILURE;
    }
}
/*****************************************************************************
 Prototype      : At_CheckCharStar
 Description    : �Ƚϡ�ƥ���ַ�*
 Input          : Char---������ַ�
 Output         : ---
 Return Value   : AT_SUCCESS --- �ɹ�
                  AT_FAILURE --- ʧ��
 Calls          : ---
 Called By      : ---

 History        : ---
  1.Date        : 2005-04-19
    Author      : ---
    Modification: Created function
*****************************************************************************/
TAF_UINT32 At_CheckCharStar( TAF_UINT8 Char )
{
    if( '*' == Char )
    {
        return AT_SUCCESS;
    }
    else
    {
        return AT_FAILURE;
    }
}
/*****************************************************************************
 Prototype      : At_CheckCharWell
 Description    : �Ƚϡ�ƥ���ַ�#
 Input          : Char---������ַ�
 Output         : ---
 Return Value   : AT_SUCCESS --- �ɹ�
                  AT_FAILURE --- ʧ��
 Calls          : ---
 Called By      : ---

 History        : ---
  1.Date        : 2005-04-19
    Author      : ---
    Modification: Created function
*****************************************************************************/
TAF_UINT32 At_CheckCharWell( TAF_UINT8 Char )
{
    if( '#' == Char )
    {
        return AT_SUCCESS;
    }
    else
    {
        return AT_FAILURE;
    }
}
/*****************************************************************************
 Prototype      : At_CheckCharRightArrow
 Description    : �Ƚϡ�ƥ���ַ�>
 Input          : Char---������ַ�
 Output         : ---
 Return Value   : AT_SUCCESS --- �ɹ�
                  AT_FAILURE --- ʧ��
 Calls          : ---
 Called By      : ---

 History        : ---
  1.Date        : 2005-04-19
    Author      : ---
    Modification: Created function
*****************************************************************************/
TAF_UINT32 At_CheckCharRightArrow( TAF_UINT8 Char )
{
    if( '>' == Char )
    {
        return AT_SUCCESS;
    }
    else
    {
        return AT_FAILURE;
    }
}

TAF_UINT32 At_CheckCharG( TAF_UINT8 Char )
{
    if( ('G' == Char) || ('g' == Char) )
    {
        return AT_SUCCESS;
    }
    else
    {
        return AT_FAILURE;
    }
}

TAF_UINT32 At_CheckCharI( TAF_UINT8 Char )
{
    if( ('I' == Char) || ('i' == Char) )
    {
        return AT_SUCCESS;
    }
    else
    {
        return AT_FAILURE;
    }
}

TAF_UINT32 At_CheckCharS( TAF_UINT8 Char )
{
    if( ('s' == Char) || ('S' == Char) )
    {
        return AT_SUCCESS;
    }
    else
    {
        return AT_FAILURE;
    }
}

TAF_UINT32 At_CheckCharD( TAF_UINT8 Char )
{
    if( ('d' == Char) || ('D' == Char) )
    {
        return AT_SUCCESS;
    }
    else
    {
        return AT_FAILURE;
    }
}

TAF_UINT32 At_CheckBasicCmdName( TAF_UINT8 Char )
{
    if( ('e' == Char) || ('E' == Char) || ('v' == Char) || ('V' == Char)
        || ('a' == Char) || ('A' == Char) || ('h' == Char) || ('H' == Char)
        || ('&' == Char) || ('F' == Char) || ('f' == Char) || ('i' == Char)
        || ('I' == Char) || ('T' == Char) || ('t' == Char) || ('P' == Char)
        || ('p' == Char) || ('X' == Char) || ('x' == Char) || ('Z' == Char)
        || ('z' == Char) || ('C' == Char) || ('c' == Char) || ('D' == Char)
        || ('d' == Char) || ('Q' == Char) || ('q' == Char)
        )
    {
        return AT_SUCCESS;
    }
    else
    {
        return AT_FAILURE;
    }
}

TAF_UINT32 At_CheckCharA( TAF_UINT8 Char )
{
    if( ('a' == Char) || ('A' == Char) )
    {
        return AT_SUCCESS;
    }
    else
    {
        return AT_FAILURE;
    }
}

TAF_UINT32 At_CheckCharT( TAF_UINT8 Char )
{
    if( ('t' == Char) || ('T' == Char) )
    {
        return AT_SUCCESS;
    }
    else
    {
        return AT_FAILURE;
    }
}

TAF_UINT32 At_CheckCharPlus( TAF_UINT8 Char )
{
#if(FEATURE_ON == MBB_FEATURE_BOX_FTEN)
    if( ('+' == Char) || ('^' == Char) || ('$' == Char) || ('*' == Char))
#else
    if( ('+' == Char) || ('^' == Char) || ('$' == Char))
#endif
    {
        return AT_SUCCESS;
    }
    else
    {
        return AT_FAILURE;
    }
}
/*****************************************************************************
 Prototype      : At_CheckLeftBracket
 Description    : �Ƚϡ�ƥ���ַ�(
 Input          : Char---������ַ�
 Output         : ---
 Return Value   : AT_SUCCESS --- �ɹ�
                  AT_FAILURE --- ʧ��
 Calls          : ---
 Called By      : ---

 History        : ---
  1.Date        : 2005-04-19
    Author      : ---
    Modification: Created function
*****************************************************************************/
TAF_UINT32 At_CheckLeftBracket( TAF_UINT8 Char )
{
    if( '(' == Char )
    {
        return AT_SUCCESS;
    }
    else
    {
        return AT_FAILURE;
    }
}
/*****************************************************************************
 Prototype      : At_CheckRightBracket
 Description    : �Ƚϡ�ƥ���ַ�)
 Input          : Char---������ַ�
 Output         : ---
 Return Value   : AT_SUCCESS --- �ɹ�
                  AT_FAILURE --- ʧ��
 Calls          : ---
 Called By      : ---

 History        : ---
  1.Date        : 2005-04-19
    Author      : ---
    Modification: Created function
*****************************************************************************/
TAF_UINT32 At_CheckRightBracket( TAF_UINT8 Char )
{
    if( ')' == Char )
    {
        return AT_SUCCESS;
    }
    else
    {
        return AT_FAILURE;
    }
}

TAF_UINT32 At_CheckDigit( TAF_UINT8 Char )
{
    if( (Char >= '0') && (Char <= '9') )
    {
        return AT_SUCCESS;
    }
    else
    {
        return AT_FAILURE;
    }
}

TAF_UINT32 At_CheckLetter( TAF_UINT8 Char )
{
    if( ((Char >= 'a') && (Char <= 'z')) || ((Char >= 'A') && (Char <= 'Z')) || ('_' == Char) || ('&' == Char))
    {
        return AT_SUCCESS;
    }
    else
    {
        return AT_FAILURE;
    }
}

TAF_UINT32 At_CheckUpLetter( TAF_UINT8 Char )
{
    if( (Char >= 'A') && (Char <= 'Z') )
    {
        return AT_SUCCESS;
    }
    else
    {
        return AT_FAILURE;
    }
}

TAF_UINT32 At_CheckChar( TAF_UINT8 Char )
{
    if( ((Char >= 'a') && (Char <= 'z')) || ((Char >= 'A') && (Char <= 'Z')) || ((Char >= '0') && (Char <= '9')) || ('*' == Char) || ('#' == Char) || ('-' == Char) || ('.' == Char) )
    {
        return AT_SUCCESS;
    }
    else
    {
        return AT_FAILURE;
    }
}

/*****************************************************************************
 Prototype      : At_CheckAlpha
 Description    : �Ƚϡ�ƥ���ַ�('a'~'z' ��'A'~'Z')
 Input          : Char---������ַ�
 Output         : ---
 Return Value   : AT_SUCCESS --- �ɹ�
                  AT_FAILURE --- ʧ��
 Calls          : ---
 Called By      : ---

 History        : ---
  1.Date        : 2010-07-1
    Author      : ---
    Modification: Created function
*****************************************************************************/

TAF_UINT32 At_CheckAlpha( TAF_UINT8 Char )
{
    if( ((Char >= 'a') && (Char <= 'z')) || ((Char >= 'A') && (Char <= 'Z')) )
    {
        return AT_SUCCESS;
    }
    else
    {
        return AT_FAILURE;
    }
}
/*****************************************************************************
 Prototype      : At_CheckColon
 Description    : �Ƚϡ�ƥ�䶺��
 Input          : Char---������ַ�
 Output         : ---
 Return Value   : AT_SUCCESS --- �ɹ�
                  AT_FAILURE --- ʧ��
 Calls          : ---
 Called By      : ---

 History        : ---
  1.Date        : 2005-04-19
    Author      : ---
    Modification: Created function
*****************************************************************************/
TAF_UINT32 At_CheckColon( TAF_UINT8 Char )
{
    if( ',' == Char )
    {
        return AT_SUCCESS;
    }
    else
    {
        return AT_FAILURE;
    }
}
/*****************************************************************************
 Prototype      : At_CheckCharSub
 Description    : �Ƚϡ�ƥ�����
 Input          : Char---������ַ�
 Output         : ---
 Return Value   : AT_SUCCESS --- �ɹ�
                  AT_FAILURE --- ʧ��
 Calls          : ---
 Called By      : ---

 History        : ---
  1.Date        : 2005-04-19
    Author      : ---
    Modification: Created function
*****************************************************************************/
TAF_UINT32 At_CheckCharSub( TAF_UINT8 Char )
{
    if( '-' == Char )
    {
        return AT_SUCCESS;
    }
    else
    {
        return AT_FAILURE;
    }
}
/*****************************************************************************
 Prototype      : At_CheckQuot
 Description    : �Ƚϡ�ƥ������
 Input          : Char---������ַ�
 Output         : ---
 Return Value   : AT_SUCCESS --- �ɹ�
                  AT_FAILURE --- ʧ��
 Calls          : ---
 Called By      : ---

 History        : ---
  1.Date        : 2005-04-19
    Author      : ---
    Modification: Created function
*****************************************************************************/
TAF_UINT32 At_CheckQuot( TAF_UINT8 Char )
{
    if( '"' == Char )
    {
        return AT_SUCCESS;
    }
    else
    {
        return AT_FAILURE;
    }
}

TAF_UINT32 At_CheckHorizontalLine( TAF_UINT8 Char )
{
    if( '-' == Char )
    {
        return AT_SUCCESS;
    }
    else
    {
        return AT_FAILURE;
    }
}

/*****************************************************************************
 Prototype      : At_CheckEqu
 Description    : �Ƚϡ�ƥ��Ⱥ�
 Input          : Char---������ַ�
 Output         : ---
 Return Value   : AT_SUCCESS --- �ɹ�
                  AT_FAILURE --- ʧ��
 Calls          : ---
 Called By      : ---

 History        : ---
  1.Date        : 2005-04-19
    Author      : ---
    Modification: Created function
*****************************************************************************/
TAF_UINT32 At_CheckEqu( TAF_UINT8 Char )
{
    if( '=' == Char )
    {
        return AT_SUCCESS;
    }
    else
    {
        return AT_FAILURE;
    }
}
/*****************************************************************************
 Prototype      : At_CheckReq
 Description    : �Ƚϡ�ƥ���ʺ�
 Input          : Char---������ַ�
 Output         : ---
 Return Value   : AT_SUCCESS --- �ɹ�
                  AT_FAILURE --- ʧ��
 Calls          : ---
 Called By      : ---

 History        : ---
  1.Date        : 2005-04-19
    Author      : ---
    Modification: Created function
*****************************************************************************/
TAF_UINT32 At_CheckReq( TAF_UINT8 Char )
{
    if( '?' == Char )
    {
        return AT_SUCCESS;
    }
    else
    {
        return AT_FAILURE;
    }
}
/*****************************************************************************
 Prototype      : At_CheckNoQuot
 Description    : �Ƚϡ�ƥ�������
 Input          : Char---������ַ�
 Output         : ---
 Return Value   : AT_SUCCESS --- �ɹ�
                  AT_FAILURE --- ʧ��
 Calls          : ---
 Called By      : ---

 History        : ---
  1.Date        : 2005-04-19
    Author      : ---
    Modification: Created function
*****************************************************************************/
TAF_UINT32 At_CheckNoQuot( TAF_UINT8 Char )
{
    if( '"' != Char )
    {
        return AT_SUCCESS;
    }
    else
    {
        return AT_FAILURE;
    }
}

TAF_UINT32 At_CheckCharE( TAF_UINT8 Char )
{
    if( ('e' == Char) || ('E' == Char) )
    {
        return AT_SUCCESS;
    }
    else
    {
        return AT_FAILURE;
    }
}
/*****************************************************************************
 Prototype      : At_CheckChar1
 Description    : �Ƚϡ�ƥ���ַ�1
 Input          : Char---������ַ�
 Output         : ---
 Return Value   : AT_SUCCESS --- �ɹ�
                  AT_FAILURE --- ʧ��
 Calls          : ---
 Called By      : ---

 History        : ---
  1.Date        : 2005-04-19
    Author      : ---
    Modification: Created function
*****************************************************************************/
TAF_UINT32 At_CheckChar1( TAF_UINT8 Char )
{
    if( '1' == Char)
    {
        return AT_SUCCESS;
    }
    else
    {
        return AT_FAILURE;
    }
}
/*****************************************************************************
 Prototype      : At_CheckChar0
 Description    : �Ƚϡ�ƥ���ַ�0
 Input          : Char---������ַ�
 Output         : ---
 Return Value   : AT_SUCCESS --- �ɹ�
                  AT_FAILURE --- ʧ��
 Calls          : ---
 Called By      : ---

 History        : ---
  1.Date        : 2005-04-19
    Author      : ---
    Modification: Created function
*****************************************************************************/
TAF_UINT32 At_CheckChar0( TAF_UINT8 Char )
{
    if( '0' == Char)
    {
        return AT_SUCCESS;
    }
    else
    {
        return AT_FAILURE;
    }
}

TAF_UINT32 At_CheckCharV( TAF_UINT8 Char )
{
    if( ('v' == Char) || ('V' == Char) )
    {
        return AT_SUCCESS;
    }
    else
    {
        return AT_FAILURE;
    }
}

TAF_UINT32 At_CheckCharF( TAF_UINT8 Char )
{
    if( ('f' == Char) || ('F' == Char) )
    {
        return AT_SUCCESS;
    }
    else
    {
        return AT_FAILURE;
    }
}
/*****************************************************************************
 Prototype      : At_CheckCharE
 Description    : �Ƚϡ�ƥ���ַ�&
 Input          : Char---������ַ�
 Output         : ---
 Return Value   : AT_SUCCESS --- �ɹ�
                  AT_FAILURE --- ʧ��
 Calls          : ---
 Called By      : ---

 History        : ---
  1.Date        : 2005-04-19
    Author      : ---
    Modification: Created function
*****************************************************************************/
TAF_UINT32 At_CheckChar0x26( TAF_UINT8 Char )
{
    if( '&' == Char)
    {
        return AT_SUCCESS;
    }
    else
    {
        return AT_FAILURE;
    }
}

TAF_UINT32 At_CheckNumString( TAF_UINT8 *pData,TAF_UINT16 usLen )
{
    TAF_UINT16 usLength = 0;
    TAF_UINT8 *pcTmp    = pData;

    if( (TAF_NULL_PTR == pData) || (0 == usLen) )
    {
        return AT_FAILURE;
    }

    pcTmp = pData;

    while( usLength++ < usLen )
    {
        /*�ж��Ƿ�������*/
        if( (*pcTmp >= '0') && (*pcTmp <= '9') )
        {
            pcTmp++;
        }
        else
        {
            return AT_FAILURE;
        }
    }
    return AT_SUCCESS;
}


TAF_UINT32 At_CheckNumCharString( TAF_UINT8 *pData,TAF_UINT16 usLen )
{
    TAF_UINT16 usLength = 0;
    TAF_UINT8 *pcTmp    = pData;
    TAF_UINT32 ulCheckDigitRslt;
    TAF_UINT32 ulCheckCharRslt;

    if( (TAF_NULL_PTR == pData) || (0 == usLen) )
    {
        return AT_FAILURE;
    }

    pcTmp = pData;

    while( usLength++ < usLen )
    {
       ulCheckDigitRslt = At_CheckDigit(*pcTmp);
       ulCheckCharRslt = At_CheckAlpha(*pcTmp);

       if ((AT_SUCCESS == ulCheckDigitRslt)|| (AT_SUCCESS ==ulCheckCharRslt))
       {
            pcTmp++;
       }
       else
       {
            return AT_FAILURE;
       }
    }
    return AT_SUCCESS;
}

/*****************************************************************************
 Prototype      : At_CheckRightArrowStr
 Description    : �Ƚϡ�ƥ������
 Input          : pData --- ������ַ���
                  usLen --- ����ĳ���
 Output         : ---
 Return Value   : AT_SUCCESS --- �ɹ�
                  AT_FAILURE --- ʧ��
 Calls          : ---
 Called By      : ---

 History        : ---
  1.Date        : 2005-04-19
    Author      : ---
    Modification: Created function
*****************************************************************************/
TAF_UINT32 At_CheckRightArrowStr( TAF_UINT8 *pData,TAF_UINT16 usLen )
{
    TAF_UINT16 usLength = 0;
    TAF_UINT8 *pcTmp    = pData;

    while( usLength++ < usLen )
    {
        /*�ж��Ƿ���MMI�ַ�*/
        if(*pcTmp == '>')
        {
            return AT_SUCCESS;
        }
        else
        {
            pcTmp++;
        }
    }
    return AT_FAILURE;
}

TAF_UINT32 At_CheckMmiString( TAF_UINT8 *pData,TAF_UINT16 usLen )
{
    TAF_UINT16 usLength = 0;
    TAF_UINT8 *pcTmp    = pData;

    while( usLength++ < usLen )
    {
        /*�ж��Ƿ���MMI�ַ�*/
        if((*pcTmp == '*') || (*pcTmp == '#') )
        {
            return AT_SUCCESS;
        }
        else
        {
            pcTmp++;
        }
    }
    return AT_FAILURE;
}

/*****************************************************************************
 Prototype      : At_CheckJuncture
 Description    : �Ƚϡ�ƥ�����ӷ�
 Input          : Char---������ַ�
 Output         : ---
 Return Value   : AT_SUCCESS --- �ɹ�
                  AT_FAILURE --- ʧ��
 Calls          : ---
 Called By      : ---

 History        : ---
  1.Date        : 2005-04-19
    Author      : ---
    Modification: Created function
*****************************************************************************/
TAF_UINT32 At_CheckJuncture( TAF_UINT8 Char )
{
    if( '-' == Char )
    {
        return AT_SUCCESS;
    }
    else
    {
        return AT_FAILURE;
    }
}

/*****************************************************************************
 Prototype      : At_CheckEnd
 Description    : �Ƚϡ�ƥ�������
 Input          : Char---������ַ�
 Output         : ---
 Return Value   : AT_SUCCESS --- �ɹ�
                  AT_FAILURE --- ʧ��
 Calls          : ---
 Called By      : ---

 History        : ---
  1.Date        : 2005-04-19
    Author      : ---
    Modification: Created function
*****************************************************************************/
TAF_UINT32 At_CheckEnd( TAF_UINT8 Char )
{
    if( '\0' == Char )
    {
        return AT_SUCCESS;
    }
    else
    {
        return AT_FAILURE;
    }
}


VOS_UINT32 AT_CheckDateFormat(
    VOS_UINT8                           *pucDateStr,
    VOS_UINT32                          ulDateStrLen
)
{
    VOS_UINT8                           ucFirstJuncture;
    VOS_UINT8                           ucSecondJuncture;
    VOS_UINT8                           ucFirstColon;
    VOS_UINT8                           ucSecondColon;
    VOS_UINT8                           ucSpace;

    /* ��ʽΪ2009-12-31 10:10:10�������ַ���: �ܳ��ȱ���Ϊ19 */
    if (19 != ulDateStrLen)
    {
        AT_NORM_LOG1("AT_CheckDateFormat: length error.", (VOS_INT32)ulDateStrLen);
        return AT_ERROR;
    }

    /* ��ʽΪ2009-12-31 10:10:10�������ַ���: ��5���ֽ�Ϊ'-', ��8���ֽ�Ϊ'-' */
    ucFirstJuncture     = *(pucDateStr + 4);
    ucSecondJuncture    = *(pucDateStr + 7);
    if (('-' != ucFirstJuncture) || ('-' != ucSecondJuncture))
    {
        AT_NORM_LOG("AT_CheckDateFormat: Fail to check juncture.");
        return AT_ERROR;
    }

    /* ��ʽΪ2009-12-31 10:10:10�������ַ���: ��11���ֽ�Ϊ' ' */
    ucSpace = *(pucDateStr + 10);
    if (' ' != ucSpace)
    {
        AT_NORM_LOG("AT_CheckDateFormat: Fail to check space.");
        return AT_ERROR;
    }

    /* ��ʽΪ2009-12-31 10:10:10�������ַ���: ��14���ֽ�Ϊ':' ��17���ֽ�Ϊ':' */
    ucFirstColon    = *(pucDateStr + 13);
    ucSecondColon   = *(pucDateStr + 16);
    if ((':' != ucFirstColon) || (':' != ucSecondColon))
    {
        AT_NORM_LOG("AT_CheckDateFormat: Fail to check colon.");
        return AT_ERROR;
    }

    return AT_OK;
}


VOS_UINT32 AT_GetDaysForEachMonth(
    VOS_UINT32                          ulYear,
    VOS_UINT32                          ulMonth
)
{
    if ((1 == ulMonth) || (3 == ulMonth) || (5 == ulMonth) || (7 == ulMonth)
     || (8 == ulMonth) || (10 == ulMonth) || (12 == ulMonth) )
    {
        /* 1,3,5,7,8,10,12����31�� */
        return 31;
    }
    else if ((4 == ulMonth) || (6 == ulMonth) || (9 == ulMonth) || (11 == ulMonth))
    {
        /* 4,6,9,11����30�� */
        return 30;
    }
    else
    {
        /* 2�¿��Ƿ�Ϊ���꣬����Ϊ29�죬����Ϊ28�� */
        if ( ((0 == (ulYear % 4)) && (0 != (ulYear % 100))) || (0 == (ulYear % 400)))
        {
            /* ���� */
            return 29;
        }
        else
        {
            /* ������ */
            return 28;
        }
    }
}


VOS_UINT32  AT_CheckDate(
    AT_DATE_STRU                        *pstDate
)
{
    VOS_UINT32                          ulDaysEachMonth;

    /* �·���Ч�Լ��: �·���ֵ���벻Ϊ0����С�ڵ���12 */
    if ((pstDate->ulMonth > 12)
     || (0 == pstDate->ulMonth))
    {
        AT_NORM_LOG("AT_CheckDate: Fail to check month.");
        return AT_ERROR;
    }

    /* ������Ч�Լ��: ������ֵ���벻Ϊ0����С�ڵ��ڵ��µ������� */
    ulDaysEachMonth = AT_GetDaysForEachMonth(pstDate->ulYear, pstDate->ulMonth);
    if ((pstDate->ulDay > ulDaysEachMonth)
     || (0 == pstDate->ulDay))
    {
        AT_NORM_LOG("AT_CheckDate: Fail to check day.");
        return AT_ERROR;
    }

    /* ʱ����Ч�Լ��: Сʱ������С��24�����ӻ���������С��60 */
    if ((pstDate->ulHour >= 24)
     || (pstDate->ulMunite >= 60)
     || (pstDate->ulSecond >= 60))
    {
        AT_NORM_LOG("AT_CheckDate: Fail to check time.");
        return AT_ERROR;
    }

    return AT_OK;
}


VOS_UINT32  AT_GetDate(
    VOS_UINT8                           *pucDateStr,
    VOS_UINT32                          ulDateStrLen,
    AT_DATE_STRU                        *pstDate
)
{
    VOS_UINT32                          ulRet;

    /* ��ȡ�����е����: ���ռ��4���ֽ� */
    ulRet = At_Auc2ul(pucDateStr, 4, &pstDate->ulYear);
    if (AT_SUCCESS != ulRet)
    {
        AT_NORM_LOG("AT_GetDate: Fail to get year.");
        return AT_ERROR;
    }

    /* ��ȡ�����е��·�: �·�ռ��2���ֽڣ�ƫ�����ռ�õ�4���ֽں�'-'һ���ֽ� */
    ulRet = At_Auc2ul((pucDateStr + 5), 2, &pstDate->ulMonth);
    if (AT_SUCCESS != ulRet)
    {
        AT_NORM_LOG("AT_GetDate: Fail to get month.");
        return AT_ERROR;
    }

    /* ��ȡ�����е�����: ����ռ��2���ֽڣ�ƫ���·�ռ�õ�2���ֽں�'-'һ���ֽ� */
    ulRet = At_Auc2ul((pucDateStr + 8), 2, &pstDate->ulDay);
    if (AT_SUCCESS != ulRet)
    {
        AT_NORM_LOG("AT_GetDate: Fail to get day.");
        return AT_ERROR;
    }

    /* ��ȡ�����е�Сʱ: Сʱռ��2���ֽڣ�ƫ������ռ�õ�2���ֽں�' 'һ���ֽ� */
    ulRet = At_Auc2ul((pucDateStr + 11), 2, &pstDate->ulHour);
    if (AT_SUCCESS != ulRet)
    {
        AT_NORM_LOG("AT_GetDate: Fail to get hour.");
        return AT_ERROR;
    }

    /* ��ȡ�����еķ���: ����ռ��2���ֽڣ�ƫ��Сʱռ�õ�2���ֽں�':'һ���ֽ� */
    ulRet = At_Auc2ul((pucDateStr + 14), 2, &pstDate->ulMunite);
    if (AT_SUCCESS != ulRet)
    {
        AT_NORM_LOG("AT_GetDate: Fail to get minute.");
        return AT_ERROR;
    }

    /* ��ȡ�����е�����: ����ռ��2���ֽڣ�ƫ�Ʒ���ռ�õ�2���ֽں�':'һ���ֽ� */
    ulRet = At_Auc2ul((pucDateStr + 17), 2, &pstDate->ulSecond);
    if (AT_SUCCESS != ulRet)
    {
        AT_NORM_LOG("AT_GetDate: Fail to get second.");
        return AT_ERROR;
    }

    return AT_OK;
}


VOS_UINT32 At_CheckAndParsePara(
    AT_PARSE_PARA_TYPE_STRU             *pstAtPara,
    VOS_UINT8                           *pucBegain,
    VOS_UINT8                           *pucEnd
)
{
    VOS_UINT32                          ulParaLen;

    ulParaLen  = (VOS_UINT32)(pucEnd - pucBegain);

    if ((0 == ulParaLen)
     || (AT_PARA_MAX_LEN < ulParaLen))
    {
        return AT_ERROR;
    }

    pstAtPara->usParaLen = (VOS_UINT16)ulParaLen;

    At_RangeCopy(pstAtPara->aucPara, pucBegain, pucEnd);

    return AT_OK;

}


VOS_UINT32 AT_CheckStrStartWith(
    VOS_UINT8                          *pucLineStr,
    VOS_UINT8                          *pucPefixStr
)
{
    for ( ; (*pucLineStr != '\0') && (*pucPefixStr != '\0'); pucLineStr++, pucPefixStr++)
    {
        if (*pucLineStr != *pucPefixStr)
        {
            return VOS_FALSE;
        }
    }

    if ('\0' == *pucPefixStr)
    {
        return VOS_TRUE;
    }
    else
    {
        return VOS_FALSE;
    }
}


#ifdef  __cplusplus
  #if  __cplusplus
  }
  #endif
#endif
