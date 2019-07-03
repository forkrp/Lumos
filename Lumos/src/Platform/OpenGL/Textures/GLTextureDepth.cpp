#include "LM.h"
#include "GLTextureDepth.h"

#include "Platform/OpenGL/GL.h"


namespace Lumos
{
	namespace Graphics
	{
		GLTextureDepth::GLTextureDepth(u32 width, u32 height)
			: m_Width(width), m_Height(height)
		{
			GLCall(glGenTextures(1, &m_Handle));

			Init();
		}

		GLTextureDepth::~GLTextureDepth()
		{
			GLCall(glDeleteTextures(1, &m_Handle));
		}

		void GLTextureDepth::Bind(u32 slot) const
		{
			GLCall(glActiveTexture(GL_TEXTURE0 + slot));
			GLCall(glBindTexture(GL_TEXTURE_2D, m_Handle));
		}

		void GLTextureDepth::Unbind(u32 slot) const
		{
			GLCall(glActiveTexture(GL_TEXTURE0 + slot));
			GLCall(glBindTexture(GL_TEXTURE_2D, 0));
		}

		void GLTextureDepth::Init()
		{
			GLCall(glBindTexture(GL_TEXTURE_2D, m_Handle));

			GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT32F, m_Width, m_Height, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL));
			GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
			GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
			GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
			GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));
			GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_FUNC, GL_LEQUAL));
#ifndef LUMOS_PLATFORM_MOBILE
			GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_MODE, GL_NONE));
#endif
			GLCall(glBindTexture(GL_TEXTURE_2D, 0));
		}

		void GLTextureDepth::Resize(u32 width, u32 height)
		{
			m_Width = width;
			m_Height = height;

			Init();
		}
	}
}
