# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: H10-add-vectors
project (Final-project)

# Create an executable named 'add-vectors' from the source file 'add-vectors.cxx'
add_executable(Final_project src/Final_project.cxx)
target_compile_features(Final_project PRIVATE
    cxx_auto_type cxx_variadic_templates)

# Create an additional target for assignment submission
add_assignment(Final_project src/Final_project.cxx)
