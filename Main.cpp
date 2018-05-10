#include <iostream>
#include "AESL/Utilities/Log.hpp"
int main()
{
    AE_LOG("Hello!");
    AE_LOG_SUCCESS("Hello!");
    AE_LOG_ERROR("Hello!");
    AE_LOG_WARNING("Hello!");
	return 0;
}
