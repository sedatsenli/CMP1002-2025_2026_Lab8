CXX      = g++
CXXFLAGS = -Wall --std=c++17
CATCH    = catch_amalgamated.cpp
BINARY   = test

# -------------------------------------------------------
# Detect OS — use 'copy' on Windows, 'cp' on Unix/Mac
# -------------------------------------------------------
ifeq ($(OS),Windows_NT)
    COPY = copy
    RM   = del /f /q
    RUN  = $(BINARY).exe
    # Windows paths use backslash
    STUDENT_SRC  = MainProgram.cpp
    TEACHER_SRC  = teacher\MainProgram.cpp
    TARGET_SRC   = MainProgram.cpp
else
    COPY = cp
    RM   = rm -f
    RUN  = ./$(BINARY)
    STUDENT_SRC  = MainProgram.cpp
    TEACHER_SRC  = teacher/MainProgram.cpp
    TARGET_SRC   = MainProgram.cpp
endif

# -------------------------------------------------------
# Copy submission into root so test.cpp can include it
# -------------------------------------------------------
prepare:
	$(COPY) $(STUDENT_SRC) $(TARGET_SRC)

prepare_teacher:
	$(COPY) $(TEACHER_SRC) $(TARGET_SRC)

# -------------------------------------------------------
# Build single test binary
# -------------------------------------------------------
build: 
	$(CXX) $(CXXFLAGS) -o $(BINARY) test.cpp $(CATCH)

build_teacher: 
	$(CXX) $(CXXFLAGS) -o $(BINARY) test.cpp $(CATCH)

# -------------------------------------------------------
# Student targets — run individual groups
# -------------------------------------------------------
point: build
	$(RUN) "[point]"

rectangle: build
	$(RUN) "[rectangle]"

friend: build
	$(RUN) "[friend]"

constdemo: build
	$(RUN) "[constdemo]"

# -------------------------------------------------------
# Run ALL groups — default target
# -------------------------------------------------------
all: build
	$(RUN)

# -------------------------------------------------------
# Teacher targets
# -------------------------------------------------------
point_teacher: build_teacher
	$(RUN) "[point]"

rectangle_teacher: build_teacher
	$(RUN) "[rectangle]"

friend_teacher: build_teacher
	$(RUN) "[friend]"

constdemo_teacher: build_teacher
	$(RUN) "[constdemo]"

test_teacher: build_teacher
	$(RUN)

# -------------------------------------------------------
# Clean
# -------------------------------------------------------
clean:
ifeq ($(OS),Windows_NT)
	$(RM) $(BINARY).exe $(TARGET_SRC)
else
	$(RM) $(BINARY) $(TARGET_SRC)
endif

.PHONY:   build build_teacher \
        point rectangle friend constdemo all \
        point_teacher rectangle_teacher friend_teacher \
        constdemo_teacher test_teacher clean