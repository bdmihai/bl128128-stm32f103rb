#______________________________________________________________________________
#│                                                                            |
#│ COPYRIGHT (C) 2020 Mihai Baneu                                             |
#│                                                                            |
#| Permission is hereby  granted,  free of charge,  to any person obtaining a |
#| copy of this software and associated documentation files (the "Software"), |
#| to deal in the Software without restriction,  including without limitation |
#| the rights to  use, copy, modify, merge, publish, distribute,  sublicense, |
#| and/or sell copies  of  the Software, and to permit  persons to  whom  the |
#| Software is furnished to do so, subject to the following conditions:       |
#|                                                                            |
#| The above  copyright notice  and this permission notice  shall be included |
#| in all copies or substantial portions of the Software.                     |
#|                                                                            |
#| THE SOFTWARE IS PROVIDED  "AS IS",  WITHOUT WARRANTY OF ANY KIND,  EXPRESS |
#| OR   IMPLIED,   INCLUDING   BUT   NOT   LIMITED   TO   THE  WARRANTIES  OF |
#| MERCHANTABILITY,  FITNESS FOR  A  PARTICULAR  PURPOSE AND NONINFRINGEMENT. |
#| IN NO  EVENT SHALL  THE AUTHORS  OR  COPYRIGHT  HOLDERS  BE LIABLE FOR ANY |
#| CLAIM, DAMAGES OR OTHER LIABILITY,  WHETHER IN AN ACTION OF CONTRACT, TORT |
#| OR OTHERWISE, ARISING FROM,  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR  |
#| THE USE OR OTHER DEALINGS IN THE SOFTWARE.                                 |
#|____________________________________________________________________________|
#|                                                                            |
#|  Author: Mihai Baneu                           Last modified: 15.May.2020  |
#|                                                                            |
#|____________________________________________________________________________|

CONFIG_MCU                  = STM32F103x8
CONFIG_OPENOCDDIR 			= ~/work/tools/openocd/src
CONFIG_OPENOCDCONFIGDIR		= ~/work/tools/openocd/tcl
CONFIG_OPENOCD_INTERFACE	= interface/stlink-v3.cfg
CONFIG_OPENOCD_BOARD		= board/stm32f103xx.cfg

.PHONY: all build clean

MAKECMDGOALS ?= all
all: build

config:
	/usr/bin/qbs config-ui
	
build: 
	/usr/bin/qbs build -d build -f source/project.qbs --jobs 16 config:$(CONFIG_MCU) qbs.installRoot:bin qbs.targetPlatform:$(CONFIG_MCU)

build-with-commands:
	/usr/bin/qbs build -d build -f source/project.qbs --jobs 16 config:$(CONFIG_MCU) --command-echo-mode command-line qbs.installRoot:bin qbs.targetPlatform:$(CONFIG_MCU)

objdump:
	arm-none-eabi-objdump -t  bin/application.elf
	
clean:
	/usr/bin/qbs clean -d build config:$(CONFIG_MCU)

debug:
	$(CONFIG_OPENOCDDIR)/openocd -s $(CONFIG_OPENOCDCONFIGDIR) -f $(CONFIG_OPENOCD_INTERFACE) -f $(CONFIG_OPENOCD_BOARD)

reset:
	$(CONFIG_OPENOCDDIR)/openocd -s $(CONFIG_OPENOCDCONFIGDIR) -f $(CONFIG_OPENOCD_INTERFACE) -f $(CONFIG_OPENOCD_BOARD) -c "init; reset; exit"

flash: all
	$(CONFIG_OPENOCDDIR)/openocd -s $(CONFIG_OPENOCDCONFIGDIR) -f $(CONFIG_OPENOCD_INTERFACE) -f $(CONFIG_OPENOCD_BOARD) -c "program bin/application.elf verify; reset; exit"

stflash:
	~/work/tools/stlink/build/Release/bin/st-flash --reset write bin/application.bin 0x08000000

monitor:
	screen /dev/ttyACM0 115200

list-usb:
	./scripts/list-usb.sh