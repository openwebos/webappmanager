/* @@@LICENSE
*
*      Copyright (c) 2008-2012 Hewlett-Packard Development Company, L.P.
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




#include "Common.h"

#include "WebAppFactory.h"

#include "Settings.h"
#include "WebAppFactoryMinimal.h"
#include "WebAppFactoryLuna.h"
#include "WindowTypes.h"

WebAppFactory* WebAppFactory::instance()
{
	static WebAppFactory* s_instance = 0;
	if (!s_instance) {
		switch (Settings::LunaSettings()->uiType) {
		case (Settings::UI_MINIMAL):
			s_instance = new WebAppFactoryMinimal;
			break;
		case (Settings::UI_LUNA):
		default:
			s_instance = new WebAppFactoryLuna;
			break;
		}
	}
		
	return s_instance;   
}

WebAppFactory::WebAppFactory()
{   
}

WebAppFactory::~WebAppFactory()
{    
}

QString WebAppFactory::nameForWindowType(WindowType::Type winType)
{
    switch (winType) {
    case WindowType::Type_StatusBar:
		return "statusbar";
    case WindowType::Type_ChildCard:
		return "childcard";
    case WindowType::Type_Card:
		return "card";
    case WindowType::Type_Launcher:
		return "launcher";
    case WindowType::Type_Dashboard:
		return "dashboard";
    case WindowType::Type_PopupAlert:
		return "popupalert";
    case WindowType::Type_BannerAlert:
		return "menu";
    case WindowType::Type_PIN:
		return "pin";
    case WindowType::Type_Emergency:
		return "emergency";
    case WindowType::Type_None:
		return "headless";
    case WindowType::Type_ModalChildWindowCard:
		return "modalChildWindowCard";
	default:
		return "unknown";
	}
}
