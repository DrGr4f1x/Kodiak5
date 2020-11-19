//
//  The ArrayProxy class is adapted from vulkan.hpp, under the Apache 2.0 license (http://www.apache.org/licenses/LICENSE-2.0).
//  Vulkan-hpp (original) is available here: https://github.com/KhronosGroup/Vulkan-Hpp
//

#pragma once

namespace Kodiak
{

template <typename T>
class ArrayProxy
{
public:
	constexpr ArrayProxy() noexcept
		: m_count(0)
		, m_ptr(nullptr)
	{}

	constexpr ArrayProxy(std::nullptr_t) noexcept
		: m_count(0)
		, m_ptr(nullptr)
	{}

	ArrayProxy(T& value) noexcept
		: m_count(1)
		, m_ptr(&value)
	{}

	template <typename B = T, typename std::enable_if<std::is_const<B>::value, int>::type = 0>
	ArrayProxy(typename std::remove_const<T>::type& value) noexcept
		: m_count(1)
		, m_ptr(&value)
	{}

	ArrayProxy(uint32_t count, T* ptr) noexcept
		: m_count(count)
		, m_ptr(ptr)
	{}

	template <typename B = T, typename std::enable_if<std::is_const<B>::value, int>::type = 0>
	ArrayProxy(uint32_t count, typename std::remove_const<T>::type* ptr) noexcept
		: m_count(count)
		, m_ptr(ptr)
	{}

	ArrayProxy(const std::initializer_list<T>& list) noexcept
		: m_count(static_cast<uint32_t>(list.size()))
		, m_ptr(list.begin())
	{}

	template <typename B = T, typename std::enable_if<std::is_const<B>::value, int>::type = 0>
	ArrayProxy(const std::initializer_list<typename std::remove_const<T>::type>& list) noexcept
		: m_count(static_cast<uint32_t>(list.size()))
		, m_ptr(list.begin())
	{}

	ArrayProxy(std::initializer_list<T>& list) noexcept
		: m_count(static_cast<uint32_t>(list.size()))
		, m_ptr(list.begin())
	{}

	template <typename B = T, typename std::enable_if<std::is_const<B>::value, int>::type = 0>
	ArrayProxy(std::initializer_list<typename std::remove_const<T>::type>& list) noexcept
		: m_count(static_cast<uint32_t>(list.size()))
		, m_ptr(list.begin())
	{}

	template <size_t N>
	ArrayProxy(const std::array<T, N>& data) noexcept
		: m_count(N)
		, m_ptr(data.data())
	{}

	template <size_t N, typename B = T, typename std::enable_if<std::is_const<B>::value, int>::type = 0>
	ArrayProxy(const std::array<typename std::remove_const<T>::type, N>& data) noexcept
		: m_count(N)
		, m_ptr(data.data())
	{}

	template <size_t N>
	ArrayProxy(std::array<T, N>& data) noexcept
		: m_count(N)
		, m_ptr(data.data())
	{}

	template <size_t N, typename B = T, typename std::enable_if<std::is_const<B>::value, int>::type = 0>
	ArrayProxy(std::array<typename std::remove_const<T>::type, N>& data) noexcept
		: m_count(N)
		, m_ptr(data.data())
	{}

	template <class Allocator = std::allocator<typename std::remove_const<T>::type>>
	ArrayProxy(const std::vector<T, Allocator>& data) noexcept
		: m_count(static_cast<uint32_t>(data.size()))
		, m_ptr(data.data())
	{}

	template <class Allocator = std::allocator<typename std::remove_const<T>::type>,
		typename B = T,
		typename std::enable_if<std::is_const<B>::value, int>::type = 0>
		ArrayProxy(const std::vector<typename std::remove_const<T>::type, Allocator>& data) noexcept
		: m_count(static_cast<uint32_t>(data.size()))
		, m_ptr(data.data())
	{}

	template <class Allocator = std::allocator<typename std::remove_const<T>::type>>
	ArrayProxy(std::vector<T, Allocator>& data) noexcept
		: m_count(static_cast<uint32_t>(data.size()))
		, m_ptr(data.data())
	{}

	template <class Allocator = std::allocator<typename std::remove_const<T>::type>,
		typename B = T,
		typename std::enable_if<std::is_const<B>::value, int>::type = 0>
		ArrayProxy(std::vector<typename std::remove_const<T>::type, Allocator>& data) noexcept
		: m_count(static_cast<uint32_t>(data.size()))
		, m_ptr(data.data())
	{}

	const T* begin() const noexcept
	{
		return m_ptr;
	}

	const T* end() const noexcept
	{
		return m_ptr + m_count;
	}

	const T& front() const noexcept
	{
		assert(m_count && m_ptr);
		return *m_ptr;
	}

	const T& back() const noexcept
	{
		assert(m_count && m_ptr);
		return *(m_ptr + m_count - 1);
	}

	bool empty() const noexcept
	{
		return (m_count == 0);
	}

	uint32_t size() const noexcept
	{
		return m_count;
	}

	T* data() const noexcept
	{
		return m_ptr;
	}

private:
	uint32_t m_count{ 0 };
	T* m_ptr{ nullptr };
};

} // namespace Kodiak