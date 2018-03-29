list(APPEND LDFLAGS -lm -lstdc++)
set(FP_ABSTOLERANCE 0.01)

add_executable(stepanov_abstraction stepanov_abstraction.cpp)
