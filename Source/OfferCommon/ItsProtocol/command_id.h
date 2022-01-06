
/////////////////////////////////////////////////////////////////////////

#ifndef __CMS_COMMAND_ID_H__
#define __CMS_COMMAND_ID_H__

#define CMS_CID_ACKNOWLEDGEMENT			0		// ����ȷ��
#define CMS_CID_BROADCAST_QUOTE			5		// ����㲥

#define CMS_CID_BROADCAST_ACCOUNTRISK	32		// �˺ŵķ�ز��Ա仯
#define CMS_CID_BROADCAST_ACCOUNTINFO	33		// �˺���Ϣ�仯
#define CMS_CID_BROADCAST_BASECAPITAL	34		// �ڳ�Ͷ��仯 δʹ��
#define CMS_CID_BROADCAST_SYSPARAM		35		// ϵͳ���ñ仯
#define CMS_CID_BROADCAST_RISKSN		36		// ĳ����ز��Ա仯
#define CMS_CID_BROADCAST_CHANNELINFO	38		// ������Ϣ�仯 δʹ��
#define CMS_CID_BROADCAST_RISK_DELETED	39		// ĳ����ز��Ա�ɾ��
#define CMS_CID_BROADCAST_MARGIN_COMMISSION_CURRENCY	40	// ��֤��/������/���ʱ仯
#define CMS_CID_BROADCAST_GROUP			41		// �������޸�
#define CMS_CID_BROADCAST_DBAGENT		42		// ���ݿ����״̬
#define CMS_CID_BROADCAST_PROCESSOR		43		// �����״̬

#define CMS_CID_BROADCAST_MA_ORDER	52			// ���˺�ί�лر��㲥 δʹ��
#define CMS_CID_BROADCAST_MA_TRADE	53			// ���˺ųɽ��ر��㲥 δʹ��
#define CMS_CID_BROADCAST_MA_CANCEL_FAILED	54	// ���˺ų���ʧ�ܹ㲥
#define CMS_CID_BROADCAST_EXCHANGE_STATUS	55	// ����״̬�㲥
#define CMS_CID_BROADCAST_NOTICE		56		// ֪ͨ�㲥
#define CMS_CID_BROADCAST_FORCECLOSE	57		// ǿƽ�㲥
#define CMS_CID_BROADCAST_TIME			58		// ʱ��㲥
#define CMS_CID_BROADCAST_DEPOSITWITHDRAWAL	59	// �˺��ʽ�仯֪ͨ
#define CMS_CID_BROADCAST_FORCECANCEL	60		// ǿ�г����㲥
#define CMS_CID_BROADCAST_ORDER			61		// �˺�ί�лر��㲥
#define CMS_CID_BROADCAST_TRADE			62		// �˺ųɽ��ر��㲥
#define CMS_CID_BROADCAST_CANCEL_FAILED	63		// �˺ų���ʧ�ܹ㲥
#define CMS_CID_BROADCAST_RISKREFUSE	64		// ��ؾܾ��㲥
#define CMS_CID_BROADCAST_REPUSH_DONE	65		// ���������󣬲��ƻر����
#define CMS_CID_BROADCAST_FORCECANCEL_CME	66	// ǿ��ȫ�������㲥 δʹ��
#define CMS_CID_BROADCAST_TOUCHED		67		// ����������
#define CMS_CID_BROADCAST_FORCECANCEL_APEX	68	// ǿ��ȫ�������㲥

#define CMS_CID_CHECK_PASSWORD			101		// У���û�������
#define CMS_CID_LOAD_RISK_BY_ACCOUNT	102		// ȡ�˺ŵķ������
#define CMS_CID_CHECK_ADMIN_PASSWORD	103		// У�����Ա�û�������
#define CMS_CID_LOAD_ADMIN_RIGHTS		104		// ��ȡ����ԱȨ��
#define CMS_CID_CHECK_MD5PASSWORD		105		// У���û���MD5���� δʹ��
#define CMS_CID_LOAD_RISK_BY_ID			106		// ȡ��ز���

