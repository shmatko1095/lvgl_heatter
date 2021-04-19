file(REMOVE_RECURSE
  "config/sdkconfig.h"
  "config/sdkconfig.cmake"
  "bootloader.bin"
  "bootloader.map"
  "project_elf_src_esp32.c"
  "CMakeFiles/uf2"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/uf2.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
