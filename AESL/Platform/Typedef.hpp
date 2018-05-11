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
    #define AE_LINUX

#elif defined(_WIN32) || defined(_WIN64)
    #define AE_WINDOWS

#elif defined(__APPLE__)
    #define AE_APPLE

#elif defined(BSD)
    #define AE_BSD

#endif // __linux__

#if defined(__clang__)
	#define COMPILER_CLANG
#elif defined(__GNUC__) || defined(__GNUG__)
	#define COMPILER_GCC
#elif defined(_MSC_VER)
	#define COMPILER_MSVC
#else
	#define COMPILER_OTHER
#endif

#ifdef COMPILER_MSVC
	#define FORCEINLINE __forceinline
#elif defined(COMPILER_GCC) || defined(COMPILER_CLANG)
	#define FORCEINLINE inline __attribute__ ((always_inline))
#else
	#define FORCEINLINE inline
#endif

#define LOG_NOTE_STR     "[LOG_NOTE]:"
#define LOG_ERROR_STR   "[LOG_ERROR]:"
#define LOG_WARNING_STR "[LOG_WARNING]:"
#define LOG_SUCCESS_STR "[LOG_SUCCESS]:"
#define LOG_STR         "[LOG]:"

#define SafeDelete(x) { if(x) { delete x; x = nullptr; } }

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
