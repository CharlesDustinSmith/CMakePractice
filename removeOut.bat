@REM This is to remove the directory 
@REM /s is for removing all the directories and files in the specified directory
@REM in addition to the directory itself. Use to remove a directory tree.
@REM /q is for quiet mode, do not ask if ok to remove a directory tree with /s

@echo off
if exist out\ (
    @echo on 
    Echo "Out Folder Exist"
    @echo off
    rmdir /s /q out
) else (
    @echo on
    echo "Out Folder Does Not Exist"
    @echo off
)


@echo off
if exist build\ (
    @echo on
    echo "Build Folder Exist"
    @echo off
    rmdir /s /q build
) else (
    @echo on
    echo "Build Folder Does Not Exist"
    @echo off
)