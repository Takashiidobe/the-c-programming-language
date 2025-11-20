rwildcard=$(foreach d, $(wildcard $(1:=/*)), $(call rwildcard, $d, $2) $(filter $(subst *, %, $2), $d))

OUT_DIR = out
SRC_DIR = src
TEST_DIR = tests
INC_DIR = includes

SRC_SOURCES = $(call rwildcard, $(SRC_DIR), *.c)
SRC_HEADERS = $(call rwildcard, $(SRC_DIR), *.h)
TEST_SOURCES = $(call rwildcard, $(TEST_DIR), *.c)
TEST_HEADERS = $(call rwildcard, $(TEST_DIR), *.h)
INC_HEADERS = $(call rwildcard, $(INC_DIR), *.h)
RAW_DEBUG_FILES = $(call rwildcard, ., *.dSYM)

SRC_OBJECTS = $(patsubst $(SRC_DIR)/%.c,$(OUT_DIR)/obj/%.o,$(SRC_SOURCES))
TEST_BIN_NAMES = $(notdir $(basename $(TEST_SOURCES)))
TEST_BINS = $(addprefix $(OUT_DIR)/tests/,$(TEST_BIN_NAMES))
DEBUG_FILES = $(patsubst ./%,%,$(RAW_DEBUG_FILES))
FMT_FILES = $(sort $(SRC_SOURCES) $(SRC_HEADERS) $(INC_HEADERS) $(TEST_SOURCES) $(TEST_HEADERS))

LDLIBS = -lm
CFLAGS = -g -Wall
CPPFLAGS = -I$(INC_DIR) -Isrc
CLANG_FORMAT ?= clang-format

.PHONY: all clean fmt test

all: $(TEST_BINS)

$(OUT_DIR)/obj/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OUT_DIR) $(DEBUG_FILES)

fmt:
	$(CLANG_FORMAT) -i $(FMT_FILES)

test: all
	@set -e; for bin in $(TEST_BINS); do echo "Running $$bin"; $$bin; done

define BUILD_TEST
$(OUT_DIR)/tests/$(notdir $(basename $(1))): $(1) $(SRC_OBJECTS)
	@mkdir -p $$(dir $$@)
	$(CC) $(CPPFLAGS) $(CFLAGS) $$< $(SRC_OBJECTS) -o $$@ $(LDLIBS)
endef

$(foreach test,$(TEST_SOURCES),$(eval $(call BUILD_TEST,$(test))))