#define CMS_CID_DEPOSIT					111		// ����� δʹ��
#define CMS_CID_CHECK_ACCOUNT			113		// ɾ�����޸��˺�ǰ�ļ�� δʹ��
#define CMS_CID_SETTLE					114		// ��ʼ���� δʹ��
#define CMS_CID_QUERY_SETTLE_STATUS		115		// ��ѯ����״̬
#define CMS_CID_CLEARSETTLE				116		// ��������� δʹ��
#define CMS_CID_RESET_MAXBALANCE		117		// ��λ���Ȩ��

#define CMS_CID_CHECK_INSERTOR			121		// ��鱨�̻�״̬
#define CMS_CID_CHECK_PROCESSOR			122		// ��鴦���״̬
#define CMS_CID_SYSTEM_STATUS			123		// ȡ�����״̬
#define CMS_CID_READ_LOG				124		// ����־ δʹ��
#define CMS_CID_UPLOAD_HARDWARE_INFO	125		// �ϱ�Ӳ����Ϣ

#define CMS_CID_CHECK_SETTLEPRICE	    150		// ��������Ƿ��յ�
#define CMS_CID_CHECK_DATABASE		    151		// ������ݿ�
#define CMS_CID_UPDATE_DB_CONTRACTS	    152		// �������ݿ�ĺ�Լ�� ��ʹ��
#define CMS_CID_LOAD_SUMMARY			153		// ���ʽ���ж�ȡָ�����ڵ�ȫ����¼
#define CMS_CID_LOAD_DEPOSIT_WITHDRAWAL	154		// �ӳ������ж�ȡָ�����ڵ�ȫ��������¼
#define CMS_CID_LOAD_ORDERS				155		// ��ί�б��ж�ȡָ�����ڵ�ί��
#define CMS_CID_LOAD_TRADES				156		// �ӳɽ����ж�ȡָ�����ڵĳɽ�
#define CMS_CID_LOAD_POSITION			157		// �ӳֲ���ϸ���ж�ȡָ�����ڵĳֲ���ϸ
#define CMS_CID_LOAD_INVESTOR_PARAM		158		// ��ȡͶ�����������
#define CMS_CID_LOAD_MARGIN_RATE		159		// ��ȡ��֤����
#define CMS_CID_LOAD_COMMISSION_RATE	160		// ��ȡ��������
#define CMS_CID_LOAD_SETTLE				161		// ��ȡ���㵥

#define CMS_CID_LOAD_ACCOUNT			163		// ��ȡָ���˺ŵ���Ϣ
#define CMS_CID_LOAD_MARGIN_PATTERN		164		// ��ȡ��֤����ģ��
#define CMS_CID_LOAD_COMMISSION_PATTERN	165		// ��ȡ��������ģ��
#define CMS_CID_LOAD_ACCOUNT_MARGIN_COMMISSION	166		// ��ȡ�����˺ŵ��������ʺͱ�֤����

#define CMS_CID_LOAD_SYSTEMPARAM		168		// ��ȡϵͳ���
#define CMS_CID_LOAD_CHANNEL_PASSWORD	169		// ��ȡ���֣����̻�������
#define CMS_CID_LOAD_SESSIONS			170		// ��ȡ���֣����̻����Ự��
#define CMS_CID_LOAD_MAXBALANCE			171		// ��ȡ���Ȩ��
#define CMS_CID_LOAD_NETVALUE			172		// ��ȡ��ֵ����
#define CMS_CID_QUERY_MOBILEACCOUNT		173		// �����ֻ��Ų��˺�
#define CMS_CID_LOAD_CURRENCY			174		// ��ȡ����ģ��
#define CMS_CID_DISABLE_MA				175		// �������˺� δʹ��
#define CMS_CID_ORDER_CONTRACT_EXPIRED	176		// δʹ��

