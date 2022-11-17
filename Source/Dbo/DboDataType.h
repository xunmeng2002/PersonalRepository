#pragma once


//布尔类型
typedef int CBoolType;
//整型
typedef int CNumType;
typedef int CIDType;
typedef int CIDTypeType;
//8位数字表示的日期
typedef int CDateType;
//年
typedef int CYearType;
//月
typedef int CMonthType;
typedef int CStatusType;
typedef int CAccountType;
typedef int CNationType;
//报单编号
typedef int COrderIDType;
//数量
typedef int CVolumeType;
typedef int CGroupIDType;
typedef int CGroupTypeType;
typedef int CFlagType;
//银行卡号
typedef int CBankCardIDType;
//出入金方式
typedef int CMethodType;
typedef int CTwoStepCodeTimeType;
typedef int CAddressTypeType;
typedef int CDomesticAccountTypeType;
typedef int CDomesticCurrencyTypeType;
typedef int COpeningIDType;
typedef int CBankIDType;
typedef int CIdentityIDType;
typedef int CEmailTypeType;
typedef int CBillLanguageType;
typedef int CBillTypeType;
typedef int CExchangeMethodType;
typedef int CFatcaStatusType;
typedef int CRecoveryCriteriaType;
typedef int CSexType;
typedef int CTaxTableTypeType;
typedef int CFatcaStatusType;
typedef int CFatcaTypeType;
typedef int CFaxTypeType;
typedef int CMobileTypeType;
typedef int COrganizationalNatureType;
typedef int CChannelIDType;
typedef int CTelTypeType;
typedef int CFrontIDType;
typedef int CSessionIDType;
typedef int CRequestIDType;
typedef int CSwapOrderType;
typedef int CT1ValidType;
typedef int CInsertIDType;
typedef int CPatchOrderType;
typedef int CItemType;
typedef int CResultType;
typedef int CLocalTradeIDType;
typedef int CDecimalDigitsType;
typedef int CT1SplitTimeType;
typedef int CDeliveryMethodType;
typedef int CRiskIDType;
typedef int CRiskClassType;
typedef int CRiskItemType;
typedef int CNoticeType;
typedef int CStageType;
typedef int CActionType;
typedef int CIconType;
typedef int CParentIDType;
typedef int CRoleIDType;
typedef int CMenuIDType;
typedef int CPermissionIDType;
typedef int CPortType;


//比率
typedef double CRateType;
//价格
typedef double CPriceType;
//金额
typedef double CMoneyType;
typedef double CParamType;
typedef double CVolumeMultipleType;
typedef double CPriceTickType;
typedef double CLevyType;

typedef char CRemarkType[64];
//交易所编号
typedef char CExchangeIDType[8];
//交易所名称
typedef char CExchangeNameType[8];
//合约
typedef char CContractIDType[32];
//合约名称
typedef char CContractNameType[32];
//品种
typedef char CProductIDType[16];
typedef char COperatorIDType[16];
typedef char CAuditorIDType[16];
typedef char CSoftwareType[12];
typedef char CAuthCodeType[16];
typedef char CCodeType[10];
typedef char CNameType[32];
//成交编号
typedef char CTradeIDType[32];
typedef char CTimeType[9];
typedef char CCurrencyGroupType[5];
typedef char CCurrencyIDType[3];
typedef char CGroupNameType[64];
typedef char CInvestorNameType[64];
typedef char CPasswordType[36];
typedef char CTwoStepCodeType[8];
typedef char CAddressType[256];
typedef char CPostCodeType[16];
typedef char CBranchType[64];
typedef char CCardNoType[24];
typedef char COwnerType[20];
typedef char CEmailType[128];
typedef char CEmployeeNameType[20];
typedef char CCareerType[64];
typedef char CEmployeeNoType[64];
typedef char CEnNameType[64];
typedef char CGinTaxNumberType[64];
typedef char CTinTaxNumberType[64];
typedef char CZhNameType[64];
typedef char CFaxType[64];
typedef char CAreaCodeType[5];
typedef char CIDIssuePlaceType[255];
typedef char CIDNumberType[32];
typedef char CMobileType[16];
typedef char CBusinessLicenseNoType[64];
typedef char CLegalPersonType[20];
typedef char CTaxNumberType[64];
typedef char CTelType[64];
typedef char CAdminType[16];
typedef char CIPType[40];
typedef char CMACType[24];
typedef char CUserProductType[20];
typedef char CHardwareType[64];
typedef char COSType[32];
typedef char CForceReasonType[64];
typedef char COrderSysIDType[40];
typedef char COrderRemarkType[256];
typedef char COrderRefType[16];
typedef char CTag50Type[16];
typedef char CChannelOrderIDType[24];
typedef char CUserOrderIDType[32];
typedef char CProductNameType[32];
typedef char CProductCombinationType[256];
typedef char CContentsType[256];
typedef char CTitleType[64];
typedef char CCommentType[4096];
typedef char CPermissionType[64];
typedef char CTargetUrlType[1024];
typedef char CAvatarType[64];
typedef char CSysParamType[32];
typedef char CSysParamValueType[8192];
typedef char CExchangeTradeIDType[72];
typedef char CPatchAccountType[16];
typedef char CUserIDType[32];
typedef char CChannelNameType[64];
typedef char CExchangeTradeIDType[72];

