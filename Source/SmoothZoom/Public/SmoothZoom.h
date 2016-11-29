// 837 Studios - MIT License - Michael Gaskin 2016

#pragma once

#include "ModuleManager.h"

class FSmoothZoomModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};