#define CMS_CID_SAVE_NETVALUE			178		// ���澻ֵ����
#define CMS_CID_SAVE_MAXBALANCE			179		// �������Ȩ��
#define CMS_CID_SAVE_SESSIONS			180		// �������֣����̻����Ự��
#define CMS_CID_ORDER_RECORD			181		// ��ί�б���д��һ����¼
#define CMS_CID_TRADE_RECORD			182		// ��ɽ�����д��һ����¼
#define CMS_CID_CLOSE_RECORD			183		// ��ƽ�ֱ���д��һ����¼
#define CMS_CID_POSITION_RECORD			184		// ����ʱ��ֲ���ϸ����д��һ����¼
#define CMS_CID_DEPOSIT_RECORD			185		// ��ת�˱���д��һ����¼ δʹ��
#define CMS_CID_SUMMARY_RECORD			186		// ����ʱ���ʽ����д��һ����¼
#define CMS_CID_LOGIN_RECORD			187		// ���¼��¼����д��һ����¼
#define CMS_CID_QUOTE_RECORD			188		// ���������д��һ����¼ ��ϵͳ��ʹ��
#define CMS_CID_TRADE_COMMISSION_RECORD	189		// ���³ɽ����е�������
#define CMS_CID_RISK_RECORD				190		// ��¼һ��ǿƽ��־
#define CMS_CID_INSERTOR_RECORD			191		// ��¼���̻���Ϣ ��ϵͳ��ʹ��
#define CMS_CID_ORDER_EXTRA_RECORD		192		// ��ί�б���д�볷����ַ��������Ʒ������ߣ���˵�ַ�����ʱ��
#define CMS_CID_CLEAR_SETTLEMENT		193		// ���������
#define CMS_CID_MOVE_ORDER_TRADE		194		// ����һ������δ�����ί�гɽ��ƶ�����ǰ������

#define CMS_CID_LOGIN					201		// ��¼
#define CMS_CID_MODIFY_TRADE_PASS		202		// �޸Ľ�������
#define CMS_CID_MODIFY_FUND_PASSWORD	203		// �޸��ʽ�����
#define CMS_CID_ACCOUNT_STATUS			204		// ���˻��ʽ�
#define CMS_CID_ACCOUNT_STATUS_BY_DATE	205		// ����ʷ�˻��ʽ�
#define CMS_CID_QUERY_SETTLE			206		// ����㵥
#define CMS_CID_CONFIRM_SETTLE			207		// ȷ�Ͻ��㵥
#define CMS_CID_QUERY_CONTRACTS			208		// ���Լ�б�
#define CMS_CID_QUERY_QUOTES			209		// ������
#define CMS_CID_QUERY_ORDERS			210		// �鵱��ί��
#define CMS_CID_QUERY_TRADES			211		// �鵱�ճɽ�
#define CMS_CID_QUERY_TRADES_BY_DATE	212		// ����ʷ�ɽ�
#define CMS_CID_QUERY_POSITIONS			213		// ��ֲ�
#define CMS_CID_QUERY_POSITIONS_DETAIL	214		// ��ֲ���ϸ
#define CMS_CID_QUERY_MAX_VOLUME		215		// ��ɿ���ƽ
#define CMS_CID_INSERT_ORDER			216		// �µ�
#define CMS_CID_CANCEL_ORDER			217		// ����
#define CMS_CID_QUERY_EXCHANGES			218		// �齻����
#define CMS_CID_QUERY_TRADE_PARAMS		219		// �齻�ײ���
#define CMS_CID_QUERY_MARGIN_RATE		220		// �鱣֤����
#define CMS_CID_QUERY_COMMISSION_RATE	221		// ����������
#define CMS_CID_QUERY_EXCHANGE_MARGIN_RATE		222		// �齻������֤����
#define CMS_CID_PATCH_ORDER				223		// ����
#define CMS_CID_QUERY_COMBINE_POSITIONS_DETAIL	224		// ����ϳֲ���ϸ
#define CMS_CID_PATCH_ORDERSTATUS		225		// ��ί��״̬
#define CMS_CID_PATCH_TRADE				226		// ���ɽ�
#define CMS_CID_APPROVE_ORDER			227		// �������
#define CMS_CID_QUERY_OPTIONS_MARGIN_RATE		228		// ����Ȩ��֤����
#define CMS_CID_QUERY_OPTIONS_COMMISSION_RATE	229		// ����Ȩ��������
#define CMS_CID_QUERY_CURRENCY			230		// �����
#define CMS_CID_QUERY_PRODUCTS			231		// ��Ʒ���б�

#define CMS_CID_ADMIN_LOGIN				301		// ����Ա��¼
#define CMS_CID_QUERY_GROUPS			302		// ����ṹ
#define CMS_CID_QUERY_GROUPED_INVESTORS	303		// �������˺�
#define CMS_CID_QUERY_MAIN_ACCOUNTS		304		// �����˺��б� ��ϵͳ��ʹ��

#endif
