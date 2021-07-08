// Fill out your copyright notice in the Description page of Project Settings.


#include "Window_Actor.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "Runtime/Engine/Public/Slate/SceneViewport.h"
#include "Runtime/SlateCore/Public/Widgets/SWindow.h"
#include "Runtime/Slate/Public/Widgets/SViewport.h"
#include "Runtime/SlateCore/Public/Widgets/SOverlay.h"
#include "Runtime/Slate/Public/Framework/Application/SlateApplication.h"
#include "Runtime/Slate/Public/Widgets/Layout/SConstraintCanvas.h"
#include "Runtime/Slate/Public/Widgets/Layout/SScaleBox.h"
#include "Runtime/Slate/Public/Widgets/Layout/SBox.h"

// Sets default values
AWindow_Actor::AWindow_Actor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWindow_Actor::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AWindow_Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called every frame
void AWindow_Actor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	//DestroySpectatorWindow();
	DestroyWindow();

}

void AWindow_Actor::CreateSpectatorWindow(FVector2D WindowSize, FVector2D WindowPosition, UUserWidget * showWidget, bool autoCenter)
{
	//WindowMode = EWindowMode::WindowedFullscreen;
	// Create and add window

	SpectatorWindow = SNew(SWindow)
		.ScreenPosition(WindowPosition)
		.ClientSize(WindowSize)
		.SizingRule(ESizingRule::UserSized)
		.Title(FText::FromString(TEXT("DentistVR Control-Panel")))
		.AutoCenter(autoCenter ? (EAutoCenter::PrimaryWorkArea) : (EAutoCenter::None))
		.FocusWhenFirstShown(true)
		.UseOSWindowBorder(true)
		.UserResizeBorder(true)
		.CreateTitleBar(true)
		.SupportsTransparency(EWindowTransparency::PerWindow)
		.InitialOpacity(1.0f)
		.SupportsMaximize(true)
		.HasCloseButton(false);

	SpectatorWindow->SetViewportSizeDrivenByWindow(true);
	//获取当前应用的实例
	FSlateApplication& SlateApp = FSlateApplication::Get();//&是引用，及slateapp是后面变量的替身，操作替身等于操作本体
	//添加新建的窗口到该实例中
	TSharedPtr<SWindow> TopWindow = SlateApp.GetActiveTopLevelWindow();
	//#if WITH_EDITOR
	SlateApp.AddWindow(SpectatorWindow.ToSharedRef(), true);
	//#else
	  //SlateApp.AddModalWindow(SpectatorWindow.ToSharedRef(), TopWindow, true);
	//#endif

	  //新建一个内容画布
	TSharedRef<SOverlay> ViewportWidget = SNew(SOverlay);
	TSharedPtr<SWidget> SlateWidget = showWidget->TakeWidget();
	// Add slate widget to window
	ViewportWidget->AddSlot()
		.HAlign(HAlign_Fill).VAlign(VAlign_Fill)//.Offset(FMargin(0,0,1,1)
		[
			SNew(SScaleBox).HAlign(HAlign_Fill).VAlign(VAlign_Fill)
			[
				SlateWidget.ToSharedRef()
			]
		];
	ViewportWidget->SetVisibility(EVisibility::Visible);
	//内容设置
	SpectatorWindow->SetContent(ViewportWidget);
	SpectatorWindow->ShowWindow();
	//设置窗口模式
	SpectatorWindow->SetWindowMode(EWindowMode::Windowed);
	bIsStandaloneGame = GetWorld()->WorldType == EWorldType::Game;
}

void AWindow_Actor::OnCombinedUIQuitButtonClickedHandler()
{
	//FSlateApplication & SlateApp = FSlateApplication::Get();

	//// Destroy window
	//if (SpectatorWindow.Get() != nullptr)
	//{
	//	if (bIsStandaloneGame == false)
	//	{
	//		SpectatorWindow->RequestDestroyWindow();
	//		return;
	//	}
	//	else
	//	{
	//		SpectatorWindow->DestroyWindowImmediately();
	//		return;
	//	}
	//}
}

void AWindow_Actor::DestroySpectatorWindow()
{
	/*if (SpectatorWindow.Get() != nullptr)
	{
		SpectatorWindow->DestroyWindowImmediately();
		return;
	}*/
}

void AWindow_Actor::DestroyWindow()
{
	if (SpectatorWindow.Get() != nullptr)
	{
		SpectatorWindow->RequestDestroyWindow();
		return;
	}
}

