# ATM-OOP Makefile
# Goal: gom toolchain commands lai de go 'make' la xong.

# ---- Config ----
CXX      := g++
CXXSTD   := -std=c++20
WARN     := -Wall -Wextra -Wpedantic
DEBUG    := -O0 -g
INCLUDES := -Isrc
CXXFLAGS := $(CXXSTD) $(WARN) $(DEBUG) $(INCLUDES)

TARGET   := atm
SRC      := src/main.cpp
BUILDDIR := build

# ---- Default target: chay 'make' khong tham so se chay 'all' ----
.PHONY: all run clean help

all: $(BUILDDIR)/$(TARGET)

$(BUILDDIR)/$(TARGET): $(SRC) $(wildcard src/**/*.hpp) $(wildcard src/*.hpp)
	@mkdir -p $(BUILDDIR)
	@echo "[CXX] Compiling $(SRC) -> $@"
	@$(CXX) $(CXXFLAGS) $(SRC) -o $@
	@echo "[OK]  Built $@"

run: $(BUILDDIR)/$(TARGET)
	@echo "[RUN] ./$(BUILDDIR)/$(TARGET)"
	@./$(BUILDDIR)/$(TARGET)

clean:
	@rm -rf $(BUILDDIR)
	@echo "[CLEAN] Removed $(BUILDDIR)/"

help:
	@echo "Targets:"
	@echo "  make         - Compile (alias of 'make all')"
	@echo "  make run     - Compile + run"
	@echo "  make clean   - Delete build/ artifacts"
	@echo "  make help    - This message"
