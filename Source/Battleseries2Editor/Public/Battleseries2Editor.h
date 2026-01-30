#pragma once

#include "Modules/ModuleManager.h"

class FBattleseries2EditorModule : public IModuleInterface
{
	public:

		/** IModuleInterface implementation */
		virtual void StartupModule() override;
		virtual void ShutdownModule() override;
};