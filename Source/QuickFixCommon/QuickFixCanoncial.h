#pragma once
#include <string>
#include "quickfix/Message.h"


std::string GetCanonicalReq(const FIX::Message& message);
