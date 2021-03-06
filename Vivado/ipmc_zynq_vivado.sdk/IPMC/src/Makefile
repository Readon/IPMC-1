ifeq (x$(BUILD_CONFIGURATION),x)
$(error Please specify a BUILD_CONFIGURATION)
endif

export GIT_DIRTY        := $(shell git diff-index --quiet HEAD || echo 'dirty')
export PROJECT_ROOT     := $(realpath ..)
export PROJECT_NAME     := $(notdir $(PROJECT_ROOT))
export BUILD_CONFIGURATION

export CC := arm-none-eabi-gcc
export CXX := arm-none-eabi-g++
export OBJCOPY := arm-none-eabi-objcopy

export WORKSPACE ?= ../..

export INCLUDE_PATHS = \
	-I"$(WORKSPACE)/IPMC/src/common/zynqipmc" \
	-I"$(WORKSPACE)/IPMC/src/config" \
	-I"$(WORKSPACE)/IPMC/src" \
	-I"$(WORKSPACE)/IPMC/src/components" \
	-I"$(WORKSPACE)/IPMC/src/common/lwIP/src/contrib/ports/xilinx/include" \
	-I"$(WORKSPACE)/IPMC/src/common/lwIP/src/lwip-2.0.2/src/include" \
	-I"$(WORKSPACE)/IPMC/src/common/FreeRTOS/portable/GCC/ARM_CA9" \
	-I"$(WORKSPACE)/IPMC/src/common/FreeRTOS/include" \
	-I"$(WORKSPACE)/ipmc_standalone_bsp/ps7_cortexa9_0/include" \

export FUNCTION_WRAPPERS = \
	-Wl,-wrap=malloc \
	-Wl,-wrap=free \
	-Wl,-wrap=calloc \
	-Wl,-wrap=realloc \
	-Wl,-wrap=printf \
	-Wl,-wrap=sprintf \
	-Wl,-wrap=snprintf \
	-Wl,-wrap=vprintf \
	-Wl,-wrap=vsprintf \
	-Wl,-wrap=vsnprintf \
	-Wl,-wrap=xil_printf \
	-Wl,-wrap=print \
	-Wl,-wrap=sleep \
	-Wl,-wrap=sha_256 \
	-Wl,-wrap=__cxa_throw \
	-Wl,-wrap=__cxa_free_exception \

export LIBRARY_PATHS = \
	-L"$(WORKSPACE)/ipmc_standalone_bsp/ps7_cortexa9_0/lib" \

export LIBS := -lrsa -Wl,--start-group,-lxil,-lgcc,-lc,-lstdc++,--end-group

ifeq ($(BUILD_CONFIGURATION),Debug)
# "-Og Optimize debugging experience.  -Og enables optimizations that do not interfere with debugging." from man g++
OPTIMIZE_OPTIONS := -O0 -ggdb3  -funwind-tables -mpoke-function-name
#-flto -fuse-linker-plugin -fno-fat-lto-objects
else
# "-Os Optimize for size.  -Os enables all -O2 optimizations that do not typically increase code size." from man g++
OPTIMIZE_OPTIONS := -Os -g0
#-flto -fuse-linker-plugin -fno-fat-lto-objects
endif

export CFLAGS = \
	$(OPTIMIZE_OPTIONS) \
	-fmessage-length=0 \
	-mcpu=cortex-a9 \
	-mfpu=neon \
	-ftree-vectorize \
	-mvectorize-with-neon-quad \
	-mfloat-abi=hard \
	-MMD -MP -MF"$(patsubst .obj/$(BUILD_CONFIGURATION)/%,.dep/$(BUILD_CONFIGURATION)/%,$@)" \
	-D XPAR_XISF_FLASH_FAMILY=5 -D XPAR_XISF_INTERFACE_PSQSPI \
	-D _BSD_SOURCE \
	-D INCLUDE_DRIVER_COMMAND_SUPPORT \

# -MT"$@"

export CXXFLAGS = \
	-std=c++11 \

export LDFLAGS := \
	-Wl,-build-id=none \
	-specs=Xilinx.spec \
	-Wl,-T -Wl,lscript.ld \
	$(FUNCTION_WRAPPERS) \

export WARNING_FLAGS = -Wall -Wno-psabi

OBJS := \
	$(patsubst ./%.c,.obj/$(BUILD_CONFIGURATION)/%.o,$(shell find -L . -type f -name '*.c')) \
	$(patsubst ./%.cc,.obj/$(BUILD_CONFIGURATION)/%.o,$(shell find -L . -type f -name '*.cc')) \
	$(patsubst ./%.cpp,.obj/$(BUILD_CONFIGURATION)/%.o,$(shell find -L . -type f -name '*.cpp')) \
	$(patsubst ./%.S,.obj/$(BUILD_CONFIGURATION)/%.o,$(shell find -L . -type f -name '*.S')) \

#all: doxygen build
all: build

pre-build: .dep/.lwip-patch
	-a9-linaro-pre-build-step

.dep/.lwip-patch:
	@mkdir -p .dep/
	touch "$@"
	find common/lwIP/src/contrib/ports/xilinx -type f -exec sed -i -re 's/#include .xil_printf\.h.//;s/xil_printf/ipmc_lwip_printf/g;s/\<printf/ipmc_lwip_printf/g;s/\<print\(/ipmc_lwip_printf("%s",/g' '{}' +
	sed -i -r -e '/^#undef /d;s/(#define\s+)(E\w+)(\s)/#undef \2\n\1\2\3/' common/lwIP/src/lwip-2.0.2/src/include/lwip/arch.h
	find common/lwIP/src -type f -name '*.h' -exec sed -i -e 's!"U16_F!" U16_F!g;s!U16_F"!U16_F "!g' '{}' +

