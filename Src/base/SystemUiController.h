/* @@@LICENSE
*
*      Copyright (c) 2008-2013 LG Electronics, Inc.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
* LICENSE@@@ */




#ifndef SYSTEMUICONTROLLER_H
#define SYSTEMUICONTROLLER_H

class SystemUiController
{
public:
	// The order of the layers below defines their priorities in terms of direct rendering
	enum DirectRenderingEnabledLayers
	{
		DISABLE_ALL_DIRECT_RENDERING = 0, // virtual layer used to temporarily completely disable direct rendering  
		DOCK_MODE_WINDOW_MANAGER,
		TOP_LEVEL_WINDOW_MANAGER,
		EMERGENCY_MODE_WINDOW_MANAGER,   // Temporarily demoted Emergency Mode WM in Dartfish (it is being used for Flash full screen)
		OVERLAY_WINDOW_MANAGER,
		CARD_WINDOW_MANAGER,
		NUMBER_OF_LAYERS
	};

	enum ModalWinLaunchErrorReason {
		LaunchUnknown = -1,
		NoErr = 0,
		MalformedRequest,
		NoMaximizedCard,
		ParentDifferent,
		AnotherModalActive,
		AppToLaunchDoesntExist,
		AppToLaunchIsntReady,
		//AppToLaunchIsNotHeadless,
		AnotherInstanceAlreadyRunning,
		MissingAppDescriptor,
		MissingProcessId,
		InternalError,
		LaunchErrorMax
	};

	enum ModalWinDismissErrorReason {
		DismissUnknown = (LaunchErrorMax+1),
		HomeButtonPressed,
		ServiceDismissedModalCard,
		ParentCardDismissed,
		ActiveCardsSwitched,
		UiMinimized,
	};
	enum LauncherOperations
	{
			LAUNCHEROP_ADDCARD,
			LAUNCHEROP_REORDER,
			LAUNCHEROP_DELETECARD,
			LAUNCHEROP_INVOKERENAMECARD,
			LAUNCHEROP_UNKNOWN						//keep this as the last one
	};

	enum LauncherActions
	{
			LAUNCHERACT_MENUACTIVE,
			LAUNCHERACT_INFOACTIVE,
			LAUNCHERACT_EDITINGCARDTITLE,
			LAUNCHERACT_DBG_ACTIVATE_SCREEN_GRID,
			LAUNCHERACT_DBG_DEACTIVATE_SCREEN_GRID,
	};
};


#endif /* SYSTEMUICONTROLLER_H */
