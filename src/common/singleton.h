#pragma once

#include <mutex>
#include <memory>
#include <utility>

namespace Com
{
	template <typename T>
	class Singleton
	{
	public:
		Singleton(const Singleton &) = delete;
		Singleton &operator=(const Singleton &) = delete;

		Singleton(Singleton &&) = delete;
		Singleton &operator=(Singleton &&) = delete;

		template <typename... Args>
		static T &instance(Args &&...args)
		{
			::std::call_once(InitFlag_, [&]() {
				Instance_.reset(new T(std::forward<Args>(args)...));
			});

			return *Instance_;
		}

	protected:
		Singleton() = default;
		virtual ~Singleton() = default;

	private:
		static ::std::unique_ptr<T> Instance_;
		static ::std::once_flag InitFlag_;
	};

	template <typename T>
	::std::unique_ptr<T> Singleton<T>::Instance_ = nullptr;

	template <typename T>
	::std::once_flag Singleton<T>::InitFlag_;
}// end of namespace for Framework