build: pre-build bin/$(BUILD_CONFIGURATION)/IPMC.elf

bin/$(BUILD_CONFIGURATION)/IPMC.elf: $(OBJS) | pre-build
	@mkdir -p "$(dir $@)"
	$(CXX) $(CFLAGS) $(LDFLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) -o "$@" $^ $(LIBS)
	$(OBJCOPY) --add-section .versiondata=/dev/stdin --set-section-flags .versiondata=noload,readonly "$@" < .obj/$(BUILD_CONFIGURATION)/common/zynqipmc/misc/version.json
	arm-none-eabi-size "$@" | tee "$@.size"

.obj/$(BUILD_CONFIGURATION)/%.o: %.c | pre-build
	@mkdir -p "$(dir $@)" "$(dir $(patsubst .obj/$(BUILD_CONFIGURATION)/%,.dep/$(BUILD_CONFIGURATION)/%,$@))"
ifeq "common/lwIP/src/" "$(patsubst $@,common/lwIP/src/%,common/lwIP/src/)"
	$(CC) -c $(CFLAGS) $(LDFLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) -o "$@" "$<" $(LIBS)
else
	$(CC) -c $(CFLAGS) $(WARNING_FLAGS) $(LDFLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) -o "$@" "$<" $(LIBS)
endif

.obj/$(BUILD_CONFIGURATION)/%.o: %.cc | pre-build
	@mkdir -p "$(dir $@)" "$(dir $(patsubst .obj/$(BUILD_CONFIGURATION)/%,.dep/$(BUILD_CONFIGURATION)/%,$@))"
ifeq "common/lwIP/src/" "$(patsubst $@,common/lwIP/src/%,common/lwIP/src/)"
	$(CXX) -c $(CFLAGS) $(CXXFLAGS) $(LDFLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) -o "$@" "$<" $(LIBS)
else
	$(CXX) -c $(CFLAGS) $(WARNING_FLAGS) $(CXXFLAGS) $(LDFLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) -o "$@" "$<" $(LIBS)
endif

.obj/$(BUILD_CONFIGURATION)/common/zynqipmc/misc/version.json:
	@mkdir -p "$(dir $@)" "$(dir $(patsubst .obj/$(BUILD_CONFIGURATION)/%,.dep/$(BUILD_CONFIGURATION)/%,$@))"
	common/zynqipmc/misc/gen_version.py > "$@"
.PHONY: .obj/$(BUILD_CONFIGURATION)/common/zynqipmc/misc/version.json

.obj/$(BUILD_CONFIGURATION)/common/zynqipmc/misc/version.json.cstr: .obj/$(BUILD_CONFIGURATION)/common/zynqipmc/misc/version.json
	@mkdir -p "$(dir $@)" "$(dir $(patsubst .obj/$(BUILD_CONFIGURATION)/%,.dep/$(BUILD_CONFIGURATION)/%,$@))"
	cat "$<" | sed -re 's/\\/\\\\/g;s/"/\\"/g;s/(.*)/"\1"/' > "$@"

.obj/$(BUILD_CONFIGURATION)/common/zynqipmc/misc/version.o: common/zynqipmc/misc/version.cpp .obj/$(BUILD_CONFIGURATION)/common/zynqipmc/misc/version.json.cstr | pre-build
	@mkdir -p "$(dir $@)" "$(dir $(patsubst .obj/$(BUILD_CONFIGURATION)/%,.dep/$(BUILD_CONFIGURATION)/%,$@))"
	$(CXX) -c $(CFLAGS) $(WARNING_FLAGS) $(CXXFLAGS) $(LDFLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) -DVERSION_INFO_STR="$$(cat .obj/$(BUILD_CONFIGURATION)/common/zynqipmc/misc/version.json.cstr)" -o "$@" "$<" $(LIBS)
.PHONY: .obj/$(BUILD_CONFIGURATION)/common/zynqipmc/misc/version.o

.obj/$(BUILD_CONFIGURATION)/%.o: %.cpp | pre-build
	@mkdir -p "$(dir $@)" "$(dir $(patsubst .obj/$(BUILD_CONFIGURATION)/%,.dep/$(BUILD_CONFIGURATION)/%,$@))"
	$(CXX) -c $(CFLAGS) $(WARNING_FLAGS) $(CXXFLAGS) $(LDFLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) -o "$@" "$<" $(LIBS)

.obj/$(BUILD_CONFIGURATION)/%.o: %.S | pre-build
	@mkdir -p "$(dir $@)" "$(dir $(patsubst .obj/$(BUILD_CONFIGURATION)/%,.dep/$(BUILD_CONFIGURATION)/%,$@))"
	$(CXX) -c $(CFLAGS) $(WARNING_FLAGS) $(CXXFLAGS) $(LDFLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) -o "$@" "$<" $(LIBS)

ifeq (x$(GIT_DIRTY),x)
export DOXYGEN_GIT_DIRTY :=
else
export DOXYGEN_GIT_DIRTY := (dirty)
endif
doxygen: doxygen.conf $(shell find -L . -type f \( -name '*.c' -o -name '*.cc' -o -name '*.cpp' -o -name '*.S' -o -name '*.h' \) )
	doxygen doxygen.conf 2>&1 | egrep -vi -e '^error: Problems running dot: ' -e 'dot: symbol lookup error: dot: undefined symbol: GvExitOnUsage'

clean:
	rm -rf .dep/$(BUILD_CONFIGURATION)/ .obj/$(BUILD_CONFIGURATION)/ bin/$(BUILD_CONFIGURATION) doxygen/ Xilinx.spec

.PHONY: build pre-build all clean

.SUFFIXES:

-include $(shell find .dep/$(BUILD_CONFIGURATION)/ -type f 2>/dev/null)
