DOCS=./html
BUILD_DIR=./build
BINARY=$(BUILD_DIR)/linked_list
SRC_DIRS=. ./src
INCLUDE_DIRS=. ./include

CC=gcc
OPT=-O0
DEPFLAGS=-MP -MD
CFLAGS=-Wall -Wextra -g $(foreach D,$(INCLUDE_DIRS),-I$(D)) $(OPT) $(DEPFLAGS)

CFILES=$(foreach D,$(SRC_DIRS),$(wildcard $(D)/*.c))
OBJECTS=$(patsubst %.c,%.o,$(CFILES))
DEPFILES=$(patsubst %.c,%.d,$(CFILES))


.PHONY: all
all: $(BUILD_DIR) | $(BINARY)


$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)


$(BINARY): $(OBJECTS)
	$(CC) -o $@ $^


%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<


.PHONY: docs
docs:
	doxygen


.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) $(OBJECTS) $(DEPFILES) $(foreach D,$(SRC_DIRS),$(wildcard $(D)/*.d)) $(DOCS)
