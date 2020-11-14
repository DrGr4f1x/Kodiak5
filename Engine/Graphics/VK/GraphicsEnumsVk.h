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

enum class Blend : uint32_t
{
	Zero =				uint32_t(vk::BlendFactor::eZero),
	One =				uint32_t(vk::BlendFactor::eOne),
	SrcColor =			uint32_t(vk::BlendFactor::eSrcColor),
	InvSrcColor =		uint32_t(vk::BlendFactor::eOneMinusSrcColor),
	SrcAlpha =			uint32_t(vk::BlendFactor::eSrcAlpha),
	InvSrcAlpha =		uint32_t(vk::BlendFactor::eOneMinusSrcAlpha),
	DstAlpha =			uint32_t(vk::BlendFactor::eDstAlpha),
	InvDstAlpha =		uint32_t(vk::BlendFactor::eOneMinusDstAlpha),
	DstColor =			uint32_t(vk::BlendFactor::eDstColor),
	InvDstColor =		uint32_t(vk::BlendFactor::eOneMinusDstColor),
	SrcAlphaSat =		uint32_t(vk::BlendFactor::eSrcAlphaSaturate),
	BlendFactor =		uint32_t(vk::BlendFactor::eConstantColor),
	InvBlendFactor =	uint32_t(vk::BlendFactor::eOneMinusConstantColor),
	Src1Color =			uint32_t(vk::BlendFactor::eSrc1Color),
	InvSrc1Color =		uint32_t(vk::BlendFactor::eOneMinusSrc1Color),
	Src1Alpha =			uint32_t(vk::BlendFactor::eSrc1Alpha),
	InvSrc1Alpha =		uint32_t(vk::BlendFactor::eOneMinusSrc1Alpha)
};


enum class BlendOp : uint32_t
{
	Add =			uint32_t(vk::BlendOp::eAdd),
	Subtract =		uint32_t(vk::BlendOp::eSubtract),
	RevSubtract =	uint32_t(vk::BlendOp::eReverseSubtract),
	Min =			uint32_t(vk::BlendOp::eMin),
	Max =			uint32_t(vk::BlendOp::eMax)
};


enum class LogicOp : uint32_t
{
	Clear =				uint32_t(vk::LogicOp::eClear),
	Set =				uint32_t(vk::LogicOp::eSet),
	Copy =				uint32_t(vk::LogicOp::eCopy),
	CopyInverted =		uint32_t(vk::LogicOp::eCopyInverted),
	Noop =				uint32_t(vk::LogicOp::eNoOp),
	Invert =			uint32_t(vk::LogicOp::eInvert),
	And =				uint32_t(vk::LogicOp::eAnd),
	Nand =				uint32_t(vk::LogicOp::eNand),
	Or =				uint32_t(vk::LogicOp::eOr),
	Nor =				uint32_t(vk::LogicOp::eNor),
	Xor =				uint32_t(vk::LogicOp::eXor),
	Equiv =				uint32_t(vk::LogicOp::eEquivalent),
	AndReverse =		uint32_t(vk::LogicOp::eAndReverse),
	OrReverse =			uint32_t(vk::LogicOp::eOrReverse),
	OrInverted =		uint32_t(vk::LogicOp::eOrInverted)
};


enum class ColorWrite : uint32_t
{
	None =		0,
	Red =		uint32_t(vk::ColorComponentFlagBits::eR),
	Green =		uint32_t(vk::ColorComponentFlagBits::eG),
	Blue =		uint32_t(vk::ColorComponentFlagBits::eB),
	Alpha =		uint32_t(vk::ColorComponentFlagBits::eA),
	All =		Red | Green | Blue | Alpha
};

template <> struct EnableBitmaskOperators<ColorWrite> { static const bool enable = true; };


enum class DepthWrite : uint32_t
{
	Zero =	0,
	All =	1
};


enum class CullMode : uint32_t
{
	None =		uint32_t(vk::CullModeFlagBits::eNone),
	Front =		uint32_t(vk::CullModeFlagBits::eFront),
	Back =		uint32_t(vk::CullModeFlagBits::eBack)
};


enum class FillMode : uint32_t
{
	Wireframe =		uint32_t(vk::PolygonMode::eLine),
	Solid =			uint32_t(vk::PolygonMode::eFill)
};


