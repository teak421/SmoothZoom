// 837 Studios - MIT License - Michael Gaskin 2016

#include "SmoothZoomPrivatePCH.h"

#define LOCTEXT_NAMESPACE "FSmoothZoomModule"

void FSmoothZoomModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	UE_LOG(LogTemp, Warning, TEXT("Smooth Zoom Plugin Enabled."))
}

void FSmoothZoomModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FSmoothZoomModule, SmoothZoom)