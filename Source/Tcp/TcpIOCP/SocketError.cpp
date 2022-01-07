#include "SocketError.h"
#include <map>
#include <string>


std::map<int, std::string> g_SocketErrors = {
	{10093, "WSANOTINITIALISED����ʹ�ô�API֮ǰӦ���ȳɹ��ص���WSAStartup()��"},
	{10050, "WSAENETDOWN��WINDOWS�׽ӿ�ʵ�ּ�⵽������ϵͳʧЧ��"},
	{10004, "WSAEINTR��ͨ��һ��WSACancelBlockingCall()��ȡ��һ���������ģ����á�"},
	{10036, "WSAEINPROGRESS��һ��������WINDOWS�׽ӿڵ������������С�"},
	{10014, "WSAEFAULT��buf���������û���ַ�ռ��е���Чλ�á�"},
	{10052, "WSAENETRESET������WINDOWS�׽ӿ�ʵ�ַ��������ӣ��ʸ����ӱ��豻��λ��"},
	{10055, "WSAENOBUFS��WINDOWS�׽ӿ�ʵ�ֱ���һ��������������"},
	{10057, "WSAENOTCONN���׽ӿ�δ�����ӡ�"},
	{10038, "WSAENOTSOCK�������ֲ���һ���׽ӿڡ�"},
	{10045, "WSAEOPNOTSUPP����������MSG_OOB�����׽ӿڷ�SOCK_STREAM���͡�"},
	{10058, "WSAESHUTDOWN���׽ӿ��ѱ��رա�һ���׽ӿ���1��2��how��������shutdown()�رպ��޷�����send()������"},
	{10035, "WSAEWOULDBLOCK��"},
	{10040, "WSAEMSGSIZE���׽ӿ�ΪSOCK_DGRAM���ͣ������ݱ�����WINDOWS�׽ӿ�ʵ����֧�ֵ����ֵ��"},
	{10022, "WSAEINVAL���׽ӿ�δ��bind()����"},
	{10053, "WSAECONNABORTED�����ڳ�ʱ������ԭ���������·���жϡ�"},
	{10054, "WSAECONNRESET�����·��Զ�˸�λ�� "}
};

