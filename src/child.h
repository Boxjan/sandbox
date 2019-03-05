//
// Created by Boxjan on Dec 16, 2018 15:30.
//

#ifndef SANDBOX_CHILD_H
#define SANDBOX_CHILD_H

#include "runner.h"

enum CHILD_EXIT_CODE {
    CPU_LIMIT_FAIL,
    MEMORY_LIMIT_FAIL,
    STACK_LIMIT_FAIL,
    OUTPUT_LIMIT_FAIL,
    OPEN_FILE_COUNT_LIMIT_FAIL,
    OPEN_INPUT_FILE_FAIL,
    MOUNT_INPUT_FILE_FAIL,
    OPEN_OUTPUT_FILE_FAIL,
    MOUNT_OUTPUT_FILE_FAIL,
    OPEN_ERROR_FILE_FAIL,
    MOUNT_ERROR_FILE_FAIL,
    SET_UID_FAIL,
    SET_GID_FAIL,
    GET_EXEC_PATH_ERROR,
    GET_EXEC_ARGS_ERROR,
    GET_EXEC_ENV_ERROR,
    SCMP_LOAD_FAIL,
    EXEC_ERROR,
    OTHER_FAIL,
};

const char CHILD_EXIT_REASON[][32] = {
        "SETTING CPU LIMIT FAIL",
        "SETTING MEMORY LIMIT FAIL",
        "SETTING STACK LIMIT FAIL",
        "SETTING OUTPUT LIMIT FAIL",
        "SETTING OPEN FILE LIMIT FAIL",
        "OPEN INPUT FILE FAIL",
        "MOUNT INPUT FILE FAIL",
        "OPEN OUTPUT FILE FAIL",
        "MOUNT OUTPUT FILE FAIL",
        "OPEN ERROR FILE FAIL",
        "MOUNT ERROR FILE FAIL",
        "SETTING USER ID FAIL",
        "SETTING GROUP ID FAIL",
        "GET EXEC PATH ERROR",
        "GET EXEC ARGS ERROR",
        "GET EXEC ENV ERROR",
        "SECCOMP RULE LOAD FAIL",
        "EXEC CAN NOT RUN",
        "OTHER ERROR"
};     //12345678123456781234567812345678

void child(const RuntimeConfig *);

#define CHILD_EXIT(code) { \
    LOG_ERROR("child process exit because: %s", CHILD_EXIT_REASON[code]); \
    close_file(IN_FILE); \
    close_file(OUT_FILE); \
    close_file(ERR_FILE); \
    raise(SIGUSR2); \
}


#endif //SANDBOX_CHILD_H
