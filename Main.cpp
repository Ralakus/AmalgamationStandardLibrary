#include <iostream>
#include "AESL/Utilities/Log.hpp"
#include "AESL/Utilities/Random.hpp"
int main()
{
    AE_LOG(AESL::Random::Name(4, 12).c_str());
    AE_LOG_SUCCESS(AESL::Random::Name(4, 12).c_str());
    AE_LOG_ERROR(AESL::Random::Name(4, 12).c_str());
    AE_LOG_WARNING(AESL::Random::Name(4, 12).c_str());
    std::cin.get();
	return 0;
}