//交易状态
enum class CTradeStatusType : char
{
	//未知
	Unknown = '0',
	//集合竞价报单
	AuctionOrdering = '1',
	//连续交易
	Trading = '2',
	//暂停
	Pause = '3',
	//收市
	Closed = '4',
};
//产品类型
enum class CProductClassType : char
{
	//未知
	Futures = '1',
	//集合竞价报单
	Options = '2',
	//连续交易
	Combination = '3',
	//暂停
	Spot = '4',
	//收市
	EFP = '5',
	//收市
	SpotOption = '6',
};
//持仓类型
enum class CPositionTypeType : char
{
	//净持仓
	Net = '1',
	//综合持仓
	Gross = '2',
};
//持仓类型
enum class CPositionDateTypeType : char
{
	//使用历史持仓（区分今昨仓）
	UseHistory = '1',
	//不使用历史持仓（不区分今昨仓）
	NoUseHistory = '2',
};
//报单状态
enum class COrderStatusType : char
{
	//正在申报
	PTK_OST_Inserting = '0',
	//已报
	PTK_OST_Inserted = '1',
	//部成
	PTK_OST_PartTraded = '2',
	//已成
	PTK_OST_AllTraded = '3',
	//已撤
	PTK_OST_Canceled = '4',
	//部成部撤
	PTK_OST_PartTradedCanceled = '5',
	//废单
	PTK_OST_Error = 'e',
	//未触发
	PTK_OST_NotTouched = 'p',
	//已触发
	PTK_OST_Touched = 't',
	//未知
	PTK_OST_Unknown = 'x',
};
//买卖方向
enum class CDirectionType : char
{
	//买入
	Buy = '0',
	//卖出
	Sell = '1',
};
//投保标志
enum class CHedgeFlagType : char
{
	//投机
	Speculation = '0',
	//套利
	Arbitrage = '1',
	//保值
	Hedge = '2',
};
//报单价格条件
enum class COrderPriceTypeType : char
{
	//市价
	AnyPrice = '1',
	//限价
	LimitPrice = '2',
	//最优价
	BestPrice = '3',
	//最新价
	LastPrice = '4',
	//最新价浮动上浮1个ticks
	LastPricePlusOneTicks = '5',
	//最新价浮动上浮2个ticks
	LastPricePlusTwoTicks = '6',
	//最新价浮动上浮3个ticks
	LastPricePlusThreeTicks = '7',
	//卖一价
	AskPrice1 = '8',
	//卖一价浮动上浮1个ticks
	AskPrice1PlusOneTicks = '9',
	//卖一价浮动上浮2个ticks
	AskPrice1PlusTwoTicks = 'A',
	//卖一价浮动上浮3个ticks
	AskPrice1PlusThreeTicks = 'B',
	//买一价
	BidPrice1 = 'C',
	//买一价浮动上浮1个ticks
	BidPrice1PlusOneTicks = 'D',
	//买一价浮动上浮2个ticks
	BidPrice1PlusTwoTicks = 'E',
	//买一价浮动上浮3个ticks
	BidPrice1PlusThreeTicks = 'F',
};
//开平标志
enum class COffsetFlagType : char
{
	//开仓
	Open = '0',
	//平仓
	Close = '1',
	//平今
	CloseToday = '2',
};
//撤单改单类型
enum class CCancelTypeType : char
{
	//撤单
	Delete = '0',
	//改单
	Modify = '3',
};
//触发条件类型
enum class CContingentConditionType : char
{
	//立即
	Immediately = '1',
	//止损
	Touch = '2',
	//止赢
	TouchProfit = '3',
	//预埋单
	ParkedOrder = '4',
	//最新价大于条件价
	LastPriceGreaterThanStopPrice = '5',
	//最新价大于等于条件价
	LastPriceGreaterEqualStopPrice = '6',
	//最新价小于条件价
	LastPriceLesserThanStopPrice = '7',
	//最新价小于等于条件价
	LastPriceLesserEqualStopPrice = '8',
	//卖一价大于条件价
	AskPriceGreaterThanStopPrice = '9',
	//卖一价大于等于条件价
	AskPriceGreaterEqualStopPrice = 'A',
	//卖一价小于条件价
	AskPriceLesserThanStopPrice = 'B',
	//卖一价小于等于条件价
	AskPriceLesserEqualStopPrice = 'C',
	//买一价大于条件价
	BidPriceGreaterThanStopPrice = 'D',
	//买一价大于等于条件价
	BidPriceGreaterEqualStopPrice = 'E',
	//买一价小于条件价
	BidPriceLesserThanStopPrice = 'F',
	//买一价小于等于条件价
	BidPriceLesserEqualStopPrice = 'H',
};
//有效期类型
enum class CTimeConditionType : char
{
	//立即完成，否则撤销
	IOC = '1',
	//本节有效
	GFS = '2',
	//当日有效
	GFD = '3',
	//指定日期前有效
	GTD = '4',
	//撤销前有效
	GTC = '5',
	//集合竞价有效
	GFA = '6',
};
//成交量类型
enum class CVolumeConditionType : char
{
	//任何数量
	AV = '1',
	//最小数量
	MV = '2',
	//全部数量
	CV = '3',
};
//强平原因
enum class CForceCloseReasonType : char
{
	//非强平
	NotForceClose = '0',
	//资金不足
	LackDeposit = '1',
	//客户超仓
	ClientOverPositionLimit = '2',
	//会员超仓
	MemberOverPositionLimit = '3',
	//持仓非整数倍
	NotMultiple = '4',
	//违规
	Violation = '5',
	//其它
	Other = '6',
	//自然人临近交割
	PersonDeliv = '7',
};
//成交类型
enum class CTradeTypeType : char
{
	//普通成交
	Common = '0',
	//期权执行
	OptionsExecution = '1',
	//OTC成交
	OTC = '2',
	//期转现衍生成交
	EFPDerived = '3',
	//组合衍生成交
	CombinationDerived = '4',
};
//保证金价格类型
enum class CMarginPriceType : char
{
	//昨结算价
	PreSettlementPrice = '1',
	//最新价
	SettlementPrice = '2',
	//成交均价
	AveragePrice = '3',
	//开仓价
	OpenPrice = '4',
};
//浮盈浮亏是否计入可用
enum class CIncludePositionProfitType : char
{
	//浮盈浮亏都计算
	All = '1',
	//浮盈不计，浮亏计
	OnlyLost = '2',
	//浮盈计，浮亏不计
	OnlyGain = '3',
	//浮盈浮亏都不计算
	None = '4',
};
//平仓盈利类型是否可用
enum class CIncludeCloseProfitType : char
{
	//浮盈浮亏都计算
	Include = '0',
	//浮盈不计，浮亏计
	NotInclude = '2',
};
//是否启用上期所大额单边保证金
enum class CLargeSideMarginType : char
{
	//不使用大额单边保证金算法
	NO = '0',
	//使用大额单边保证金算法
	YES = '1',
};
//账户类型
enum class CInvestorAccountType : char
{
	//投资者
	Investor = '0',
	//管理员
	Admin = '1',
};
//通知类型
enum class CNotifyType : char
{
	//普通
	Message = '0',
	//警告
	Warning = '1',
	//已强平
	ForceClose = '2',
	//CTP通知（此消息只推给监控）
	CTP = '3',
};
//账号状态
enum class CAccountStatusType : char
{
	//禁用
	Forbidden = '0',
	//启用
	Enable = '1',
};
//账号类型
enum class CAccountTypeType : char
{
	//个人
	Individual = '1',
	//机构
	Organizational = '2',
	//做市商
	MarketMaker = '3',
};
//代理类型
enum class CAgentTypeType : char
{
	Client = '1',
	House = '2',
	Account = '3',
};
//委托类型
enum class COrderTypeType : char
{
	NonPlenipotentiary = '1',
	Plenipotentiary = '2',
};
//投资者类型
enum class CInvestorTypeType : char
{
	InvestorA = '1',
	InvestorB = '2',
};
//登录状态
enum class CLoginStatusType : char
{
	//正常
	Normal = '1',
	//禁止登录
	Forbidden = '2',
};
//保证金类型
enum class CMarginTypeType : char
{
	//比例
	Rate = '1',
	//固定金额
	Fixed = '2',
	//折扣
	Discount = '3',
};

//日期时间类型
typedef char CDateTimeType[32];

