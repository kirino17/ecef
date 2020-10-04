#msvcpch.cmake
#����һ���꣬��������
#USE_MSVC_PCH        ��������
#PCH_TARGET          ����Ŀ����
#PCH_HEADER_FILE     ��Ԥ����ͷ�ļ����ƣ�stdafx.h��
#PCH_SOURCE_FILE     ��Ԥ����Դ�ļ����ƣ�stdafx.cpp��
MACRO(USE_MSVC_PCH PCH_TARGET PCH_HEADER_FILE PCH_SOURCE_FILE)
IF(MSVC)
	# ��ȡԤ����ͷ�ļ����ļ�����ͨ����stdafx
	GET_FILENAME_COMPONENT(PCH_NAME ${PCH_HEADER_FILE} NAME_WE)
	
	# ����Ԥ�����ļ���·��
	IF(CMAKE_CONFIGURATION_TYPES)
        # ���������ѡ�Debug/Release����·�������Լ�����ѡ��
		SET(PCH_DIR "${CMAKE_CURRENT_BINARY_DIR}/PCH")
	ELSE(CMAKE_CONFIGURATION_TYPES)
		SET(PCH_DIR "${CMAKE_CURRENT_BINARY_DIR}/PCH")
	ENDIF(CMAKE_CONFIGURATION_TYPES)

	# ����Ԥ�����ļ���·��
	FILE(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/PCH)

	# ������Ŀ���ԣ�ʹ��Ԥ����ͷ�ļ�
	SET_TARGET_PROPERTIES(${PCH_TARGET} PROPERTIES COMPILE_FLAGS 
		"/Yu${PCH_HEADER_FILE} /FI${PCH_HEADER_FILE} /Fp${PCH_DIR}/${PCH_NAME}.pch")

	# Ԥ����Դ�ļ���stdafx.cpp���������ԣ�����Ԥ�����ļ�
	SET_SOURCE_FILES_PROPERTIES(${PCH_SOURCE_FILE} PROPERTIES COMPILE_FLAGS
		"/Yc${PCH_HEADER_FILE}")
    
	# ��Ԥ�����ļ��ĵ�����б�
	SET_DIRECTORY_PROPERTIES(PROPERTIES
		ADDITIONAL_MAKE_CLEAN_FILES ${PCH_DIR}/${PCH_NAME}.pch)
ENDIF(MSVC)
ENDMACRO(USE_MSVC_PCH)