enum class ComparisonFunc : uint32_t
{
	Never =				uint32_t(vk::CompareOp::eNever),
	Less =				uint32_t(vk::CompareOp::eLess),
	Equal =				uint32_t(vk::CompareOp::eEqual),
	LessEqual =			uint32_t(vk::CompareOp::eLessOrEqual),
	Greater =			uint32_t(vk::CompareOp::eGreater),
	NotEqual =			uint32_t(vk::CompareOp::eNotEqual),
	GreaterEqual =		uint32_t(vk::CompareOp::eGreaterOrEqual),
	Always =			uint32_t(vk::CompareOp::eAlways)
};


enum class StencilOp : uint32_t
{
	Keep =			uint32_t(vk::StencilOp::eKeep),
	Zero =			uint32_t(vk::StencilOp::eZero),
	Replace =		uint32_t(vk::StencilOp::eReplace),
	IncrSat =		uint32_t(vk::StencilOp::eIncrementAndClamp),
	DecrSat =		uint32_t(vk::StencilOp::eDecrementAndClamp),
	Invert =		uint32_t(vk::StencilOp::eInvert),
	Incr =			uint32_t(vk::StencilOp::eIncrementAndWrap),
	Decr =			uint32_t(vk::StencilOp::eDecrementAndWrap)
};


enum class IndexBufferStripCutValue : uint32_t
{
	Disabled,
	Value_0xFFFF,
	Value_0xFFFFFFFF
};


enum class PrimitiveTopology : uint32_t
{
	PointList,
	LineList,
	LineStrip,
	TriangleList,
	TriangleStrip,
	LineListWithAdjacency,
	LineStripWithAdjacency,
	TriangleListWithAdjacency,
	TriangleStripWithAdjacency,
	Patch_1_ControlPoint,
	Patch_2_ControlPoint,
	Patch_3_ControlPoint,
	Patch_4_ControlPoint,
	Patch_5_ControlPoint,
	Patch_6_ControlPoint,
	Patch_7_ControlPoint,
	Patch_8_ControlPoint,
	Patch_9_ControlPoint,
	Patch_10_ControlPoint,
	Patch_11_ControlPoint,
	Patch_12_ControlPoint,
	Patch_13_ControlPoint,
	Patch_14_ControlPoint,
	Patch_15_ControlPoint,
	Patch_16_ControlPoint,
	Patch_17_ControlPoint,
	Patch_18_ControlPoint,
	Patch_19_ControlPoint,
	Patch_20_ControlPoint,
	Patch_21_ControlPoint,
	Patch_22_ControlPoint,
	Patch_23_ControlPoint,
	Patch_24_ControlPoint,
	Patch_25_ControlPoint,
	Patch_26_ControlPoint,
	Patch_27_ControlPoint,
	Patch_28_ControlPoint,
	Patch_29_ControlPoint,
	Patch_30_ControlPoint,
	Patch_31_ControlPoint,
	Patch_32_ControlPoint
};


vk::PrimitiveTopology PrimitiveTopologyToVulkan(PrimitiveTopology topology);
uint32_t GetControlPointCount(PrimitiveTopology topology);


enum class InputClassification : uint32_t
{
	PerVertexData =		uint32_t(vk::VertexInputRate::eVertex),
	PerInstanceData =	uint32_t(vk::VertexInputRate::eInstance)
};


enum class ShaderVisibility : uint32_t
{
	All =			uint32_t(vk::ShaderStageFlagBits::eAll),
	Graphics =		uint32_t(vk::ShaderStageFlagBits::eAllGraphics),
	Compute =		uint32_t(vk::ShaderStageFlagBits::eCompute),
	Domain =		uint32_t(vk::ShaderStageFlagBits::eTessellationEvaluation),
	Geometry =		uint32_t(vk::ShaderStageFlagBits::eGeometry),
	Hull =			uint32_t(vk::ShaderStageFlagBits::eTessellationControl),
	Pixel =			uint32_t(vk::ShaderStageFlagBits::eFragment),
	Vertex =		uint32_t(vk::ShaderStageFlagBits::eVertex),
	Amplification =	uint32_t(vk::ShaderStageFlagBits::eTaskNV),
	Mesh =			uint32_t(vk::ShaderStageFlagBits::eMeshNV)
};


