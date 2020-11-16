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

class GraphicsDevice 
{
public:
	GraphicsDevice() = default;
	~GraphicsDevice() = default;

	void Initialize(const std::string& appName, HINSTANCE hInstance, HWND hWnd, uint32_t width, uint32_t height, Format colorFormat, Format depthFormat);

private:

	void InitializeInstance();
	
	HRESULT CreateInstance(
		const std::string& appName, 
		const std::string& engineName, 
		const std::vector<std::string>& layers, 
		const std::vector<std::string>& extensions, 
		uint32_t apiVersion, void** pUVkInstance);

private:
	std::string m_appName;

	HINSTANCE m_hinst{ 0 };
	HWND m_hwnd{ 0 };

	uint32_t m_width{ 0 };
	uint32_t m_height{ 0 };

	Format m_colorFormat;
	Format m_depthFormat;

	// Vulkan members
	Microsoft::WRL::ComPtr<UVkInstance> m_instance;
};

} // namespace Kodiak