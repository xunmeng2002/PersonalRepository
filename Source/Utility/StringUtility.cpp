#include "StringUtility.h"

using std::string;
using std::set;


void Split(set<string>& result, const string& src, const string& op)
{
	size_t startIndex = 0;
	size_t endIndex = src.size();
	while ((endIndex = src.find(op, startIndex)) < src.size())
	{
		result.insert(src.substr(startIndex, endIndex - startIndex));
		startIndex = endIndex + 1;
	}
	if (startIndex < src.size())
	{
		result.insert(src.substr(startIndex, src.size() - startIndex));
	}
}
void Split(set<string>& result, const string& src, char op)
{
	size_t startIndex = 0;
	size_t endIndex = src.size();
	while ((endIndex = src.find(op, startIndex)) < src.size())
	{
		result.insert(src.substr(startIndex, endIndex - startIndex));
		startIndex = endIndex + 1;
	}
	if (startIndex < src.size())
	{
		result.insert(src.substr(startIndex, src.size() - startIndex));
	}
}

