include $(THEOS)/makefiles/common.mk

BUNDLE_NAME = Defluxit
Defluxit_FILES = $(wildcard *.*m*)
Defluxit_INSTALL_PATH = /Library/PreferenceBundles
Defluxit_FRAMEWORKS = UIKit
Defluxit_PRIVATE_FRAMEWORKS = Preferences

Defluxit_EXTRA_FRAMEWORKS += Cephei CepheiPrefs

Defluxit_CFLAGS += -fobjc-arc

Defluxit_LDFLAGS += -F/opt/theos/sdks/iPhoneOS9.3.sdk/System/Library/PrivateFrameworks/

include $(THEOS_MAKE_PATH)/bundle.mk

internal-stage::
	$(ECHO_NOTHING)mkdir -p $(THEOS_STAGING_DIR)/Library/PreferenceLoader/Preferences$(ECHO_END)
	$(ECHO_NOTHING)cp entry.plist $(THEOS_STAGING_DIR)/Library/PreferenceLoader/Preferences/Defluxit.plist$(ECHO_END)
