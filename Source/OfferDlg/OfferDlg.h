
// OfferDlg.h: 头文件
//

#pragma once
#include <vector>
#include "AccountInfo.h"
#include "OfferInit.h"

// COfferDlg 对话框
class COfferDlg : public CDialogEx
{
// 构造
public:
	COfferDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OFFER_DIALOG };
#endif
	CListCtrl	m_List;
	std::vector<AccountInfo*> m_AccountInfos;


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	void SetProgramName(const char* name);
	void AddAccountInfo(AccountInfo* accountInfo);
	void UpdateAccountInfo(AccountInfo* accountInfo);
	void UpdateStatus(const std::wstring& accountID, int status);
	void UpdateReqOrderNum(const std::wstring& accountID, int reqOrderNum);
	void UpdateReqCancelNum(const std::wstring& accountID, int reqCancelNum);
	void UpdateTradeNum(const std::wstring& accountID, int tradeNum);
	void UpdateTradeVolume(const std::wstring& accountID, int tradeVolume);
	void UpdateRtnOrderNum(const std::wstring& accountID, int rtnOrderNum);
	void UpdateRtnTradeNum(const std::wstring& accountID, int rtnTradeNum);
	void UpdateExchangeNotify(const std::wstring& accountID, const std::wstring& exchangeNotify);
	void UpdateLoginStatus(const std::wstring& accountID, int loginStatus);
protected:
	void AddListRow(int row, AccountInfo* accountInfo);
	void UpdateListRow(int row, AccountInfo* accountInfo);
	void UpdateListItem(int row, int column, const std::wstring& value);

	std::vector<AccountInfo*>::iterator GetAccountInfoIterator(const std::wstring& accountID);
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnClose();

private:
	OfferInit* m_OfferInit;
public:
	std::wstring m_ProgramName;
	int m_Send;
	int m_Recv;
	int m_Statistic;
	int m_ErrorData;
	CString m_SendAndRecvText;
	CString m_StatisticNumberText;
	CString m_TradingDayText;
};
