#pragma once

using uint64 = unsigned long long int;
using uint32 = unsigned long      int;
using uint16 = unsigned short     int;
using uint8  = unsigned char;

using int64  = signed long long int;
using int32  = signed long      int;
using int16  = signed short     int;
using int8   = signed char;

using float32 = float;
using float64 = double;

#if defined(__linux__)
    #define AE_LINUX   1

#elif defined(_WIN32) || defined(_WIN64)
    #define AE_WINDOWS 1

#elif defined(__APPLE__)
    #define AE_APPLE   1

#elif defined(BSD)
    #define AE_BSD     1

#endif // __linux__

#define SafeDelete(x) { if(x) { delete x; x = nullptr; } }

#ifdef COMPILER_MSVC
	#define FORCEINLINE __forceinline
#elif defined(COMPILER_GCC) || defined(COMPILER_CLANG)
	#define FORCEINLINE inline __attribute__ ((always_inline))
#else
	#define FORCEINLINE inline
#endif

#define LOG_ERROR_STR   "[LOG_ERROR]:"
#define LOG_WARNING_STR "[LOG_WARNING]:"
#define LOG_SUCCESS_STR "[LOG_SUCCESS]:"
#define LOG_STR         "[LOG]:"

namespace AESL {
	template<class Type>
	struct IsPointer { static const bool Value = false; };
	template<class Type>
	struct IsPointer<Type*> { static const bool Value = true; };
	class Error {
		const char* Message;
	public:
		Error(const char* ErrMessage) : Message(ErrMessage) {}
		~Error() {}
		const char* What() const {
			return Message;
		}
	};
	class ID {
	public:
		static uint64 GetUnique() {
			static uint64 m_ID = 0;
			return ++m_ID;
		}
	};
}
