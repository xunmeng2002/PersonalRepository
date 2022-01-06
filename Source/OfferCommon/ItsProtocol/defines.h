
/////////////////////////////////////////////////////////////////////////

#ifndef __CMS_PROCESSOR_DEFINES__
#define __CMS_PROCESSOR_DEFINES__

#define MAX_EXCHANGE_ID_LEN 12
#define MAX_EXCHANGE_NAME_LEN 32
#define MAX_PRODUCT_ID_LEN 16
#define MAX_PRODUCT_NAME_LEN 32
#define MAX_CONTRACT_ID_LEN 32
#define MAX_CONTRACT_NAME_LEN 32
#define MAX_BROKER_NAME_LEN 8
#define MAX_ACCOUNT_ID_LEN 16
#define MAX_PASSWORD_LEN 48
#define MAX_ACCOUNT_NAME_LEN 64
#define MAX_ORDER_REF_LEN 16
#define MAX_ORDER_SYSID_LEN 24
#define MAX_ORDER_USERID_LEN 32
#define MAX_TRADE_ID_LEN 24
#define MAX_EXCHANGE_TRADE_ID_LEN 72
#define MAX_TIME_LEN 12
#define MAX_ORDER_SOURCE_LEN 24
#define MAX_CURRENCY_GROUP_LEN 6
#define MAX_CURRENCY_ID_LEN 4
#define MAX_TAG50_LEN 16
#define MAX_CHANNEL_ORDERID_LEN 24

/////////////////////////////////////////////////////////////////////////
///����״̬
/////////////////////////////////////////////////////////////////////////
///δ֪
#define PTK_ES_Unknown '0'
///���Ͼ��۱���
#define PTK_ES_AuctionOrdering '1'
///��������
#define PTK_ES_Trading '2'
///��ͣ
#define PTK_ES_Pause '3'
///����
#define PTK_ES_Closed '4'

/////////////////////////////////////////////////////////////////////////
///��Ʒ����
/////////////////////////////////////////////////////////////////////////
///�ڻ�
#define PTK_PC_Futures '1'
///�ڻ���Ȩ
#define PTK_PC_Options '2'
///���
#define PTK_PC_Combination '3'
///����
#define PTK_PC_Spot '4'
///��ת��
#define PTK_PC_EFP '5'
///�ֻ���Ȩ
#define PTK_PC_SpotOption '6'

/////////////////////////////////////////////////////////////////////////
///�ֲ�����
/////////////////////////////////////////////////////////////////////////
///���ֲ�
#define PTK_PT_Net '1'
///�ۺϳֲ�
#define PTK_PT_Gross '2'

/////////////////////////////////////////////////////////////////////////
///�ֲ���������
/////////////////////////////////////////////////////////////////////////
///ʹ����ʷ�ֲ֣����ֽ���֣�
#define PTK_PDT_UseHistory '1'
///��ʹ����ʷ�ֲ֣������ֽ���֣�
#define PTK_PDT_NoUseHistory '2'

/////////////////////////////////////////////////////////////////////////
///����״̬
/////////////////////////////////////////////////////////////////////////
///�����걨
#define PTK_OST_Inserting '0'
///�ѱ�
#define PTK_OST_Inserted '1'
///����
#define PTK_OST_PartTraded '2'
///�ѳ�
#define PTK_OST_AllTraded '3'
///�ѳ�
#define PTK_OST_Canceled '4'
///���ɲ���
#define PTK_OST_PartTradedCanceled '5'
///�ϵ�
#define PTK_OST_Error 'e'
///δ����
#define PTK_OST_NotTouched 'p'
///�Ѵ���
#define PTK_OST_Touched 't'
///δ֪
#define PTK_OST_Unknown 'x'

/////////////////////////////////////////////////////////////////////////
///��������
/////////////////////////////////////////////////////////////////////////
///��
#define PTK_D_Buy '0'
///��
#define PTK_D_Sell '1'

/////////////////////////////////////////////////////////////////////////
///Ͷ���ױ���־
/////////////////////////////////////////////////////////////////////////
///Ͷ��
#define PTK_HF_Speculation '1'
///����
#define PTK_HF_Arbitrage '2'
///��ֵ
#define PTK_HF_Hedge '3'

