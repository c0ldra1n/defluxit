
# TARGET = simulator:clang
# ARCHS = x86_64 i386

include $(THEOS)/makefiles/common.mk

TWEAK_NAME = Defluxit
Defluxit_FILES = $(wildcard *.*m*)

Defluxit_CFLAGS += -D THEOSBUILD=1 -D HBLogError=NSLog -w
Defluxit_CFLAGS += -fobjc-arc

include $(THEOS_MAKE_PATH)/tweak.mk

after-install::
	install.exec "killall -9 SpringBoard"
SUBPROJECTS += preferences
include $(THEOS_MAKE_PATH)/aggregate.mk
