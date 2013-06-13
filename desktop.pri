# @@@LICENSE
#
#      Copyright (c) 2010-2013 LG Electronics, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# LICENSE@@@
CONFIG += debug

debug {
	QMAKE_MAKEFILE = Makefile.Ubuntu
	BUILD_TYPE = debug
} else {
	QMAKE_MAKEFILE = Makefile.Ubuntu.Release
	BUILD_TYPE = release
}

MACHINE_NAME = x86

LUNA_SRC_BASE = $$(LUNA_SRC_BASE)

isEmpty (LUNA_SRC_BASE) {
	TOP_DIR_REL = ".."
} else:exists ($${LUNA_SRC_BASE}) {
	TOP_DIR_REL = "$${LUNA_SRC_BASE}"
} else {
	error("LUNA_SRC_BASE environment variable defined to $${LUNA_SRC_BASE}, but it doesn't exist")
}

TOP_DIR_ABS = $$system(cd $$TOP_DIR_REL; pwd)

WEBKIT_PATH = $$(WEBKIT_PATH)
isEmpty (WEBKIT_PATH) {
    WEBKIT_PATH = $$TOP_DIR_ABS/webkit4v8
}

DEFINES += TARGET_DESKTOP
#DEFINES += ENABLE_JS_DEBUG_VERBOSE

CONFIG_BUILD += opengl

#CONFIG_BUILD += openglcomposited

LIBS += \
	-Wl,-rpath $$(LUNA_STAGING)/lib \
	-Wl,-rpath $$(LUNA_STAGING)/usr/lib \
	-L$$(LUNA_STAGING)/lib \
	-L$$(LUNA_STAGING)/usr/lib

INCLUDEPATH += \
	$$(LUNA_STAGING)/include \
	$$(LUNA_STAGING)/include/Qt \
	$$(LUNA_STAGING)/include/QtCore \
	$$(LUNA_STAGING)/include/QtGui \
	$$(LUNA_STAGING)/include/QtNetwork \
	$$(LUNA_STAGING)/include/QtOpenGL \
	$$(LUNA_STAGING)/include/QtSql \
	$$(LUNA_STAGING)/include/QtDeclarative \
	$$(LUNA_STAGING)/include/ime \
        $$(LUNA_STAGING)/include/luna-sysmgr-common \
	$$(LUNA_STAGING)/usr/include

contains(QT_VERSION, "^5.*") {
    INCLUDEPATH += $$(LUNA_STAGING)/include/QtWebKitWidgets
}

#install
target.path = $$(LUNA_STAGING)/bin
INSTALLS += target
