file(REMOVE_RECURSE
  "libfunctions.a"
  "libfunctions.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/functions.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