/////////////////////////////////////////////////////////////////////////
///�����۸�����
/////////////////////////////////////////////////////////////////////////
///�м�
#define PTK_OPT_AnyPrice '1'
///�޼�
#define PTK_OPT_LimitPrice '2'
///���ż�
#define PTK_OPT_BestPrice '3'
///���½�����������
///���¼�
#define PTK_OPT_LastPrice '4'
///���¼۸����ϸ�1��ticks
#define PTK_OPT_LastPricePlusOneTicks '5'
///���¼۸����ϸ�2��ticks
#define PTK_OPT_LastPricePlusTwoTicks '6'
///���¼۸����ϸ�3��ticks
#define PTK_OPT_LastPricePlusThreeTicks '7'
///��һ��
#define PTK_OPT_AskPrice1 '8'
///��һ�۸����ϸ�1��ticks
#define PTK_OPT_AskPrice1PlusOneTicks '9'
///��һ�۸����ϸ�2��ticks
#define PTK_OPT_AskPrice1PlusTwoTicks 'A'
///��һ�۸����ϸ�3��ticks
#define PTK_OPT_AskPrice1PlusThreeTicks 'B'
///��һ��
#define PTK_OPT_BidPrice1 'C'
///��һ�۸����ϸ�1��ticks
#define PTK_OPT_BidPrice1PlusOneTicks 'D'
///��һ�۸����ϸ�2��ticks
#define PTK_OPT_BidPrice1PlusTwoTicks 'E'
///��һ�۸����ϸ�3��ticks
#define PTK_OPT_BidPrice1PlusThreeTicks 'F'

/////////////////////////////////////////////////////////////////////////
///��ƽ��־
/////////////////////////////////////////////////////////////////////////
///����
#define PTK_OF_Open '0'
///ƽ��
#define PTK_OF_Close '1'
///ƽ��
#define PTK_OF_CloseToday '2'

/////////////////////////////////////////////////////////////////////////
///����ֱ�־
/////////////////////////////////////////////////////////////////////////
///�ֻܲ����
#define PTK_PSD_Total PTK_OF_Close
///���
#define PTK_PSD_Today PTK_OF_CloseToday

/////////////////////////////////////////////////////////////////////////
///�����ĵ�����
/////////////////////////////////////////////////////////////////////////
///����
#define PTK_AF_Delete '0'
///�ĵ�
#define PTK_AF_Modify '3'

/////////////////////////////////////////////////////////////////////////
///������������
/////////////////////////////////////////////////////////////////////////
///����
#define PTK_CC_Immediately '1'
///ֹ��
#define PTK_CC_Touch '2'
///ֹӮ
#define PTK_CC_TouchProfit '3'
///Ԥ��
#define PTK_CC_ParkedOrder '4'
///���¼۴���������
#define PTK_CC_LastPriceGreaterThanStopPrice '5'
///���¼۴��ڵ���������
#define PTK_CC_LastPriceGreaterEqualStopPrice '6'
///���¼�С��������
#define PTK_CC_LastPriceLesserThanStopPrice '7'
///���¼�С�ڵ���������
#define PTK_CC_LastPriceLesserEqualStopPrice '8'
///��һ�۴���������
#define PTK_CC_AskPriceGreaterThanStopPrice '9'
///��һ�۴��ڵ���������
#define PTK_CC_AskPriceGreaterEqualStopPrice 'A'
///��һ��С��������
#define PTK_CC_AskPriceLesserThanStopPrice 'B'
///��һ��С�ڵ���������
#define PTK_CC_AskPriceLesserEqualStopPrice 'C'
///��һ�۴���������
#define PTK_CC_BidPriceGreaterThanStopPrice 'D'
///��һ�۴��ڵ���������
#define PTK_CC_BidPriceGreaterEqualStopPrice 'E'
///��һ��С��������
#define PTK_CC_BidPriceLesserThanStopPrice 'F'
///��һ��С�ڵ���������
#define PTK_CC_BidPriceLesserEqualStopPrice 'H'

/////////////////////////////////////////////////////////////////////////
///��Ч������
/////////////////////////////////////////////////////////////////////////
///������ɣ�������
#define PTK_TC_IOC '1'
///������Ч
#define PTK_TC_GFS '2'
///������Ч
#define PTK_TC_GFD '3'
///ָ������ǰ��Ч
#define PTK_TC_GTD '4'
///����ǰ��Ч
#define PTK_TC_GTC '5'
///���Ͼ�����Ч
#define PTK_TC_GFA '6'

