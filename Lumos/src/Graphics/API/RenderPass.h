#pragma once
#include "LM.h"
#include "Textures/Texture.h"

namespace Lumos
{
	namespace maths
	{
		class Vector4;
	}

	class Framebuffer;
}

namespace Lumos
{
	namespace graphics
	{
		namespace api
		{
			class CommandBuffer;

			struct RenderpassInfo
			{
				TextureType* textureType;
				int attachmentCount;
				bool depthOnly = false;
			};

			enum SubPassContents
			{
				INLINE,
				SECONDARY
			};

			class LUMOS_EXPORT RenderPass
			{
			public:
				virtual ~RenderPass() = default;
				static RenderPass* Create();

				virtual bool Init(const RenderpassInfo& renderpassCI) = 0;
				virtual void Unload() const = 0;
				virtual void BeginRenderpass(CommandBuffer* commandBuffer, const maths::Vector4& clearColour, Framebuffer* frame,
					SubPassContents contents, uint32_t width, uint32_t height) const = 0;
				virtual void EndRenderpass(CommandBuffer * commandBuffer) = 0;
			};
		}
	}
}
