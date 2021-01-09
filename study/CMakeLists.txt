aux_source_directory(. SRC_LIST)
link_directories(/usr/lib)

foreach (var ${SRC_LIST})
    string(REGEX REPLACE ".*/" "" var ${var})
    string(REGEX REPLACE ".cpp" "" tgt ${var})

    add_executable(${tgt} ${var})
#    set(LINK_ARGS eb_network libgo evpp_static event glog pthread dl)
#    target_link_libraries(${tgt} ${LINK_ARGS})
endforeach (var)