enum class DescriptorType : uint32_t
{
	CBV,
	DynamicCBV,
	Sampler,
	TextureSRV,
	TypedBufferSRV,
	StructuredBufferSRV,
	TextureUAV,
	TypedBufferUAV,
	StructuredBufferUAV
};

vk::DescriptorType DescriptorTypeToVulkan(DescriptorType type);


enum class RootSignatureFlags : uint32_t
{
	None,
	AllowInputAssemblerInputLayout,
	DenyVertexShaderRootAccess,
	DenyHullShaderRootAccess,
	DenyDomainShaderRootAccess,
	DenyGeometryShaderRootAccess,
	DenyPixelShaderRootAccess,
	AllowStreamOutput
};

template <> struct EnableBitmaskOperators<RootSignatureFlags> { static const bool enable = true; };


enum class TextureFilter : uint32_t
{
	MinMagMipPoint,
	MinMagPointMipLinear,
	MinPointMagLinearMipPoint,
	MinPointMagMipLinear,
	MinLinearMagMipPoint,
	MinLinearMagPointMipLinear,
	MinMagLinearMipPoint,
	MinMagMipLinear,
	Anisotropic,

	ComparisonMinMagMipPoint,
	ComparisonMinMagPointMipLinear,
	ComparisonMinPointMagLinearMipPoint,
	ComparisonMinPointMagMipLinear,
	ComparisonMinLinearMagMipPoint,
	ComparisonMinLinearMagPointMipLinear,
	ComparisonMinMagLinearMipPoint,
	ComparisonMinMagMipLinear,
	ComparisonAnisotropic,

	MinimumMinMagMipPoint,
	MinimumMinMagPointMipLinear,
	MinimumMinPointMagLinearMipPoint,
	MinimumMinPointMagMipLinear,
	MinimumMinLinearMagMipPoint,
	MinimumMinLinearMagPointMipLinear,
	MinimumMinMagLinearMipPoint,
	MinimumMinMagMipLinear,
	MinimumAnisotropic,

	MaximumMinMagMipPoint,
	MaximumMinMagPointMipLinear,
	MaximumMinPointMagLinearMipPoint,
	MaximumMinPointMagMipLinear,
	MaximumMinLinearMagMipPoint,
	MaximumMinLinearMagPointMipLinear,
	MaximumMinMagLinearMipPoint,
	MaximumMinMagMipLinear,
	MaximumAnisotropic
};


enum class TextureAddress : uint32_t
{
	Wrap,
	Mirror,
	Clamp,
	Border,
	MirrorOnce
};


