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

#if defined(DX12)
#include "Graphics\DX12\GraphicsDevice12.h"
#elif defined(VK)
#include "Graphics\VK\GraphicsDeviceVk.h"
#else
#error "No graphics API specified!"
#endif
