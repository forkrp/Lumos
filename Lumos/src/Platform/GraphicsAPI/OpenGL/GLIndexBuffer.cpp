#include "LM.h"
#include "GLIndexBuffer.h"

#include "GL.h"


namespace Lumos
{
	static uint BufferUsageToOpenGL(const BufferUsage usage)
	{
		switch (usage)
		{
		case BufferUsage::STATIC:  return GL_STATIC_DRAW;
		case BufferUsage::DYNAMIC: return GL_DYNAMIC_DRAW;
		case BufferUsage::STREAM:  return GL_STREAM_DRAW;
		}
		return 0;
	}

	GLIndexBuffer::GLIndexBuffer(uint16* data, uint count, BufferUsage bufferUsage)
		: m_Count(count), m_Usage(bufferUsage)
	{
		GLCall(glGenBuffers(1, &m_Handle));
		GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Handle));
		GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(uint16), data, BufferUsageToOpenGL(m_Usage)));
	}

	GLIndexBuffer::GLIndexBuffer(uint* data, uint count, BufferUsage bufferUsage)
		: m_Count(count), m_Usage(bufferUsage)
	{
		GLCall(glGenBuffers(1, &m_Handle));
		GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Handle));
		GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(uint), data, BufferUsageToOpenGL(m_Usage)));
	}

	GLIndexBuffer::~GLIndexBuffer()
	{
		GLCall(glDeleteBuffers(1, &m_Handle));
	}

	void GLIndexBuffer::Bind() const
	{
		GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Handle));
	}

	void GLIndexBuffer::Unbind() const
	{

#ifdef LUMOS_DEBUG
		GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
#endif
	}

	uint GLIndexBuffer::GetCount() const
	{
		return m_Count;
	}
}