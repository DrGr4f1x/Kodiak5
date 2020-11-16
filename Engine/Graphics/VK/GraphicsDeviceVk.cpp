//
// This code is licensed under the MIT License (MIT).
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.
//
// Author:  David Elder
//

#include "Stdafx.h"

#include "GraphicsDeviceVk.h"


using namespace Kodiak;
using namespace std;


void GraphicsDevice::Initialize(const string& appName, HINSTANCE hInstance, HWND hWnd, uint32_t width, uint32_t height, Format colorFormat, Format depthFormat)
{
	m_appName = appName;

	m_hinst = hInstance;
	m_hwnd = hWnd;

	m_width = width;
	m_height = height;
	m_colorFormat = colorFormat;
	m_depthFormat = depthFormat;

	InitializeInstance();
}


void GraphicsDevice::InitializeInstance()
{

}


HRESULT GraphicsDevice::CreateInstance(
	const string& appName,
	const string& engineName,
	const vector<string>& layers,
	const vector<string>& extensions,
	uint32_t apiVersion, 
	void** pUVkInstance)
{
	if (!pUVkInstance)
	{
		return E_INVALIDARG;
	}
	*pUVkInstance = nullptr;

	return S_OK;
}