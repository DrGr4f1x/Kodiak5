//
// This code is licensed under the MIT License (MIT).
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.
//
// Author:  David Elder
//

#pragma once

namespace Kodiak
{

// GUIDs for IUnknown::QueryInterface

// {2F3AF08F-0ADA-4E39-B62B-A05714319E09}
DEFINE_GUID(IID_UVkInstance, 0x2f3af08f, 0xada, 0x4e39, 0xb6, 0x2b, 0xa0, 0x57, 0x14, 0x31, 0x9e, 0x9);


// Macro to define the IUnknown interface
#define IMPLEMENT_IUNKNOWN(IID_TYPE) \
HRESULT QueryInterface(REFIID riid, LPVOID* ppvObj) final \
{ \
	if (!ppvObj) \
	{ \
		return E_INVALIDARG; \
	} \
	*ppvObj = nullptr; \
	if (riid == IID_IUnknown || riid == IID_TYPE) \
	{ \
		*ppvObj = (LPVOID)this; \
		AddRef(); \
		return NOERROR; \
	} \
	return E_NOINTERFACE; \
} \
\
ULONG AddRef() final \
{ \
	++m_cRef; \
	return m_cRef; \
} \
\
ULONG Release() final \
{ \
	ULONG ulRefCount = --m_cRef; \
	if (0 == m_cRef) \
	{ \
		delete this; \
	} \
	return ulRefCount; \
}\
\
private: \
	std::atomic_ulong m_cRef{ 0 };


//
// vk::Instance
//
class UVkInstance : public IUnknown
{
public:
	explicit UVkInstance(VkInstance instance)
		: m_instance(instance)
	{}
	~UVkInstance()
	{
		if (m_instance)
		{
			vkDestroyInstance(m_instance, nullptr);
			m_instance = VK_NULL_HANDLE;
		}
	}

	operator VkInstance() const 
	{
		return m_instance;
	}

	IMPLEMENT_IUNKNOWN(IID_UVkInstance)

private:
	VkInstance m_instance{ nullptr };
};

} // namespace Kodiak