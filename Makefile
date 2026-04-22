# ATM-OOP Makefile (separate compilation)
# Auto-discovers src/**/*.cpp, compiles each to build/obj/, links to build/atm.

# ---- Config ----
CXX      := g++
CXXSTD   := -std=c++20
WARN     := -Wall -Wextra -Wpedantic
DEBUG    := -O0 -g
INCLUDES := -Isrc
# -MMD -MP: emit .d files tracking which headers each .cpp depends on.
# Ket qua: sua header -> chi cac .o lien quan rebuild.
DEPFLAGS := -MMD -MP
CXXFLAGS := $(CXXSTD) $(WARN) $(DEBUG) $(INCLUDES) $(DEPFLAGS)

TARGET   := atm
BUILDDIR := build
OBJDIR   := $(BUILDDIR)/obj

# Discover all .cpp recursively under src/
SRCS := $(shell find src -name '*.cpp')
# Map src/foo/bar.cpp -> build/obj/foo/bar.o
OBJS := $(SRCS:src/%.cpp=$(OBJDIR)/%.o)
# Dependency files emitted by -MMD
DEPS := $(OBJS:.o=.d)

.PHONY: all run clean help

all: $(BUILDDIR)/$(TARGET)

# ---- Link step ----
$(BUILDDIR)/$(TARGET): $(OBJS)
	@mkdir -p $(BUILDDIR)
	@echo "[LINK] $@"
	@$(CXX) $(OBJS) -o $@
	@echo "[OK]   Built $@"

# ---- Compile step (pattern rule) ----
# $< = first prerequisite (the .cpp), $@ = target (the .o)
$(OBJDIR)/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	@echo "[CXX]  $<"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(BUILDDIR)/$(TARGET)
	@echo "[RUN]  ./$(BUILDDIR)/$(TARGET)"
	@./$(BUILDDIR)/$(TARGET)

clean:
	@rm -rf $(BUILDDIR)
	@echo "[CLEAN] Removed $(BUILDDIR)/"

help:
	@echo "Targets:"
	@echo "  make         - Compile + link"
	@echo "  make run     - Compile + link + run"
	@echo "  make clean   - Delete build/"

# Include auto-generated dependency files (silent if missing)
-include $(DEPS)
