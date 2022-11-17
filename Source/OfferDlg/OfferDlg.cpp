
// OfferDlg.cpp: 实现文件
//
#pragma warning(disable: 4311 4302)
#include "pch.h"
#include "framework.h"
#include "Offer.h"
#include "OfferDlg.h"
#include "afxdialogex.h"
#include "Logger.h"
#include "Encode.h"
#include "TimeUtility.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

TCHAR g_sztListCols[13][12] = {
	_T("序号"), _T("公司"), _T("客户号"), _T("客户名称"), _T("状态"), _T("委托"),
	_T("撤单"), _T("成交"), _T("成手"), _T("委托回报"), _T("成交回报"),
	_T("开收盘通知"), _T("登录状态")
};
int g_iListCols[13] = { 37, 0, 72, 100, 100, 37, 37, 37, 37, 60, 60, 0, 80 };

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// COfferDlg 对话框



COfferDlg::COfferDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_OFFER_DIALOG, pParent),
	m_TradingDayText(L""),
	m_SendAndRecvText(L"0\n0"),
	m_StatisticNumberText(L"0\n0")
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_OfferInit = nullptr;
	m_Send = 0;
	m_Recv = 0;
	m_Statistic = 0;
	m_ErrorData = 0;
}

void COfferDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Text(pDX, IDC_STATIC_TRADING_DAY, m_TradingDayText);
	DDX_Text(pDX, IDC_STATIC_SEND_AND_RECV, m_SendAndRecvText);
	DDX_Text(pDX, IDC_STATIC_STATISTIC_NUMBER, m_StatisticNumberText);
}

