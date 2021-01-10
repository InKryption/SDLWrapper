.ONESHELL:

# start FUNCTIONS
define All_Files_Inside
$(foreach file,$(wildcard $(1)/*),$(if $(wildcard $(file)/*),$(call All_Files_Inside,$(file)),$(file)))
endef
# end FUNCTIONS

COMPILER:=x86_64-w64-mingw32-g++-win32

# Absolute root to project folder
root:=.

BIN:=bin
SRC:=src
BUILD:=Debug
NAME:=PROJECT

SRC_FOLDER:=$(root)/$(SRC)# Source folder absolute path
BIN_FOLDER:=$(root)/$(BIN)# Binary folder absolute path

# Linker Flags
LFlags:=\
-L$(ODIR) -static


# Compiler Flags definition by build
ifeq ($(BUILD),Debug)

CFlags:=\
-D_DEBUG \
-I$(SRC_FOLDER) -Ivendor \
-std=c++17 \
-g -Og \
-Wall -Werror -Wpedantic -Wno-error=pedantic \
-Wno-error=unknown-pragmas -Wno-error=unused-variable -Wno-error=unused-but-set-variable 

else ifeq ($(BUILD),Release)

CFlags:=\
-DNDEBUG \
-I$(SRC_FOLDER) -Ivendor \
-std=c++17 \
-O3

endif

# Output & Object Output directories
ODIR:=$(BIN_FOLDER)/$(BUILD)
OBJDIR:=$(ODIR)/obj
EXECUTABLE:=$(ODIR)/$(NAME).exe

# List of Source file paths, and a list of matching object files
SOURCE_FILES:=$(filter %.cpp,$(call All_Files_Inside,$(SRC_FOLDER)))
OBJECT_FILES:=$(foreach src,$(SOURCE_FILES),$(OBJDIR)/$(firstword $(subst ., ,$(notdir $(src)))).o)

$(EXECUTABLE): $(OBJECT_FILES)
	-$(COMPILER) $(OBJECT_FILES) -o $(EXECUTABLE) $(LFlags)


# Do this in the foreach, so that every source file in the list created before goes through this process automatically.
define Compile_Source
$(OBJDIR)/$(notdir $(firstword $(subst ., ,$(1)))).o: $(1) $(filter %$(notdir $(firstword $(subst ., ,$(1)))).hpp,$(call All_Files_Inside,$(SRC_FOLDER)))
	$(COMPILER) -c $(1) -o $(OBJDIR)/$(notdir $(firstword $(subst ., ,$(1)))).o $(CFlags)
endef
$(foreach src,$(SOURCE_FILES),$(eval $(call Compile_Source,$(src))))

.PHONY: clean dir run



# Run the executable
run: $(EXECUTABLE)
	@$(BIN)/run.bs $(EXECUTABLE)

# Create directory for the output if it doesn't exist
dir:
	-mkdir -p $(OBJDIR)

# Clean all object files that have no equivalent source file
Dirty_Objects=$(foreach pdo,$(wildcard $(OBJDIR)/*),$(if $(filter $(pdo),$(OBJECT_FILES)),,$(pdo))) $(filter-out $(EXECUTABLE),$(wildcard $(ODIR)/*.exe))

# Clean up object files
clean:
	@rm $(Dirty_Objects)
	@echo $(Dirty_Objects)