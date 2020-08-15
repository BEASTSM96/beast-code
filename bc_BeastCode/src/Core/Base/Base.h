#pragma once

#include <memory>

#ifdef BC_PLATFORM_WINDOWS
#define BEASTCODE_API_EXPORT_ALL __declspec(dllexport)
#else
#error Beastcode only supports Windows!
#endif

#ifdef BC_PLATFORM_WINDOWS
#if BC_DYNAMIC_LINK
#ifdef BC_BUILD_DLL
#define BEASTCODE_API __declspec(dllexport)
#else
#define BEASTCODE_API __declspec(dllimport)
#endif
#else
#define BEASTCODE_API
#endif
#else
#error Beastcode only supports Windows!
#endif 

#define BIT(x) (1 << x)

#ifdef BC_CORE_DEBUG
#if defined(BC_PLATFORM_WINDOWS)
#define BC_DEBUGBREAK() __debugbreak()
#elif defined(BC_PLATFORM_LINUX)
#include <signal.h>
#define BC_DEBUGBREAK() raise(SIGTRAP)
#else
#error "Platform doesn't support debugbreak yet!"
#endif
#define BC_ENABLE_ASSERTS
#else
#define BC_DEBUGBREAK()
#endif


// TODO: Make this macro able to take in no arguments except condition
#ifdef BC_ENABLE_ASSERTS
#define BC_ASSERT(x, ...) { if(!(x)) { BC_ERROR("Assertion Failed: {0}", __VA_ARGS__); BC_DEBUGBREAK(); } }
#define BC_CORE_ASSERT(x, ...) { if(!(x)) { BC_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); BC_DEBUGBREAK(); } }
#else
#define BC_ASSERT(x, ...)
#define BC_CORE_ASSERT(x, ...)
#endif

#define BC_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

namespace BeastCode {

	template<typename T>
	using Scope = std::unique_ptr<T>;

	template<typename T>
	using Ref = std::shared_ptr<T>;

}