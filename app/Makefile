TOP_DIR=$(CURDIR)/..
SRC_DIR=$(CURDIR)

BUILD_DIR=$(TOP_DIR)/temp/app
OBJ_DIR=$(BUILD_DIR)/obj
BIN_DIR=$(BUILD_DIR)/bin
LIB_DIR=$(BUILD_DIR)/lib

BIN_NAME=app
SHARED_BINARY=$(BIN_DIR)/$(BIN_NAME)-shared
STATIC_BINARY=$(BIN_DIR)/$(BIN_NAME)-static
APP_LIB=$(LIB_DIR)/lib$(BIN_NAME).so

SRCS=$(wildcard $(SRC_DIR)/*.cpp)
OBJS=$(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

STATIC_LIBS_DIR=$(TOP_DIR)/temp/libs/static
SHARED_LIBS_DIR=$(TOP_DIR)/temp/libs/shared
LIBS_INCLUDE_DIR=$(TOP_DIR)/libs/include

SHARED_LIBS=$(wildcard $(SHARED_LIBS_DIR)/*.so)
SHARED_LD_FLAGS=-fPIE -L$(SHARED_LIBS_DIR) \
	-Wl,-rpath,$(SHARED_LIBS_DIR) \
	$(SHARED_LIBS:$(SHARED_LIBS_DIR)/lib%.so=-l%)

STATIC_LIBS=$(wildcard $(STATIC_LIBS_DIR)/*.a)
STATIC_LD_FLAGS=-L$(STATIC_LIBS_DIR) \
	$(STATIC_LIBS:$(STATIC_LIBS_DIR)/%.a:-l:lib%.a)

.PHONY: all clean

all: $(SHARED_BINARY) $(STATIC_BINARY) $(APP_LIB)

clean:
	rm -rf $(BUILD_DIR)

$(SHARED_BINARY): $(OBJS)
	@mkdir -p $(@D)
	$(CXX) $^ $(SHARED_LD_FLAGS) -o $@

$(STATIC_BINARY): $(OBJS)
	@mkdir -p $(@D)
	$(CXX) $^ $(STATIC_LD_FLAGS) -o $@

$(APP_LIB): $(filter-out $(OBJ_DIR)/main.o, $(OBJS))
	@mkdir -p $(@D)
	$(CXX) -shared $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(info compiling $<)
	@$(CXX) -c $< -I$(LIBS_INCLUDE_DIR) -fPIC -o $@