/////////////////////////////////////////////////////////////////////////
///�ɽ�������
/////////////////////////////////////////////////////////////////////////
///�κ�����
#define PTK_VC_AV '1'
///��С����
#define PTK_VC_MV '2'
///ȫ������
#define PTK_VC_CV '3'

/////////////////////////////////////////////////////////////////////////
///ǿƽԭ��
/////////////////////////////////////////////////////////////////////////
///��ǿƽ
#define PTK_FCC_NotForceClose '0'
///�ʽ���
#define PTK_FCC_LackDeposit '1'
///�ͻ�����
#define PTK_FCC_ClientOverPositionLimit '2'
///��Ա����
#define PTK_FCC_MemberOverPositionLimit '3'
///�ֲַ�������
#define PTK_FCC_NotMultiple '4'
///Υ��
#define PTK_FCC_Violation '5'
///����
#define PTK_FCC_Other '6'
///��Ȼ���ٽ�����
#define PTK_FCC_PersonDeliv '7'

/////////////////////////////////////////////////////////////////////////
///�ɽ�����
/////////////////////////////////////////////////////////////////////////
///��ͨ�ɽ�
#define PTK_TRDT_Common '0'
///��Ȩִ��
#define PTK_TRDT_OptionsExecution '1'
///OTC�ɽ�
#define PTK_TRDT_OTC '2'
///��ת�������ɽ�
#define PTK_TRDT_EFPDerived '3'
///��������ɽ�
#define PTK_TRDT_CombinationDerived '4'

/////////////////////////////////////////////////////////////////////////
///��֤��۸�����
/////////////////////////////////////////////////////////////////////////
///������
#define PTK_MPT_PreSettlementPrice '1'
///���¼�
#define PTK_MPT_SettlementPrice '2'
///�ɽ�����
#define PTK_MPT_AveragePrice '3'
///���ּ�
#define PTK_MPT_OpenPrice '4'

/////////////////////////////////////////////////////////////////////////
///��ӯ�����Ƿ�������
/////////////////////////////////////////////////////////////////////////
///��ӯ����������
#define PTK_AG_All '1'
///��ӯ���ƣ�������
#define PTK_AG_OnlyLost '2'
///��ӯ�ƣ���������
#define PTK_AG_OnlyGain '3'
///��ӯ������������
#define PTK_AG_None '4'

/////////////////////////////////////////////////////////////////////////
///ƽ��ӯ�������Ƿ����
/////////////////////////////////////////////////////////////////////////
///����ƽ��ӯ��
#define PTK_ICP_Include '0'
///������ƽ��ӯ��
#define PTK_ICP_NotInclude '2'

/////////////////////////////////////////////////////////////////////////
///�Ƿ��������������߱�֤��
/////////////////////////////////////////////////////////////////////////
///��ʹ�ô��߱�֤���㷨
#define PTK_MMSA_NO '0'
///ʹ�ô��߱�֤���㷨
#define PTK_MMSA_YES '1'

/////////////////////////////////////////////////////////////////////////
///�˻�����
/////////////////////////////////////////////////////////////////////////
///Ͷ����
#define PTK_IAT_Investor '0'
///����Ա
#define PTK_IAT_Admin '1'

/////////////////////////////////////////////////////////////////////////
///���˺ű�����Դ
/////////////////////////////////////////////////////////////////////////
///�ⲿ
#define PTK_MOS_Others '0'
///����
#define PTK_MOS_Local '1'

/////////////////////////////////////////////////////////////////////////
///֪ͨ����
/////////////////////////////////////////////////////////////////////////
///��ͨ
#define PTK_NT_Message '0'
///����
#define PTK_NT_Warning '1'
///��ǿƽ
#define PTK_NT_ForceClose '2'
///CTP֪ͨ������Ϣֻ�Ƹ���أ�
#define PTK_NT_CTP '3'

/////////////////////////////////////////////////////////////////////////
///�������
/////////////////////////////////////////////////////////////////////////
#ifdef _DEBUG

#define CMS_PROCESSOR_BUFFER_INIT_LARGE 256				// �󻺴��ÿ������
#define CMS_PROCESSOR_BUFFER_INIT_LARGE_CONCURRENT 4	// �󻺴�鲢������
#define CMS_PROCESSOR_BUFFER_INIT_SMALL 1024			// С�����ÿ������
#define CMS_PROCESSOR_BUFFER_INIT_SMALL_CONCURRENT 4	// С����鲢������
#define CMS_PROCESSOR_INVESTORMAP_INIT 257				// �ͻ�ӳ����ʼ��С
#define CMS_PROCESSOR_CONTRACTMAP_INIT 521				// ��Լӳ����ʼ��С
#define CMS_PROCESSOR_ORDERMAP_INIT 1031				// ί��ӳ����ʼ��С

