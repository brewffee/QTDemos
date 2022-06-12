# convenience script 
SOURCE_FILE="main"
EXECUTABLE_FILE="qtdemos"
PROJECT_DIR="." 

if [ "$1" = "test" ]; then
    cd $PROJECT_DIR && qmake && make && rm .qmake.stash && rm $SOURCE_FILE.o && ./$EXECUTABLE_FILE
elif [ "$1" = "build" ] || [ "$1" = "" ]; then
    cd $PROJECT_DIR && qmake && make && rm .qmake.stash && rm $SOURCE_FILE.o
fi

