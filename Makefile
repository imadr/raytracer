ifeq ($(OS),Windows_NT)
	LDFLAGS = -l gdi32 -mwindows
	CPPFLAGS ?= -MMD -MP -D _WIN32
else
	LDFLAGS = -lm -lX11
	CPPFLAGS ?= -MMD -MP -D X11
endif

CC = g++

ifeq ($(WINDOWS_ON_LINUX),yes)
	LDFLAGS = -l gdi32 -mwindows -static-libstdc++ -static-libgcc -static -lpthread
	CPPFLAGS ?= -MMD -MP -D _WIN32
	CC = i686-w64-mingw32-c++
endif

TARGET_EXEC ?= raytracer

BUILD_DIR ?= ./build
SRC_DIRS ?= ./src

SRCS := $(shell find $(SRC_DIRS) -name *.cpp -or -name *.c -or -name *.s)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CC) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

.PHONY: clean

clean:
	$(RM) -r $(BUILD_DIR)

-include $(DEPS)

MKDIR_P ?= mkdir -p
