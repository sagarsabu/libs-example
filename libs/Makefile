TOP_DIR=$(CURDIR)/..
LIBS_DIR=$(CURDIR)

BUILD_DIR=$(TOP_DIR)/temp/libs
OBJ_DIR=$(BUILD_DIR)/obj
SHARED_LIBS_DIR=$(BUILD_DIR)/shared
STATIC_LIBS_DIR=$(BUILD_DIR)/static

LIBS=$(shell find $(LIBS_DIR) -mindepth 1 -maxdepth 1 -type d -not -iname include)
SHARED_LIBS=$(LIBS:$(LIBS_DIR)/%=$(SHARED_LIBS_DIR)/lib%.so)
STATIC_LIBS=$(LIBS:$(LIBS_DIR)/%=$(STATIC_LIBS_DIR)/lib%.a)

.PHONY: all clean

all: $(SHARED_LIBS) $(STATIC_LIBS)

clean:
	rm -rf $(BUILD_DIR)

$(SHARED_LIBS_DIR)/lib%.so: $(LIBS_DIR)/%/*.cpp
	@mkdir -p $(@D)
	@echo "creating shared lib $@ from..."
	@for i in $^; do echo "  <- $$i"; done
	@$(CXX) $^ -I$(LIBS_DIR)/include -shared -fPIC -o $@

$(STATIC_LIBS_DIR)/lib%.a: $(LIBS_DIR)/%/*.cpp
	@mkdir -p $(@D)
	@echo "creating static lib $@ from..."
	@for i in $^; do echo "  <- $$i"; done
	@$(AR) cr $@ $^