enum class Format : uint32_t
{
	Unknown =				uint32_t(vk::Format::eUndefined),
	B4G4R4A4_UNorm =		uint32_t(vk::Format::eB4G4R4A4UnormPack16),
	B5G6R5_UNorm =			uint32_t(vk::Format::eB5G6R5UnormPack16),
	B5G5R5A1_UNorm =		uint32_t(vk::Format::eB5G5R5A1UnormPack16),
	B8G8R8A8_UNorm =		uint32_t(vk::Format::eB8G8R8A8Unorm),
	R8_UNorm =				uint32_t(vk::Format::eR8Unorm),
	R8_SNorm =				uint32_t(vk::Format::eR8Snorm),
	R8_UInt =				uint32_t(vk::Format::eR8Uint),
	R8_SInt =				uint32_t(vk::Format::eR8Sint),
	R8G8_UNorm =			uint32_t(vk::Format::eR8G8Unorm),
	R8G8_SNorm =			uint32_t(vk::Format::eR8G8Snorm),
	R8G8_UInt =				uint32_t(vk::Format::eR8G8Uint),
	R8G8_SInt =				uint32_t(vk::Format::eR8G8Sint),
	R8G8B8A8_UNorm =		uint32_t(vk::Format::eR8G8B8A8Unorm),
	R8G8B8A8_UNorm_SRGB =	uint32_t(vk::Format::eR8G8B8A8Srgb),
	R8G8B8A8_SNorm =		uint32_t(vk::Format::eR8G8B8A8Snorm),
	R8G8B8A8_UInt =			uint32_t(vk::Format::eR8G8B8A8Uint),
	R8G8B8A8_SInt =			uint32_t(vk::Format::eR8G8B8A8Sint),
	R9G9B9E5_Float =		uint32_t(vk::Format::eE5B9G9R9UfloatPack32),
	R16_UNorm =				uint32_t(vk::Format::eR16Unorm),
	R16_SNorm =				uint32_t(vk::Format::eR16Snorm),
	R16_UInt =				uint32_t(vk::Format::eR16Uint),
	R16_SInt =				uint32_t(vk::Format::eR16Sint),
	R16_Float =				uint32_t(vk::Format::eR16Sfloat),
	R16G16_UNorm =			uint32_t(vk::Format::eR16G16Unorm),
	R16G16_SNorm =			uint32_t(vk::Format::eR16G16Snorm),
	R16G16_UInt =			uint32_t(vk::Format::eR16G16Uint),
	R16G16_SInt =			uint32_t(vk::Format::eR16G16Sint),
	R16G16_Float =			uint32_t(vk::Format::eR16G16Sfloat),
	R16G16B16A16_UNorm =	uint32_t(vk::Format::eR16G16B16A16Unorm),
	R16G16B16A16_SNorm =	uint32_t(vk::Format::eR16G16B16A16Snorm),
	R16G16B16A16_UInt =		uint32_t(vk::Format::eR16G16B16A16Uint),
	R16G16B16A16_SInt =		uint32_t(vk::Format::eR16G16B16A16Sint),
	R16G16B16A16_Float =	uint32_t(vk::Format::eR16G16B16A16Sfloat),
	R32_UInt =				uint32_t(vk::Format::eR32Uint),
	R32_SInt =				uint32_t(vk::Format::eR32Sint),
	R32_Float =				uint32_t(vk::Format::eR32Sfloat),
	R32G32_UInt =			uint32_t(vk::Format::eR32G32Uint),
	R32G32_SInt =			uint32_t(vk::Format::eR32G32Sint),
	R32G32_Float =			uint32_t(vk::Format::eR32G32Sfloat),
	R32G32B32_UInt =		uint32_t(vk::Format::eR32G32B32Uint),
	R32G32B32_SInt =		uint32_t(vk::Format::eR32G32B32Sint),
	R32G32B32_Float =		uint32_t(vk::Format::eR32G32B32Sfloat),
	R32G32B32A32_UInt =		uint32_t(vk::Format::eR32G32B32A32Uint),
	R32G32B32A32_SInt =		uint32_t(vk::Format::eR32G32B32A32Sint),
	R32G32B32A32_Float =	uint32_t(vk::Format::eR32G32B32A32Sfloat),
	R11G11B10_Float =		uint32_t(vk::Format::eB10G11R11UfloatPack32),
	R10G10B10A2_UNorm =		uint32_t(vk::Format::eA2B10G10R10UnormPack32),

	D16_UNorm =				uint32_t(vk::Format::eD16Unorm),
	D24S8 =					uint32_t(vk::Format::eD24UnormS8Uint),
	D32_Float =				uint32_t(vk::Format::eD32Sfloat),
	D32_Float_S8_UInt =		uint32_t(vk::Format::eD32SfloatS8Uint),

	BC1_UNorm =				uint32_t(vk::Format::eBc1RgbaUnormBlock),
	BC1_UNorm_SRGB =		uint32_t(vk::Format::eBc1RgbaSrgbBlock),
	BC2_UNorm =				uint32_t(vk::Format::eBc2UnormBlock),
	BC2_UNorm_SRGB =		uint32_t(vk::Format::eBc2SrgbBlock),
	BC3_UNorm =				uint32_t(vk::Format::eBc3UnormBlock),
	BC3_UNorm_SRGB =		uint32_t(vk::Format::eBc3SrgbBlock),
	BC4_UNorm =				uint32_t(vk::Format::eBc4UnormBlock),
	BC4_SNorm =				uint32_t(vk::Format::eBc4SnormBlock),
	BC5_UNorm =				uint32_t(vk::Format::eBc5UnormBlock),
	BC5_SNorm =				uint32_t(vk::Format::eBc5SnormBlock),
	BC6H_Float =			uint32_t(vk::Format::eBc6HSfloatBlock),
	BC6H_UFloat =			uint32_t(vk::Format::eBc6HUfloatBlock),
	BC7_UNorm =				uint32_t(vk::Format::eBc7UnormBlock),
	BC7_UNorm_SRGB =		uint32_t(vk::Format::eBc7SrgbBlock)
};

Format VulkanFormatToEngine(vk::Format format);

} // namespace Kodiak