#define CMS_FRONT_BUFFER_INIT_LARGE 256				// �󻺴��ÿ������
#define CMS_FRONT_BUFFER_INIT_LARGE_CONCURRENT 4	// �󻺴�鲢������
#define CMS_FRONT_BUFFER_INIT_SMALL 1024			// С�����ÿ������
#define CMS_FRONT_BUFFER_INIT_SMALL_CONCURRENT 4	// С����鲢������

#define CMS_INSERTOR_BUFFER_INIT_LARGE 32			// �󻺴��ÿ������
#define CMS_INSERTOR_BUFFER_INIT_LARGE_CONCURRENT 2	// �󻺴�鲢������
#define CMS_INSERTOR_BUFFER_INIT_SMALL 128			// С�����ÿ������
#define CMS_INSERTOR_BUFFER_INIT_SMALL_CONCURRENT 2	// С����鲢������

#define CMS_DB_BUFFER_INIT_SMALL 128			// С�����ÿ������
#define CMS_DB_BUFFER_INIT_SMALL_CONCURRENT 2	// С����鲢������

#else

#define CMS_PROCESSOR_BUFFER_INIT_LARGE 1024			// �󻺴��ÿ������
#define CMS_PROCESSOR_BUFFER_INIT_LARGE_CONCURRENT 16	// �󻺴�鲢������
#define CMS_PROCESSOR_BUFFER_INIT_SMALL 51200			// С�����ÿ������
#define CMS_PROCESSOR_BUFFER_INIT_SMALL_CONCURRENT 32	// С����鲢������
#define CMS_PROCESSOR_INVESTORMAP_INIT 99991			// �ͻ�ӳ����ʼ��С
#define CMS_PROCESSOR_CONTRACTMAP_INIT 4099				// ��Լӳ����ʼ��С
#define CMS_PROCESSOR_ORDERMAP_INIT 130003				// ί��ӳ����ʼ��С

#define CMS_FRONT_BUFFER_INIT_LARGE 4096			// �󻺴��ÿ������
#define CMS_FRONT_BUFFER_INIT_LARGE_CONCURRENT 16	// �󻺴�鲢������
#define CMS_FRONT_BUFFER_INIT_SMALL 5120			// С�����ÿ������
#define CMS_FRONT_BUFFER_INIT_SMALL_CONCURRENT 16	// С����鲢������

#define CMS_INSERTOR_BUFFER_INIT_LARGE 128				// �󻺴��ÿ������
#define CMS_INSERTOR_BUFFER_INIT_LARGE_CONCURRENT 4		// �󻺴�鲢������
#define CMS_INSERTOR_BUFFER_INIT_SMALL 256				// С�����ÿ������
#define CMS_INSERTOR_BUFFER_INIT_SMALL_CONCURRENT 16	// С����鲢������

#define CMS_DB_BUFFER_INIT_SMALL 5120			// С�����ÿ������
#define CMS_DB_BUFFER_INIT_SMALL_CONCURRENT 8	// С����鲢������

/* // �ƽ�ģ��ʹ��
#define CMS_PROCESSOR_BUFFER_INIT_LARGE 2048			// �󻺴��ÿ������
#define CMS_PROCESSOR_BUFFER_INIT_LARGE_CONCURRENT 16	// �󻺴�鲢������
#define CMS_PROCESSOR_BUFFER_INIT_SMALL 102400			// С�����ÿ������
#define CMS_PROCESSOR_BUFFER_INIT_SMALL_CONCURRENT 16	// С����鲢������
#define CMS_PROCESSOR_INVESTORMAP_INIT 10093			// �ͻ�ӳ����ʼ��С
#define CMS_PROCESSOR_CONTRACTMAP_INIT 17				// ��Լӳ����ʼ��С
#define CMS_PROCESSOR_ORDERMAP_INIT 1046527				// ί��ӳ����ʼ��С

#define CMS_DB_BUFFER_INIT_LARGE 4096			// �󻺴��ÿ������
#define CMS_DB_BUFFER_INIT_LARGE_CONCURRENT 16	// �󻺴�鲢������
#define CMS_DB_BUFFER_STOP 4096				// ��������������ֵʱֹͣ����
*/

#endif

#endif
