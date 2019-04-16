#include "LM.h"
#include "System.h"
#include "VFS.h"
#include "JobSystem.h"
#include "Profiler.h"

namespace Lumos
{ 
	namespace internal 
	{
	void System::Init()
	{
		system::Profiler::SetEnabled(true);
		system::Profiler::OnInit();

		LMLog::OnInit();
		system::JobSystem::OnInit();
		LUMOS_CORE_INFO("Initializing System");
		VFS::OnInit();
	}

	void System::Shutdown()
	{
		LUMOS_CORE_INFO("Shutting down System");
		VFS::OnShutdown();
    }
} }
