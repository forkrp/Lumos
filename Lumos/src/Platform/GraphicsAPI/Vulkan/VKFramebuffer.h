#pragma once
#include "LM.h"
#include "Graphics/API/FrameBuffer.h"
#include "Dependencies/vulkan/vulkan.h"
#include "VKTexture2D.h"
#include "VKRenderpass.h"

namespace Lumos
{
	namespace graphics
	{
		class LUMOS_EXPORT VKFrameBuffer : public Framebuffer
		{
		public:

			VKFrameBuffer(FrameBufferInfo frameBufferInfo);
			~VKFrameBuffer();

			inline VkFramebuffer GetFrameBuffer() const { return m_Framebuffer; }

			void SetClearColour(const maths::Vector4& colour) override {};

			uint GetWidth() const override { return m_Width; }
			uint GetHeight() const override { return m_Height; }

			void Bind(uint width, uint height) const override {};
			void Bind() const override {};
			void UnBind() const override {};
			void Clear() override {};

			void AddTextureAttachment(Attachment attachmentType, Texture* texture) override {};
			void AddCubeTextureAttachment(Attachment attachmentType, CubeFace face, TextureCube* texture) override {};
			void AddShadowAttachment(Texture* texture) override {};
			void AddTextureLayer(int index, Texture* texture) override {};
			void GenerateFrameBuffer() override {};

		private:

			uint m_Width;
			uint m_Height;
			uint m_AttachmentCount;
			VkFramebuffer m_Framebuffer;
		};
	}
}