BEGIN_MESSAGE_MAP(COfferDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_CLOSE()
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// COfferDlg 消息处理程序

BOOL COfferDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	
	// TODO: 在此添加额外的初始化代码
	
	auto date = Encode::utf8_to_wstring(GetLocalDate());
	m_TradingDayText = date.c_str();

	LVCOLUMN lc = { 0 };
	lc.mask = LVCF_FMT | LVCF_ORDER | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;
	for (int i = 0; i < (int)sizeof(g_sztListCols) / sizeof(g_sztListCols[0]); ++i)
	{
		lc.cx = g_iListCols[i];
		lc.iOrder = i;
		lc.iSubItem = i;
		lc.fmt = LVCFMT_LEFT;
		lc.pszText = g_sztListCols[i];
		ListView_InsertColumn(m_List.m_hWnd, i, &lc);
	}
	LRESULT lListStyle = ::SendMessage(m_List.m_hWnd, LVM_GETEXTENDEDLISTVIEWSTYLE, 0, 0);
	lListStyle |= (LVS_EX_FULLROWSELECT | LVS_EX_HEADERDRAGDROP);
	::SendMessage(m_List.m_hWnd, LVM_SETEXTENDEDLISTVIEWSTYLE, 0, lListStyle);

	m_OfferInit = OfferInit::CreateInstance();
	if (!m_OfferInit->Init(this))
	{
		SendMessage(WM_CLOSE, 0, 0);
		return FALSE;
	}
	if (!m_OfferInit->Start())
	{
		SendMessage(WM_CLOSE, 0, 0);
		return FALSE;
	}
	auto dateTime = Encode::utf8_to_wstring(GetLocalDateTime());
	SetWindowText((m_ProgramName + L": Start at " + dateTime).c_str());
	UpdateData(FALSE);
	SetTimer(1, 2000, NULL);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void COfferDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void COfferDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR COfferDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void COfferDlg::SetProgramName(const char* name)
{
	m_ProgramName = Encode::utf8_to_wstring(name);
}
void COfferDlg::AddAccountInfo(AccountInfo* accountInfo)
{
	AddListRow(int(m_AccountInfos.size()), accountInfo);
	AccountInfo* newAccountInfo = new AccountInfo();
	*newAccountInfo = *accountInfo;
	m_AccountInfos.push_back(newAccountInfo);
}
void COfferDlg::UpdateAccountInfo(AccountInfo* accountInfo)
{
	auto it = GetAccountInfoIterator(accountInfo->AccountID);
	if (it == m_AccountInfos.end())
	{
		AddListRow(int(m_AccountInfos.size()), accountInfo);
		AccountInfo* newAccountInfo = new AccountInfo();
		*newAccountInfo = *accountInfo;
		m_AccountInfos.push_back(newAccountInfo);
	}
	else
	{
		**it = *accountInfo;
		UpdateListRow(int(it - m_AccountInfos.begin()), accountInfo);
	}
}
void COfferDlg::UpdateStatus(const std::wstring& accountID, int status)
{
	auto it = GetAccountInfoIterator(accountID);
	if (it != m_AccountInfos.end())
	{
		m_List.SetItemText(int(it - m_AccountInfos.begin()), 4, StatusText::MapValues[status].c_str());
	}
}
void COfferDlg::UpdateReqOrderNum(const std::wstring& accountID, int reqOrderNum)
{
	auto it = GetAccountInfoIterator(accountID);
	if (it != m_AccountInfos.end())
	{
		m_List.SetItemText(int(it - m_AccountInfos.begin()), 5, std::to_wstring(reqOrderNum).c_str());
	}
}
void COfferDlg::UpdateReqCancelNum(const std::wstring& accountID, int reqCancelNum)
{
	auto it = GetAccountInfoIterator(accountID);
	if (it != m_AccountInfos.end())
	{
		m_List.SetItemText(int(it - m_AccountInfos.begin()), 6, std::to_wstring(reqCancelNum).c_str());
	}
}
void COfferDlg::UpdateTradeNum(const std::wstring& accountID, int tradeNum)
{
	auto it = GetAccountInfoIterator(accountID);
	if (it != m_AccountInfos.end())
	{
		m_List.SetItemText(int(it - m_AccountInfos.begin()), 7, std::to_wstring(tradeNum).c_str());
	}
}
void COfferDlg::UpdateTradeVolume(const std::wstring& accountID, int tradeVolume)
{
	auto it = GetAccountInfoIterator(accountID);
	if (it != m_AccountInfos.end())
	{
		m_List.SetItemText(int(it - m_AccountInfos.begin()), 8, std::to_wstring(tradeVolume).c_str());
	}
}
void COfferDlg::UpdateRtnOrderNum(const std::wstring& accountID, int rtnOrderNum)
{
	auto it = GetAccountInfoIterator(accountID);
	if (it != m_AccountInfos.end())
	{
		m_List.SetItemText(int(it - m_AccountInfos.begin()), 9, std::to_wstring(rtnOrderNum).c_str());
	}
}
void COfferDlg::UpdateRtnTradeNum(const std::wstring& accountID, int rtnTradeNum)
{
	auto it = GetAccountInfoIterator(accountID);
	if (it != m_AccountInfos.end())
	{
		m_List.SetItemText(int(it - m_AccountInfos.begin()), 10, std::to_wstring(rtnTradeNum).c_str());
	}
}
void COfferDlg::UpdateExchangeNotify(const std::wstring& accountID, const std::wstring& exchangeNotify)
{
	auto it = GetAccountInfoIterator(accountID);
	if (it != m_AccountInfos.end())
	{
		m_List.SetItemText(int(it - m_AccountInfos.begin()), 11, exchangeNotify.c_str());
	}
}
void COfferDlg::UpdateLoginStatus(const std::wstring& accountID, int loginStatus)
{
	auto it = GetAccountInfoIterator(accountID);
	if (it != m_AccountInfos.end())
	{
		m_List.SetItemText(int(it - m_AccountInfos.begin()), 12, LoginStatusText::MapValues[loginStatus].c_str());
	}
}

void COfferDlg::AddListRow(int row, AccountInfo* accountInfo)
{
	static LVITEM listItem;
	listItem.mask = LVIF_TEXT | LVIF_PARAM;
	listItem.iItem = row;
	listItem.iSubItem = 0;
	m_List.InsertItem(&listItem);
	UpdateListRow(row, accountInfo);
}
void COfferDlg::UpdateListRow(int row, AccountInfo* accountInfo)
{
	m_List.SetItemText(row, 0, std::to_wstring(accountInfo->SequenceNo).c_str());
	m_List.SetItemText(row, 1, accountInfo->CompanyName.c_str());
	m_List.SetItemText(row, 2, accountInfo->AccountID.c_str());
	m_List.SetItemText(row, 3, accountInfo->AccountName.c_str());
	m_List.SetItemText(row, 4, StatusText::MapValues[accountInfo->Status].c_str());
	m_List.SetItemText(row, 5, std::to_wstring(accountInfo->ReqOrderNum).c_str());
	m_List.SetItemText(row, 6, std::to_wstring(accountInfo->ReqCancelNum).c_str());
	m_List.SetItemText(row, 7, std::to_wstring(accountInfo->TradeNum).c_str());
	m_List.SetItemText(row, 8, std::to_wstring(accountInfo->TradeVolume).c_str());
	m_List.SetItemText(row, 9, std::to_wstring(accountInfo->RtnOrderNum).c_str());
	m_List.SetItemText(row, 10, std::to_wstring(accountInfo->RtnTradeNum).c_str());
	m_List.SetItemText(row, 11, accountInfo->ExchangeNotify.c_str());
	m_List.SetItemText(row, 12, LoginStatusText::MapValues[accountInfo->LoginStatus].c_str());
}
void COfferDlg::UpdateListItem(int row, int column, const std::wstring& value)
{
	m_List.SetItemText(row, column, value.c_str());
}

std::vector<AccountInfo*>::iterator COfferDlg::GetAccountInfoIterator(const std::wstring& accountID)
{
	auto it = std::find_if(m_AccountInfos.begin(), m_AccountInfos.end(), [&](AccountInfo* a) {
		return a->AccountID == accountID;
		});
	if (it == m_AccountInfos.end())
	{
		WRITE_LOG(LogLevel::Warning, "Can't Find AccountInfo for AccountID:[%s].", Encode::wstring_to_utf8(accountID).c_str());
	}
	return it;
}

void COfferDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	auto tradingDay = Encode::utf8_to_wstring(GetLocalDate());
	if (m_TradingDayText.Compare(tradingDay.c_str()) != 0)
	{
		m_TradingDayText = tradingDay.c_str();
	}
	m_SendAndRecvText = (std::to_wstring(m_Send) +L"\n" + std::to_wstring(m_Recv)).c_str();
	m_StatisticNumberText = (std::to_wstring(m_Statistic) + L"\n" + std::to_wstring(m_ErrorData)).c_str();

	UpdateData(FALSE);
	
	CDialogEx::OnTimer(nIDEvent);
}

void COfferDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	auto result = AfxMessageBox(L"停止并退出报盘机吗？", MB_OKCANCEL);
	if (result == IDCANCEL)
	{
		return;
	}

	m_OfferInit->Stop();
	for (auto accountInfo : m_AccountInfos)
	{
		delete accountInfo;
	}
	m_AccountInfos.clear();

	CDialogEx::OnClose();
}
