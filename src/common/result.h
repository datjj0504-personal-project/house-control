#pragma once

#include <tuple>
#include <cstdint>

namespace Common {
	// 
	// [ Result ]
	// std::tuple<bool, ::std::int32_t>
	// bool: status of the operation <success or failure>
	// ::std::int32_t: error code of the operation>

	template <typename T = void>
	struct Result : public ::std::tuple<bool, ::std::int32_t>
	{
		using ::std::tuple<bool, ::std::int32_t>::tuple;
		Result(void) noexcept;
		Result(bool _Status, ::std::int32_t _ErrorCode);
		explicit operator bool(void) const;
		auto operator=(Result const &_Result) -> Result &;
		auto Status(void) const -> bool;
		auto ErrorCode(void) const -> ::std::int32_t;
		static auto Make(bool const &_Status, ::std::int32_t const &_ErrorCode) -> Result<T>;
	};

	template <typename T>
	Result<T>::Result(void) noexcept : ::std::tuple<bool, ::std::int32_t>(false, 0)
	{
	}

	template <typename T>
	Result<T>::Result(bool _Status, ::std::int32_t _ErrorCode) : ::std::tuple<bool, ::std::int32_t>(_Status, _ErrorCode)
	{
	}

	template <typename T>
	Result<T>::operator bool(void) const
	{
		return this->Status();
	}

	template <typename T>
	auto Result<T>::operator=(Result const &_Result) -> Result &
	{
		::std::get<0>(*this) = ::std::get<0>(_Result);
		::std::get<1>(*this) = ::std::get<1>(_Result);
		return(*this);
	}

	template <typename T>
	auto Result<T>::Status(void) const -> bool
	{
		return ::std::get<0>(*this);
	}

	template <typename T>
	auto Result<T>::ErrorCode(void) const -> ::std::int32_t
	{
		return ::std::get<1>(*this);
	}

	template <typename T>
	auto Result<T>::Make(bool const &_Status, ::std::int32_t const &_ErrorCode) -> Result<T>
	{
		return Result<T>(_Status, _ErrorCode);
	}
}// end of namespace for Common
