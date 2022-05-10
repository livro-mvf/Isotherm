
set (       IsothermExe
            "TesteLangmuirFreundlich"
            )

set (       IsothermFile
            "TesteLangmuirFreundlich.cpp"
            )



set     (   CMAKE_RUNTIME_OUTPUT_DIRECTORY
            "${CMAKE_CURRENT_LIST_DIR}"
            )

add_executable  (   ${IsothermExe}
                    ${IsothermFile}
                    )

target_include_directories  (   ${IsothermExe}
                                PRIVATE
                                "${CMAKE_SOURCE_DIR}/IsothermLib/include"
                                )

target_link_libraries    (      ${IsothermExe}
                                PRIVATE
                                IsothermLib
                                )

target_link_directories (   ${IsothermExe}
                            PRIVATE
                            "${CMAKE_SOURCE_DIR}/IsothermLib/lib"
                            )
